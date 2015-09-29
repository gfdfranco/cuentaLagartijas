#include <NewPing.h>
#include <LiquidCrystal.h>
#define TRIGGER_PIN  10  
#define ECHO_PIN     6  
#define MAX_DISTANCE 250

LiquidCrystal lcd(12, 11, 5, 4, 3, 2);
NewPing sonar(TRIGGER_PIN, ECHO_PIN, MAX_DISTANCE);
int var=0;
int distancia=0;
boolean bandera=true;
void setup() {
  Serial.begin(9600);
  pinMode(8,OUTPUT);
  pinMode(9,OUTPUT);
  // put your setup code here, to run once:
   analogWrite(9,100);
   lcd.begin(16, 2);
  // Print a message to the LCD.
 
}

void loop() {
   
   unsigned int uS = sonar.ping(); 
  distancia=(uS / US_ROUNDTRIP_CM); 
  Serial.println(distancia);
  if(distancia<4)
  {
    if(bandera==true)
    {
    digitalWrite(8,HIGH);
    var=var+1;
    lcd.clear();
    lcd.print(var);
    delay(300);
    digitalWrite(8,LOW);
    bandera=false;
    }
  }
  if(distancia>8)
  {
    bandera=true;
  }
}