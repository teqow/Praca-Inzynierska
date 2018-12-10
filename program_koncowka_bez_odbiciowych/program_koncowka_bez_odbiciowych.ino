int czujnik1 = A0; 
int czujnik2 = A1;
int dalmierz = A2;
int IA1=10;
int IA2=12;
int IB1=11;
int IB2=13;
 
void setup(){
  Serial.begin(9600);        //inicjalizacja monitora szeregowego
  Serial.println("Test czujnika odbiciowego i odleglosci");
  
 pinMode(IA1, OUTPUT);
 pinMode(IA2, OUTPUT);
 pinMode(IB1, OUTPUT);
 pinMode(IB2, OUTPUT); 
}

void loop(){
  int odczyt1 = analogRead(czujnik1);
  int odczyt2 = analogRead(czujnik2); 
  int odczyt3 = analogRead(dalmierz);      
  
  Serial.print("czujnik 1 ");
  Serial.println(odczyt1);
  Serial.print("czujnik 2 ");
  Serial.println(odczyt2);
  Serial.print("dalmierz ");
  Serial.println(odczyt3);

  if(odczyt3>110){
    MB2_Backward(150);//Motor MA1 forward; PWM speed control
    MA2_Backward(150);//Motor MA2 forward; PWM speed control
  
  }
  else{
    MB1_Forward(100);
    MA2_Backward(100);
  }         
}

void MA1_Forward(int Speed1)  //fast decay; Speed = High duty-cycle 
{
     analogWrite(IA1,Speed1);
     digitalWrite(IA2,LOW);  
  }
  
void MA2_Backward(int Speed1)  //slow decay; Speed = Low duty-cycle 
{    
    int Speed2=255-Speed1;
    analogWrite(IA1,Speed2);
    digitalWrite(IA2,HIGH); 
  }
  
void MB1_Forward(int Speed1)
{
     analogWrite(IB1,Speed1);
     digitalWrite(IB2,LOW);  
  }
  
void MB2_Backward(int Speed1)
{    
    int Speed2=255-Speed1;
    analogWrite(IB1,Speed2);
    digitalWrite(IB2,HIGH);   
  }
 
