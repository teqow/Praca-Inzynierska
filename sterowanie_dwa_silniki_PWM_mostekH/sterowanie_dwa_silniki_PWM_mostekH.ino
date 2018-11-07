#define LEFT     0
#define RIGHT    1

void setup() {

  pinMode(5, OUTPUT); //PWM dla jednego silnika
  pinMode(6, OUTPUT); //PWM dla drugiego silnika
  pinMode(7, OUTPUT);
  pinMode(8, OUTPUT);
  pinMode(9, OUTPUT);
  pinMode(10, OUTPUT);

}

void loop() {
  
  startMotor(LEFT, 255);
  delay(1000);
  startMotor(LEFT, 127);
  delay(1000);
  startMotor(RIGHT, 255);
  delay(1000);
  startMotor(RIGHT, 127);
  delay(1000);
  stopMotor();
  delay(1000);
  
}


void startMotor (boolean dir, uint8_t _speed) {

    if(dir) {
      
      digitalWrite(7, LOW);
      digitalWrite(8, HIGH);
      digitalWrite(9, LOW);
      digitalWrite(10, HIGH);
      analogWrite(5, _speed);
      analogWrite(6, _speed);
      }
    else {

      digitalWrite(7, HIGH);
      digitalWrite(8, LOW);
      digitalWrite(9, HIGH);
      digitalWrite(10, LOW);
      analogWrite(5, _speed);
      analogWrite(6, _speed);;
      
      }
  }

void stopMotor() {

      digitalWrite(7, LOW);
      digitalWrite(8, LOW);
      digitalWrite(9, LOW);
      digitalWrite(10, LOW);
      analogWrite(5,0);
      analogWrite(6,0);;
      
  
  }
