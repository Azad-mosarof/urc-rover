#include <SoftwareSerial.h>
#include <Servo.h>
SoftwareSerial ArduinoUno(3,2);
Servo myservo;  
int pos = 0;

void setup(){
	Serial.begin(9600);
	ArduinoUno.begin(4800);
  myservo.attach(9);
}

void loop(){
	// while(ArduinoUno.available()>0){
	//   int val = ArduinoUno.parseInt();
	//   if(ArduinoUno.read()== '\n'){
	//     Serial.println(val);
	//   }
  // }
  for (pos = 0; pos <= 180; pos += 1) { 
    myservo.write(pos);              
    delay(15);                     
  }
  for (pos = 180; pos >= 0; pos -= 1) { 
    myservo.write(pos);              
    delay(15);                   
  }
}