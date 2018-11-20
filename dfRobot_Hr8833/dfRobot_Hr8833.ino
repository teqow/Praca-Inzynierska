int IA1=10;
int IA2=12;
int IB1=11;
int IB2=13;
 
void setup() {
     pinMode(IA1, OUTPUT);
     pinMode(IA2, OUTPUT);
     pinMode(IB1, OUTPUT);
     pinMode(IB2, OUTPUT);
}

void loop() {
 MA1_Forward(120);//Motor MA1 forward; PWM speed control

 MB1_Forward(120);//Motor MA2 forward; PWM speed control

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
