/********* Connections **********/
// Motor connections
#define   IN1   9
#define   IN2   8
#define   IN3   7
#define   IN4   6
#define   ENA   10
#define   ENB   5
/******** Variables ********/
// Direction variables
#define   FF     1
#define   FR    2
#define   R     3
#define   BR    4
#define   B     5
#define   BL    6
#define   L     7
#define   FL    8
#define   STOP  0
#define   SPEED_CONSTANT  0.2
void setup() {
  Serial.begin(9600);
  delay(30);
  for (int i = 5; i <= 10; i++) {
    pinMode(i, OUTPUT);
  }
}
void motor(int dir, int speed);
int velocidad = 220;
void loop()
{
  if(Serial.available())  {
    int incomingData= Serial.read(); // can be -1 if read error
    switch(incomingData) {
        case '1':
           Serial.println("FORWARE");
           motor(1,velocidad);
           break;

        case '2':
           Serial.println("FORWARE RIGHT");
           motor(2,velocidad);
           break;

        case '3':
           Serial.println("RIGHT");
            motor(3,velocidad);
           break;
        case '4':
           Serial.println("BACKWARD RIGHT");
           motor(4,velocidad);
           break;

        case '5':
           Serial.println("BACKWARD");
           motor(5,velocidad);
           break;

        case '6':
           Serial.println("BACKWARD LEFT");
            motor(6,velocidad);
           break;
        case '7':
           Serial.println("LEFT");
           motor(7,velocidad);
           break;

        case '8':
           Serial.println("FORWARE LEFT");
           motor(8,velocidad);
           break;

        case '0':
           Serial.println("STOP");
            motor(0,velocidad);
           break;
        default:
           // handle unwanted input here
           break;
    }
  }
}

/*
  dir:
  F- Forward
  FR- Forward Right
  R- Right
  BR- Backward Right
  B- Backward
  BL- Backward Left
  L- Left
  FL- Forward Left
  STOP- Stop
  speed:
  min: 0, max: 255
*/
void motor(int dir, int speed) {
  if (dir == FF) {
    // Left motor forward with full speed
    digitalWrite(IN1, HIGH);
    digitalWrite(IN2, LOW);
    analogWrite(ENA, speed);
    // Right motor forward with full speed
    digitalWrite(IN3, HIGH);
    digitalWrite(IN4, LOW);
    analogWrite(ENB, speed);
  } else if (dir == FR) {
    // Left motor forward with full speed
    digitalWrite(IN1, HIGH);
    digitalWrite(IN2, LOW);
    analogWrite(ENA, speed);
    // Right motor forward with speed*SPEED_CONSTANT
    digitalWrite(IN3, HIGH);
    digitalWrite(IN4, LOW);
    analogWrite(ENB, speed * SPEED_CONSTANT);
  } else if (dir == R) {
    // Left motor forward with full speed
    digitalWrite(IN1, HIGH);
    digitalWrite(IN2, LOW);
    analogWrite(ENA, speed);
    // Right motor backward with full speed
    digitalWrite(IN3, LOW);
    digitalWrite(IN4, HIGH);
    analogWrite(ENB, speed);
  } else if (dir == BR) {
    // Left motor backward with full speed
    digitalWrite(IN1, LOW);
    digitalWrite(IN2, HIGH);
    analogWrite(ENA, speed);
    // Right motor backward with speed*SPEED_CONSTANT
    digitalWrite(IN3, LOW);
    digitalWrite(IN4, HIGH);
    analogWrite(ENB, speed * SPEED_CONSTANT);
  } else if (dir == B) {
    // Left motor backward with full speed
    digitalWrite(IN1, LOW);
    digitalWrite(IN2, HIGH);
    analogWrite(ENA, speed);
    // Right motor backward with full speed
    digitalWrite(IN3, LOW);
    digitalWrite(IN4, HIGH);
    analogWrite(ENB, speed);
  } else if (dir == BL) {
    // Left motor backward with speed*SPEED_CONSTANT
    digitalWrite(IN1, LOW);
    digitalWrite(IN2, HIGH);
    analogWrite(ENA, speed * SPEED_CONSTANT);
    // Right motor backward with full speed
    digitalWrite(IN3, LOW);
    digitalWrite(IN4, HIGH);
    analogWrite(ENB, speed);
  } else if (dir == L) {
    // Left motor forward with full speed
    digitalWrite(IN1, LOW);
    digitalWrite(IN2, HIGH);
    analogWrite(ENA, speed);
    // Right motor backward with full speed
    digitalWrite(IN3, HIGH);
    digitalWrite(IN4, LOW);
    analogWrite(ENB, speed);
  } else if (dir == FL) {
    // Left motor forward with speed*SPEED_CONSTANT
    digitalWrite(IN1, HIGH);
    digitalWrite(IN2, LOW);
    analogWrite(ENA, speed * SPEED_CONSTANT);
    // Right motor forward with full speed
    digitalWrite(IN3, HIGH);
    digitalWrite(IN4, LOW);
    analogWrite(ENB, speed);
  } else if (dir == STOP) {
    // Left motor stop
    analogWrite(ENA, 0);
    // Right motor stop
    analogWrite(ENB, 0);
  }
}
