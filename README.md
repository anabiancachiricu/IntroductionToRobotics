# IntroductionToRobotics
Introduction to Robotics (2021 - 2022) Description about the repo. Examples include, but are not limited to: "Introduction to Robotics laboratory homeworks, taken in the 3rd year at the Faculty of Mathematics and Computer Science, University of Bucharest. Each homework includes requirements, implementation details, code and image files." 

# Homework 1 

<details>
  <summary> 
    Details
  </summary>
  
## Task requierments:
Use a separat potentiometer in controlling each of thecolor of the RGB led (Red, Green and Blue).  The control must be done with digital electronics (aka you must read the value of the potentiometer with Arduino, and write a mapped value to each of the pins connected to the led.
## Picture of the setup:
![alt text](https://github.com/anabiancachiricu/IntroductionToRobotics/blob/main/poza1.jpeg)
![alt text](https://github.com/anabiancachiricu/IntroductionToRobotics/blob/main/poza2.jpeg)

## Link to video showcasing functionality:
https://www.youtube.com/watch?v=BYpQmuv6mjg&ab_channel=AnaBiancaChiricu
</details>

# Homework 2

<details>
  <summary> 
    Details
  </summary>
  
## Task requierments:
Building the traffic lights for a crosswalk. I will use 2 LEDs to represent the traffic lights for people (red and green) and 3 LEDs to represent the traffic lights for cars (red, yellow and green).

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

</details>

# Homework 3

<details>
  <summary> 
    Details
  </summary>
  
## Task requierments:
Basically, we’re building the ghost detector (aka an EMF - electromagneticfield  -  detector).   
It should detect EMF (check body and near outlets.  DO NOT IN-SERT INTO OUTLET - AKA NU-L BAGATI IN PRIZA). It should print the value on the 7-segment display (or light the led bar) and should make a sound based on the intensity.

## Picture of the setup:
![alt text](https://github.com/anabiancachiricu/IntroductionToRobotics/blob/main/Hw3_poza1.jpeg)
![alt text](https://github.com/anabiancachiricu/IntroductionToRobotics/blob/main/Hw3_poza2.jpeg)
![alt text](https://github.com/anabiancachiricu/IntroductionToRobotics/blob/main/Hw3_poza3.jpeg)


## Link to video showcasing functionality:
https://www.youtube.com/watch?v=PzIKLrkWwt4&ab_channel=AnaBiancaChiricu

https://www.youtube.com/watch?v=UGvX-TAcic0&ab_channel=AnaBiancaChiricu (fun part)

  </details>
  
# Homework 4

<details>
  <summary> 
    Details
  </summary>
  
## Task requierments:
The current homework  involves  using  a  joystick  in  setting  the  values  on  each  digit  of  a  4-digit7-segment display connected to a shift register 74hc595. 
First  state:   I will  use  a  joystick  axis  to  cycle  through  the  4digits; the other axis does nothing.  A blinking decimal point shows the current digit position.  When pressing the button,  I  lock  in  on  the  selected  digit  and  enter  the second state.  In this state, the decimal point stays always on, no longer blinking and I can no longer use the axis to cycle through the 4 digits. Instead, using the other axis, I can increment or decrement the number on the current digit.  Pressing the button again returns to the previous state.  

## Picture of the setup:
![alt text](https://github.com/anabiancachiricu/IntroductionToRobotics/blob/main/Hw4_poza2.jpeg)
![alt text](https://github.com/anabiancachiricu/IntroductionToRobotics/blob/main/Hw4_poza1.jpeg)
![alt text](https://github.com/anabiancachiricu/IntroductionToRobotics/blob/main/Hw4_poza3.jpeg)

## Link to video showcasing functionality:
https://youtu.be/b10ZX4KvGxM

  </details>
