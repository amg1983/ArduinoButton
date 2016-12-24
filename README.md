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
```
CLICK, DOUBLE_CLICK, LONG_CLICK and CLICK_CONFIRMED
```
You shouldn't use CLICK if you want to detect double clicks or long clicks. In that case, use CLICK_CONFIRMED
### Single time events
```
PRESSED, RELEASED, LONG_PRESSED and DOUBLE_PRESSED
```
