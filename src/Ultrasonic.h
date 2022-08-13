#ifndef ULTRASONIC_H
#define ULTRASONIC_H

class Ultrasonic
{
    
    private:
    unsigned char trigger;
    unsigned char echo;
    
    
    public:
    Ultrasonic();
    Ultrasonic(unsigned char trigger, unsigned char echo);
    ~Ultrasonic();

    void setup();
    void setup(unsigned char trigger, unsigned char echo);

    unsigned long measure();

};

#endif