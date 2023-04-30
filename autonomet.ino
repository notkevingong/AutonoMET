#include <Servo.h>

Servo servo1; 
Servo servo2;

//Servo Constants/Variables
int buttonState = 0;
const int buttonPin = 11; //buttonPin
const int servo1Pin = 3; 
const int servo2Pin = 2;

//LEFT Signal Pin Constants
const int digital_pin_LEFT = 8;
const int analog_pin_LEFT = A0;
const int led_LEFT = 6;
int analog_val_LEFT = 0;
int digital_val_LEFT = 0;
bool isLeft = false;


//RIGHT Signal Pin Constants
const int digital_pin_RIGHT = 9;
const int analog_pin_RIGHT = A1;
const int led_RIGHT = 5;
int analog_val_RIGHT = 0;
int digital_val_RIGHT = 0;

void signalLights();


void setup()
{
  //Signal Setup
  Serial.begin(9600);
  pinMode(digital_pin_LEFT,INPUT);
  pinMode(analog_pin_LEFT,INPUT);
  pinMode(led_LEFT,OUTPUT);
  pinMode(led_RIGHT,OUTPUT);

  //Servo Setup
  servo1.attach (servo1Pin);
  servo2.attach (servo2Pin);
  pinMode(buttonPin, INPUT);

}

void loop(){

  while(digitalRead(buttonPin) != 0){
    servo1.write(90);
    servo2.write(0);
    signalLights();}
  while(digitalRead(buttonPin) == 0){delay(100);}
  while(digitalRead(buttonPin) != 0){signalLights();
    servo1.write(30);
    delay(200);
    servo2.write(60);
   }
  while(digitalRead(buttonPin) == 0){delay(150);}

  }

void signalLights(){
    Serial.print("LEFT SENSOR:\n");
    Serial.println(analog_val_LEFT); Serial.print(" ");Serial.println(digital_val_LEFT);
    Serial.print("\nRIGHT SENSOR: \n");
    Serial.println(analog_val_RIGHT); Serial.print(" ");Serial.println(digital_val_RIGHT);
    
    //Analog Values
    analog_val_LEFT = analogRead(analog_pin_LEFT);
    analog_val_RIGHT = analogRead(analog_pin_RIGHT);
  
    //Digital Values
    digital_val_LEFT = digitalRead(digital_pin_LEFT);
    digital_val_RIGHT = digitalRead(digital_pin_RIGHT);
    
    //Left Blinker
    if (analog_val_LEFT <= 100) {
        digitalWrite(led_LEFT, HIGH);
        delay(500);
        digitalWrite(led_LEFT, LOW);
        delay(500);
        digitalWrite(led_LEFT, HIGH);
        delay(500);
        digitalWrite(led_LEFT, LOW);
        delay(500);
        digitalWrite(led_LEFT, HIGH);
        delay(500);
        digitalWrite(led_LEFT, LOW);
        
      }
      
    //Right Blinker
    if (analog_val_RIGHT <= 100) {
        digitalWrite(led_RIGHT, HIGH);
        delay(500);
        digitalWrite(led_RIGHT, LOW);
        delay(500);
        digitalWrite(led_RIGHT, HIGH);
        delay(500);
        digitalWrite(led_RIGHT, LOW);
        delay(500);
        digitalWrite(led_RIGHT, HIGH);
        delay(500);
        digitalWrite(led_RIGHT, LOW);
}
}
