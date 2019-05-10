#include "IRremote.h"
int bright;
int before;
int green1Out = 2; //connect your LED to pin 2
int green2Out = 3; //connect your LED to pin 3 
int yellow1Out = 5; //connect your LED to pin 5 
int yellow2Out = 6; //connect your LED to pin 6
int red1Out = 8; //connect your LED to pin 8 
int red2Out = 9; //connect your LED to pin 9 
int receiver = 11; // Signal Pin of IR receiver to Arduino Digital Pin 11

/*-----( Declare objects )-----*/
IRrecv irrecv(receiver);     // create instance of 'irrecv'
decode_results results;      // create instance of 'decode_results'

void setup()   /*----( SETUP: RUNS ONCE )----*/
{
  Serial.begin(9600);
  Serial.println("IR Receiver Button Decode"); 
  irrecv.enableIRIn(); // Start the receiver
  pinMode(green1Out, OUTPUT);
  pinMode(green2Out, OUTPUT);
  pinMode(yellow1Out, OUTPUT);
  pinMode(yellow2Out, OUTPUT);
  pinMode(red1Out, OUTPUT);
  pinMode(red2Out, OUTPUT);

}/*--(end setup )---*/


void loop()   /*----( LOOP: RUNS CONSTANTLY )----*/
{
  if (irrecv.decode(&results)) // have we received an IR signal?

  {
    translateIR(); 
    irrecv.resume(); // receive the next value
  }  
}/* --(end main loop )-- */

/*-----( Function )-----*/
void translateIR() // takes action based on IR code received

// describing Remote IR codes 

{

  switch(results.value)

  {

  case 0xFFE01F: Serial.println(" -");   digitalWrite(green1Out, LOW); digitalWrite(green2Out, LOW); digitalWrite(yellow1Out, LOW); digitalWrite(yellow2Out, LOW); digitalWrite(red1Out, LOW); digitalWrite(red2Out, LOW); break;
  case 0xFF22DD: Serial.println(" LEFT");    break;
  case 0xFF02FD: Serial.println(" -OK-");    break;
  case 0xFFC23D: Serial.println(" RIGHT");   break;
  case 0xFFA857: Serial.println(" REVERSE"); break;
  case 0xFF30CF: Serial.println(" 1"); digitalWrite(green1Out, HIGH); digitalWrite(green2Out, HIGH); digitalWrite(yellow1Out, LOW); digitalWrite(yellow2Out, LOW); digitalWrite(red1Out, LOW); digitalWrite(red2Out, LOW);  break;
  case 0xFF18E7: Serial.println(" 2"); digitalWrite(green1Out, LOW); digitalWrite(green2Out, LOW); digitalWrite(yellow1Out, HIGH); digitalWrite(yellow2Out, HIGH); digitalWrite(red1Out, LOW); digitalWrite(red2Out, LOW);   break;
  case 0xFF7A85: Serial.println(" 3"); digitalWrite(green1Out, LOW); digitalWrite(green2Out, LOW); digitalWrite(yellow1Out, LOW); digitalWrite(yellow2Out, LOW); digitalWrite(red1Out, HIGH); digitalWrite(red2Out, HIGH);    break;
  case 0xFF10EF: Serial.println(" 4");   
  digitalWrite(green1Out, HIGH);   // turn the LED on (HIGH is the voltage level)
  delay(23);              // wait for a second
  digitalWrite(green1Out, LOW);    // turn the LED off by making the voltage LOW
  delay(23);              // wait for a second
  
  digitalWrite(green2Out, HIGH);   // turn the LED on (HIGH is the voltage level)
  delay(23);              // wait for a second
  digitalWrite(green2Out, LOW);    // turn the LED off by making the voltage LOW
  delay(23);              // wait for a second
  
  digitalWrite(yellow1Out, HIGH);   // turn the LED on (HIGH is the voltage level)
  delay(23);              // wait for a second
  digitalWrite(yellow1Out, LOW);    // turn the LED off by making the voltage LOW
  delay(23);              // wait for a second

  digitalWrite(yellow2Out, HIGH);   // turn the LED on (HIGH is the voltage level)
  delay(23);              // wait for a second
  digitalWrite(yellow2Out, LOW);    // turn the LED off by making the voltage LOW
  delay(23);              // wait for a second

  digitalWrite(red1Out, HIGH);   // turn the LED on (HIGH is the voltage level)
  delay(23);              // wait for a second
  digitalWrite(red1Out, LOW);    // turn the LED off by making the voltage LOW
  delay(23);              // wait for a second
  
  digitalWrite(red2Out, HIGH);   // turn the LED on (HIGH is the voltage level)
  delay(23);              // wait for a second
  digitalWrite(red2Out, LOW);    // turn the LED off by making the voltage LOW
  delay(23);              // wait for a second
  break;
  case 0xFF38C7: Serial.println(" 5"); digitalWrite(green1Out, HIGH); digitalWrite(green2Out, HIGH); digitalWrite(yellow1Out, HIGH); digitalWrite(yellow2Out, HIGH); digitalWrite(red1Out, HIGH); digitalWrite(red2Out, HIGH);  break;
 
  case 0xfff2f: Serial.println(" 7");    break;
  case 0xF238C7: Serial.println(" 8");    break;
  case 0xffffe4: Serial.println(" 9");    break;
  case 0xFF42BD: Serial.println(" *");    break;
    case 0xFF52AD: Serial.println(" #");    break;
  case 0xFFFFFFFF: Serial.println(" REPEAT");break;  

  default: 
    Serial.println(results.value, HEX);
    if (results.value == 0xFF5AA5){ Serial.println(" 6"); digitalWrite(green1Out, HIGH); digitalWrite(green2Out, HIGH); digitalWrite(yellow1Out, LOW); digitalWrite(yellow2Out, LOW); digitalWrite(red1Out, HIGH); digitalWrite(red2Out, HIGH);}
  

  }// End Case

  delay(500); // Do not get immediate repeat


} //END translateIR
