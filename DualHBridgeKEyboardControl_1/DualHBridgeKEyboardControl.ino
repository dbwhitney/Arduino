//Code by Reichenstein7 (thejamerson.com)

//Keyboard Controls:
//
// 1 -Motor 1 Left
// 2 -Motor 1 Stop
// 3 -Motor 1 Right
//
// 4 -Motor 2 Left
// 5 -Motor 2 Stop
// 6 -Motor 2 Right

// Declare L298N Dual H-Bridge Motor Controller directly since there is not a library to load.

// Motor 1
int m1f = 4;  //IN A Forward Motor 1
int m1r = 5;  //IN B Forward motor 2
int m2f = 7;  //IN D reverse motor 1
int m2r = 6;  //IN C reverse motor 2

void setup() {  // Setup runs once per reset
				// initialize serial communication @ 9600 baud:
	Serial.begin(9600);

	//Define L298N Dual H-Bridge Motor Controller Pins

	pinMode(m1f, OUTPUT);
	pinMode(m1r, OUTPUT);
	pinMode(m2f, OUTPUT);
	pinMode(m2r, OUTPUT);

	Serial.println("Ready to go!");
}

void loop() {

	// Initialize the Serial interface:

	if (Serial.available() > 0) {
		int inByte = Serial.read();
		int speed; // Local variable

		switch (inByte) {

			//______________Motor 1______________

		case '1': //  Forward
			digitalWrite(m1r, LOW);
			digitalWrite(m2r, LOW);
			digitalWrite(m1f, HIGH);
			digitalWrite(m2f, HIGH);
			Serial.println("Forward"); // Prints out “Motor 1 Forward” on the serial monitor
			Serial.println("   "); // Creates a blank line printed on the serial monitor
			break;

		case '2': //  Stop (Freespin)
			digitalWrite(m1r, LOW);
			digitalWrite(m1f, LOW);
			digitalWrite(m2r, LOW);
			digitalWrite(m2f, LOW);
			Serial.println("Stop");
			Serial.println("   ");
			break;

		case '3': //  Reverse
			digitalWrite(m1r, HIGH);
			digitalWrite(m2r, HIGH);
			digitalWrite(m1f, LOW);
			digitalWrite(m2f, LOW);
			Serial.println("Reverse");
			Serial.println("   ");
			break;

			//______________Motor 2______________

		case '4': // Motor 2 Forward
			digitalWrite(m1r, HIGH);
			digitalWrite(m2r, LOW);
			digitalWrite(m1f, LOW);
			digitalWrite(m2f, HIGH);
			Serial.println("Turn 1");
			Serial.println("   ");
			break;

		case '5': // Motor 1 Stop (Freespin)
			digitalWrite(m1r, LOW);
			digitalWrite(m1f, LOW);
			digitalWrite(m2r, LOW);
			digitalWrite(m2f, LOW);
			Serial.println("Stop");
			Serial.println("   ");
			break;

		case '6': // Motor 2 Reverse
			digitalWrite(m1r, LOW);
			digitalWrite(m2r, HIGH);
			digitalWrite(m1f, HIGH);
			digitalWrite(m2f, LOW);
			Serial.println("Turn 2");
			Serial.println("   ");
			break;

		default:
			// turn all the connections off if an unmapped key is pressed:
			for (int thisPin = 2; thisPin < 11; thisPin++) {
				digitalWrite(thisPin, LOW);
			}
		}
	}
}

