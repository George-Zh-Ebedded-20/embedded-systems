const int keyPin = 3; // pin for a button(key)
const int ledPin = 13; // pin for a lamp(led)
volatile unsigned long lastButton;
boolean ledOn = false;

void setup() {
  Serial.begin(9600);
  pinMode(keyPin, INPUT_PULLUP);  // 3 pin with pullup
  pinMode(ledPin, OUTPUT);
  attachInterrupt(1, interrupt,  RISING);  // turn on interrupt
}

void loop() {
  Serial.println("Interrupted!");
  digitalWrite(ledPin, ledOn);
}

void interrupt() {
  if(millis() - lastButton > 250) {
    ledOn = !ledOn;
    lastButton = millis();
  }
}
