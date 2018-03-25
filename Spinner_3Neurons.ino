/*
Dekatron Pendulum Example

modified March 25, 2017
by Michael Moorrees
*/

int D_count = 0;
int i_count = 0;
int state = 0;
int LED = 13;          // Test LED


int Guide1A = 52;       // Guide 1 - G1 pin of 2-guide Dekatron
int Guide2A = 50;       // Guide 2 - G2 pin of 2-guide Dekatron
int IndexA = 48;        // Index   - NDX input pin. High when glow at K0


int Guide1B = 44;       // Guide 1 - G1 pin of 2-guide Dekatron
int Guide2B = 42;       // Guide 2 - G2 pin of 2-guide Dekatron
int IndexB = 40;        // Index   - NDX input pin. High when glow at K0


int Guide1C = 36;       // Guide 1 - G1 pin of 2-guide Dekatron
int Guide2C = 34;       // Guide 2 - G2 pin of 2-guide Dekatron
int IndexC = 32;        // Index   - NDX input pin. High when glow at K0

int Guide1D = 28;       // Guide 1 - G1 pin of 2-guide Dekatron
int Guide2D = 26;       // Guide 2 - G2 pin of 2-guide Dekatron
int IndexD = 24;        // Index   - NDX input pin. High when glow at K0



boolean Dir = true;  // Direction Flag, true for clockwise

int Ndx = 0;          // K0 IndexA indicator variable
int Acceleration = 0;
int Counter = 0;

//const int  buttonPin = 10;    // the pin that the pushbutton is attached to
//int buttonPushCounter = 0;   // counter for the number of button presses
//int buttonState = 0;         // current state of the button
//int lastButtonState = 0;     // previous state of the button


// Dekatron Stepper
void G_step(int CINT)
{
	if (CINT > 2) CINT = 0;
	if (CINT == 0)
	{
		digitalWrite(Guide1A, LOW);
		digitalWrite(Guide2A, LOW);
		
		digitalWrite(Guide1B, LOW);
		digitalWrite(Guide2B, LOW);
		
		digitalWrite(Guide1C, LOW);
		digitalWrite(Guide2C, LOW);
		

		digitalWrite(Guide1D, LOW);
		digitalWrite(Guide2D, LOW);


	}
	if (CINT == 1)
	{
		digitalWrite(Guide1A, HIGH);
		digitalWrite(Guide2A, LOW);

		digitalWrite(Guide1B, HIGH);
		digitalWrite(Guide2B, LOW);


		digitalWrite(Guide1C, HIGH);
		digitalWrite(Guide2C, LOW);


		digitalWrite(Guide1D, HIGH);
		digitalWrite(Guide2D, LOW);

	}
	if (CINT == 2)
	{
		digitalWrite(Guide1A, LOW);
		digitalWrite(Guide2A, HIGH);

		digitalWrite(Guide1B, LOW);
		digitalWrite(Guide2B, HIGH);


		digitalWrite(Guide1C, LOW);
		digitalWrite(Guide2C, HIGH);


		digitalWrite(Guide1D, LOW);
		digitalWrite(Guide2D, HIGH);

	}
}

// setup() runs once, at reset, to initialize system
void setup() {
	pinMode(Guide1A, OUTPUT);
	pinMode(Guide2A, OUTPUT);
	pinMode(IndexA, INPUT);


	pinMode(Guide1B, OUTPUT);
	pinMode(Guide2B, OUTPUT);
	pinMode(IndexB, INPUT);

	
	pinMode(Guide1C, OUTPUT);
	pinMode(Guide2C, OUTPUT);
	pinMode(IndexC, INPUT);

	pinMode(Guide1D, OUTPUT);
	pinMode(Guide2D, OUTPUT);
	pinMode(IndexD, INPUT);



	pinMode(LED, OUTPUT);

	// initialize the button pin as a input:
	//pinMode(buttonPin, INPUT_PULLUP);

	
}

/*
int buttonstate() {
	// read the pushbutton input pin:
	buttonState = digitalRead(buttonPin);

	// compare the buttonState to its previous state
	if (buttonState != lastButtonState) {
		// if the state has changed, increment the counter
		if (buttonState == LOW) {
			// if the current state is HIGH then the button went from off to on:
			buttonPushCounter++;
			Serial.println("on");
			Serial.print("number of button pushes: ");
			Serial.println(buttonPushCounter);
		}
		else {
			// if the current state is LOW then the button went from on to off:
			Serial.println("off");
		}
		// Delay a little bit to avoid bouncing
		delay(10);
	}
	// save the current state as the last state, for next time through the loop
	lastButtonState = buttonState;


	// turns on the LED every four button pushes by checking the modulo of the
	// button push counter. the modulo function gives you the remainder of the
	// division of two numbers:
	
	//if (buttonPushCounter % 2 == 0)
	

	return buttonPushCounter;
}

*/


// the loop function runs over and over again forever
void loop() {
	
	
	
//	buttonstate();
	
	Ndx = digitalRead(IndexA);			// Sample for glow at K0
	Ndx = digitalRead(IndexB);
	Ndx = digitalRead(IndexC);
	Ndx = digitalRead(IndexD);


	if (Ndx) digitalWrite(LED, HIGH);
	if (!Ndx) digitalWrite(LED, LOW);
	if (Ndx && state == 0)				// If yes, and state = 0,
	{
		state = 1;						// then, set to state 1 to ignore Ndx for 5mS        
		i_count = 0;					// clr ignore counter (i_count)       
		//Dir = !Dir;					// flip direction (Dir)
	

//	if (buttonPushCounter == 1) {
//			Dir = Dir;
//		}
//		else {
//			Dir = !Dir;
//			buttonPushCounter = 0;
//		}

	}
	if (Dir)
	{
		D_count++;						// increment D_count for clockwise motion
		i_count++;						// increment ignore period counter
	}
	else
	{
		D_count--;						// decrement D_count for counter-clockwise motion
		i_count++;						// increment ignore period counter
	}
	if (i_count == 5)					// at count of 5, stop ignoring Ndx, to allow looking for K0 glow.
	{
		state = 0;
		//digitalWrite(LED, LOW);  
	}


	if (Counter >= 1000) //if (Ndx)Acceleration = Acceleration + pow(2, Acceleration); // if you use 200  (or 50 with flip on) as the counter size it's an interesting effect.
	{
		Counter = 0;
		Acceleration = 0;
	}
	Counter++;

	//delay(1000); //Uncomment this to just count seconds.
	delay(Acceleration);
	
	if (Ndx)Acceleration = Acceleration + pow(1, Acceleration);
	//if (Ndx)Acceleration = Acceleration + pow(2, Acceleration);
	//A101 Dec has 64 cathodes ?
	
	Serial.println(Acceleration);
	//Serial.println(Counter);
	if (D_count > 2) D_count = 0;
	if (D_count < 0) D_count = 2;
	G_step(D_count);					// Step Dekatron
}