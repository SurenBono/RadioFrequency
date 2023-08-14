// Uno Rx to DS-12 Tx
// Uno Tx to DS-13 Rx

int pz = 11;             // piezo (+)11 (-)GND

void setup() {
  Serial.begin(9600);    // Same as tx
  pinMode(pz, OUTPUT);
  tone(pz, 4000, 30);    // ,freq,time
  tone(pz, 4000, 30);    // beep beep init
}

void loop() {
  if (Serial.available()) {
    char data = Serial.read();
    if (data == 'A') {tone(pz, 4000, 30);}
  } 
}
// end of code
