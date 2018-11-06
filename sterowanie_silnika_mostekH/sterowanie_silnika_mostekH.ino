void setup() {

 
  pinMode(6, OUTPUT);
  pinMode(7, OUTPUT);

}

void loop() {
  
  startMotor();
  delay(1000);
  stopMotor();
  delay(1000);
  
}


void startMotor () {
      
      digitalWrite(6, LOW);
      digitalWrite(7, HIGH);
 }

void stopMotor() {

      digitalWrite(6, LOW);
      digitalWrite(7, LOW);
 }
