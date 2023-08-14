// Uno Rx to DS-12 Tx
// Uno Tx to DS-12 Rx

  void setup(){
  Serial.begin(9600);
  }

  void loop(){
  Serial.write('A');
  delay(500);
  }
// end of code
