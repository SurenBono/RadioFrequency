#include <RH_ASK.h>
#include <SPI.h> 

//RH_ASK tx;  // SPI 
RH_ASK tx{2000,2,3}; //bps,RX,TX*

int i=0;
String b,x=",";
const char* c="test,";
char d[5];

void setup() {
   Serial.begin(9600);
   if (!tx.init())Serial.println("init failed");
}

void loop() {
  
  i++;
  c="pass,";
  Serial.println(c);
  b=(String)i+x;
  b.toCharArray(d,5);
  c=d;
  tx.send((uint8_t *)c, strlen(c));
  tx.waitPacketSent();
  if(i>100){i=0;}
  delay(50);
}
