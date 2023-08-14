int pz = 11;

void setup() {

  Serial.begin(9600);
  pinMode(pz, OUTPUT);
  tone(pz, 4000, 30);
  tone(pz, 4000, 30);
}

void loop() {

  if (Serial.available()) {
    char data = Serial.read();
    if (data == 'A') {tone(pz, 4000, 30);  }
  } 
}
// end of code
