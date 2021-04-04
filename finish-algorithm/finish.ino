int reflectionSensor1AnaloginIn = A0; 
int reflectionSensor2AnaloginIn = A1;
int distanceSensorAnalogIn = A2;
int IA1=10;
int IA2=12;
int IB1=11;
int IB2=13;
int a = 0;
 
void setup(){
  Serial.begin(9600);        //inicjalizacja monitora szeregowego
  Serial.println("Test czujnika odbiciowego i odleglosci");
  
 pinMode(IA1, OUTPUT);
 pinMode(IA2, OUTPUT);
 pinMode(IB1, OUTPUT);
 pinMode(IB2, OUTPUT);
 pinMode(2, INPUT_PULLUP);
}

void loop(){
  int reflectionSensor1 = analogRead(reflectionSensor1AnaloginIn);
  int reflectionSensor2 = analogRead(reflectionSensor2AnaloginIn); 
  int distanceSensor = analogRead(distanceSensorAnalogIn); 
  int startButton = digitalRead(2);
    
     
  
  Serial.print("czujnik 1 ");
  Serial.println(reflectionSensor1);
  Serial.print("czujnik 2 ");
  Serial.println(reflectionSensor2);
  Serial.print("dalmierz ");
  Serial.println(distanceSensor);

if (startButton== LOW){
  a =1;
  }

  if(a == 1){
if(reflectionSensor1 >100 && reflectionSensor2 >100){
  if(distanceSensor>150){
    MB2_Forward(150);
    MA2_Forward(150);
    delay(50);
  Serial.println("przeciwnik wykryty ");
  }
  else{
    MB1_Backward(100);
    MA2_Forward(100);
    Serial.println("szukam przeciwnika ");
  }     
}
else{
  MA1_Backward(100);
  MB1_Backward(100);
  Serial.println("wykryto biala obrecz ");
}

}

}


void MA1_Backward(int Speed1)  
{
     analogWrite(IA1,Speed1);
     digitalWrite(IA2,LOW);  
  }
  
void MA2_Forward(int Speed1) 
{    
    int Speed2=255-Speed1;
    analogWrite(IA1,Speed2);
    digitalWrite(IA2,HIGH); 
  }
  
void MB1_Backward(int Speed1)
{
     analogWrite(IB1,Speed1);
     digitalWrite(IB2,LOW);  
  }
  
void MB2_Forward(int Speed1)
{    
    int Speed2=255-Speed1;
    analogWrite(IB1,Speed2);
    digitalWrite(IB2,HIGH);   
  }
 
