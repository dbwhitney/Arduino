//adapted from
//https://www.youtube.com/user/greatscottlab

#include <IRremote.h>
int bright;
int before;
int yellow1Out=2; //connect your LED to pin 2
int yellow2Out=3; //connect your LED to pin 3 
int blue1Out=4; //connect your LED to pin 4 
int blue2Out=5; //connect your LED to pin 5 
int green1Out=6; //connect your LED to pin 6
int green2Out=7; //connect your LED to pin 7
int red1Out=8; //connect your LED to pin 8 
int red2Out=9; //connect your LED to pin 9 


int RECV_PIN = 11; //data out of IR receiver connects to pin 11

IRrecv irrecv(RECV_PIN);

decode_results results;

void setup(){
  irrecv.enableIRIn(); // start the receiver
  before=0; //LED is turned off
//  pinMode(out,OUTPUT);

  pinMode(green1Out, OUTPUT);
  pinMode(green2Out, OUTPUT);
  pinMode(yellow1Out, OUTPUT);
  pinMode(yellow2Out, OUTPUT);
  pinMode(red1Out, OUTPUT);
  pinMode(red2Out, OUTPUT);
 }

void loop() {
  if (irrecv.decode(&results)) {

  //Green
  if (results.value==0xFF30CF){ //1 Button Code to turn the LED ON/OFF
    if(before!=1){ // if the LED was turned off, then we turn it on 
      digitalWrite(green1Out,LOW);
      digitalWrite(green2Out,LOW);
      digitalWrite(yellow1Out,LOW);
      digitalWrite(yellow2Out,LOW);
      digitalWrite(red1Out,HIGH);
      digitalWrite(red2Out,HIGH);
      before=1; //LED is now turned on
    }
    else{
      digitalWrite(green1Out,LOW); //if the LED was turned on, then we turn it off
      digitalWrite(green2Out, LOW);
      before=0; 
    }}
  //Yellow
  if (results.value==0xFF18E7){ //2 Button Code to turn the LED ON/OFF
    if(before!=2){ //if the LED was turned off, then we turn it on 
      digitalWrite(green1Out,LOW);
      digitalWrite(green2Out,LOW);
      digitalWrite(yellow1Out,HIGH);
      digitalWrite(yellow2Out,HIGH);
      digitalWrite(red1Out,LOW);
      digitalWrite(red2Out,LOW);
      before=2; //LED is now turned on
    }
    else{
      digitalWrite(yellow1Out,LOW); //if the LED was turned on, then we turn it off
      digitalWrite(yellow2Out,LOW);
      before=0;
    }}
    //Red
    if (results.value==0xFF7A85){ //3 Button Code to turn the LED ON/OFF
    if(before!=3){ // if the LED was turned off, then we turn it on 
      digitalWrite(green1Out,HIGH);
      digitalWrite(green2Out,HIGH);
      digitalWrite(yellow1Out,LOW);
      digitalWrite(yellow2Out,LOW);
      digitalWrite(red1Out,LOW);
      digitalWrite(red2Out,LOW);
      before=3; //LED is now turned on
    }
    else{
      digitalWrite(red1Out,LOW); //if the LED was turned on, then we turn it off
      digitalWrite(red2Out,LOW); 
      before=0;
        }}
  //ALL
  if (results.value==0xFF10EF){ //4 button Code to turn the LED ON/OFF
    if(before!=4){ // if the LED was turned off, then we turn it on 
      digitalWrite(green1Out,HIGH);
      digitalWrite(green2Out,HIGH);
      digitalWrite(yellow1Out,HIGH);
      digitalWrite(yellow2Out,HIGH);
      digitalWrite(red1Out,HIGH);
      digitalWrite(red2Out,HIGH);
      before=4; //LED is now turned on
    }
    else{
      digitalWrite(green1Out,LOW);
      digitalWrite(green2Out,LOW);
      digitalWrite(yellow1Out,LOW);
      digitalWrite(yellow2Out,LOW);
      digitalWrite(red1Out,LOW);
      digitalWrite(red2Out,LOW);
      before=0; 
    }}

     }
  //FF38C7 5 Button
  irrecv.resume();
}




