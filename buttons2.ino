#include <Keyboard.h>

const int  BbtnPin1 = 4;
const int  BbtnPin2 = 5;
const int  BbtnPin3 = 7;
const int  SbtnPin1 = 9;
const int  SbtnPin2 = 6;
const int  SbtnPin3 = 10;
const int  HbtnPin = 3;

const int  ledPin1 = 2;
const int  ledPin2 = 11;

//const int  ScreenbtnPin = 13;

int btnState = 0;
int lastState = 0;
const int btnPin = 13;

const int  togglePin1 = 12;
const int  togglePin2 = 8;
const int  resetPin = A0;

int BbtnState1 = 0;
int BlastbtnState1 = 0;

int BbtnState2 = 0;
int BlastbtnState2 = 0;

int BbtnState3 = 0;
int BlastbtnState3 = 0;

int SbtnState1 = 0;
int SlastbtnState1 = 0;

int SbtnState2 = 0;
int SlastbtnState2 = 0;

int SbtnState3 = 0;
int SlastbtnState3 = 0;

int toggleState1 = 0;
int lasttoggleState1 = 0;

int toggleState2 = 0;
int lasttoggleState2 = 0;

int HbtnState = 0;
int HlastbtnState = 0;

int ScreenbtnState = 0;
int ScreenlastbtnState = 0;

int PbtnState = 0;
int PlastbtnState = 0;

int sensorValue = 0;
int lastsensorValue;

boolean wasTouched = false;
boolean videoPlay = false;

long lastDebounceTime = 0;
long debounceDelay = 50;
int ledState = HIGH;
int buttonState;
int lastButtonState = LOW;


void setup() {
  // initialize the button pin as a input:
  pinMode(BbtnPin1, INPUT);
  pinMode(BbtnPin2, INPUT);
  pinMode(BbtnPin3, INPUT);
  pinMode(SbtnPin1, INPUT);
  pinMode(SbtnPin2, INPUT);
  pinMode(SbtnPin3, INPUT);
  pinMode(togglePin1, INPUT);
  pinMode(togglePin2, INPUT);
  pinMode(resetPin, INPUT);
  pinMode(HbtnPin, INPUT);

  pinMode(ledPin1, OUTPUT);
  pinMode(ledPin2, OUTPUT);

  //  pinMode(ScreenbtnPin, INPUT);
  //  pinMode(PbtnPin, INPUT);
  //   initialize serial communication:
  Serial.begin(9600);

  pinMode(btnPin, INPUT_PULLUP);
  Serial.begin(9600);
  Keyboard.begin();

}

void loop() {

  //  if (Serial.available() > 0) {
  //button1
  //if(Serial.available()>0){
  //int Byte = Serial.read();


  BbtnState1 = digitalRead(BbtnPin1);

  if (BbtnState1 != BlastbtnState1) {
    if (BbtnState1 == HIGH) {
      Serial.println("a");
    }
    delay(30);
  }

  BlastbtnState1 = BbtnState1;

  //button2
  BbtnState2 = digitalRead(BbtnPin2);

  if (BbtnState2 != BlastbtnState2) {
    if (BbtnState2 == HIGH) {
      Serial.println("b");
    }

  }

  BlastbtnState2 = BbtnState2;


  //button3
  BbtnState3 = digitalRead(BbtnPin3);

  if (BbtnState3 != BlastbtnState3) {
    if (BbtnState3 == HIGH) {
      Serial.println("c");
    }
  }
  BlastbtnState3 = BbtnState3;


  //stamp button1
  SbtnState1 = digitalRead(SbtnPin1);

  if (SbtnState1 != SlastbtnState1) {
    if (SbtnState1 == HIGH) {
      Serial.println("s1");
    }
  }
  SlastbtnState1 = SbtnState1;


  //stamp button2
  SbtnState2 = digitalRead(SbtnPin2);

  if (SbtnState2 != SlastbtnState2) {
    if (SbtnState2 == HIGH) {
      Serial.println("s2");
    }
  } delay(30);
  SlastbtnState2 = SbtnState2;


  //stamp button3
  SbtnState3 = digitalRead(SbtnPin3);



  if (SbtnState3 != SlastbtnState3) {
    if (SbtnState3 == HIGH) {
      Serial.println("s3");
    }
  }
  SlastbtnState3 = SbtnState3;




  //how to play button

  HbtnState = digitalRead(HbtnPin);

  if (HbtnState != HlastbtnState) {
    // reset the debouncing timer
    lastDebounceTime = millis();
  }

  if ((millis() - lastDebounceTime) > debounceDelay) {



    if (HbtnState != buttonState) {
      buttonState = HbtnState;


      if (buttonState == HIGH) {
        ledState = !ledState;

        if (ledState == 1) {
          Serial.println("play");
        } else {
          Serial.println("stop");
        }

      }
    }
  }

  HlastbtnState = HbtnState;



  //Screen shot button

  //         ScreenbtnState = digitalRead(ScreenbtnPin);
  //
  //        if (ScreenbtnState != ScreenlastbtnState) {
  //          if (ScreenbtnState == HIGH) {
  //            Serial.println("screenshot!");
  //          }
  //        }
  //        ScreenlastbtnState = ScreenbtnState;
  //






  //hand type-toggle button
  toggleState1 = digitalRead(togglePin1);

  if (toggleState1 != lasttoggleState1) {
    if (toggleState1 == HIGH) {
      Serial.println("right hand on");
    } else {
      Serial.println("left hand on");


    }
  }
  lasttoggleState1 = toggleState1;
  


  //brush-stamp mode toggle

  toggleState2 = digitalRead(togglePin2);

  if (toggleState2 != lasttoggleState2) {
    if (toggleState2 == HIGH) {
      Serial.println("sticker mode on");
      digitalWrite(ledPin1, HIGH);
      digitalWrite(ledPin2, LOW);

    } else {
      Serial.println("brush mode on");
      digitalWrite(ledPin1, LOW);
      digitalWrite(ledPin2, HIGH);


    }
  }
  lasttoggleState2 = toggleState2;





  //reset button
  //
          sensorValue = analogRead(resetPin);
  
  
  
  
            if (sensorValue > 0) { // someone is touching sensor
              if (!wasTouched)
              {
                Serial.println("ON");
                wasTouched = true;
              }
            }
            else
            {
              wasTouched = false;
            }


  btnState = digitalRead(btnPin);

  if (btnState != lastState) {
    if (btnState == LOW) {

      Keyboard.press(0x82);
      Keyboard.press('.');


      //    Keyboard.write(65);
      Serial.println("pressed");

      delay(100);
      Keyboard.releaseAll();
    }
    delay(30);
  }
  lastState = btnState;

}
