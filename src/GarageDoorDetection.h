#ifndef GARAGE_DOOR_DETECTION_h
#define GARAGE_DOOR_DETECTION_h

#include <Arduino.h>
#include <KStandardCore.h>
#include <Ultrasonic.h>

class GarageDoorDetection
{

public:
    GarageDoorDetection(KStandardCore *kStandardCore);
    ~GarageDoorDetection();
    void setup();
    void loop();

private:
    KStandardCore *kStandardCore;
    Ultrasonic ultrasonic;
    void clc_60s();
};

#endif