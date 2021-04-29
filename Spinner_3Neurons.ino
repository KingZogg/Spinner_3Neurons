/*
Dekatron Pendulum Example

modified March 25, 2017
by Michael Moorrees
*/

int D_count = 0;
int i_count = 0;
int state = 0;
int LED = 13;          // Test LED

//Dek 15
int Guide1A = 63;       // Guide 1 - G1 pin of 2-guide Dekatron
int Guide2A = 62;       // Guide 2 - G2 pin of 2-guide Dekatron
int IndexA = 61;        // Index   - NDX input pin. High when glow at K0

//Dek 14
int Guide1B = 66;       // Guide 1 - G1 pin of 2-guide Dekatron
int Guide2B = 65;       // Guide 2 - G2 pin of 2-guide Dekatron
int IndexB = 64;        // Index   - NDX input pin. High when glow at K0

//Dek 13
int Guide1C = 69;       // Guide 1 - G1 pin of 2-guide Dekatron
int Guide2C = 68;       // Guide 2 - G2 pin of 2-guide Dekatron
int IndexC = 67;        // Index   - NDX input pin. High when glow at K0

//Dek 12
int Guide1D = 34;       // Guide 1 - G1 pin of 2-guide Dekatron
int Guide2D = 38;       // Guide 2 - G2 pin of 2-guide Dekatron
int IndexD = 36;        // Index   - NDX input pin. High when glow at K0

//Dek 11
int Guide1E = 40;       // Guide 1 - G1 pin of 2-guide Dekatron
int Guide2E = 42;       // Guide 2 - G2 pin of 2-guide Dekatron
int IndexE = 46;        // Index   - NDX input pin. High when glow at K0

//Dek 10
int Guide1F = 41;       // Guide 1 - G1 pin of 2-guide Dekatron
int Guide2F = 45;       // Guide 2 - G2 pin of 2-guide Dekatron
int IndexF = 43;        // Index   - NDX input pin. High when glow at K0

//Dek 9
int Guide1G = 35;       // Guide 1 - G1 pin of 2-guide Dekatron
int Guide2G = 39;       // Guide 2 - G2 pin of 2-guide Dekatron
int IndexG = 37;        // Index   - NDX input pin. High when glow at K0

//Dek 8
int Guide1H = 29;       // Guide 1 - G1 pin of 2-guide Dekatron
int Guide2H = 31;       // Guide 2 - G2 pin of 2-guide Dekatron
int IndexH = 33;        // Index   - NDX input pin. High when glow at K0

//Dek 7
int Guide1I = 25;       // Guide 1 - G1 pin of 2-guide Dekatron
int Guide2I = 23;       // Guide 2 - G2 pin of 2-guide Dekatron
int IndexI = 27;        // Index   - NDX input pin. High when glow at K0

//Dek 6
int Guide1J = 26;       // Guide 1 - G1 pin of 2-guide Dekatron
int Guide2J = 24;       // Guide 2 - G2 pin of 2-guide Dekatron
int IndexJ = 22;        // Index   - NDX input pin. High when glow at K0

//Dek 5
int Guide1K = 30;       // Guide 1 - G1 pin of 2-guide Dekatron
int Guide2K = 32;       // Guide 2 - G2 pin of 2-guide Dekatron
int IndexK = 28;        // Index   - NDX input pin. High when glow at K0

//Dek 4
int Guide1L = 3;       // Guide 1 - G1 pin of 2-guide Dekatron
int Guide2L = 4;       // Guide 2 - G2 pin of 2-guide Dekatron
int IndexL = 2;        // Index   - NDX input pin. High when glow at K0

//Dek 3
int Guide1M = 6;       // Guide 1 - G1 pin of 2-guide Dekatron
int Guide2M = 7;       // Guide 2 - G2 pin of 2-guide Dekatron
int IndexM = 5;        // Index   - NDX input pin. High when glow at K0

//Dek 2
int Guide1N = 9;       // Guide 1 - G1 pin of 2-guide Dekatron
int Guide2N = 10;       // Guide 2 - G2 pin of 2-guide Dekatron
int IndexN = 12;        // Index   - NDX input pin. High when glow at K0

//Dek 1
int Guide1O = 12;       // Guide 1 - G1 pin of 2-guide Dekatron
int Guide2O = 13;       // Guide 2 - G2 pin of 2-guide Dekatron
int IndexO = 11;        // Index   - NDX input pin. High when glow at K0

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

		digitalWrite(Guide1N, LOW);
		digitalWrite(Guide2N, LOW);

		digitalWrite(Guide1O, LOW);
		digitalWrite(Guide2O, LOW);


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

		digitalWrite(Guide1N, HIGH);
		digitalWrite(Guide2N, LOW);

		digitalWrite(Guide1O, HIGH);
		digitalWrite(Guide2O, LOW);



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

		digitalWrite(Guide1N, HIGH);
		digitalWrite(Guide2N, LOW);

		digitalWrite(Guide1O, HIGH);
		digitalWrite(Guide2O, LOW);



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

	pinMode(Guide1N, OUTPUT);
	pinMode(Guide2N, OUTPUT);
	pinMode(IndexN, INPUT);

	pinMode(Guide1O, OUTPUT);
	pinMode(Guide2O, OUTPUT);
	pinMode(IndexO, INPUT);






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



	//  buttonstate();

	Ndx = digitalRead(IndexA);      // Sample for glow at K0
	//Ndx = digitalRead(IndexB);      // Sample for glow at K0
	//Ndx = digitalRead(IndexC);      // Sample for glow at K0




	//if (Ndx) digitalWrite(LED, HIGH);
	//if (!Ndx) digitalWrite(LED, LOW);
	if (Ndx && state == 0)        // If yes, and state = 0,
	{
		state = 1;            // then, set to state 1 to ignore Ndx for 5mS        
		i_count = 0;          // clr ignore counter (i_count)       
		Dir = !Dir;         // flip direction (Dir)


	//  if (buttonPushCounter == 1) {
	//      Dir = Dir;
	//    }
	//    else {
	//      Dir = !Dir;
	//      buttonPushCounter = 0;
	//    }

	}
	if (Dir)
	{
		D_count++;            // increment D_count for clockwise motion
		i_count++;            // increment ignore period counter
	}
	else
	{
		D_count--;            // decrement D_count for counter-clockwise motion
		i_count++;            // increment ignore period counter
	}
	if (i_count == 5)         // at count of 5, stop ignoring Ndx, to allow looking for K0 glow.
	{
		state = 0;
		digitalWrite(LED, LOW);
	}


	if (Counter >= 500) 
	{
		Counter = 0;
		Acceleration = 0;
	}
	Counter++;

	//delay(1000); //Uncomment this to just count seconds.
	delay(Acceleration);

	if (Ndx)Acceleration = Acceleration + pow(1, Acceleration);
	//if (Ndx)Acceleration = Acceleration + pow(2, Acceleration);
	//if (Ndx)Acceleration = Acceleration + pow(4, Acceleration);
	//A101 Dec has 64 cathodes ?

	Serial.println(Acceleration);
	Serial.println(Counter);
	if (D_count > 2) D_count = 0;
	if (D_count < 0) D_count = 2;
	G_step(D_count);          // Step Dekatron
}