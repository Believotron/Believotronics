// MotorLab WIP

#define NUM_MOTOR_CHANNELS 4
#define NUM_MOTOR_SIGNALS  4

uint8_t motor[NUM_MOTOR_CHANNELS][NUM_MOTOR_SIGNALS];



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

    motor[0][0] = A4;
    motor[0][1] = A5;
    motor[0][2] = 23;
    motor[0][3] = 20;

    for (int i=0; i< NUM_MOTOR_SIGNALS; i++) {pinMode(motor[0][i], OUTPUT);}

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

void loop()
{
    switch(iGlobalStep)
    {
        case 0:
            digitalWrite(motor[0][0], 0);
            digitalWrite(motor[0][1], 0);
            digitalWrite(motor[0][2], 0);
            digitalWrite(motor[0][3], 1);
            break;
        case 1:
            digitalWrite(motor[0][0], 0);
            digitalWrite(motor[0][1], 0);
            digitalWrite(motor[0][2], 1);
            digitalWrite(motor[0][3], 1);
            break;
        case 2:
            digitalWrite(motor[0][0], 0);
            digitalWrite(motor[0][1], 0);
            digitalWrite(motor[0][2], 1);
            digitalWrite(motor[0][3], 0);
            break;
        case 3:
            digitalWrite(motor[0][0], 0);
            digitalWrite(motor[0][1], 1);
            digitalWrite(motor[0][2], 1);
            digitalWrite(motor[0][3], 0);
            break;
        case 4:
            digitalWrite(motor[0][0], 0);
            digitalWrite(motor[0][1], 1);
            digitalWrite(motor[0][2], 0);
            digitalWrite(motor[0][3], 0);
            break;
        case 5:
            digitalWrite(motor[0][0], 1);
            digitalWrite(motor[0][1], 1);
            digitalWrite(motor[0][2], 0);
            digitalWrite(motor[0][3], 0);
            break;
        case 6:
            digitalWrite(motor[0][0], 1);
            digitalWrite(motor[0][1], 0);
            digitalWrite(motor[0][2], 0);
            digitalWrite(motor[0][3], 0);
            break;
        case 7:
            digitalWrite(motor[0][0], 1);
            digitalWrite(motor[0][1], 0);
            digitalWrite(motor[0][2], 0);
            digitalWrite(motor[0][3], 1);
            break;

        default:
            digitalWrite(motor[0][0], 0);
            digitalWrite(motor[0][1], 0);
            digitalWrite(motor[0][2], 0);
            digitalWrite(motor[0][3], 0);
            break;

    }

    delay(1);

    if (++iGlobalStep >=8){ iGlobalStep = 0; }

}
