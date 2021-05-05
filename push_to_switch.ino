#include <Keyboard.h>

const int buttonPin = 3;  // the number of the pushbutton pin
const int ledPin = 2;  // the number of the LED pin
int buttonVal = 0;
int scene = 0;

void setup() {
  // put your setup codne here, to run once:
  pinMode(buttonPin, INPUT_PULLUP);
  pinMode(ledPin, OUTPUT);
  
  Keyboard.begin();
}

void loop() {
  // put your main code here, to run repeatedly:
  buttonVal = digitalRead(buttonPin);
  if (buttonVal == 0) {
    digitalWrite(ledPin, HIGH);
    delay(250);
   
    if (scene == 0) {
      Keyboard.press(KEY_LEFT_ALT);
      Keyboard.press(KEY_F2);
      delay(250);
      Keyboard.releaseAll();
      delay(150);
    }
    else {
      Keyboard.press(KEY_LEFT_ALT);
      Keyboard.press(KEY_F1);
      delay(250);
      Keyboard.releaseAll();
      delay(150);
    }

    scene = !scene;
    
  }
  else
    digitalWrite(ledPin, LOW);
}
