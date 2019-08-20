/*
Dekatron Spinner Example

modified March 25, 2017
by Michael Moorrees f
*/




int D_count = 0;
int i_count = 0;
int state = 0;
int LED = 13;          // Test LED

// WHITE  = G1
// YELLOW = G2
// PURPLE = NDX

//PWM PINS
int Guide1A = 11;       // Guide 1 - G1 pin of 2-guide Dekatron
int Guide2A = 12;       // Guide 2 - G2 pin of 2-guide Dekatron
int IndexA = 13;        // Index   - NDX input pin. High when glow at K0 A

int Guide1B = 9;       // Guide 1 - G1 pin of 2-guide Dekatron
int Guide2B = 8;       // Guide 2 - G2 pin of 2-guide Dekatron
int IndexB = 10;        // Index   - NDX input pin. High when glow at K0 B

int Guide1C = 6;       // Guide 1 - G1 pin of 2-guide Dekatron
int Guide2C = 5;       // Guide 2 - G2 pin of 2-guide Dekatron
int IndexC = 7;        // Index   - NDX input pin. High when glow at K0 C

int Guide1D = 3;       // Guide 1 - G1 pin of 2-guide Dekatron
int Guide2D = 2;       // Guide 2 - G2 pin of 2-guide Dekatron
int IndexD = 4;        // Index   - NDX input pin. High when glow at K0 D

int Guide1E = 23;       // Guide 1 - G1 pin of 2-guide Dekatron
int Guide2E = 22;       // Guide 2 - G2 pin of 2-guide Dekatron
int IndexE = 24;        // Index   - NDX input pin. High when glow at K0 E

int Guide1F = 26;       // Guide 1 - G1 pin of 2-guide Dekatron
int Guide2F = 25;       // Guide 2 - G2 pin of 2-guide Dekatron
int IndexF = 27;        // Index   - NDX input pin. High when glow at K0 F

int Guide1G =29;       // Guide 1 - G1 pin of 2-guide Dekatron
int Guide2G =28;       // Guide 2 - G2 pin of 2-guide Dekatron
int IndexG = 30;        // Index   - NDX input pin. High when glow at K0 G

int Guide1H = 32;       // Guide 1 - G1 pin of 2-guide Dekatron
int Guide2H = 31;       // Guide 2 - G2 pin of 2-guide Dekatron
int IndexH = 33;        // Index   - NDX input pin. High when glow at K0 H

int Guide1I = 35;       // Guide 1 - G1 pin of 2-guide Dekatron
int Guide2I = 34;       // Guide 2 - G2 pin of 2-guide Dekatron
int IndexI= 36;        // Index   - NDX input pin. High when glow at K0 I

int Guide1J = 38;       // Guide 1 - G1 pin of 2-guide Dekatron
int Guide2J = 37;       // Guide 2 - G2 pin of 2-guide Dekatron
int IndexJ = 39;        // Index   - NDX input pin. High when glow at K0 J

int Guide1K = 41;       // Guide 1 - G1 pin of 2-guide Dekatron
int Guide2K = 40;       // Guide 2 - G2 pin of 2-guide Dekatron
int IndexK = 42;        // Index   - NDX input pin. High when glow at K0 K

int Guide1L = 44;       // Guide 1 - G1 pin of 2-guide Dekatron
int Guide2L = 43;       // Guide 2 - G2 pin of 2-guide Dekatron
int IndexL = 45;        // Index   - NDX input pin. High when glow at K0 L

int Guide1M = 47;       // Guide 1 - G1 pin of 2-guide Dekatron
int Guide2M = 46;       // Guide 2 - G2 pin of 2-guide Dekatron
int IndexM = 48;        // Index   - NDX input pin. High when glow at K0 M

