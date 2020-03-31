#include <analogWrite.h>

/*
  Blink

  Turns an LED on for one second, then off for one second, repeatedly.

  Most Arduinos have an on-board LED you can control. On the UNO, MEGA and ZERO
  it is attached to digital pin 13, on MKR1000 on pin 6. LED_BUILTIN is set to
  the correct LED pin independent of which board is used.
  If you want to know what pin the on-board LED is connected to on your Arduino
  model, check the Technical Specs of your board at:
  https://www.arduino.cc/en/Main/Products

  modified 8 May 2014
  by Scott Fitzgerald
  modified 2 Sep 2016
  by Arturo Guadalupi
  modified 8 Sep 2016
  by Colby Newman

  This example code is in the public domain.

  http://www.arduino.cc/en/Tutorial/Blink
*/
int red = 12;
int green = 27;
int blue = 33;

//the button
int PressedButton = A0;

//a counter for how many clicks you have done
int counter = 0;

int delaytime = 5;



// the setup function runs once when you press reset or power the board
void setup() {

// initialize serial communication at 9600 bits per second:
Serial.begin(9600);
  
// initialize digital pin LED_BUILTIN as an output.
pinMode(red, OUTPUT);
pinMode(green, OUTPUT);
pinMode(blue, OUTPUT);

pinMode(PressedButton, INPUT);

}

// the loop function runs over and over again forever
void loop() {

  int buttonState = digitalRead(PressedButton);

  //this if for debugging
  Serial.println(buttonState);
  delay(30);

  Serial.println(counter);
  delay(30);

  //starting the code / counting upon presses
  if(buttonState == HIGH){
    counter++;
    delay(100);
   }

   else if(counter == 1){
     for(int brightness = 0; brightness <= 255; brightness++){   
    // changing the LED brightness with PWM
    analogWrite(red, brightness);
    delay(delaytime);
    }
   }

   else if(counter == 2){
     for(int brightness = 0; brightness <= 255; brightness++){   
     // changing the LED brightness with PWM
     analogWrite(green, brightness);
     delay(delaytime);
     }
   }

   else if(counter == 3){
     for(int brightness = 0; brightness <= 255; brightness++){   
     // changing the LED brightness with PWM
     analogWrite(blue, brightness);
     delay(delaytime);
     }
   }

    else{
      digitalWrite(red, LOW);
      digitalWrite(green, LOW);
      digitalWrite(blue, LOW);
      counter = 0;
    }

}
