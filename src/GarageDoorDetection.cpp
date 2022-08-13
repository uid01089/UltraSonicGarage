#include <GarageDoorDetection.h>
#include <ESP8266WiFi.h>

#define TRIGGER D2
#define ECHO D1

GarageDoorDetection::GarageDoorDetection(KStandardCore *kStandardCore)
{
    this->kStandardCore = kStandardCore;
}

GarageDoorDetection::~GarageDoorDetection()
{
}

void GarageDoorDetection::setup()
{
    ultrasonic.setup(TRIGGER, ECHO);
    clc_60s();
}

void GarageDoorDetection::loop()
{
    kStandardCore->getKMqtt()->loop();
}

void GarageDoorDetection::clc_60s()
{
    unsigned long distance = ultrasonic.measure();
    kStandardCore->getKMqtt()->publish("/" + kStandardCore->getHostname() + "/torsensor/distance", String(distance).c_str());
    Serial.print("distance: " + String(distance) + "\n");
    // Serial.println(kStandardCore->getHostname() + "/torsensor/distance");

    kStandardCore->getNTPClient()->update();

    kStandardCore->getKMqtt()->publish("/" + kStandardCore->getHostname() + "/torsensor/time", kStandardCore->getNTPClient()->getFormattedTime().c_str());
    Serial.print("time: " + kStandardCore->getNTPClient()->getFormattedTime() + "\n");

    // Reschedule it again

    // Reschedule it again
    kStandardCore->getKSchedule()->schedule(std::bind(&GarageDoorDetection::clc_60s, this), 1000 * 60);
}