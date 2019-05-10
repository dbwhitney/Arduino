/*
* IRremote: IRrecvDemo - demonstrates receiving IR codes with IRrecv
* An IR detector/demodulator must be connected to the input RECV_PIN.
* Version 0.1 July, 2009
* Copyright 2009 Ken Shirriff
* http://arcfn.com
*/

#include <IRremote.h>

int RECV_PIN = 11;

IRrecv irrecv(RECV_PIN);

decode_results results;

void setup()
{
	Serial.begin(9600);
	irrecv.enableIRIn(); // Start the receiver
}

void loop() {
	if (irrecv.decode(&results)) {
		long int decCode = results.value;
		String hexCode = String(decCode, HEX);
		String decodedSignal = decodeSignal(hexCode);

		if (decodedSignal != "unknown")
		{
			Serial.print("dec: ");
			Serial.print(hexCode);
			Serial.print("|");
			Serial.print(decCode);
			Serial.print("|");
			Serial.print(decodedSignal);
			Serial.println();
		}
		//    Serial.println(, HEX);
		irrecv.resume(); // Receive the next value
	}
}

String decodeSignal(String hex)
{
	hex.toUpperCase();
	if (hex == "FFA25D") return "power";
	if (hex == "FF629D") return "mode";
	if (hex == "FFE21D") return "mute";

	if (hex == "FF22DD") return "play";
	if (hex == "FF02FD") return "rewind";
	if (hex == "FFC23D") return "forward";

	if (hex == "FFE01F") return "eq";
	if (hex == "FFA857") return "-";
	if (hex == "FF906F") return "+";

	if (hex == "FF6897") return "0";
	if (hex == "FF9867") return "repeat";
	if (hex == "FFB04F") return "usd";

	if (hex == "FF30CF") return "1";
	if (hex == "FF18E7") return "2";
	if (hex == "FF7A85") return "3";

	if (hex == "FF10EF") return "4";
	if (hex == "FF38C7") return "5";
	if (hex == "FF5AA5") return "6";

	if (hex == "FF42BD") return "7";
	if (hex == "FF4AB5") return "8";
	if (hex == "FF52AD") return "9";
	return "unknown";

}
