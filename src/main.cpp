#include <Arduino.h>
#include <KStandardCore.h>
#include "incredential.h"
#include <GarageDoorDetection.h>
#include <KBlink.h>

// https://randomnerdtutorials.com/esp8266-pinout-reference-gpios/

KStandardCore kStandardCore;
KBlink kblink;

GarageDoorDetection garageDoorDetection(&kStandardCore);

void setup()
{
  Serial.begin(9600); // Baudrate: 9600

  kStandardCore.setup("Garagentor", SSID, PSK, MQTT_BROKER, 1883);

  garageDoorDetection.setup();
  Serial.print("Ultrasonic Setup done\n");

  kblink.setup(kStandardCore.getKSchedule(), 100, 3000);
}

void loop()
{

  kStandardCore.loop();
  garageDoorDetection.loop();
  kblink.loop();
}
