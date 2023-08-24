#include <Keyboard.h>

#define THROTTLEBTN 4
#define BRAKEBTN 5

void setup() {
  Keyboard.begin();
  pinMode(THROTTLEBTN, INPUT_PULLUP);
  pinMode(BRAKEBTN, INPUT_PULLUP);
  
}
bool rdt=false;
bool rdb=false;
void loop() {
  byte buttonState = digitalRead(THROTTLEBTN);
  
  if (buttonState == LOW) {
      Keyboard.press('w');
      rdt=true;
  }
  else
  {
    if(rdt)
    {
      rdt=false;
      Keyboard.release('w');
    }
  }
  
  byte buttonStateBrk = digitalRead(BRAKEBTN);
  if (buttonStateBrk == LOW) {
      Keyboard.press('s');
      rdb=true;
  }
  else
  {
    if(rdb)
    {
      rdb=false;
      Keyboard.release('s');
    }
  }
  
  delay(50);
}
