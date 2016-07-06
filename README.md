# Source Code Repository for AWS IoT Home Security Model Hardwares

### AWS IoT Home Security Model
###### A model of home security system that utilized sensors and internet to monitor the security status in real-time.

The difference between this repository and the [original](https://github.com/AaronKow/IoT-Home-Security-Model-HW) is that, this source code is using AWS IoT to communicate the data to the Real-Time Dashboard instead of "HTTP". Modification of coding can be found in IoTHome-Yun folder only. The rest remain the same as the [original repository](https://github.com/AaronKow/IoT-Home-Security-Model-HW).


The hardwares (microcontroller) used in this project are Arduino Yun and Arduino Mega 2560.
In this repository contains two important folders, IoTHome-Yun and IoTHome-Mega. Each folder contains Arduino Sketch .ino which one for Arduino Yun and another for Arduino Mega 2560.
Please add Modified-DHT-sensor-library to your Arduino IDE. The DHT library is customized for this project.
If there is any issue or question about the codes, you can open issue or leave a message to me.


For more detail about this project, please visit [here](https://goo.gl/aZGpg3).


### Require Steps
Please follow this steps before compile the code. This source code require the "Modified-DHT-sensor-library" for it as the library. Please follow the pictures below to include it in your Arduino IDE:
Step 1:
![Step 1](https://raw.githubusercontent.com/AaronKow/AWS-IoT-Home-Security-Model-HW/master/Pictures/step1.png)

Step 2:
![Step 2](https://raw.githubusercontent.com/AaronKow/AWS-IoT-Home-Security-Model-HW/master/Pictures/step2.png)
