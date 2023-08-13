#include <RH_ASK.h>
#include <SPI.h> 

//RH_ASK tx;  // SPI D12 MISO (5VCC)
RH_ASK tx{2000,2,3}; //bps,RX,TX*

int i=0;               // example dummy variable 
String b,x=",";        // delimiters for easy receiving extraction 
const char* c="test,"; // Transmit ready data type
char d[5];             // int to string to char array 

void setup() {
   Serial.begin(9600);
   if (!tx.init())Serial.println("init failed");
}

void loop() {
  
  i++;
  c="pass,";           // Now const char points to this address 
  //Serial.println(c);
  b=(String)i+x;       // convert int to string with delimiter on the end
  b.toCharArray(d,5);  // convert that string to char array
  c=d;                 // point const char to this address resetting other
  tx.send((uint8_t *)c, strlen(c)); // ask_driver send parameters 
  tx.waitPacketSent();
  if(i>100){i=0;}
  delay(50);
}
