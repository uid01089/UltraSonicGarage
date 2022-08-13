#include "Ultrasonic.h"
#include "Arduino.h"

Ultrasonic::Ultrasonic()
{
    //
}

Ultrasonic::Ultrasonic(unsigned char trigger, unsigned char echo)
{
    this->echo = echo;
    this->trigger = trigger;
}

Ultrasonic::~Ultrasonic()
{
}

void Ultrasonic::setup()
{
    pinMode(trigger, OUTPUT);
    // Serial.print("setup: " + String(trigger) + "to output\n");
    pinMode(echo, INPUT);
    // Serial.print("setup: " + String(echo) + "to input\n");
}

void Ultrasonic::setup(unsigned char trigger, unsigned char echo)
{
    this->echo = echo;
    this->trigger = trigger;

    setup();
}

unsigned long Ultrasonic::measure()
{
    // Serial.print("measure: " + String(trigger) + "trigger\n");
    // Serial.print("measure: " + String(echo) + "echo\n");

    unsigned long duration;     // vom Sensor gemessene Dauer
    unsigned long distance = 0; // aus Dauer errechnete Entfernung

    // Sensor wird von HIGH Puls ausgelöst, der länger als 10 Microsekunden dauert
    // vorher ein kurzer LOW Puls, für sauberen HIGH Puls
    digitalWrite(trigger, LOW);
    delayMicroseconds(2);
    digitalWrite(trigger, HIGH);
    delayMicroseconds(10);
    digitalWrite(trigger, LOW);

    // Signal vom Sensor einlesen:
    // duration = Zeit in Mikrosekunden für Senden eines Pings
    // bis zum Empfangen des Echos von einem Objekt
    duration = pulseIn(echo, HIGH, 100000UL);

    // Formel: distance = 1/2 * duration / Schallgeschwindigkeit
    // Schallgeschwindigkeit ca 323m/s
    // durch 2, da duration die Zeit für hin und zurück ist
    distance = duration * 0.034 / 2;

    return distance;
}