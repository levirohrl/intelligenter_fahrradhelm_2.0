//ESP32-S3
#include "ESP32_NOW_Serial.h"
#include "MacAddress.h"
#include "WiFi.h"
#include "esp_wifi.h"

#define ESPNOW_WIFI_CHANNEL 1

const MacAddress peer_mac({0xA0, 0xDD, 0x6C, 0x9B, 0x42, 0x30});

ESP_NOW_Serial_Class NowSerial(peer_mac, ESPNOW_WIFI_CHANNEL, WIFI_IF_STA);

struct statusData {
  bool flashlight;
};

statusData currentStatus = {false};

int LED_PIN = 7;

void setup() {
    Serial.begin(115200);
    WiFi.mode(WIFI_STA);
    WiFi.setChannel(ESPNOW_WIFI_CHANNEL, WIFI_SECOND_CHAN_NONE);

    while (!(WiFi.STA.started())) {
        delay(100);
    }
    NowSerial.begin(115200);

    pinMode(LED_PIN, OUTPUT);
}

void loop() {
    if (NowSerial.available()) {
        NowSerial.readBytes((byte*)&currentStatus, sizeof(currentStatus));
        //Serial.print("Humidity [%]    : ");
        //Serial.println(currentStatus.humidity);
        if (currentStatus.flashlight) {
            Serial.println("Die Taschenlampe ist an.\n");
            digitalWrite(LED_PIN, HIGH);
        }
        else {
            Serial.println("Die Taschenlampe ist aus.\n");
            NowSerial.println("Thank you!");
            digitalWrite(LED_PIN, LOW);
        }
    }
    delay(1);
}