/*
  Source Code for Simple and Smart Air Purifier System
  Written by Aaron Kow
  Licence: MIT Licence
*/

#ifndef iotconfig_h
#define iotconfig_h

#include <Arduino.h>
#include <aws_iot_mqtt.h>
#include <aws_iot_version.h>
#include "aws_iot_config.h"

class aws_iot_setup {
  public:
    void config(void);
    void test(void);
    void data(char*, float);
};

#endif
