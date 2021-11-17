// declare all the joystick pins
const int pinSW = 2; // digital pin connected to switch output
const int pinX = A0; // A0 - analog pin connected to X output
const int pinY = A1; // A1 - analog pin connected to Y output

//declare the shift-register pins
const int dataPin = 12;
const int latchPin = 11;
const int clockPin = 10;

//declare the 4 digit 7 segment display pins
const int segD1 = 7;
const int segD2 = 6;
const int segD3 = 5;
const int segD4 = 4;

const int segmentsCount = 4;
int displayNumber = 0;
int segmentNumber = 0;
boolean registers[8];
int currentSegment = 0;

bool displayChanged = false;
unsigned long lastChanged = 0;
const int blinkingInterval = 100;
bool dpState = LOW;
const int debounceInterval = 50;

//array for the segments
int displayDigits[] =
{
  segD1, segD2, segD3, segD4
};
//array for values of segments
int segmentValue[4] = 
{
  0, 0, 0, 0
};

int digitArray[16] = 
{
  //A B C D E F G DP
  B11111100, // 0
  B01100000, // 1
  B11011010, // 2
  B11110010, // 3
  B01100110, // 4
  B10110110, // 5
  B10111110, // 6
  B11100000, // 7
  B11111110, // 8
  B11110110, // 9
  B11101110, // A
  B00111110, // b
  B10011100, // C
  B01111010, // d
  B10011110, // E
  B10001110  // F
};

unsigned long previousMillis = 0;
const long interval = 1000;

// states of the button press

bool swState = LOW;
bool lastSwState = LOW;
//joystick values
int switchValue;
int xValue = 0;
int yValue = 0;
//values used to determine if the joystick moved and which way
bool joyMoved = false;
int digit = 0;
int minThreshold = 400;
int maxThreshold = 600;
int currentNumber = 0;

void setup() 
{
  // put your setup code here, to run once:
  pinMode(dataPin, OUTPUT);
  pinMode(latchPin, OUTPUT);
  pinMode(clockPin, OUTPUT);

  pinMode(pinX, INPUT);
  pinMode(pinY, INPUT);
  pinMode(pinSW, INPUT_PULLUP);

  for (int i = 0; i < segmentsCount; i++)
  {
    pinMode(displayDigits[i], OUTPUT);
  }
  attachInterrupt(digitalPinToInterrupt(pinSW), interruptBlink, FALLING);

  Serial.begin(9600);
}

void loop() 
{
  // put your main code here, to run repeatedly:
  showDigits();
  if (displayChanged)
  {
    changeNumber(currentSegment);
  }
  else
  {
    changeDisplay();
  }
}

void interruptBlink()
{
  static unsigned long lastDebounceTime = 0;
  if (millis() - lastDebounceTime > debounceInterval)
  {
    displayChanged = !displayChanged;
  }
  lastDebounceTime = millis();
}

void writeReg(int digit) 
{
  // ST_CP LOW to keep LEDs from changing while reading serial data
  digitalWrite(latchPin, LOW);
  // Shift out the bits
  shiftOut(dataPin, clockPin, MSBFIRST, digit);
  /* ST_CP on Rising to move the data from shift register
    to storage register, making the bits available for output.
  */
  digitalWrite(latchPin, HIGH);
}

void showDigit(int displayNumber)
{
  digitalWrite(displayDigits[displayNumber], LOW);
  delay(5);
  for (int i = 0; i < segmentsCount; i++)
  {
    digitalWrite(displayDigits[i], HIGH);
  }
}

void showDigits()
{
  for (int i = 0; i < segmentsCount; i++)
  {
    showDigit(i);
    if (i == currentSegment)
    {
      showDP();
    }
    else
    {
      writeReg(digitArray[segmentValue[i]]);
    }
  }
}

void writeNumber(int number, int displayDigit)
{
  int currentNumber = number;
  //    int displayDigit = 0;
  int lastDigit;
  while (currentNumber != 0) {
    // get the last digit of the number
    lastDigit = currentNumber % 10;
    // enable only the display digit for that
    showDigit(displayDigit);
    // send the number to the display
    writeReg(digitArray[lastDigit]);
    // increase the delay to see multiplexing in action
    //delay(5);
    // increment the display digit
    //displayDigit++;
    // eliminate the last digit of the number
    currentNumber /= 10;
  }
}

void changeDisplay()
{
  yValue = analogRead(pinY);
  
  if (yValue > maxThreshold && joyMoved == false)
  {
    if (currentSegment > 0) 
    {
      currentSegment--;
    }
    else 
    {
      currentSegment = 3;
    }
    joyMoved = true;
  }

  if (yValue < minThreshold && joyMoved == false)
  {
    if (currentSegment < 3) 
    {
      currentSegment++;
    }
    else 
    {
      currentSegment = 0;
    }
    joyMoved = true;
  }

  if (yValue >= minThreshold && yValue <= maxThreshold)
  {
    joyMoved = false;
  }
  
}

void changeNumber(int currentSegment)
{
  xValue = analogRead(pinX);
  // On Ox axis, if the value is lower than a chosen min threshold, then
  // decrease by 1 the digit value.

  if (xValue < minThreshold && joyMoved == false) 
  {
    if (segmentValue[currentSegment] > 0) 
    {
      segmentValue[currentSegment]--;
    }
    else 
    {
      segmentValue[currentSegment] = 9;
    }
    joyMoved = true;

  }
  
  // On Ox axis, if the value is bigger than a chosen max threshold, then
  // increase by 1 the digit value
  if (xValue > maxThreshold && joyMoved == false) 
  {
    if (segmentValue[currentSegment] < 9) 
    {
      segmentValue[currentSegment]++;
    }
    else 
    {
      segmentValue[currentSegment] = 0;
    }
    joyMoved = true;
  }

  if (xValue >= minThreshold && xValue <= maxThreshold) 
  {
    joyMoved = false;
  }
}

void showDP()
{
  if (displayChanged)
  {
    writeReg(digitArray[segmentValue[currentSegment]] + 1);
  }
  else
  {
    if (millis() - lastChanged > blinkingInterval)
    {
      dpState = !dpState;
      lastChanged = millis();
    }
    if (dpState == LOW)
    {
      writeReg(digitArray[segmentValue[currentSegment]] + 1);
    }
    else
    {
      writeReg(digitArray[segmentValue[currentSegment]]);
    }
  }
}
