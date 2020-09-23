# FloodDetection
Do you also want to know when your basement or some other place is being flooded? Follow the steps in this simple project to get a message on your phone or pc from the moment the water enters the room!

## Requirements
* ESP32 (I used a ESP-WROOM-32, but any ESP32 with Wi-Fi will work!)
* Arduino IDE
* Water sensor (I bought a [45-in-1 sensor pack from AliExpress](https://nl.aliexpress.com/item/4000238240904.html?spm=a2g0o.productlist.0.0.a6ac6ad8Ft0rnA&algo_pvid=ebc0b29b-06fd-4a20-b50e-c5b1e13eef4c&algo_expid=ebc0b29b-06fd-4a20-b50e-c5b1e13eef4c-1&btsid=0bb0623615990671693976493ec567&ws_ab_test=searchweb0_0,searchweb201602_,searchweb201603_))
* Some jumper cables and/or wires

## Procedure
1. Connect the water sensor pins to the pins of the ESP32:
    * Connect GND to GND
    * Connect V+ to 3.3V or 5V
    * Connect the sensor pin to any available pin on the ESP32
2. Setup a Telegram bot (follow the steps on https://randomnerdtutorials.com/telegram-esp32-motion-detection-arduino/)
3. Upload the [sketch from this repo](esp32-flood_sensor.ino) to the ESP32 using the Arduino IDE. Input your Wi-Fi credentials and the Telegram token.

DONE!

Demo:
![Flood detector demo](flood_detector_demo.gif)
