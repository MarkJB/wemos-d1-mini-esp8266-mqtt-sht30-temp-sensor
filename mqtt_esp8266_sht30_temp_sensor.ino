#include <ESP8266WiFi.h>
#include <PubSubClient.h>
#include <WEMOS_SHT3X.h>
#include <ArduinoJson.h>

SHT3X sht30(0x45);
StaticJsonDocument<200> doc;

const char* ssid = "ssid";
const char* password = "password";
const char* mqtt_server = "127.0.0.1";

const char* sensor_location = "where_am_i";

WiFiClient espClient;
PubSubClient client(espClient);

void setup() {
  setup_wifi();
  pinMode(D0, WAKEUP_PULLUP);
  client.setServer(mqtt_server, 1883); // Setup the mqtt server details (this is the MQTT broker address and port that we will connect to)
}

void setup_wifi() {
  WiFi.begin(ssid, password);
  while (WiFi.status() != WL_CONNECTED) {
    delay(500);
  }
}

void reconnect() {
  while (!client.connected()) {
      client.connect("ESP8266Client1");
      delay(250);
   }
}

void send_temp(){
    if(sht30.get()==0){      
      doc["location"] = sensor_location;
      doc["temperature"] = sht30.cTemp;
      doc["humidity"] = sht30.humidity;
      char JSONmessageBuffer[200];
      serializeJson(doc, JSONmessageBuffer);
      client.publish("temp_sensors", JSONmessageBuffer);
    }
}

void loop() {
  if (!client.connected()) {
    reconnect();
  }
  send_temp();
  client.loop();  // Run this regularly to check for MQTT messages
  ESP.deepSleep(5 *60 * 1000000, WAKE_RF_DEFAULT);
}
