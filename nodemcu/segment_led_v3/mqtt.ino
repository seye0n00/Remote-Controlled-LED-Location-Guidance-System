#include <PubSubClient.h>
#include <ArduinoJson.h>
#include "log.h"
#include "config.h"
#include "device.h"

extern WiFiClient espClient;

const char* mqtt_server = MQTT_SERVER;
PubSubClient client(espClient);

void callback(char* topic, byte* payload, unsigned int length) {
  String msg;
  for (int i = 0; i < length; i++) {
    msg += (char)payload[i];
  }

  //[INFO] MQTT : RX [inventory/node/A/cmd] {"edge": 1}
  LOG_I("MQTT", String("RX [") + topic + "] " + msg);
  
  StaticJsonDocument<128> doc; //key-val 저장 변수
  DeserializationError err = deserializeJson(doc, msg);

  if (err) {
    LOG_E("MQTT", "JSON parse failed");
    return;
  }

  if (doc.containsKey("seg")){
    uint8_t seg = doc["seg"];
    
    toggle_segment(seg);
  }
}

void mqtt_reconnect() {
  LOG_I("MQTT", "Trying to connect");

  while (!client.connected()) {

    String clientId = "ESP8266Client-";
    clientId += String(random(0xffff), HEX);

    if (client.connect(clientId.c_str())) {
      LOG_I("MQTT", "Connected");

      String subTopic = String(MQTT_SUB_TOPIC) + EDGE_ID + "/cmd";
      client.subscribe(subTopic.c_str());
      LOG_I("MQTT", String("Subscribed to ") + subTopic);

    } else {
      LOG_E("MQTT", String("Failed, rc=") + client.state());
      delay(500);
    }
  }
}

void mqtt_init() {
  client.setServer(mqtt_server, 1883);
  client.setCallback(callback);
}

void mqtt_loop() {

  if (!client.connected()) {
    mqtt_reconnect();
  }
  client.loop();
}
