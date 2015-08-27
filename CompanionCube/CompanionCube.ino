 /*
 Mood Lamp - oscillates between colors
 */
// this pin corresponds to our on/off switch
const int  switchPin = 4;

// each of these pins corresponds to an LED color:
const int led0 = 10;
const int led1 = 11;
const int led2 = 12;
const int led3 = 9;
const int led4 = 8;
const int led5 = 7;
const int led6 = 6;
 
//declare internal variables; these will change 
int brightness = 200;                     
int red = 0;
int blue = 0;
int green = 0; 
int switchState = 0;         // current state of the button

// this routine runs each time you hit the reset button
void setup() {                
    // initialize the button pin as an input:
  pinMode(switchPin, INPUT);
  // declare the relevant pins to be output
  pinMode(led0, OUTPUT);    
  pinMode(led1, OUTPUT);    
  pinMode(led2, OUTPUT);
  pinMode(led3, OUTPUT); 
  pinMode(led4, OUTPUT); 
  pinMode(led5, OUTPUT);
  pinMode(led6, OUTPUT);  
}
 
// this routine loops indefinitely
void loop() {
  // read the tilt switch input pin:
  switchState = digitalRead(switchPin);
  
   if (switchState = HIGH) {
    for (float x=0;x < PI; x = x + 0.000004){
      red = brightness * abs(sin(x*(180/PI)));           // calculate red brightness
      green = brightness * abs(sin((x+PI/3)*(180/PI)));    // calculate green brightness
      blue = brightness * abs(sin((x+(2*PI)/3)*(180/PI)));// calculate the blue brightness
      analogWrite(led0, blue);   // send the value to the LED
      analogWrite(led1, red);   // send the value to the LED
      analogWrite(led2, 0);
      analogWrite(led3, red); 
      analogWrite(led4, red);
      digitalWrite(led5, green);
      analogWrite(led6, blue);  // send the value to the LED
    }
    } 
    else if (switchState = LOW) {
      analogWrite(led0, 0);
      analogWrite(led1, 0);
      analogWrite(led0, 0);
    }
    delay(10);
 
}
