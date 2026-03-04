//This example code is in the Public Domain (or CC0 licensed, at your option.)
//By Evandro Copercini - 2018
//
//This example creates a bridge between Serial and Classical Bluetooth (SPP)
//and also demonstrate that SerialBT have the same functionalities of a normal Serial

#include "ESP32_NOW_Serial.h"
#include "MacAddress.h"
#include "WiFi.h"
#include "esp_wifi.h"

#include "BluetoothSerial.h"

#define ESPNOW_WIFI_CHANNEL 1
#define SEND_PERIOD 4000


#if !defined(CONFIG_BT_ENABLED) || !defined(CONFIG_BLUEDROID_ENABLED)
#error Bluetooth is not enabled! Please run `make menuconfig` to and enable it
#endif

BluetoothSerial SerialBT;

const MacAddress peer_mac({0xFC, 0x01, 0x2C, 0xCA, 0x99, 0xA8});

ESP_NOW_Serial_Class NowSerial(peer_mac, ESPNOW_WIFI_CHANNEL, WIFI_IF_STA);

struct statusData {
  bool back_light;
  bool led_on;
};

statusData currentStatus = { false, false };

void setup() {
    Serial.begin(115200);
    WiFi.mode(WIFI_STA);
    WiFi.setChannel(ESPNOW_WIFI_CHANNEL, WIFI_SECOND_CHAN_NONE);

    while (!(WiFi.STA.started())) {
        delay(100);
    }
    NowSerial.begin(115200);
  SerialBT.begin("ESP32test"); //Bluetooth device name
  Serial.println("The device started, now you can pair it with bluetooth!");
}

void loop() {
    static unsigned long lastSent = 0;
    
    if (millis() - lastSent > SEND_PERIOD) {
        int success = NowSerial.write((byte*)&currentStatus, sizeof(currentStatus));
        if (success) {
            Serial.println("Message sent"); 
        }
        else {
            Serial.println("Connection issue - rebooting in 3 seconds");
            delay(3000);
            ESP.restart();
        }
        lastSent = millis();        
    }
    
//String wird in Variable 'received' gespeichert.
  if (SerialBT.available()) {
    String received = SerialBT.readStringUntil('\n');
    received.trim(); // Remove whitespace and newline

  if (received == "led_on") {
    SerialBT.println("Received: led_on");
    Serial.println("LED ist an.");
    currentStatus.led_on = true;
  } else if (received == "led_off") {
    SerialBT.println("Received: led_off");
    Serial.println("LED ist aus.");
    currentStatus.led_on = false;
  } else if (received == "strip_on") {
    SerialBT.println("Received: strip_on");
    Serial.println("LED-Streifen ist an.");
    currentStatus.back_light = true;
  } else if (received == "strip_off") {
    SerialBT.println("Received: strip_off");
    Serial.println("LED-Streifen ist aus.");
    currentStatus.back_light = false;
  }

}








    if (NowSerial.available()) {
        String messageIn = NowSerial.readStringUntil('\n');
        Serial.print("Receiver feedback: ");
        Serial.println(messageIn);
        Serial.println();
    }

    delay(1);
}