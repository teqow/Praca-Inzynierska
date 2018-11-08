int pwmA=5, pwmB=6;
int goraLewa = 8, dolLewa= 7,goraPrawa = 10, dolPrawa= 9;

int dalmierz1 = A0;
int odbiciowy=A1;

int dalmierzValue = 0;
int odbiciowyValue=0;

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
  odbiciowyValue=analogRead(odbiciowy);
  Serial.print("\n odleglosc i cny70 ");
  //Serial.print( dalmierzValue);
 Serial.print( odbiciowyValue);
  delay(2000);
  
  if(dalmierzValue<400)
  {
   // startMotorLooking(1,105);
    //startMotorLooking(2,125);
   }
  else{
   // startMotorAttack(1,200);
    //startMotorAttack(2,200);
    delay(50);
  }
}

void startMotorAttack (int motor, uint8_t predkosc) {
      digitalWrite(dolLewa, HIGH);
      digitalWrite(goraLewa, LOW);
      digitalWrite(dolPrawa, HIGH);
      digitalWrite(goraPrawa, LOW);
      analogWrite(pwmA, predkosc);
      analogWrite(pwmB, predkosc);
    
  }
  void startMotorLooking (int motor, uint8_t predkosc) {
      //digitalWrite(dolLewa, LOW);
      digitalWrite(goraLewa, HIGH);
      //digitalWrite(dolPrawa, HIGH);
      //digitalWrite(goraPrawa, HIGH);
      analogWrite(pwmA, predkosc);
      //analogWrite(pwmB, predkosc);
    
  }
