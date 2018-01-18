// MotorLab WIP

#define NUM_MOTOR_CHANNELS 4
#define NUM_MOTOR_SIGNALS  4

struct Motor
{
    uint8_t  iSignalAddress[NUM_MOTOR_SIGNALS];
    uint16_t iStepRatio;
    int8_t   iStep;
    int8_t   iDirection;
};


Motor motors[NUM_MOTOR_CHANNELS];
//uint8_t motor[NUM_MOTOR_CHANNELS][NUM_MOTOR_SIGNALS];

struct Joystick
{
    uint8_t iXAddr;
    uint8_t iYAddr;
    uint16_t iXVal;
    uint16_t iYVal;
    uint8_t xMotor;
    uint8_t yMotor;
};

#define NUM_JOYS 2
Joystick joy[NUM_JOYS];




// Debug declarations
    int ledPin = 13;  // select the pin for the LED


// Joystick declaration
    int JoyX = A0;    // select the input pin for the potentiometer
    int JoyY = A1;

    int JoyXVal = 0;  // variable to store the value coming from the sensor
    int JoyYVal = 0;


uint8_t iGlobalStep = 0;
void setup()
{
    pinMode(ledPin, OUTPUT); // declare the ledPin as an OUTPUT:
    Serial.begin(9600);

    joy[0].iXAddr = A1;
    joy[0].iYAddr = A0;
    joy[0].xMotor = 1;
    joy[0].yMotor = 0;

    joy[1].iXAddr = A3;
    joy[1].iYAddr = A2;
    joy[1].xMotor = 3;
    //joy[1].yMotor = 4;

    motors[0].iSignalAddress[0] = A4;
    motors[0].iSignalAddress[1] = A5;
    motors[0].iSignalAddress[2] = 23;
    motors[0].iSignalAddress[3] = 20;
    motors[0].iStepRatio        = 1;
    motors[0].iDirection        = 0;
    motors[0].iStep             = 0;

    motors[1].iSignalAddress[0] = 24;
    motors[1].iSignalAddress[1] = 21;
    motors[1].iSignalAddress[2] = 1;
    motors[1].iSignalAddress[3] = 0;
    motors[1].iStepRatio        = 1;
    motors[1].iDirection        = 0;
    motors[1].iStep             = 0;

    motors[2].iSignalAddress[0] = 13;
    motors[2].iSignalAddress[1] = 12;
    motors[2].iSignalAddress[2] = 11;
    motors[2].iSignalAddress[3] = 10;
    motors[2].iStepRatio        = 1;
    motors[2].iDirection        = 0;
    motors[2].iStep             = 0;



    motors[3].iSignalAddress[0] = 9;
    motors[3].iSignalAddress[1] = 6;
    motors[3].iSignalAddress[2] = 5;
    motors[3].iSignalAddress[3] = 22;
    motors[3].iStepRatio        = 1;
    motors[3].iDirection        = 0;
    motors[3].iStep             = 0;

    for (int iMotors=0; iMotors < NUM_MOTOR_SIGNALS; iMotors++)
    {
            for (int i=0; i< NUM_MOTOR_SIGNALS; i++)
            {
                    pinMode(motors[iMotors].iSignalAddress[i], OUTPUT);
                    digitalWrite(motors[iMotors].iSignalAddress[i], 0);
            }
    }


    digitalWrite(ledPin, HIGH);     // turn the ledPin on
    iGlobalStep = 0;
}

int debugJoyXY(int iX, int iY)
{
    Serial.print("JoyX: [");
    Serial.print(iX);
    Serial.print("], JoyY: [");
    Serial.print(iY);
    Serial.print("\n");

    return 0;
}

void SetMotor(uint8_t iMotor, uint8_t iStep)
{
    switch(iStep)
    {
        case 0:
            digitalWrite(motors[iMotor].iSignalAddress[0], 0);
            digitalWrite(motors[iMotor].iSignalAddress[1], 0);
            digitalWrite(motors[iMotor].iSignalAddress[2], 0);
            digitalWrite(motors[iMotor].iSignalAddress[3], 1);
            break;
        case 1:
            digitalWrite(motors[iMotor].iSignalAddress[0], 0);
            digitalWrite(motors[iMotor].iSignalAddress[1], 0);
            digitalWrite(motors[iMotor].iSignalAddress[2], 1);
            digitalWrite(motors[iMotor].iSignalAddress[3], 1);
            break;
        case 2:
            digitalWrite(motors[iMotor].iSignalAddress[0], 0);
            digitalWrite(motors[iMotor].iSignalAddress[1], 0);
            digitalWrite(motors[iMotor].iSignalAddress[2], 1);
            digitalWrite(motors[iMotor].iSignalAddress[3], 0);
            break;
        case 3:
            digitalWrite(motors[iMotor].iSignalAddress[0], 0);
            digitalWrite(motors[iMotor].iSignalAddress[1], 1);
            digitalWrite(motors[iMotor].iSignalAddress[2], 1);
            digitalWrite(motors[iMotor].iSignalAddress[3], 0);
            break;
        case 4:
            digitalWrite(motors[iMotor].iSignalAddress[0], 0);
            digitalWrite(motors[iMotor].iSignalAddress[1], 1);
            digitalWrite(motors[iMotor].iSignalAddress[2], 0);
            digitalWrite(motors[iMotor].iSignalAddress[3], 0);
            break;
        case 5:
            digitalWrite(motors[iMotor].iSignalAddress[0], 1);
            digitalWrite(motors[iMotor].iSignalAddress[1], 1);
            digitalWrite(motors[iMotor].iSignalAddress[2], 0);
            digitalWrite(motors[iMotor].iSignalAddress[3], 0);
            break;
        case 6:
            digitalWrite(motors[iMotor].iSignalAddress[0], 1);
            digitalWrite(motors[iMotor].iSignalAddress[1], 0);
            digitalWrite(motors[iMotor].iSignalAddress[2], 0);
            digitalWrite(motors[iMotor].iSignalAddress[3], 0);
            break;
        case 7:
            digitalWrite(motors[iMotor].iSignalAddress[0], 1);
            digitalWrite(motors[iMotor].iSignalAddress[1], 0);
            digitalWrite(motors[iMotor].iSignalAddress[2], 0);
            digitalWrite(motors[iMotor].iSignalAddress[3], 1);
            break;

#define STEP_OFF 99

        case STEP_OFF:
        default:
            digitalWrite(motors[iMotor].iSignalAddress[0], 0);
            digitalWrite(motors[iMotor].iSignalAddress[1], 0);
            digitalWrite(motors[iMotor].iSignalAddress[2], 0);
            digitalWrite(motors[iMotor].iSignalAddress[3], 0);
            break;
    }
}


