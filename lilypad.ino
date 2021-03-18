#include <Servo.h>

#define PIN_LED 13
#define PIN_SERVO 3
#define PIN_VIBRO 5

const int ALARM_MAX = 3;  // cycles
int alarm = 0;
Servo servo;

void setup() {
  pinMode(PIN_LED, OUTPUT);
  pinMode(PIN_VIBRO, INPUT);
  servo.attach(PIN_SERVO);
}

void loop() {
  digitalWrite(PIN_LED, HIGH);
  delay(200);
  digitalWrite(PIN_LED, LOW);
  delay(200);
  if (alarm > 0) {
    alarm --;
    digitalWrite(PIN_LED, HIGH);
    servo.write(50);
    delay(500);
    digitalWrite(PIN_LED, LOW);
    servo.write(0);
    delay(500);
  } else {
    int val = digitalRead(PIN_VIBRO);
    if (val == HIGH && alarm == 0) {
      alarm = ALARM_MAX;
    }
    delay(100);
  }
}
