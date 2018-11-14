int czujnik1 = A0; 
int czujnik2 = A1;

void setup(){
  Serial.begin(9600);        //inicjalizacja monitora szeregowego
  Serial.println("Test czujnika odbiciowego"); 
}

void loop(){
  int odczyt1 = analogRead(czujnik1);
  int odczyt2 = analogRead(czujnik2);       
  
  Serial.print("czujnik 1 ");
  Serial.println(odczyt1);
  Serial.print("czujnik 2 ");
  Serial.println(odczyt2);
  
  delay(2000);                         
}
 
