#include <SoftwareSerial.h>

SoftwareSerial mySerial (7, 8);
int ledPin =13;
int valueCrash = 1;
int crashpin=3;
char msg;
char call;
void setup()
{
mySerial.begin (9600) ;
// Setting the baud rate of GSM Module 
Serial.begin (9600);
Serial.begin (9600);
delay (100);
pinMode(ledPin, OUTPUT);
pinMode (crashpin, INPUT_PULLUP);
}
void loop ()
{
valueCrash = digitalRead (crashpin); // read the state of the crash sensor 
digitalWrite (ledPin, !valueCrash); // light LED if switch closed 
Serial.println (valueCrash);
delay(1000);

if (valueCrash==0)
{
Serial.println ("Accident occured"); 
digitalWrite (ledPin, HIGH);
SendMessage();

delay (1000);
}
 
if (mySerial.available() >0) 
Serial.write (mySerial.read());
}

//to send a Message
void SendMessage()
{
Serial.println("Message ");
mySerial.println("AT+CMGF=1"); //Sets the GSM Module in Text Mode 
delay(1000); // Delay of 1000 milli seconds or 1 second
mySerial.println("AT+CMGS=\"+9779863858330\"\r"); // Replace x with mobile number delay (1000) ;
delay(1000);
mySerial.println("Aayush is hit in an accident");// The SMS text you want to send
delay(100);
mySerial.println((char)26);// ASCII code of CTRL+Z
delay(1000);
}
