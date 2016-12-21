#include "Arduino.h"
#include "Button.h"

static const int INTERNAL_STATUS_FINAL_UP = 0;
static const int INTERNAL_STATUS_DOWN_1 = 1;
static const int INTERNAL_STATUS_PRE_UP = 2;
static const int INTERNAL_STATUS_DOWN_2 = 3;
static const int INTERNAL_STATUS_LONG_DOWN = 4;


Button::Button()
{
  status = INTERNAL_STATUS_FINAL_UP;
}

Button::Button(int pin, int mode)
{
  status = INTERNAL_STATUS_FINAL_UP;
  setup(pin, mode);
}

Button::~Button()
{
}

void Button::setup(int pin, int mode){
  pinMode(pin, INPUT);
  _pin = pin;
  _mode = mode;
}


int Button::getStatus()
{
  int result;
  int prevStatus = status;
  unsigned long nowTime = millis();
  bool buttonStatus = digitalRead(_pin) == _mode;
  bool inTime = nowTime < startClickTime + 500 ;
  

  switch(status){
    case INTERNAL_STATUS_FINAL_UP:
        if(buttonStatus){
            //Click
            status = INTERNAL_STATUS_DOWN_1;
            startClickTime = nowTime;
            result = Button::CLICK; 
        } else {
            status = INTERNAL_STATUS_FINAL_UP;
            startClickTime = nowTime;
            result = Button::RELEASED;
        }
        break;

    case INTERNAL_STATUS_DOWN_1:
        if(buttonStatus){
            if(inTime){
                status = INTERNAL_STATUS_DOWN_1;
                result = Button::PRESSED;
            } else {
                status = INTERNAL_STATUS_LONG_DOWN;
                result = Button::LONG_CLICK;
            }
        } else {
            //Released
            status = INTERNAL_STATUS_PRE_UP;
            result = Button::UP; 
        }
        break;

    case INTERNAL_STATUS_PRE_UP:
        if(buttonStatus){
            status = INTERNAL_STATUS_DOWN_2;
            result = Button::DOUBLE_CLICK;
        } else {
            if(inTime){
                status = INTERNAL_STATUS_PRE_UP;
                result = Button::RELEASED;
            } else {
                status = INTERNAL_STATUS_FINAL_UP;
                result = Button::CLICK_CONFIRMED; 
            }
        }
        break;

    case INTERNAL_STATUS_DOWN_2:
        if(buttonStatus){
            status = INTERNAL_STATUS_DOWN_2;
            result = Button::DOUBLE_PRESSED;
        } else {
            status = INTERNAL_STATUS_FINAL_UP;
            result = Button::UP;
        }
        break;

    case INTERNAL_STATUS_LONG_DOWN:
        if(buttonStatus){
            status = INTERNAL_STATUS_LONG_DOWN;
            result = Button::LONG_PRESSED;
        } else {
            status = INTERNAL_STATUS_FINAL_UP;
            result = Button::UP;
        }
        break;

    }

    return result;
}


int Button::getPin()
{
  return _pin;
}
