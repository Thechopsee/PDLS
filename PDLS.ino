#include <Keyboard.h>
#include <Joystick.h>

Joystick_ Joystick(JOYSTICK_DEFAULT_REPORT_ID, JOYSTICK_TYPE_JOYSTICK,
0, 0, // Button Count, Hat Switch Count
false, false, false, // X and Y, but no Z Axis
false, false, false, // No Rx, Ry, or Rz
false, false, // No rudder or throttle
false, false, true); // No accelerator, brake, or steering;

#define THROTTLEBTN 4
#define BRAKEBTN 5

void setup() {
  Keyboard.begin();
  Joystick.begin();
  Serial.begin(9600);
  //Joystick.setXAxisRange(0, 1023);
  pinMode(THROTTLEBTN, INPUT_PULLUP);
  pinMode(BRAKEBTN, INPUT_PULLUP);
  pinMode(A0,INPUT);
  
}
bool rdt=false;
bool rdb=false;
void loop() {
  byte buttonState = digitalRead(THROTTLEBTN);
  
  int steValue=analogRead(A0);
  //steValue=map(steValue,0,1023,0,255);
  //popř Joystick.setSteering(steValue/4);
  Serial.println(steValue);
  Joystick.setSteering(steValue);

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
