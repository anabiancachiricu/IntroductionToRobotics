# IntroductionToRobotics
Introduction to Robotics (2021 - 2022) Description about the repo. Examples include, but are not limited to: "Introduction to Robotics laboratory homeworks, taken in the 3rd year at the Faculty of Mathematics and Computer Science, University of Bucharest. Each homework includes requirements, implementation details, code and image files." 
# Homework 1 
## Task requierments:
Use a separat potentiometer in controlling each of thecolor of the RGB led (Red,Green andBlue).  The control must be donewithdigital electronics(aka you must read the value of the potentiome-ter with Arduino, and write a mapped value to each of the pins connectedto the led.
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
