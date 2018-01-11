// MotorLab WIP

#define NUM_MOTOR_CHANNELS 4
#define NUM_MOTOR_SIGNALS  4

struct Motor
{
    uint8_t  iSignalAddress[NUM_MOTOR_SIGNALS];
    uint16_t iStepRatio;
    int8_t   iStep;
    uint8_t  bDirection;
};


Motor motors[NUM_MOTOR_CHANNELS];
//uint8_t motor[NUM_MOTOR_CHANNELS][NUM_MOTOR_SIGNALS];



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

    motors[0].iSignalAddress[0] = A4;
    motors[0].iSignalAddress[1] = A5;
    motors[0].iSignalAddress[2] = 23;
    motors[0].iSignalAddress[3] = 20;
    motors[0].iStepRatio        = 1;
    motors[0].bDirection        = 1;
    motors[0].iStep             = 0;

    for (int i=0; i< NUM_MOTOR_SIGNALS; i++) {pinMode(motors[0].iSignalAddress[i], OUTPUT);}

    digitalWrite(ledPin, HIGH);     // turn the ledPin on
    iGlobalStep = 0;
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

        default:
            digitalWrite(motors[0].iSignalAddress[0], 0);
            digitalWrite(motors[0].iSignalAddress[1], 0);
            digitalWrite(motors[0].iSignalAddress[2], 0);
            digitalWrite(motors[0].iSignalAddress[3], 0);
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

void loop()
{

    JoyXVal = analogRead(JoyX);

    if (JoyXVal > 900)
    {
        motors[0].bDirection = 1;
        if (++(motors[0].iStep) >=8){ motors[0].iStep = 0; }
        SetMotor(0, motors[0].iStep);
        delayMicroseconds(1000);
    }
    else if (JoyXVal < 412)
    {
        motors[0].bDirection = 0;
        if (--(motors[0].iStep) < 0){ motors[0].iStep = 7; }
        SetMotor(0, motors[0].iStep);
        delayMicroseconds(1000);
    }

debugJoyXY();







    // if  (motors[0].bDirection == 1) { if (++(motors[0].iStep) >=8){ motors[0].iStep = 0; } }
    // else                            { if (--(motors[0].iStep) < 0){ motors[0].iStep = 7; } }
    //
    //
    // delayMicroseconds(2000);

}
