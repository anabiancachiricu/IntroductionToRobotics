//The program uses an antenna to read the emf
//one 7-segment display to show the value of emf (from 0-lowest to 9-highest) 
//and an RGB led that goes from green(0) to red(9) to suggest the danger (aka ghosts)

#define sample 300

const int inPin=5; // analog 5, the pin connected to the antenna
float val;
float val1;
int val2;

int array1[sample];
unsigned long averaging;
//connect the RGB led
const int ledPinRed =9;
const int ledPinGreen =10;
const int ledPinBlue =11;

//connect the buzzer
const int buzzerPin=12;
int buzzerTone=100;

// declare all the segments pins
const int pinA = 2;
const int pinB = 3;
const int pinC = 4;
const int pinD = 5;
const int pinE = 6;
const int pinF = 7;
const int pinG = 8;

const int segSize = 8;
const int noOfDigits = 10;

// store the pins in an array for easier access
int segments[segSize] = {
  pinA, pinB, pinC, pinD, pinE, pinF, pinG
};

byte digitMatrix[noOfDigits][segSize - 1] = {
// a  b  c  d  e  f  g
  {1, 1, 1, 1, 1, 1, 0}, // 0
  {0, 1, 1, 0, 0, 0, 0}, // 1
  {1, 1, 0, 1, 1, 0, 1}, // 2
  {1, 1, 1, 1, 0, 0, 1}, // 3
  {0, 1, 1, 0, 0, 1, 1}, // 4
  {1, 0, 1, 1, 0, 1, 1}, // 5
  {1, 0, 1, 1, 1, 1, 1}, // 6
  {1, 1, 1, 0, 0, 0, 0}, // 7
  {1, 1, 1, 1, 1, 1, 1}, // 8
  {1, 1, 1, 1, 0, 1, 1}  // 9
};

void displayNumber(byte digit) {
  for (int i = 0; i < segSize - 1; i++) {
  digitalWrite(segments[i], digitMatrix[digit][i]);
  }

}


void setup() {
  // initialize all the pins
  for (int i = 0; i < segSize; i++) {
    pinMode(segments[i], OUTPUT);
  }
  pinMode(ledPinRed, OUTPUT);
  pinMode(ledPinGreen, OUTPUT);
  pinMode(ledPinBlue, OUTPUT);
  Serial.begin(9600);
 
}

void loop() {

  for (int i=0; i<sample; i++)
  {
    array1[i]=analogRead(inPin);
    averaging += array1[i];
  }

  val=averaging/sample;                     //calculate the value that needs to be displayed 
  val=constrain(val, 0, 100);
 // val1=map(val, 0, 100, 0, 255);
  val2=map(val, 0, 100, 0,  9);
  
  val2=int(val2);

  displayNumber(val2);                      //display the number on the 7 segment display
  
   
  if (val2==0)                              //set the color of the RGB led and the sound depending on the value
  {
    setColor(0, 255, 0);
    
  }
  if (val2==1)
  {
    setColor(188, 255, 0);
    tone(buzzerPin, buzzerTone*val2, 200);
  } 
  if (val2==2)
  {
    setColor(201, 255, 149);
    tone(buzzerPin, buzzerTone*val2, 190);
  }
   if (val2==3)
  {
     setColor(220, 255, 0);
     tone(buzzerPin, buzzerTone*val2, 180);
  }
   if (val2==4)
  {
    setColor(220, 255, 71);
    tone(buzzerPin, buzzerTone*val2, 170);
  }
   if (val2==5)
  {
    setColor(255, 255, 0);
    tone(buzzerPin, buzzerTone*val2, 150);
  }
   if (val2==6)
  {
    setColor(255, 210, 1);
    tone(buzzerPin, buzzerTone*val2, 125);
  }
   if (val2==7)
  {
    setColor(190, 255, 1);
    tone(buzzerPin, buzzerTone*val2, 100);
  }
   if (val2==8)
  {
    setColor(135, 255, 1);
    tone(buzzerPin, buzzerTone*val2, 50);
  }
   if (val2==9)
  {
    setColor(255, 0, 0);
    tone(buzzerPin, 5000, 250);
  }
  
  averaging=0;
  delay(250);
  
}

void setColor(int red,int green,int blue)         //function for setting the color of the RGB led
{
  analogWrite(ledPinRed, red);
  analogWrite(ledPinGreen, green);
  analogWrite(ledPinBlue, blue);
  }
