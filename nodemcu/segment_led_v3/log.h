#ifndef LOG_H
#define LOG_H

#include <Arduino.h>

// ===== 로그 설정 =====
#define ENABLE_LOG 1        // 0: OFF, 1: ON
#define LOG_LEVEL_INFO  1
#define LOG_LEVEL_WARN  1
#define LOG_LEVEL_ERROR 1

// ===== 로그 매크로 =====
#if ENABLE_LOG

  #if LOG_LEVEL_INFO
    #define LOG_I(tag, msg) \
      Serial.println(String("[INFO] ") + tag + " : " + msg)
  #else
    #define LOG_I(tag, msg)
  #endif

  #if LOG_LEVEL_WARN
    #define LOG_W(tag, msg) \
      Serial.println(String("[WARN] ") + tag + " : " + msg)
  #else
    #define LOG_W(tag, msg)
  #endif

  #if LOG_LEVEL_ERROR
    #define LOG_E(tag, msg) \
      Serial.println(String("[ERROR] ") + tag + " : " + msg)
  #else
    #define LOG_E(tag, msg)
  #endif

#else
  #define LOG_I(tag, msg)
  #define LOG_W(tag, msg)
  #define LOG_E(tag, msg)
#endif

#endif