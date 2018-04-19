# Wemos-D1 mini ESP8266 WiFi MQTT SHT30 temperature and humidity sensor
Arduino firmware for the Wemos D1 Mini (ESP8266) and the SHT30 temperature and humidity sensor shield

Uses:

The Wemos D1 mini ESP8266 dev board: https://wiki.wemos.cc/products:d1:d1_mini

The SHT30 sheild: https://wiki.wemos.cc/products:d1_mini_shields:sht30_shield

An mqtt server

A backend to make use of the mqtt temperature and humidity messages.

Messages have the following format:

{"location":"lounge","temperature":23.25628,"humditiy":57.82254}
{"location":"office","temperature":24.01465,"humditiy":56.94514}

Location and WiFi login details are all set in firmware and uploaded to each node.
