/*
  Analog Input
 Demonstrates analog input by reading an analog sensor on analog pin 0 and
 turning on and off a light emitting diode(LED)  connected to digital pin 13.
 The amount of time the LED will be on and off depends on
 the value obtained by analogRead().

 The circuit:
 * Potentiometer attached to analog input 0
 * center pin of the potentiometer to the analog pin
 * one side pin (either one) to ground
 * the other side pin to +5V
 * LED anode (long leg) attached to digital output 13
 * LED cathode (short leg) attached to ground

 * Note: because most Arduinos have a built-in LED attached
 to pin 13 on the board, the LED is optional.


 Created by David Cuartielles
 modified 30 Aug 2011
 By Tom Igoe

 This example code is in the public domain.

 http://www.arduino.cc/en/Tutorial/AnalogInput

 */

 #include <AccelStepper.h>
 #include <Wire.h>
 #include <Adafruit_MotorShield.h>
 #include "utility/Adafruit_MS_PWMServoDriver.h"

// Motor declarations
    Adafruit_MotorShield AFMS = Adafruit_MotorShield(); // Adafruit_MotorShield(Address); Address = 0x60-0x63
    // Connect a stepper motor with 200 steps per revolution (1.8 degree)
    // to motor port #2 (M3 and M4)
    Adafruit_StepperMotor *myMotor = AFMS.getStepper(200, 1);

// Debug declarations
    int ledPin = 13;  // select the pin for the LED


// Joystick declaration
    int JoyX = A0;    // select the input pin for the potentiometer
    int JoyY = A1;

    int JoyXVal = 0;  // variable to store the value coming from the sensor
    int JoyYVal = 0;

void setup()
{
    pinMode(ledPin, OUTPUT); // declare the ledPin as an OUTPUT:
    Serial.begin(9600);

    AFMS.begin();  // create with the default frequency 1.6KHz
    myMotor->setSpeed(100);  // rpm

    digitalWrite(ledPin, HIGH);     // turn the ledPin on
}

int debugJoyXY(int iX, int iY)
{
    Serial.print("JoyX: [");
    Serial.print(JoyXVal);
    Serial.print("], JoyY: [");
    Serial.print(JoyYVal);
    Serial.print("\n");

    return 0;
}

void loop()
{
    { // tick

        JoyXVal = analogRead(JoyX);
        JoyYVal = analogRead(JoyY);

        // dY = kYtheta
        // Move Y axis to Calculated Amplitude from Joystick Deflection
            int iMagnitude=10;
            if      (JoyYVal > 612)
            {
                    //iMagnitude = (JoyYVal - 512) / 512;
                    debugJoyXY(JoyXVal,JoyYVal);
                    myMotor->step(iMagnitude, FORWARD, SINGLE);
            }
            else if (JoyYVal < 412)
            {
                    //iMagnitude = (JoyYVal - 512) / 512;
                    myMotor->step(iMagnitude, BACKWARD, SINGLE);
                    debugJoyXY(JoyXVal,JoyYVal);
            }
            //delay(20);


    }



}
