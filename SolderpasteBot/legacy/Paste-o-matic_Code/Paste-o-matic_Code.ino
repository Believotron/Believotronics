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


#if defined(ARDUINO_SAMD_ZERO) && defined(SERIAL_PORT_USBVIRTUAL)
    // Required for Serial on Zero based boards
    #define Serial SERIAL_PORT_USBVIRTUAL
#endif

/*
// Motor declarations
    Adafruit_MotorShield AFMS = Adafruit_MotorShield(); // Adafruit_MotorShield(Address); Address = 0x60-0x63

    // Connect a stepper motor with 200 steps per revolution (1.8 degree)
    // to motor port #2 (M3 and M4)
    Adafruit_StepperMotor *myMotor0 = AFMS.getStepper(200, 0);
    Adafruit_StepperMotor *myMotor = AFMS.getStepper(200, 1);

*/

// Debug declarations
    int ledPin = 3;  // select the pin for the LED

    #define IN1  10
    #define IN2  11
    #define IN3  12
    #define IN4  13
    int Steps = 0;
    boolean Direction = true;// gre
    unsigned long last_time;
    unsigned long currentMillis ;
    int steps_left=4095*4;
    long time;


// Joystick declaration
    int JoyX = A2;    // select the input pin for the potentiometer
    int JoyY = A1;
    int Knob = A5;

    int JoyXVal = 0;  // variable to store the value coming from the sensor
    int JoyYVal = 0;

    int KnobVal = 0;

void setup()
{
    pinMode(ledPin, OUTPUT); // declare the ledPin as an OUTPUT:
    Serial.begin(115200);
    pinMode(IN1, OUTPUT);
    pinMode(IN2, OUTPUT);
    pinMode(IN3, OUTPUT);
    pinMode(IN4, OUTPUT);
    //while (!Serial);
    Serial.print("I'm alive!\n");
    //Serial.begin();

//    AFMS.begin();  // create with the default frequency 1.6KHz
//    myMotor->setSpeed(100);  // rpm
//    myMotor0->setSpeed(100);

    digitalWrite(ledPin, HIGH);     // turn the ledPin on
}

int debugJoyXYZ(int iX, int iY, int iZ)
{
    static int iLoop=0;
    Serial.print("JoyX: [");
    Serial.print(iX);
    Serial.print("], JoyY: [");
    Serial.print(iY);
    Serial.print("], <");
    Serial.print("], Knob: [");
    Serial.print(iZ);
    Serial.print("], <");
    Serial.print(iLoop);
    Serial.print(">\n");
    iLoop++;

    return 0;
}

void loop()
{
    steps_left=0;
    JoyXVal = analogRead(JoyX);
    JoyYVal = analogRead(JoyY);
    KnobVal = analogRead(Knob);
    //debugJoyXY(JoyXVal,JoyYVal);

    // dY = kYtheta
    // Move Y axis to Calculated Amplitude from Joystick Deflection
    int iMagnitude=10;
    if      (JoyYVal > 612)
    {
        //iMagnitude = (JoyYVal - 512) / 512;
        Direction = 0;
        steps_left = KnobVal;
        debugJoyXYZ(JoyXVal,JoyYVal, KnobVal);
    }
    else if (JoyYVal < 412)
    {
        //iMagnitude = (JoyYVal - 512) / 512;
        Direction = 1;
        steps_left = KnobVal;
        debugJoyXYZ(JoyXVal,JoyYVal, KnobVal);
    }

    if (steps_left)
    {
        while(steps_left>0)
        {
            currentMillis = micros();
            if(currentMillis-last_time>=1000)
            {
                stepper(1);
                time=time+micros()-last_time;
                last_time=micros();
                steps_left--;
            }
        }
    }
    else
    {
        digitalWrite(IN1, LOW);
        digitalWrite(IN2, LOW);
        digitalWrite(IN3, LOW);
        digitalWrite(IN4, LOW);
        delay(200);
    }
}

void stepper(int xw){
    for (int x=0;x<xw;x++)
    {
        switch(Steps)
        {
            case 0:
                 digitalWrite(IN1, LOW);
                 digitalWrite(IN2, LOW);
                 digitalWrite(IN3, LOW);
                 digitalWrite(IN4, HIGH);
                 break;
            case 1:
                 digitalWrite(IN1, LOW);
                 digitalWrite(IN2, LOW);
                 digitalWrite(IN3, HIGH);
                 digitalWrite(IN4, HIGH);
                 break;
            case 2:
                 digitalWrite(IN1, LOW);
                 digitalWrite(IN2, LOW);
                 digitalWrite(IN3, HIGH);
                 digitalWrite(IN4, LOW);
                 break;
            case 3:
                 digitalWrite(IN1, LOW);
                 digitalWrite(IN2, HIGH);
                 digitalWrite(IN3, HIGH);
                 digitalWrite(IN4, LOW);
                 break;
            case 4:
                 digitalWrite(IN1, LOW);
                 digitalWrite(IN2, HIGH);
                 digitalWrite(IN3, LOW);
                 digitalWrite(IN4, LOW);
                 break;
            case 5:
                 digitalWrite(IN1, HIGH);
                 digitalWrite(IN2, HIGH);
                 digitalWrite(IN3, LOW);
                 digitalWrite(IN4, LOW);
                 break;
             case 6:
                 digitalWrite(IN1, HIGH);
                 digitalWrite(IN2, LOW);
                 digitalWrite(IN3, LOW);
                 digitalWrite(IN4, LOW);
                 break;
            case 7:
                 digitalWrite(IN1, HIGH);
                 digitalWrite(IN2, LOW);
                 digitalWrite(IN3, LOW);
                 digitalWrite(IN4, HIGH);
                 break;
            default:
                 digitalWrite(IN1, LOW);
                 digitalWrite(IN2, LOW);
                 digitalWrite(IN3, LOW);
                 digitalWrite(IN4, LOW);
                 break;
        }
        //delay(500);
        SetDirection();
    }
}
void SetDirection()
{
    if(Direction==1)
    {
        Steps++;
        //digitalWrite(13, LOW);
    }
    if(Direction==0)
    {
        Steps--;
        //digitalWrite(13, HIGH);
    }
    if(Steps>7){Steps=0;}
    if(Steps<0){Steps=7; }
}
