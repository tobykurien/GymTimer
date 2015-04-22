# GymTimer
Dead-simple arduino-based gym timer for StrongLifts 5x5 style gym routine

# Usage

- Power on device. 5 LED's light up to show that you have 5 sets left.
- Complete your first set, then press button. One LED goes off and rest period begins.
- Once buzzer sounds, press button to silence it.
- Complete next set, then press button to enter rest period.
- Once buzzer sounds, press button to silence it.
- Keep going for the rest of the sets. If this was the last set, then process repeats from start.

# Wiring

[![Fritzing breadboard diagram](https://raw.githubusercontent.com/tobykurien/GymTimer/master/docs/breadboard_bb.png)](https://github.com/tobykurien/GymTimer/tree/master/docs)

- Use an Arduino Uno
- Connect 5 LED's via current-limiting resistors (e.g. 220ohm) to pins 3 to 7.
- Connect a piezo buzzer to pin 8 and down to ground.
- Connect a push-button switch to pin 2 and down to ground.

