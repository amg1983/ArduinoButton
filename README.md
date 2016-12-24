# ArduinoButton

This library helps you to detect the most common events in buttons.

## How to use


```c++
#include <Button.h>

// Configure pin number and mode (can be LOW or HIGH, It means the value of the pin when the button is pressed)
Button buttonA(1, HIGH);

void setup() {
}

void loop() {
  // Read the status of the button ONLY one time inside the loop() method
  int result = buttonA.getStatus();

  switch (result) {
    case Button::CLICK_CONFIRMED:
      Serial.write("CLICK_CONFIRMED\n");
      break;
    case Button::LONG_CLICK:
      Serial.write("LONG_CLICK\n");
      break;
    case Button::DOUBLE_CLICK:
      Serial.write("DOUBLE_CLICK\n");
      break;
  }
  ```

## Diagram

![](button_diagram_w.png?raw=true)
### Single time events
###### 1. CLICK
Triggered when the button is clicked.
You shouldn't use CLICK if you want to detect also double or long clicks. In that case you should wait for CLICK_CONFIRMED
###### 2. DOUBLE_CLICK
The button was double clicked. To trigger this event, the maximum interval between clicks has to be less than 500ms.
###### 3. LONG_CLICK
The button is pressed for 500ms
###### 4. CLICK_CONFIRMED
Triggered if 500ms after a CLICK event no DOUBLE_CLICK or LONG_CLICK events are detected
### Single time events
###### 1. RELEASED
The button is not pressed.
###### 2. PRESSED
After the CLICK status, while the button is still pressed.
###### 3. DOUBLE_PRESSED
After the DOUBLE_CLICK event, while the button is still pressed.
###### 4. LONG_PRESSED
After the LONG_CLICK event, while the button is still pressed.
