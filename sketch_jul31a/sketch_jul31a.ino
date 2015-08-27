const int  buttonPin = 2;    // the pin that the pushbutton is attached to
const int led0 = 10;
const int led1 = 11;
const int led2 = 12;     // the pin that the LED is attached to

// Variables will change:
int buttonPushCounter = 0;   // counter for the number of button presses
int buttonState = 0;         // current state of the button
int lastButtonState = 0;     // previous state of the button
int brightness = 200;
int red = 0;
int blue = 0;
int green = 0;

void setup() {
  // initialize the button pin as a input:
  pinMode(buttonPin, INPUT);
  // initialize the LED as an output:
  pinMode(led0, OUTPUT);    
  pinMode(led1, OUTPUT);    
  pinMode(led2, OUTPUT); 
  // initialize serial communication:
  Serial.begin(9600);
}


void loop() {
  // read the pushbutton input pin:
  buttonState = digitalRead(buttonPin);

  // compare the buttonState to its previous state
  if (buttonState != lastButtonState) {
    // if the state has changed, increment the counter
    if (buttonState == HIGH) {
      // if the current state is HIGH then the button
      // wend from off to on:
      buttonPushCounter++;
      Serial.println("on");
      Serial.print("number of button pushes:  ");
      Serial.println(buttonPushCounter);
    } 
    else {
      // if the current state is LOW then the button
      // wend from on to off:
      Serial.println("off"); 
    }
  }
  // save the current state as the last state, 
  //for next time through the loop
  lastButtonState = buttonState;

  
  // turns on the LED every four button pushes by 
  // checking the modulo of the button push counter.
  // the modulo function gives you the remainder of 
  // the division of two numbers:
  if (buttonPushCounter % 2 == 0) {
    for (float x=0;x < PI; x = x + 0.000004){
      red = brightness * abs(sin(x*(180/PI)));           // calculate red brightness
      green = brightness * abs(sin((x+PI/3)*(180/PI)));    // calculate green brightness
      blue = brightness * abs(sin((x+(2*PI)/3)*(180/PI)));// calculate the blue brightness
      analogWrite(led0, red);   // send the value to the LED
      analogWrite(led1, green);   // send the value to the LED
      analogWrite(led2, blue);   // send the value to the LED
    }
    } else if (buttonPushCounter % 3 == 0) {
      analogWrite(led0, 0);
      analogWrite(led1, 0);
      analogWrite(led2, 0);
  }
  
}
