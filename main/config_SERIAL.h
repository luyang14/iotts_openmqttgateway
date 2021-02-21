/*
  OpenMQTTGateway  - ESP8266 or Arduino program for home automation

   This files enables you to set your parameters for the PWM actuator

    Copyright: (c)

    This file is part of OpenMQTTGateway.

    OpenMQTTGateway is free software: you can redistribute it and/or modify
    it under the terms of the GNU General Public License as published by
    the Free Software Foundation, either version 3 of the License, or
    (at your option) any later version.

    OpenMQTTGateway is distributed in the hope that it will be useful,
    but WITHOUT ANY WARRANTY; without even the implied warranty of
    MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
    GNU General Public License for more details.

    You should have received a copy of the GNU General Public License
    along with this program.  If not, see <http://www.gnu.org/licenses/>.
*/

/*-------------------SERIAL topics & parameters----------------------*/
extern void setupSERIAL();
extern bool SERIALtoMQTT();
extern void MQTTtoSERIAL(char* topicOri, JsonObject& data);
extern void MQTTtoSERIAL(char* topicOri, char* datacallback);

// SERIAL MQTT Subjects
#define subjectMQTTtoSERIAL          "/commands/MQTTtoSERIAL"
#define subjectSERIALtoMQTT          "/SERIALtoMQTT"
#define subjectMQTTtoSERIALset       subjectMQTTtoSERIAL "/set" //set channel(s) with JSON struct {"r":0-1,"g":0-1,"b":0-1,"w0":0-1,"w0":0-1,"fade":<fade time in seconds>}
#define subjectMQTTtoSERIALcalibrate subjectMQTTtoSERIAL "/calibrate" //set calibration data JSON struct {"gamma-r":0.5-4.0,"min-r":0-1,"max-r":0-1 etc. }

//config serial
#define serial_port Serial //Serial1 Serial2
#define UART_BAUD 115200   //Baudrate UART

#define BUFFERSIZE 1024