//DIGITAL PINS
// WHITE  = G1
// YELLOW = G2
// PURPLE = NDX



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

		digitalWrite(Guide1E, LOW);
		digitalWrite(Guide2E, LOW);

		digitalWrite(Guide1F, LOW);
		digitalWrite(Guide2F, LOW);

		digitalWrite(Guide1G, LOW);
		digitalWrite(Guide2G, LOW);

		digitalWrite(Guide1H, LOW);
		digitalWrite(Guide2H, LOW);

		digitalWrite(Guide1I, LOW);
		digitalWrite(Guide2I, LOW);

		digitalWrite(Guide1J, LOW);
		digitalWrite(Guide2J, LOW);

		digitalWrite(Guide1K, LOW);
		digitalWrite(Guide2K, LOW);

		digitalWrite(Guide1L, LOW);
		digitalWrite(Guide2L, LOW);

		digitalWrite(Guide1M, LOW);
		digitalWrite(Guide2M, LOW);



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

		digitalWrite(Guide1E, HIGH);
		digitalWrite(Guide2E, LOW);

		digitalWrite(Guide1F, HIGH);
		digitalWrite(Guide2F, LOW);

		digitalWrite(Guide1G, HIGH);
		digitalWrite(Guide2G, LOW);

		digitalWrite(Guide1H, HIGH);
		digitalWrite(Guide2H, LOW);

		digitalWrite(Guide1I, HIGH);
		digitalWrite(Guide2I, LOW);

		digitalWrite(Guide1J, HIGH);
		digitalWrite(Guide2J, LOW);

		digitalWrite(Guide1K, HIGH);
		digitalWrite(Guide2K, LOW);

		digitalWrite(Guide1L, HIGH);
		digitalWrite(Guide2L, LOW);

		digitalWrite(Guide1M, HIGH);
		digitalWrite(Guide2M, LOW);



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

		digitalWrite(Guide1E, LOW);
		digitalWrite(Guide2E, HIGH);

		digitalWrite(Guide1F, LOW);
		digitalWrite(Guide2F, HIGH);

		digitalWrite(Guide1G, LOW);
		digitalWrite(Guide2G, HIGH);
		
		digitalWrite(Guide1H, LOW);
		digitalWrite(Guide2H, HIGH);
		
		digitalWrite(Guide1I, LOW);
		digitalWrite(Guide2I, HIGH);
		
		digitalWrite(Guide1J, LOW);
		digitalWrite(Guide2J, HIGH);

		digitalWrite(Guide1K, LOW);
		digitalWrite(Guide2K, HIGH);
		
		digitalWrite(Guide1L, LOW);
		digitalWrite(Guide2L, HIGH);

		digitalWrite(Guide1M, LOW);
		digitalWrite(Guide2M, HIGH);
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

	pinMode(Guide1E, OUTPUT);
	pinMode(Guide2E, OUTPUT);
	pinMode(IndexE, INPUT);

	pinMode(Guide1F, OUTPUT);
	pinMode(Guide2F, OUTPUT);
	pinMode(IndexF, INPUT);

	pinMode(Guide1G, OUTPUT);
	pinMode(Guide2G, OUTPUT);
	pinMode(IndexG, INPUT);

	pinMode(Guide1H, OUTPUT);
	pinMode(Guide2H, OUTPUT);
	pinMode(IndexH, INPUT);

	pinMode(Guide1I, OUTPUT);
	pinMode(Guide2I, OUTPUT);
	pinMode(IndexI, INPUT);

	pinMode(Guide1J, OUTPUT);
	pinMode(Guide2J, OUTPUT);
	pinMode(IndexJ, INPUT);

	pinMode(Guide1K, OUTPUT);
	pinMode(Guide2K, OUTPUT);
	pinMode(IndexK, INPUT);

	pinMode(Guide1L, OUTPUT);
	pinMode(Guide2L, OUTPUT);
	pinMode(IndexL, INPUT);

	pinMode(Guide1M, OUTPUT);
	pinMode(Guide2M, OUTPUT);
	pinMode(IndexM, INPUT);



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
	Ndx = digitalRead(IndexE);			// Sample for glow at K0
	Ndx = digitalRead(IndexF);
	Ndx = digitalRead(IndexG);
	Ndx = digitalRead(IndexH);
	Ndx = digitalRead(IndexI);			// Sample for glow at K0
	Ndx = digitalRead(IndexJ);
	Ndx = digitalRead(IndexK);
	Ndx = digitalRead(IndexL);
	Ndx = digitalRead(IndexM);			// Sample for glow at K0
	



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