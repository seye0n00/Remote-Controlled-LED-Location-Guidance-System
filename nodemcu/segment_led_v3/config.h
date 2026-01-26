#ifndef CONFIG_H
#define CONFIG_H

// ===== Board / Device =====
static const char EDGE_ID = 'B';

// ===== Edge LED =====
#define LED_EDGE_PIN D1

// ===== WiFi =====
#define WIFI_SSID     ""
#define WIFI_PASSWORD ""

// ===== MQTT =====
#define MQTT_SERVER   ""
#define MQTT_PORT     1883
#define MQTT_SUB_TOPIC "inventory/node/"

#endif
