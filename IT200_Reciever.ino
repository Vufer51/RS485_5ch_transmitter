
#include <SoftEasyTransfer.h>
#include <SoftwareSerial.h>

#define DIR 4                                       // переключатель прием\передача
#define INPUTPIN1 9
#define INPUTPIN2 10
#define INPUTPIN3 11
#define INPUTPIN4 12
#define INPUTPIN5 13
SoftwareSerial mySerial(3, 6);                     // Serial для RS485

 
SoftEasyTransfer ET;
  
  
struct RECEIVE_DATA_RS485{  
  int pin1;
  int pin2;
  int pin3;
  int pin4;
  int pin5; 
};
 
RECEIVE_DATA_RS485 rxdata; 


void setup(){
  Serial.begin(9600); 
  mySerial.begin(9600);
  
    
   
  ET.begin(details(rxdata), &mySerial);
  pinMode(INPUTPIN1, OUTPUT);
  pinMode(INPUTPIN2, OUTPUT);
  pinMode(INPUTPIN3, OUTPUT);
  pinMode(INPUTPIN4, OUTPUT);
  pinMode(INPUTPIN5, OUTPUT);
  
  pinMode(DIR, OUTPUT);
  digitalWrite(DIR, LOW);                          // включаем прием 
  
 
}

void loop(){
  
  if(ET.receiveData()){                         
                                                  
  delay(10);
    digitalWrite(INPUTPIN1, rxdata.pin1);
    digitalWrite(INPUTPIN2, rxdata.pin2);
    digitalWrite(INPUTPIN3, rxdata.pin3);
    digitalWrite(INPUTPIN4, rxdata.pin4);
    digitalWrite(INPUTPIN5, rxdata.pin5);
Serial.print(rxdata.pin1);
     
  }
 
}
