# IntroductionToRobotics
Introduction to Robotics (2021 - 2022) Description about the repo. Examples include, but are not limited to: "Introduction to Robotics laboratory homeworks, taken in the 3rd year at the Faculty of Mathematics and Computer Science, University of Bucharest. Each homework includes requirements, implementation details, code and image files." 
# Homework 1 
## Task requierments:
Use a separat potentiometer in controlling each of thecolor of the RGB led (Red, Green and Blue).  The control must be done with digital electronics (aka you must read the value of the potentiometer with Arduino, and write a mapped value to each of the pins connected to the led.
## Picture of the setup:
![alt text](https://github.com/anabiancachiricu/IntroductionToRobotics/blob/main/poza1.jpeg)
![alt text](https://github.com/anabiancachiricu/IntroductionToRobotics/blob/main/poza2.jpeg)

## Link to video showcasing functionality:
https://www.youtube.com/watch?v=BYpQmuv6mjg&ab_channel=AnaBiancaChiricu

# Homework 2
## Task requierments:
Building the traffic lights for a crosswalk. You will use 2 LEDs to represent the traffic lights for people (red and green) and 3 LEDs to represent the traffic lights for cars (red, yellow and green).

The system has the following states:
1. State 1 (default, reinstated after state 4 ends): green light for cars, red light for people, no sounds. Duration: indefinite, changed by pressing the button.
2. State 2 (initiated by counting down 10 seconds after a button press): the light should be yellow for cars, red for people and no sounds. Duration: 3 seconds.
3. State 3 (iniated after state 2 ends): red for cars, green for people and a beeping sound from the buzzer at a constant interval. Duration: 10 seconds.
4. State 4 (initiated after state 3 ends): red for cars, blinking green for people and a beeping sound from the buzzer, at a constant interval, faster than the beeping in state 3.

## Picture of the setup:
![alt text](https://github.com/anabiancachiricu/IntroductionToRobotics/blob/main/Poza1.jpeg)
![alt text](https://github.com/anabiancachiricu/IntroductionToRobotics/blob/main/Poza2.jpeg)
![alt text](https://github.com/anabiancachiricu/IntroductionToRobotics/blob/main/Poza3.jpeg)
![alt text](https://github.com/anabiancachiricu/IntroductionToRobotics/blob/main/Poza4.jpeg)

## Link to video showcasing functionality:
https://youtu.be/ZIVulcF-aNk


# Homework 3
## Task requierments:
Basically, we’re building the ghost detector (aka an EMF - electromagneticfield  -  detector).   
It should detect EMF (check body and near outlets.  DO NOT IN-SERT INTO OUTLET - AKA NU-L BAGATI IN PRIZA). It should printthe value on the 7-segment display (or light the led bar)andshould makea sound based on the intensity.

## Picture of the setup:
![alt text](https://github.com/anabiancachiricu/IntroductionToRobotics/blob/main/Hw3_poza1.jpeg)
![alt text](https://github.com/anabiancachiricu/IntroductionToRobotics/blob/main/Hw3_poza2.jpeg)
![alt text](https://github.com/anabiancachiricu/IntroductionToRobotics/blob/main/Hw3_poza3.jpeg)


## Link to video showcasing functionality:
https://www.youtube.com/watch?v=PzIKLrkWwt4&ab_channel=AnaBiancaChiricu

https://www.youtube.com/watch?v=UGvX-TAcic0&ab_channel=AnaBiancaChiricu (fun part)

# Homework 4
## Task requierments:
The current home-work  involves  using  a  joystick  in  setting  the  values  on  each  digit  of  a  4-digit7-segment display connected to a shift register 74hc595. 
First  state:   you  can  use  a  joystick  axis  to  cycle  through  the  4digits; using the other axis does nothing.  A blinking decimal point shows the current digit position.  When pressing the button (must use interruptfor  maximum  points!),  you  lock  in  on  the  selected  digit  and  enter  thesecond state.  In this state, the decimal point stays always on, no longerblinking and you can no longer use the axis to cycle through the 4 digits.Instead, using the other axis, you can increment on decrement the numberon the current digit.  Pressing the button again returns you to the previousstate.  For bonus, save the last value in eeprom and load it when starting arduino.  Also, keep in mind that when changing the number, you mustincrement it for each joystick movement - it should not work continuoslyincrement if you keep the joystick in one position.

## Picture of the setup:
![alt text](https://github.com/anabiancachiricu/IntroductionToRobotics/blob/main/Hw4_poza2.jpeg)
![alt text](https://github.com/anabiancachiricu/IntroductionToRobotics/blob/main/Hw4_poza1.jpeg)
![alt text](https://github.com/anabiancachiricu/IntroductionToRobotics/blob/main/Hw4_poza3.jpeg)

## Link to video showcasing functionality:
https://youtu.be/b10ZX4KvGxM
