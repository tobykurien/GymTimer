/***
 * Gym Timer for 5x5
 * Toby Kurien
 */

#define REST_PERIOD_MS 90000  // How long the rest period is
#define MAX_SETS       5      // How many sets (i.e. LEDs connected), up to 10

// Pin assignments 
int button = 2;
int buzzer = 8;
int leds[] = {3, 4, 5, 6, 7, 9, 10, 11, 12, 13};

int count = MAX_SETS;
long debounceTime = 0;
long timer = 0;

boolean resting = false;
boolean alarm = false;
int buzzerOn = false;
long alarmPeriod = 0;

// the setup routine runs once when you press reset:
void setup() {                
  // initialize the pins
  for (int i=0; i < 10; i++) {
   pinMode(leds[i], OUTPUT);
  }
  
  pinMode(buzzer, OUTPUT);
  digitalWrite(buzzer, LOW);
  
  pinMode(button, INPUT);
  digitalWrite(button, HIGH);  

  showCount();
}

// Output the number of remaining sets on the LEDs
void showCount() {
  for (int i=0; i < 10; i++) {
    digitalWrite(leds[i], count > i ? HIGH : LOW);
  }
}

// the loop routine runs over and over again forever:
void loop() {
  if (millis() - debounceTime > 500 && digitalRead(button) == LOW) {
    // button pressed
    debounceTime = millis();
    timer = millis();
    
    if (alarm || resting) {
      // alarm is sounding or we're resting, turn off alarm/resting
      alarm = false;
      resting = false;
      digitalWrite(buzzer, LOW);

      // if this was the last set, reset for next round      
      if (count == 0) {
        count = MAX_SETS;
        showCount();
      }
    } else {
      // a set was completed
      resting = true;
      count--;
      if (count < 0) count = MAX_SETS;
      showCount();
    }
  }

  if (count < MAX_SETS && 
        !alarm && 
        resting && 
        timer != 0 && 
        millis() - timer > REST_PERIOD_MS) {
    // resting period is over
    alarm = true;
    buzzerOn = true;
    digitalWrite(buzzer, HIGH);
  }
  
  if (alarm && millis() - alarmPeriod > 60) {
    // pulse the buzzer if alarm is on, for a more pleasing sound
    alarmPeriod = millis();
    digitalWrite(buzzer, buzzerOn ? LOW : HIGH);  
    buzzerOn = !buzzerOn;
  }
}

