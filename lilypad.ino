#include <Servo.h>

#define PIN_LED 13
#define PIN_SERVO 3
#define PIN_VIBRO 5

const int ALARM_MAX = 3;  // cycles
int alarm;
Servo servo;

void setup() {
  pinMode(PIN_LED, OUTPUT);
  pinMode(PIN_VIBRO, INPUT);
  servo.attach(PIN_SERVO);
}

void loop() {
  if (alarm > 0) {
    alarm --;
    servo.write(50);
    delay(300);
    servo.write(0);
    delay(300);
  } else {
    int val = digitalRead(PIN_VIBRO);
    if (val == HIGH && alarm == 0) {
      alarm = ALARM_MAX;
    }
    delay(100);
  }
}
