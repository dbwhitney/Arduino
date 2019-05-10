int flame=A0;
int LED=13;
int val=0;
void setup() 
{ pinMode(LED,OUTPUT);
pinMode(flame,INPUT);
Serial.begin(9600);}  
void loop() 
{
  val=analogRead(flame);
  Serial.println(val);
if(val>=600)
  { digitalWrite(LED,HIGH); } 
else 
  { digitalWrite(LED,LOW); } 
}
