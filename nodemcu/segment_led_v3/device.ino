#include <Arduino.h>
#include "device.h"
#include "neopixel_controller.h"
#include "log.h"
#include "config.h"

static int8_t current_seg = -1;

void device_init() {
  pinMode(LED_EDGE_PIN, OUTPUT);
  digitalWrite(LED_EDGE_PIN, LOW);
  current_seg = -1;
  update_edge_led();
}

void update_edge_led() {
  if (current_seg == -1) {
    digitalWrite(LED_EDGE_PIN, LOW);
  } else {
    digitalWrite(LED_EDGE_PIN, HIGH);
  }
}

void toggle_segment(uint8_t seg_id) {
  if (seg_id >= NUM_SEGMENT) return;

  // Same segment pressed again: OFF
  if(current_seg == seg_id){
    neopixel_set_segment(current_seg, 0, 0, 0);
    current_seg = -1;
  }
  // Different segment pressed: switch (previous OFF, new ON)
  else{

    if(current_seg != -1){
      neopixel_set_segment(current_seg, 0, 0, 0);
    }

    neopixel_set_segment(seg_id, 0x20,0x20,0x20);
    current_seg=seg_id;
  }

  neopixel_show();
  update_edge_led();
}
