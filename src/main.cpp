#include <Arduino.h>
#include <KStandardCore.h>
#include "incredential.h"
#include <GarageDoorDetection.h>

// https://randomnerdtutorials.com/esp8266-pinout-reference-gpios/

KStandardCore kStandardCore;

GarageDoorDetection garageDoorDetection(&kStandardCore);

void setup()
{
  Serial.begin(9600); // Baudrate: 9600

  kStandardCore.setup("Garagentor", SSID, PSK, MQTT_BROKER, 1883);

  garageDoorDetection.setup();
  Serial.print("Ultrasonic Setup done\n");
}

void loop()
{

  kStandardCore.loop();
  garageDoorDetection.loop();
  delay(100);
}
