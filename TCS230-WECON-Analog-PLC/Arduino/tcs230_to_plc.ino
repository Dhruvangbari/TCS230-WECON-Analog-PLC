#define S2 4
#define S3 5
#define sensorOut 2
#define pwmOut 9

unsigned long duration;

int readColor(bool s2, bool s3) {
  digitalWrite(S2, s2);
  digitalWrite(S3, s3);
  delay(100);
  duration = pulseIn(sensorOut, LOW);
  return duration;
}

void setup() {
  pinMode(S2, OUTPUT);
  pinMode(S3, OUTPUT);
  pinMode(sensorOut, INPUT);
  pinMode(pwmOut, OUTPUT);
}

void loop() {
  int red = readColor(LOW, LOW);
  int green = readColor(HIGH, HIGH);
  int blue = readColor(LOW, HIGH);

  int minColor = min(red, min(green, blue));
  int pwmValue = map(minColor, 100, 1000, 0, 255);
  pwmValue = constrain(pwmValue, 0, 255);

  analogWrite(pwmOut, pwmValue);
}
