#include "Arduino.h"

class Button
{
private:
    int _pin;
    int _mode;
    int status;
    unsigned long startClickTime;
    bool longClickDone;

public:
    //one time events
    static const int CLICK = 0;
    static const int UP = 1;
    static const int CLICK_CONFIRMED = 2;
    static const int LONG_CLICK = 3;
    static const int DOUBLE_CLICK = 4;

    //multiple times events
    static const int PRESSED = 5;
    static const int RELEASED = 6;
    static const int LONG_PRESSED = 7;
    static const int DOUBLE_PRESSED = 8;

    Button();
    Button(int pin, int mode);
    ~Button();
    void setup(int led, int mode);
    int getStatus();
    int getPin();
};
