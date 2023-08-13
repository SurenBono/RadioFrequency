#include <RH_ASK.h>
#include <SPI.h>

#define Pz  11      // Sound range reception test
//#define GND 4     // Digital Low for piezo (-)
#define f   4096    // 1024 x 4 Natural Crystal Octave

char *ext=",",msg;  // delimiter data extraction 

//RH_ASK rx;//SPI D11 MOSI  
RH_ASK rx{2000,2,3}; //bps,RX*,TX

void setup()
{
  Serial.begin(9600);  
  if (!rx.init()) Serial.println("init failed");
  pinMode(Pz, OUTPUT);
//  pinMode(GND, OUTPUT);
  
  digitalWrite(Pz,LOW);
  //digitalWrite(GND,LOW);

    tone(Pz,f);delay(30);noTone(Pz);delay(30);
    tone(Pz,f);delay(30);noTone(Pz);delay(30);
}

void loop()
{
    uint8_t buf[RH_ASK_MAX_MESSAGE_LEN];// Max Transmission 
    // uint8_t buf[6];
    uint8_t buflen = sizeof(buf);
    if (rx.recv(buf, &buflen))

    {
   tone(Pz,f);delay(30);noTone(Pz);    // Sound if received 
   //rx.printBuffer("rx: ",buf, buflen);
   char *msg=strtok(buf,ext);          // extract data
   Serial.println((char*)buf);         // print useful data
    }
}
//end of code