int debugJoyXY()
{
    Serial.print("JoyX: [");
    Serial.print(JoyXVal);
    Serial.print("], JoyY: [");
    Serial.print(JoyYVal);
    Serial.print("\n");

    return 0;
}

int debugFoo(int foo1, int foo2, int foo3)
{
    Serial.print("Foo1: [");
    Serial.print(foo1);
    Serial.print("], Foo2: [");
    Serial.print(foo2);
    Serial.print("], Foo3: [");
    Serial.print(foo3);
    Serial.print("]\n");

    return 0;
}


void PollJoysticks()
{
    for (int i=0; i<2; i++)
    {
        joy[i].iXVal = analogRead(joy[i].iXAddr);
        joy[i].iYVal = analogRead(joy[i].iYAddr);
    }

}

void debugJoy(int iJoy)
{
    Serial.print("joy x: [");
    Serial.print(joy[iJoy].iXVal);
    Serial.print("], joy y: [");
    Serial.print(joy[iJoy].iYVal);
    Serial.print("] \n");
}

#define JOY_THRESH_LO 200
#define JOY_THRESH_HI 850
void setMotorDir(int iJoy, int isX, int iMotor, int iDir)
{
    if( isX )
    {
        if (iDir > 0)
        {
            if      (joy[iJoy].iXVal > JOY_THRESH_HI) { motors[iMotor].iDirection =  1; }
            else if (joy[iJoy].iXVal < JOY_THRESH_LO) { motors[iMotor].iDirection = -1; }
            else                                      { motors[iMotor].iDirection =  0; }
        }
        else
        {
            if      (joy[iJoy].iXVal > JOY_THRESH_HI) { motors[iMotor].iDirection = -1; }
            else if (joy[iJoy].iXVal < JOY_THRESH_LO) { motors[iMotor].iDirection =  1; }
            else                                      { motors[iMotor].iDirection =  0; }
        }
    }
    else // is Y
    {
        if (iDir > 0)
        {
            if      (joy[iJoy].iYVal > JOY_THRESH_HI) { motors[iMotor].iDirection =  1; }
            else if (joy[iJoy].iYVal < JOY_THRESH_LO) { motors[iMotor].iDirection = -1; }
            else                                      { motors[iMotor].iDirection =  0; }
        }
        else
        {
            if      (joy[iJoy].iYVal > JOY_THRESH_HI) { motors[iMotor].iDirection = -1; }
            else if (joy[iJoy].iYVal < JOY_THRESH_LO) { motors[iMotor].iDirection =  1; }
            else                                      { motors[iMotor].iDirection =  0; }
        }
    }

}


void loop()
{
    PollJoysticks();
    //debugJoy(0);
    #define XDIR 1
    #define YDIR 0
    #define JOY0 0
    #define JOY1 1
    #define MOTOR0 0
    #define MOTOR1 1
    #define MOTOR2 2
    #define MOTOR3 3
    #define DIRFWD 1
    #define DIRREV 0

    setMotorDir(JOY0, YDIR, MOTOR0, DIRFWD);


    setMotorDir(JOY1, XDIR, MOTOR1, DIRFWD);

    // int iMotor = 1;
    // if      (joy[i].iXVal > 900) { motors[iMotor].iDirection =  1; }
    // else if (joy[i].iXVal < 432) { motors[iMotor].iDirection = -1; }
    // else                         { motors[iMotor].iDirection =  0; }
    //
    //
    // iMotor = 2;

    setMotorDir(JOY1, YDIR, MOTOR2, DIRFWD);
    // if      (joy[i].iYVal > 900) { motors[iMotor].iDirection =  1; }
    // else if (joy[i].iYVal < 432) { motors[iMotor].iDirection = -1; }
    // else                         { motors[iMotor].iDirection =  0; }
    //
    // iMotor = 3;

    setMotorDir(JOY1, YDIR, MOTOR3, DIRREV);

    // if      (joy[i].iYVal > 900) { motors[iMotor].iDirection = -1; }
    // else if (joy[i].iYVal < 432) { motors[iMotor].iDirection =  1; }
    // else                         { motors[iMotor].iDirection =  0; }

    for (int i=0; i<4; i++)
    {
        if (motors[i].iDirection !=0)
        {

           if      (motors[i].iDirection > 0) { if (++(motors[i].iStep) >=8){ motors[i].iStep = 0;        } }
           else if (motors[i].iDirection < 0) { if (--(motors[i].iStep) < 0){ motors[i].iStep = 7;        } }
           else                               {                               motors[i].iStep = STEP_OFF;   }

            debugFoo(i, motors[i].iStep, motors[i].iDirection);

            SetMotor(i, motors[i].iStep);
        }
    }
    //delay(6 );
    //delayMicroseconds(1);
}
