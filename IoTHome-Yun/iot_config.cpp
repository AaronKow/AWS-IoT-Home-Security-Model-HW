/*
 * Copyright 2010-2015 Amazon.com, Inc. or its affiliates. All Rights Reserved.
 *
 * Licensed under the Apache License, Version 2.0 (the "License").
 * You may not use this file except in compliance with the License.
 * A copy of the License is located at
 *
 *  http://aws.amazon.com/apache2.0
 *
 * or in the "license" file accompanying this file. This file is distributed
 * on an "AS IS" BASIS, WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either
 * express or implied. See the License for the specific language governing
 * permissions and limitations under the License.
 */


/*
 * This Source Code is Modified for Simple and Smart Air Purifier System
 * Written by Aaron Kow
*/

#include "iot_config.h"

aws_iot_mqtt_client myClient; // init iot_mqtt_client
char msg[32]; // read-write buffer
int cnt = 0; // loop counts
int rc = -100; // return value placeholder

void msg_callback(char* src, int len) {
  Serial.println("CALLBACK:");
  int i;
  for(i = 0; i < len; i++) {
    Serial.print(src[i]);
  }
  Serial.println("");
}

void aws_iot_setup::config(void){
  
  Serial.begin(115200);
  //  while(!Serial); // Start Serial for print-out and wait until it's ready

  char curr_version[80];
  sprintf(curr_version, "AWS IoT SDK Version(dev) %d.%d.%d-%s\n", VERSION_MAJOR, VERSION_MINOR, VERSION_PATCH, VERSION_TAG);
  Serial.println(curr_version);
  
  // Set up the client
  if((rc = myClient.setup(AWS_IOT_CLIENT_ID)) != 0) {
    Serial.println("Setup failed!");
    Serial.println(rc);
  }
  // Load user configuration
  if((rc = myClient.config(AWS_IOT_MQTT_HOST, AWS_IOT_MQTT_PORT, AWS_IOT_ROOT_CA_PATH, AWS_IOT_PRIVATE_KEY_PATH, AWS_IOT_CERTIFICATE_PATH)) != 0) {
    Serial.println("Config failed!");
    Serial.println(rc);
  }
  // Use default connect: 60 sec for keepalive
  if((rc = myClient.connect()) != 0) {
    Serial.println("Connect failed!");
    Serial.println(rc); // fail = -5
  }
  // Subscribe to "dustlevel"
  if((rc = myClient.subscribe("dustlevel", 1, msg_callback)) != 0) {
    Serial.println("Subscribe failed!");
    Serial.println(rc); // fail = -7
  }
  // Delay to make sure SUBACK is received, delay time could vary according to the server
  delay(2000);
}

void aws_iot_setup::test(void){
  // Generate a new message in each loop and publish to "dustlevel"
  char msg[32];
  sprintf(msg, "new message %d", cnt);
  if((rc = myClient.publish("dustlevel", msg, strlen(msg), 1, false)) != 0) {
    Serial.println("Publish failed!");
    Serial.println(rc); // fail = -6
  }
  
  // Get a chance to run a callback
  if((rc = myClient.yield()) != 0) {
    Serial.println("Yield failed!");
    Serial.println(rc);
  }
  
  // Done with the current loop
  sprintf(msg, "loop %d done", cnt++);
  Serial.println(msg);
  
  delay(1000);
}

void aws_iot_setup::data(char* topic, float data){
  char msg[32], mqtt[32];
//  sprintf(mqtt, "%s", data.c_str()); // because it is a C function and does not understand C++ objects, call c_str() is needed
  dtostrf(data , 3, 2, msg);
  sprintf(mqtt, "%s", msg);
  
  if((rc = myClient.publish(topic, mqtt, strlen(mqtt), 1, false)) != 0) {
    Serial.println("Publish failed!");
    Serial.println(rc); // fail = -6
  }

  // for debug print
  Serial.print("Topic: ");
  Serial.print(topic);
  Serial.print(", message: ");
  Serial.println(mqtt);
}
