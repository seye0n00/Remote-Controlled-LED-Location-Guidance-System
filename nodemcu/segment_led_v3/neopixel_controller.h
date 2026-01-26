#ifndef NEOPIXEL_CONTROLLER
#define NEOPIXEL_CONTROLLER

#include <SPI.h>

/* ===== Configuration ===== */
#define NUM_LED     4
#define NUM_SEGMENT 4

#define RESET_PULSE 16   // 50us reset
#define MOSI_PIN    D7

// WS2812B GRB order
#define GRB_GREEN   0
#define GRB_RED     1
#define GRB_BLUE    2

/* ===== Data Structures ===== */
typedef struct {
  uint16_t start;
  uint16_t len;
} Segment;

/* ===== Extern Variables ===== */
extern Segment col[NUM_SEGMENT];

/* ===== API ===== */
void set_led(uint8_t idx, uint8_t r, uint8_t g, uint8_t b);
void neopixel_init();
void neopixel_clear();
void neopixel_segments_init();
void neopixel_set_segment(uint8_t idx, uint8_t r, uint8_t g, uint8_t b);
void neopixel_show();

#endif