/*
Dekatron Pendulum Example

modified March 25, 2017
by Michael Moorrees
*/

int D_count = 0;
int i_count = 0;
int state = 0;
int LED = 0;          // Test LED
int Guide1 = 5;       // Guide 1 - G1 pin of 2-guide Dekatron
int Guide2 = 6;       // Guide 2 - G2 pin of 2-guide Dekatron
int Index = 7;        // Index   - NDX input pin. High when glow at K0
boolean Dir = false;  // Direction Flag, true for clockwise
int Ndx = 0;          // K0 index indicator variable
int Acceleration = 0;
int Counter = 0;

const int  buttonPin = 10;    // the pin that the pushbutton is attached to
int buttonPushCounter = 0;   // counter for the number of button presses
int buttonState = 0;         // current state of the button
int lastButtonState = 0;     // previous state of the button


// Dekatron Stepper
void G_step(int CINT)
{
	if (CINT > 2) CINT = 0;
	if (CINT == 0)
	{
		digitalWrite(Guide1, LOW);
		digitalWrite(Guide2, LOW);
	}
	if (CINT == 1)
	{
		digitalWrite(Guide1, HIGH);
		digitalWrite(Guide2, LOW);
	}
	if (CINT == 2)
	{
		digitalWrite(Guide1, LOW);
		digitalWrite(Guide2, HIGH);
	}
}

// setup() runs once, at reset, to initialize system
void setup() {
	pinMode(Guide1, OUTPUT);
	pinMode(Guide2, OUTPUT);
	pinMode(Index, INPUT);
	pinMode(LED, OUTPUT);

	// initialize the button pin as a input:
	pinMode(buttonPin, INPUT_PULLUP);

	D_count = 0;
	i_count = 0;
	state = 0;
	Ndx = 0;
	Dir = true;
	G_step(D_count);
	digitalWrite(LED, LOW);
	Acceleration = 0;
	Counter = 0;
}


void buttonstate() {
	// read the pushbutton input pin:
	buttonState = digitalRead(buttonPin);

	// compare the buttonState to its previous state
	if (buttonState != lastButtonState) {
		// if the state has changed, increment the counter
		if (buttonState == HIGH) {
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
		delay(50);
	}
	// save the current state as the last state, for next time through the loop
	lastButtonState = buttonState;


	// turns on the LED every four button pushes by checking the modulo of the
	// button push counter. the modulo function gives you the remainder of the
	// division of two numbers:
	if (buttonPushCounter % 1 == 0) {
		Dir = Dir;
	}
	else {
		Dir = !Dir;
	}

}

// the loop function runs over and over again forever
void loop() {
	Ndx = digitalRead(Index);			// Sample for glow at K0
	if (Ndx) digitalWrite(LED, HIGH);
	if (!Ndx) digitalWrite(LED, LOW);
	if (Ndx && state == 0)				// If yes, and state = 0,
	{
		state = 1;						// then, set to state 1 to ignore Ndx for 5mS        
		i_count = 0;					// clr ignore counter (i_count)       
		//Dir = !Dir;					// flip direction (Dir)
		buttonstate();
		;

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
	
	//Serial.println(Acceleration);
	Serial.println(Counter);
	if (D_count > 2) D_count = 0;
	if (D_count < 0) D_count = 2;
	G_step(D_count);					// Step Dekatron
}