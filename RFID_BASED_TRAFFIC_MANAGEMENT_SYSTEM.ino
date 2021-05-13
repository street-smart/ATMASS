
#include <SPI.h>
#include <MFRC522.h>
 
#define SS_PIN 10
#define RST_PIN 9
MFRC522 mfrc522(SS_PIN, RST_PIN);   

const int trigPin = 5;
const int echoPin = 6;
const int ledPin = 3;

long duration;
int distance; 
int safetyDistance;
int redled = 7;
int yellowled = 4;
int greenled = 2;

void setup() {
pinMode(trigPin, OUTPUT); 
pinMode(echoPin, INPUT); 
pinMode(ledPin, OUTPUT);
Serial.begin(9600); 
  SPI.begin();      
  mfrc522.PCD_Init();   
  Serial.println("Surveilance System Active at MPSTME!");
  Serial.println();

  

  pinMode (7, OUTPUT);
  pinMode (4, OUTPUT);
  pinMode (2, OUTPUT);
}

void loop()
{ 
   
   TRAFFIC();
   
}

  void RFID()

 { 
  if ( ! mfrc522.PICC_IsNewCardPresent()) 
  {
    return;
  }
  
  if ( ! mfrc522.PICC_ReadCardSerial()) 
  {
    
    return;
  }
 
  
  
  //Show UID on serial monitor
  Serial.print("Car unique identification");
  Serial.print("\n");
  String content= "";
  byte letter;
  for (byte i = 0; i < mfrc522.uid.size; i++) 
  {
     Serial.print(mfrc522.uid.uidByte[i] < 0x10 ? " 0" : " ");
     Serial.print(mfrc522.uid.uidByte[i], HEX);
     content.concat(String(mfrc522.uid.uidByte[i] < 0x10 ? " 0" : " "));
     content.concat(String(mfrc522.uid.uidByte[i], HEX));
  }
  Serial.println();

  content.toUpperCase();
  if (content.substring(1) == "0B 9D FA 29") // this is your RFID tag's unique id which you need to change 
  {
    Serial.print("The CAR NUMBER GJXXXXXX has broken and signal and has been reported:");
 
   
  }
  
 
 
 }

void TRAFFIC()

{ 
  
  
   digitalWrite (redled, 1);
   
for (float f=0; f<=240; f++)
  {
    RFID();
    
    
    
  }
  
  digitalWrite (redled, 0);
  
   
      
     
  
    
     

   
    
   digitalWrite (yellowled, 1); 
   delay (3000); 
   digitalWrite (yellowled, 0);
   digitalWrite (greenled, 1);
   delay (5000);
   digitalWrite (greenled, 0);
   delay (500);
   digitalWrite (greenled, 1);
   delay (500);    
   digitalWrite (greenled, 0);
   delay (500);
   digitalWrite (greenled, 1);
   delay (500);
   digitalWrite (greenled, 0);
  delay (500);
  digitalWrite (greenled, 1);
  delay (500);
  digitalWrite (greenled, 0);
  delay (500);
  digitalWrite (greenled, 1);
  delay (500);
  digitalWrite (greenled, 0);
  RFID();
  
 }
