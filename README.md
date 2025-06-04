# engr103puzzle10
For my engr103 puzzle 10 assignment
#  Circuit Playground Reaction Game


## Overview

This game challenges players to react to randomly generated cues with the correct input:
- Left button
- Right button
- Loud sound (clap or shout)

Score points for correct reactions, lose points for incorrect ones. Reach 10 points to win!

---

- This is game was made with the Adafruit Circuit Playground Express in mind


##  How to Play

1. Start the Game
   - Slide the onboard switch to ON (right side).
   - The game resets and begins with a score of 0.

2. Watch for LED Hints
   - Blue LED on pixel 2 → Press the left button
   - Blue LED on pixel 7 → Press the right button
   - Blue LEDs on pixels 4 & 5 → Make a loud sound(≥ 80 dB)

3. Scoring System
   - Correct input:  
     - Green LED flash  
     - Short high-pitched tone  
     - +1 point
   -  Wrong input:  
     - Red LED flash  
     - Low-pitched tone  
     - –1 point

4. Winning the Game
   - Reach a score of 10 to win.
   - A celebratory green LED animation and sound sequence plays.
   - Slide the switch OFF then ON to reset and play again.

---

## Resetting the Game

- Toggle the slide switch OFF and back on at any time to reset the game and clear your score.

---

##  Notes

- Sound input requires a loud, short burst like a clap or sharp vocal noise.
- Score is printed to the Serial Monitor for debugging or live tracking.
