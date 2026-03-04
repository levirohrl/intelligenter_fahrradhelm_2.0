/*
 * This ESP32 code is created by esp32io.com
 *
 * This ESP32 code is released in the public domain
 *
 * For more detail (instruction and wiring diagram), visit https://esp32io.com/tutorials/esp32-ws2812b-led-strip
 */

#include <Adafruit_NeoPixel.h>



#include "ESP32_NOW_Serial.h"
#include "MacAddress.h"
#include "WiFi.h"
#include "esp_wifi.h"

#define ESPNOW_WIFI_CHANNEL 1

#define LED_PIN 9
#define MOTOR_PIN1 4
#define MOTOR_PIN2 5
#define MOTOR_PIN3 6
#define MOTOR_PIN4 7

#define PIN_WS2812B 16  // The ESP32 pin GPIO16 connected to WS2812B
#define NUM_PIXELS 144   // The number of LEDs (pixels) on WS2812B LED strip


Adafruit_NeoPixel ws2812b(NUM_PIXELS, PIN_WS2812B, NEO_GRB + NEO_KHZ800);

const MacAddress peer_mac({0xA0, 0xDD, 0x6C, 0x9B, 0x42, 0x30});

ESP_NOW_Serial_Class NowSerial(peer_mac, ESPNOW_WIFI_CHANNEL, WIFI_IF_STA);

struct statusData {
  bool back_light;
  bool led_on;
  float pwm_motor;
};

statusData currentStatus = { false, false, 0.0 };

void setup() {
    Serial.begin(115200);
    WiFi.mode(WIFI_STA);
    WiFi.setChannel(ESPNOW_WIFI_CHANNEL, WIFI_SECOND_CHAN_NONE);

    while (!(WiFi.STA.started())) {
        delay(100);
    }
    NowSerial.begin(115200);
    
    ws2812b.begin();  // initialize WS2812B strip object (REQUIRED)
}


