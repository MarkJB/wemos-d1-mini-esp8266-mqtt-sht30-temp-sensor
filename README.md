# Wemos-D1 mini ESP8266 WiFi MQTT SHT30 temperature and humidity sensor
Arduino firmware for the **Wemos D1 Mini** (ESP8266) and the **SHT30** temperature and humidity sensor shield

Uses:

The **Wemos D1 mini ESP8266** dev board: https://wiki.wemos.cc/products:d1:d1_mini

The **SHT30 sheild**: https://wiki.wemos.cc/products:d1_mini_shields:sht30_shield

An mqtt server

A backend to make use of the mqtt temperature and humidity messages.

Messages have the following format:

`{"location":"lounge","temperature":23.25628,"humditiy":57.82254}
{"location":"office","temperature":24.01465,"humditiy":56.94514}`

Location and WiFi login details are all set in firmware and uploaded to each node.

## To compile the Arduino code, you will need to install the following boards and libraries:

### Board

Add the following to 'Preferences -> Additional Boards Manager URLs'
`https://arduino.esp8266.com/stable/package_esp8266com_index.json`

Then in **'Tools -> Board -> Boards Manager'** install the **esp8266 'ESP8266 Community'** boards package (tested with v3.0.2)

### Libraries

**PubSubClient** by Nick O'Leary (Tested with v2.8.0)
**ArduinoJson** by Benoit Blanchon (Tested with v6.19.4)
**WEMOS_SHT3X** by wemos https://github.com/wemos/WEMOS_SHT3x_Arduino_Library
