/*  
  OpenMQTTGateway  - ESP8266 or Arduino program for home automation 

   Act as a wifi or ethernet gateway between your 433mhz/infrared IR signal  and a MQTT broker 
   Send and receiving command by MQTT
 
  This gateway enables to:
 - receive MQTT data from a topic and send SMS corresponding to the received MQTT data
 - publish MQTT data to a different topic related to received SMS

    Copyright: (c)Florian ROBERT
  
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
#include "User_config.h"

#ifdef ZgatewaySERIAL

#include <ArduinoJson.h>

char serial_sendbuf[BUFFERSIZE];

void setupSERIAL(void) 
{
  serial_port.begin(UART_BAUD);
  Log.trace(F("ZgatewaySERIAL setup done " CR));
}
//serial2mqtt
bool SERIALtoMQTT(void) 
{
  int i = 0;
  if (serial_port.available())
  {
    memset(serial_sendbuf,0,sizeof(serial_sendbuf));
    while (serial_port.available())
    {
      serial_sendbuf[i] = serial_port.read(); // read char from UART
      if (i < BUFFERSIZE - 1)i++;
    }
    Log.notice(F("MQTT SEND: %s" CR), serial_sendbuf);
    pub(subjectSERIALtoMQTT, serial_sendbuf);
    
    i = 0;
  }  

  return true;
}

//mqtt2serial
#ifdef simpleReceiving
void MQTTtoSERIAL(char* topicOri, char* datacallback) 
{

  if (cmpToMainTopic(topicOri, subjectMQTTtoSERIAL))
  {
    serial_port.write((const uint8_t*)datacallback,strlen(datacallback));
    Log.trace(F("MQTTtoSERIAL data analysis" CR));
  }
}
#endif

#ifdef jsonReceiving
void MQTTtoSERIAL(char* topicOri, JsonObject& data) 
{
  if (cmpToMainTopic(topicOri, subjectMQTTtoSERIAL))
  {
    //do something
    Log.trace(F("MQTTtoSERIAL json data analysis" CR));
  }
}
#endif
#endif

