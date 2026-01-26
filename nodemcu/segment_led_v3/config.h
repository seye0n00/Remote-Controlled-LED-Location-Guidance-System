#ifndef CONFIG_H
#define CONFIG_H

// ===== Board / Device =====
static const char EDGE_ID = 'B';

// ===== Edge LED =====
#define LED_EDGE_PIN D1

// ===== WiFi =====
#define WIFI_SSID     "KT_GiGA_7ABD"
#define WIFI_PASSWORD "acbc3hh290"

// ===== MQTT =====
#define MQTT_SERVER   "172.30.1.99"
#define MQTT_PORT     1883
#define MQTT_SUB_TOPIC "inventory/node/"

#endif
