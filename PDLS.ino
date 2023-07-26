#include <Keyboard.h>




#define THROTTLEBTN 4
#define BRAKEBTN 5

void setup() {
  Serial.begin(9600);
  pinMode(THROTTLEBTN, INPUT_PULLUP);
  pinMode(BRAKEBTN, INPUT_PULLUP);
  Keyboard.begin();

}

void loop() {
  // put your main code here, to run repeatedly:
  byte buttonState = digitalRead(THROTTLEBTN);
  
  if (buttonState == LOW) {
      Serial.println("THR Button is pressed");
      Keyboard.write('w');
  }
  else {
      Serial.println("THR Button is not pressed");
  }
  byte buttonStateBrk = digitalRead(BRAKEBTN);
  if (buttonStateBrk == LOW) {
      Serial.println("BRK Button is pressed");
      Keyboard.write('s');
  }
  else {
      Serial.println("BRK Button is not pressed");
  }
  Serial.println(digitalRead(BRAKEBTN));
  delay(100);
}
