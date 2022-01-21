const int ledPinRed = 11;
const int ledPinGreen = 10;
const int ledPinBlue = 9;

const int potPinRed = A0;
const int potPinGreen = A1;
const int potPinBlue = A2;

float voltageRed = 0;
float voltageGreen = 0;
float voltageBlue = 0;

int potValueRed = 0;
int potValueGreen = 0;
int potValueBlue = 0;

float brightnessRed = 0;
float brightnessGreen = 0;
float brightnessBlue = 0;

const float maxAnalogValue = 5.0;
const float maxVoltageValue = 1023.0;

void setup() {
  // put your setup code here, to run once:
  
  pinMode(potPinRed, INPUT);
  pinMode(ledPinRed, OUTPUT);

  pinMode(potPinGreen, INPUT);
  pinMode(ledPinGreen, OUTPUT);

  pinMode(potPinBlue, INPUT);
  pinMode(ledPinBlue, OUTPUT);

  Serial.begin(9600);
}

void loop() {
  // put your main code here, to run repeatedly:
  
  potValueRed = analogRead(potPinRed);                              //read the input value from the potentiometer for red value
  voltageRed = potValueRed * maxAnalogValue / maxVoltageValue;      //calculate the voltage for the red input
  brightnessRed = map(potValueRed, 0, 1023, 0, 255);                //calculate the brightness for the red led
  analogWrite(ledPinRed, brightnessRed);                            //modify the led to have the brightness selected from the potentiometer

  potValueGreen = analogRead(potPinGreen);                          //read the input value from the potentiometer for green value
  voltageGreen = potValueGreen * maxAnalogValue / maxVoltageValue;  //calculate the voltage for the green input
  brightnessGreen = map(potValueGreen, 0, 1023, 0, 255);            //calculate the brightness for the green led
  analogWrite(ledPinGreen, brightnessGreen);                        //modify the led to have the brightness selected from the potentiometer

  potValueBlue = analogRead(potPinBlue);                            //read the input value from the potentiometer for blue value
  voltageBlue = potValueBlue * maxAnalogValue / maxVoltageValue;    //calculate the voltage for the blue input
  brightnessBlue = map(potValueBlue, 0, 1023, 0, 255);              //calculate the brightness for the blue led
  analogWrite(ledPinBlue, brightnessBlue);                          //modify the led to have the brightness selected from the potentiometer
}
