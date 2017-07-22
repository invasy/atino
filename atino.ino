#include <SoftwareSerial.h>

#define SERIAL_SPEED 9600
#define BT_SPEED 38400

const byte pinRx = 10;
const byte pinTx = 11;
const byte pinKey = 9;

SoftwareSerial bt(pinRx, pinTx);

void setup() {
  Serial.begin(SERIAL_SPEED);

  pinMode(pinKey, OUTPUT);
  digitalWrite(pinKey, HIGH);
  bt.begin(BT_SPEED);
}

void loop() {
  if (bt.available())
    Serial.write(bt.read());
  if (Serial.available())
    bt.write(Serial.read());
}
