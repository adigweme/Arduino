int switchPin = 8;
int led1 = 11;
int switchState = 0;

void setup() {
  // put your setup code here, to run once:
pinMode(switchPin, INPUT);
pinMode(led1, OUTPUT);
Serial.begin(9600);
}

void loop() {
  // put your main code here, to run repeatedly:
switchState = digitalRead(switchPin);
Serial.print(switchState);
if (switchState = HIGH) {
  analogWrite(led1, 200); 
}
}
