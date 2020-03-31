#include <analogWrite.h>


int red = 12;
int green = 27;
int blue = 33;

//the button
int PressedButton = A0;

//a counter for how many clicks you have done
int counter = 0;

int delaytime = 5;

int lastButtonState = 0;



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
  Serial.print("\t buttonState: ");
  Serial.print(buttonState);

  Serial.println(" ");

  Serial.print("counter: ");
  Serial.print(counter);

 if(buttonState != lastButtonState){

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
      analogWrite(red, 0);
      analogWrite(green, 0);
      analogWrite(blue, 0);
      counter = 0;
    }

  }

    lastButtonState = buttonState;

}
