/*
 * FLOOD DETECTOR SENSOR

Author: Danny van den Brande, Arduinosensors.nl. BlueCore Tech.
This code is very simple and made for a flood alarm, can be used anywhere to detect water.
it simply reads a boolean value of 1 or 0. You cannot use this code for Water level monitoring. I would not used this sensor anyway
for water level measuring unless it was gold coated, but they are great to use as a alarm. I do not sell them on my website because they wont last long.
I tested it in a glass of water and the metal disapears. I just made this example so people can actually use this pretty bad sensor.
I will order some gold coated ones which are new on the market from a new supplier who has delivered me only good stuff recently, i will test them and see if they are 
qood quality and useful for long term water level measuring without breaking apart within a few days.

Telegram bot tutorial: https://randomnerdtutorials.com/telegram-esp32-motion-detection-arduino/

 */

#include <WiFi.h>
#include <WiFiClientSecure.h>
#include <UniversalTelegramBot.h>
#include <ArduinoJson.h>

// Network credentials
const char* ssid = "YOUR_WIFI_SSID";
const char* password = "YOUR_WIFI_PASSWORD!";

// Initialize Telegram BOT
#define BOTtoken "YOUR_TELEGRAM_BOT_TOKEN"
#define CHAT_ID "YOUR_TELEGRAM_CHAT_ID"

WiFiClientSecure client;
UniversalTelegramBot bot(BOTtoken, client);


int waterSensorPin = 2;

boolean waterDetected = false; //simply reads 1 or 0 as a value 1 when detecting water

void IRAM_ATTR detectsWater() {
  waterDetected = true;
}

void setup() {
    // Set water sensor pin as interrupt, assign interrupt function and set RISING mode
    Serial.begin(9600);
    pinMode(waterSensorPin, INPUT_PULLUP);
    attachInterrupt(digitalPinToInterrupt(waterSensorPin), detectsWater, RISING);

    // Attempt to connect to Wifi network:
    Serial.print("Connecting Wifi: ");
    Serial.println(ssid);
    WiFi.mode(WIFI_STA);
    WiFi.begin(ssid, password);
    while (WiFi.status() != WL_CONNECTED) {
      Serial.print(".");
      delay(500);
    }
    Serial.println("");
    Serial.println("WiFi connected");
    Serial.print("IP address: ");
    Serial.println(WiFi.localIP());

    bot.sendMessage(CHAT_ID, "Bot started up", "");
    Serial.println("Bot started up!");
}

void loop() {
    if (waterDetected)
    {
    Serial.println("Water detected!");
    bot.sendMessage(CHAT_ID, "Water detected in your basement!", "");
    waterDetected = false;
    }
    else
    {
    Serial.println("No water detected");    
    }
    delay(500);
}
