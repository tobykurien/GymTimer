/***
 * Gym Timer for 5x5
 * Toby Kurien
 */

#define REST_PERIOD_MS 90000
#define MAX_SETS 5
 
// Pin 13 has an LED connected on most Arduino boards.
// give it a name:
int button = 2;
int led1 = 3;
int led2 = 4;
int led3 = 5;
int led4 = 6;
int led5 = 7;
int buzzer = 8;

int count = 5;
long debounceTime = 0;
long timer = 0;

boolean resting = false;
boolean alarm = false;
int buzzerOn = false;
long alarmPeriod = 0;

// the setup routine runs once when you press reset:
void setup() {                
  // initialize the digital pin as an output.
  pinMode(led1, OUTPUT);     
  pinMode(led2, OUTPUT);     
  pinMode(led3, OUTPUT);     
  pinMode(led4, OUTPUT);     
  pinMode(led5, OUTPUT);  
  
  pinMode(buzzer, OUTPUT);
  digitalWrite(buzzer, LOW);
  
  pinMode(button, INPUT);
  digitalWrite(button, HIGH);  

  showCount();
}

void showCount() {
    digitalWrite(led1, count > 0 ? HIGH : LOW);
    digitalWrite(led2, count > 1 ? HIGH : LOW);
    digitalWrite(led3, count > 2 ? HIGH : LOW);
    digitalWrite(led4, count > 3 ? HIGH : LOW);
    digitalWrite(led5, count > 4 ? HIGH : LOW);  
}

// the loop routine runs over and over again forever:
void loop() {
  if (millis() - debounceTime > 500 && digitalRead(button) == LOW) {
    debounceTime = millis();
    timer = millis();
    
    if (alarm || resting) {
      // turn off alarm
      alarm = false;
      resting = false;
      digitalWrite(buzzer, LOW);
      
      if (count == 0) {
        count = MAX_SETS;
        showCount();
      }
    } else {
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
    alarm = true;
    buzzerOn = true;
    digitalWrite(buzzer, HIGH);
  }
  
  if (alarm && millis() - alarmPeriod > 60) {
    alarmPeriod = millis();
    digitalWrite(buzzer, buzzerOn ? LOW : HIGH);  
    buzzerOn = !buzzerOn;
  }
}

