int pwmA=5, pwmB=6;
int goraLewa = 8, dolLewa= 7,goraPrawa = 10, dolPrawa= 9;

int dalmierz1 = A0;

int dalmierzValue = 0;

void setup() {
  
  pinMode(pwmA, OUTPUT); //PWM dla jednego silnika
  pinMode(pwmB, OUTPUT); //PWM dla drugiego silnika
  pinMode(dolLewa, OUTPUT);
  pinMode(goraLewa, OUTPUT);
  pinMode(dolPrawa, OUTPUT);
  pinMode(goraPrawa, OUTPUT);
  Serial.begin(9600);

}

void loop() {
  dalmierzValue=analogRead(dalmierz1);
  Serial.print("\n odleglosc ");
  Serial.print( dalmierzValue);

  if(dalmierzValue<400)
  {
    startMotor1Looking(105);
    startMotor2Looking(105);
   }
  else{
    startMotorAttack(200);
    //startMotorAttack(2,200);
    delay(50);
  }
}

void startMotorAttack (uint8_t predkosc) {
      digitalWrite(dolLewa, HIGH);
      digitalWrite(goraLewa, LOW);
      digitalWrite(dolPrawa, HIGH);
      digitalWrite(goraPrawa, LOW);
      analogWrite(pwmA, predkosc);
      analogWrite(pwmB, predkosc);
    
  }
  void startMotor1Looking (uint8_t predkosc) {
      //digitalWrite(dolLewa, LOW);
      digitalWrite(goraLewa, HIGH);
      //digitalWrite(dolPrawa, HIGH);
      //digitalWrite(goraPrawa, HIGH);
      analogWrite(pwmA, predkosc);
      
    
  }
  void startMotor2Looking (uint8_t predkosc)
  {
    digitalWrite(dolLewa, LOW);
    analogWrite(pwmB, predkosc);
  }
  
  
  



  
//TODO: ODBICIOWY