void notfall() {

  ws2812b.setBrightness(255); // a value from 0 to 255

    ws2812b.setPixelColor(1, ws2812b.Color(255, 0, 0));  // it only takes effect if pixels.show() is called
    //ws2812b.show();                                          // update to the WS2812B Led Strip
    ws2812b.setPixelColor(2, ws2812b.Color(255, 0, 0));  // it only takes effect if pixels.show() is called
    //ws2812b.show();                                          // update to the WS2812B Led Strip
    ws2812b.setPixelColor(3, ws2812b.Color(255, 0, 0));  // it only takes effect if pixels.show() is called
    //ws2812b.show();                                          // update to the WS2812B Led Strip
    ws2812b.setPixelColor(4, ws2812b.Color(255, 0, 0));  // it only takes effect if pixels.show() is called
    //ws2812b.show();                                          // update to the WS2812B Led Strip
    ws2812b.setPixelColor(5, ws2812b.Color(255, 0, 0));  // it only takes effect if pixels.show() is called
    //ws2812b.show();                                          // update to the WS2812B Led Strip
    ws2812b.setPixelColor(6, ws2812b.Color(255, 0, 0));  // it only takes effect if pixels.show() is called
    //ws2812b.show();                                          // update to the WS2812B Led Strip
    ws2812b.setPixelColor(7, ws2812b.Color(255, 0, 0));  // it only takes effect if pixels.show() is called
    //ws2812b.show();                                          // update to the WS2812B Led Strip
    ws2812b.setPixelColor(8, ws2812b.Color(255, 0, 0));  // it only takes effect if pixels.show() is called
    //ws2812b.show();                                          // update to the WS2812B Led Strip
    ws2812b.setPixelColor(9, ws2812b.Color(255, 0, 0));  // it only takes effect if pixels.show() is called
    //ws2812b.show();                                          // update to the WS2812B Led Strip
    ws2812b.setPixelColor(10, ws2812b.Color(255, 0, 0));  // it only takes effect if pixels.show() is called
    //ws2812b.show();                                          // update to the WS2812B Led Strip
    ws2812b.setPixelColor(11, ws2812b.Color(255, 0, 0));  // it only takes effect if pixels.show() is called
    //ws2812b.show();                                          // update to the WS2812B Led Strip
    ws2812b.setPixelColor(12, ws2812b.Color(255, 0, 0));  // it only takes effect if pixels.show() is called
    //ws2812b.show();                                          // update to the WS2812B Led Strip
    ws2812b.setPixelColor(13, ws2812b.Color(255, 0, 0));  // it only takes effect if pixels.show() is called
    //ws2812b.show();                                          // update to the WS2812B Led Strip
    ws2812b.setPixelColor(14, ws2812b.Color(255, 0, 0));  // it only takes effect if pixels.show() is called
    //ws2812b.show();                                          // update to the WS2812B Led Strip
    ws2812b.setPixelColor(15, ws2812b.Color(255, 0, 0));  // it only takes effect if pixels.show() is called
    //ws2812b.show();                                          // update to the WS2812B Led Strip
    ws2812b.setPixelColor(16, ws2812b.Color(255, 0, 0));  // it only takes effect if pixels.show() is called
    //ws2812b.show();                                          // update to the WS2812B Led Strip
    ws2812b.setPixelColor(17, ws2812b.Color(255, 0, 0));  // it only takes effect if pixels.show() is called
    //ws2812b.show();                                          // update to the WS2812B Led Strip
    ws2812b.setPixelColor(18, ws2812b.Color(255, 0, 0));  // it only takes effect if pixels.show() is called
    //ws2812b.show();                                          // update to the WS2812B Led Strip
    ws2812b.setPixelColor(19, ws2812b.Color(255, 0, 0));  // it only takes effect if pixels.show() is called
    //ws2812b.show();                                          // update to the WS2812B Led Strip
    ws2812b.setPixelColor(20, ws2812b.Color(255, 0, 0));  // it only takes effect if pixels.show() is called
    ws2812b.setPixelColor(21, ws2812b.Color(255, 0, 0));  // it only takes effect if pixels.show() is called
    //ws2812b.show();                                          // update to the WS2812B Led Strip
    ws2812b.setPixelColor(22, ws2812b.Color(255, 0, 0));  // it only takes effect if pixels.show() is called
    //ws2812b.show();                                          // update to the WS2812B Led Strip
    ws2812b.setPixelColor(23, ws2812b.Color(255, 0, 0));  // it only takes effect if pixels.show() is called
    //ws2812b.show();                                          // update to the WS2812B Led Strip
    ws2812b.setPixelColor(24, ws2812b.Color(255, 0, 0));  // it only takes effect if pixels.show() is called
    //ws2812b.show();                                          // update to the WS2812B Led Strip
    ws2812b.setPixelColor(25, ws2812b.Color(255, 0, 0));  // it only takes effect if pixels.show() is called
    //ws2812b.show();                                          // update to the WS2812B Led Strip
    ws2812b.setPixelColor(26, ws2812b.Color(255, 0, 0));  // it only takes effect if pixels.show() is called
    //ws2812b.show();                                          // update to the WS2812B Led Strip
    ws2812b.setPixelColor(27, ws2812b.Color(255, 0, 0));  // it only takes effect if pixels.show() is called
    //ws2812b.show();                                          // update to the WS2812B Led Strip
    ws2812b.show();                                          // update to the WS2812B Led Strip
    
  delay(200);
  ws2812b.clear();  // set all pixel colors to 'off'. It only takes effect if pixels.show() is called
  ws2812b.show();
  delay(200);
}


void loop() {
    if (NowSerial.available()) {
        NowSerial.readBytes((byte*)&currentStatus, sizeof(currentStatus));
        if (currentStatus.back_light) {
            Serial.println("Rücklicht ist an.\n");
        } else {
            Serial.println("Rücklicht ist aus.\n");
        }

        if (currentStatus.led_on) {
            Serial.println("LED ist an.\n");
            analogWrite(LED_PIN, 255);
        }
        else {
            Serial.println("LED ist aus.\n");
            analogWrite(LED_PIN, 0);
            NowSerial.println("Thank you!");
        }

        if (currentStatus.back_light) {
            Serial.println("LED-Streifen ist an.\n");
            notfall();
        } else {
            Serial.println("LED-Streifen ist aus.\n");
            ws2812b.setPixelColor(27, ws2812b.Color(0, 0, 0));  // it only takes effect if pixels.show() is called
            ws2812b.show();                                          // update to the WS2812B Led Strip
            ws2812b.clear();  // set all pixel colors to 'off'. It only takes effect if pixels.show() is called
        }

        if (currentStatus.pwm_motor >= 0.0) {
            float pwm_value = int(currentStatus.pwm_motor);
            Serial.println(pwm_value);
            analogWrite(MOTOR_PIN1, int(pwm_value));
            analogWrite(MOTOR_PIN2, int(pwm_value));
            analogWrite(MOTOR_PIN3, int(pwm_value));
            analogWrite(MOTOR_PIN4, int(pwm_value));
        }
    }
    delay(1);
}