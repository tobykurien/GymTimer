# GymTimer
Dead-simple arduino-based gym timer for StrongLifts 5x5 style gym routine

# Usage

- Power on device. 5 LED's light up to show that you have 5 sets left.
- Complete your first set, then press button. First LED blinks and rest period begins.
- Once buzzer sounds, press button to silence it. The first LED goes off and shows you have 4 sets left.
- Keep going for the rest of the sets, pressing the button each time you complete a set or finish your rest period.
- If this was the last set, then the process repeats from start with 5 new sets.
- Note that you can press the button *during* a rest period to cancel the timer for that rest period.

You can change the number of sets (up to 10) and the rest period by editing the 2 variables (```REST_PERIOD_MS``` and ```MAX_SETS```) at the top of the source file.

# Wiring

[![Fritzing breadboard diagram](https://raw.githubusercontent.com/tobykurien/GymTimer/master/docs/breadboard_bb.png)](https://github.com/tobykurien/GymTimer/tree/master/docs)

- Use an Arduino Uno
- Connect 5 LED's via current-limiting resistors (e.g. 220ohm) to pins 3 to 7.
- Optionally, connect more LED's (up to another 5) via current-limiting resistors (e.g. 220ohm) to pins 9 to 13.
- Connect a piezo buzzer to pin 8 and down to ground.
- Connect a push-button switch to pin 2 and down to ground.

