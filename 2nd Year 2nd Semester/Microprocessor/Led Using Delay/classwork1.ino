

void setup() {
  // put your setup code here, to run once:
 
  pinMode(8,OUTPUT);
  pinMode(9,OUTPUT);  
  pinMode(13,OUTPUT);
}

void loop() {
  // put your main code here, to run repeatedly:
  
     digitalWrite(8,HIGH); 
     digitalWrite(9,LOW);
     digitalWrite(13,LOW);
     delay(5000);
 
     digitalWrite(8,LOW); 
     digitalWrite(9,HIGH);
     digitalWrite(13,LOW);
     delay(3000);
     
     digitalWrite(8,LOW);
     digitalWrite(9,LOW);
     digitalWrite(13,HIGH);
     
     delay(1500);
  
}
