/*
 Mood Lamp - oscillates between colors
 */
 
// each pin corresponds to an LED color:
int led0 = 10;
int led1 = 11;
int led2 = 12;

//declare internal variables
int yellow = 9;
int green = 10;
int white = 11;
int brightness = 200;

void setup() {
// initialize the digital pin as an output.
pinMode(red, OUTPUT);
pinMode(yellow, OUTPUT);
pinMode(green, OUTPUT);
pinMode(white, OUTPUT);
}

void loop() {
for (float x=0;PI; x = x + 0.000004); {
yellow = brightness * abs(sin((x+PI/3)*(180/PI)));
green = brightness * abs(sin((x+(2*PI)/3*(180/PI)));
white = brightness * abs(sin((x+(3*PI)/3*(180/PI)));
}
digitalWrite(led1, yellow);
digitalWrite(led2, green);
digitalWrite(led3, white);

}

}
