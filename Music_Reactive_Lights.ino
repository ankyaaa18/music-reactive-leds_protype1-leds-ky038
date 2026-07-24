//==========================================
// ESP32 Music Reactive LEDs
// KY-038 Sound Sensor (AO -> GPIO34)
//==========================================

const int micPin = 34;

const int ledPins[10] = {
  12, 13, 14, 27, 4,
  5, 25, 21, 22, 23
};

void setup() {
  Serial.begin(115200);

  for (int i = 0; i < 10; i++) {
    pinMode(ledPins[i], OUTPUT);
    digitalWrite(ledPins[i], LOW);
  }
}

void loop() {

  // Find sound amplitude
  int signalMax = 0;
  int signalMin = 4095;

  unsigned long start = millis();

  while (millis() - start < 50) {
    int sample = analogRead(micPin);

    if (sample > signalMax) signalMax = sample;
    if (sample < signalMin) signalMin = sample;
  }

  int amplitude = signalMax - signalMin;

  Serial.println(amplitude);

  int level = map(amplitude, 0, 600, 0, 10);

  if (level < 0) level = 0;
  if (level > 10) level = 10;

  for (int i = 0; i < 10; i++) {
    if (i < level)
      digitalWrite(ledPins[i], HIGH);
    else
      digitalWrite(ledPins[i], LOW);
  }

  delay(5);
}
