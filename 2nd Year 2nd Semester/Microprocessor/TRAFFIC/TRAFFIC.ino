int input = 0;
int red = 10;

void setup() {
  // put your setup code here, to run once:
  pinMode(12,INPUT);
  pinMode(8,OUTPUT);
  pinMode(9,OUTPUT);  
  pinMode(13,OUTPUT);
}

void loop() {
  // put your main code here, to run repeatedly:
  input=digitalRead(12);
  if(input == HIGH)
  {
     digitalWrite(8,HIGH); 
     digitalWrite(9,LOW);
     digitalWrite(13,LOW);
     red = LOW;
  }
  else if(red == HIGH){
     digitalWrite(8,LOW);
     digitalWrite(9,LOW);
     digitalWrite(13,HIGH);
  }
  else{
     delay(1000);
     digitalWrite(8,LOW); 
     digitalWrite(9,HIGH);
     digitalWrite(13,LOW);
     delay(2000);
     digitalWrite(8,LOW);
     digitalWrite(9,LOW);
     digitalWrite(13,HIGH);
     red = HIGH;
  }
}
