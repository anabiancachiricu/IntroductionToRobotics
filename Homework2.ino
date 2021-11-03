const int pushButton=2;

const int buzzerPin=3;
int buzzerTone=100;

const int ledPinCarsRed=13;
const int ledPinCarsYellow=12;
const int ledPinCarsGreen=11;

const int ledPinPeopleRed=10;
const int ledPinPeopleGreen=9;

bool ledStateCarsRed=LOW;
bool ledStateCarsYellow=LOW;
bool ledStateCarsGreen=LOW;

bool ledStatePeopleGreen=HIGH;
bool ledStatePeopleRed=HIGH;

bool buttonState=LOW;
bool lastButtonState=LOW;
bool reading=LOW;
bool lastReading=LOW;
int counter= 0;
int lastDebounceTimer=0;

const int debounceInterval=50;
const unsigned long timer = 500; // interval to blink
const unsigned long soundTimer=1000; //interval for sound at state 3
const unsigned long state2Delay=10000;//interval to wait after pressing the button
const unsigned long state2Timer=3000; //interval for state 2
const unsigned long state3Timer=10000; //interval for state 3 
unsigned long previousMillis=0;
unsigned long startMillis=0;
unsigned long currentMillis=0;


void setup() {
  // put your setup code here, to run once:
  
 pinMode(pushButton, INPUT_PULLUP);
 
 pinMode(ledPinCarsRed, OUTPUT);
 pinMode(ledPinCarsYellow, OUTPUT);
 pinMode(ledPinCarsGreen, OUTPUT);
 pinMode(ledPinPeopleRed, OUTPUT);
 pinMode(ledPinPeopleGreen, OUTPUT);
 
 state1();
 Serial.begin(9600);
}

void loop() {
  // put your main code here, to run repeatedly:
  
  state1(); 
   
  reading=digitalRead(pushButton);
  if (reading!=lastReading)
  {
    lastDebounceTimer=millis();
   }
  if (millis()-lastDebounceTimer>debounceInterval)
  {
    if(reading!=buttonState)
    {
     
      buttonState=reading;
      if (buttonState== LOW)
      {
        state2();
        state3();
        state4();
        
      }
     
    }
   
  }
    lastReading=reading;
  
  Serial.println(buttonState);
  
  
}

void state1()
{
  // In the first state, we want the traffic lights to be green for cars and red for peoplewith no timer and no sound
  
   ledStateCarsRed=LOW;
   ledStateCarsYellow=LOW;
   ledStateCarsGreen=HIGH;
   ledStatePeopleRed=HIGH;
   ledStatePeopleGreen=LOW;

   digitalWrite(ledPinCarsRed, ledStateCarsRed);
   digitalWrite(ledPinCarsYellow, ledStateCarsYellow);
   digitalWrite(ledPinCarsGreen, ledStateCarsGreen);
   digitalWrite(ledPinPeopleGreen, ledStatePeopleGreen);
   digitalWrite(ledPinPeopleRed, ledStatePeopleRed);
}

void state2()
{
  // In second state, the traffic light for cars changes from green to yellow
  // This initiates 10 seconds after pressing the button an lasts for  3 seconds
  
    //delay(10000);
    startMillis=millis();
    currentMillis=millis();
    while (currentMillis-startMillis<=state2Delay)
    {
      currentMillis=millis();
    }
    startMillis=millis();
    while (currentMillis-startMillis<=state2Timer )                   //mentain state 2 for 10 seconds
    {
      if (ledStateCarsYellow==LOW)                                  //if the cars light is not yellow, change it from green to yellow
      {
        ledStateCarsYellow=HIGH;
        digitalWrite(ledPinCarsYellow, ledStateCarsYellow);
      }
      if (ledStateCarsGreen=!LOW)
      {
        ledStateCarsGreen=!ledStateCarsGreen;
        digitalWrite(ledPinCarsGreen, ledStateCarsGreen);
      }
       currentMillis=millis();
      
    }
   
}

void state3()
{
   // In third state, the traffic light for cars changes from yellow to red
   // The traffic light for people changes from red to green
   // A beep sounds at a constant intterval
   // This lasts for 10 seconds

    startMillis=millis();
    currentMillis=millis();
    while (currentMillis-startMillis<=state3Timer)                 //mentain state 3 for 10 seconds
    {
      if(ledStateCarsRed!=HIGH)                                   //change the colors for the traffic lights
      {
        ledStateCarsRed=!ledStateCarsRed;                         //the cars traffic light changes from yellow to red
        digitalWrite(ledPinCarsRed, ledStateCarsRed);             //the people traffic light changes from red to green
      }

      if(ledStateCarsYellow!=LOW)
      {
        ledStateCarsYellow=!ledStateCarsYellow;
        digitalWrite(ledPinCarsYellow, ledStateCarsYellow);
      }
      
      if(ledStatePeopleGreen!=HIGH)
      {
        ledStatePeopleGreen=!ledStatePeopleGreen;
        digitalWrite(ledPinPeopleGreen, ledStatePeopleGreen);
      }

      if(ledStatePeopleRed!=LOW)
      {
        ledStatePeopleRed=!ledStatePeopleRed;
        digitalWrite(ledPinPeopleRed, ledStatePeopleRed);
      }

      if(currentMillis-previousMillis>=soundTimer)                 //set a tone for the buzzer to sound every other second
      {
         previousMillis=currentMillis;
         tone(buzzerPin, buzzerTone, 250);
      }
       currentMillis=millis();
    }
}

void state4()
{

   // In fourth state, the traffic light for people is green and blinks every half second
   // The traffic light for cars stays red
   // A beep sounds at a constant intterval, smaller than the previous one
   // This lasts for 5 seconds
   
  startMillis=millis();
  currentMillis=millis();
  while (currentMillis-startMillis<=5000)                           //set duration for state 4 (5 seconds)
  {
   
      if(currentMillis-previousMillis>=timer)                       //blink the led at a constant interval
    {
        previousMillis=currentMillis;                               //and set a tone for the buzzer to sound at a smaller interval
        ledStatePeopleGreen=!ledStatePeopleGreen;
        tone(buzzerPin, buzzerTone, 250);
        digitalWrite(ledPinPeopleGreen, ledStatePeopleGreen);
    }
       currentMillis=millis();
    
  }
  
}
