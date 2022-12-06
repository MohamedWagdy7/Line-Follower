#include <LiquidCrystal.h>

LiquidCrystal lcd(13,12,7,2,3,4);

//motor A
#define PWMA 7
#define INPA1 5
#define INPA2 6

//motor B
#define PWMB 11
#define INPB1 9
#define INPB2=10

//sensors
#define rightSensor A0;
#define middleSensor A1;
#define leftSensor A2;
int valueR ;
int valueM ;
int valueL ;
char letter;

void setup() {
 pinMode(PWMA,OUTPUT);
 pinMode(INPA1,OUTPUT);
 pinMode(INPA2,OUTPUT);
 pinMode(PWMA,OUTPUT);
 pinMode(INPB1,OUTPUT);
 pinMode(INPB2,OUTPUT);
 lcd.begin(16,2);
 lcd.setCursor(2,0);
 lcd.print(F("DebugBunny"));
 lcd.setCursor(5,1);
 lcd.print(F("START"));
 delay(1000);
 // to delete "START"
 lcd.setCursor(5,1);
 lcd.print(F("     "));
 letter = 'Z' ;
}

void loop() {
 AAA:
 valueR = digitalRead(rightSensor);
 valueM = digitalRead(middleSensor);
 valueL = digitalRead(leftSensor);
 analogWrite(PWMA,120);//motor speed
 analogWrite(PWMB,120);//motor speed
//Motion Cases
if (valueM==HIGH && valueR==LOW  && valueL==LOW)
Forward();
if (valueM==HIGH && valueR==HIGH && valueL==LOW)
Right();
if (valueM==HIGH && valueR==LOW  && valueL==HIGH)
Left();
if (valueM==LOW  && valueR==LOW  && valueL==LOW)
Stop();

if (valueM==HIGH && valueR==HIGH && valueL==HIGH && letter=='Z')
{
  letter='A'; // display letter A
  lcdA();
  Forward();
  goto AAA;
  }
  
  if (valueM==HIGH && valueR==HIGH && valueL==HIGH && letter=='A')
  {
    letter='B'; // display letter B
    lcdB();
    Forward();
    goto AAA;
    }
     if (valueM==HIGH && valueR==HIGH && valueL==HIGH && letter=='B')
  {
    letter='C'; // display letter C
    lcdC();
    Forward();
    goto AAA;
    }
     if (valueM==HIGH && valueR==HIGH && valueL==HIGH && letter=='C')
  {
    letter='D'; // display letter D
    lcdD();
    Forward();
    goto AAA;
  }
}
void Forward()
{
 digitalWrite(INPA1,HIGH);
 digitalWrite(INPA2,LOW);  
 digitalWrite(INPB1,HIGH); 
 digitalWrite(INPB2,LOW);
 lcd.setCursor(5,1);
 lcd.print(F("        ")); 
 lcd.setCursor(5,1);
 lcd.print(F("Forward"));
  }
  void Right()
{
 digitalWrite(INPA1,HIGH);
 digitalWrite(INPA2,LOW);  
 digitalWrite(INPB1,LOW); 
 digitalWrite(INPB2,HIGH);
 lcd.setCursor(5,1);
 lcd.print(F("        "));
 lcd.setCursor(5,1);
 lcd.print(F("RIGHT"));
  }
   void Left()
{
 digitalWrite(INPA1,LOW);
 digitalWrite(INPA2,HIGH);  
 digitalWrite(INPB1,HIGH); 
 digitalWrite(INPB2,LOW); 
 lcd.setCursor(5,1);
 lcd.print(F("        "));
 lcd.setCursor(5,1);
 lcd.print(F("LEFT"));
  }
   void Stop()
{
 digitalWrite(INPA1,LOW);
 digitalWrite(INPA2,LOW);  
 digitalWrite(INPB1,LOW); 
 digitalWrite(INPB2,LOW); 
 lcd.setCursor(5,1);
 lcd.print(F("        "));
 lcd.setCursor(6,2);
 lcd.print(F("END"));
  }
  void lcdA()
  {
    lcd.setCursor(2,1);
    lcd.print(F(" "));
    lcd.setCursor(2,1);
    lcd.print(F("A"));
    }
     void lcdB()
  {
    lcd.setCursor(2,1);
    lcd.print(F(" "));
    lcd.setCursor(2,1);
    lcd.print(F("B"));
    }
     void lcdC()
  {
    lcd.setCursor(2,1);
    lcd.print(F(" "));
    lcd.setCursor(2,1);
    lcd.print(F("C"));
    }
     void lcdD()
  {
    lcd.setCursor(2,1);
    lcd.print(F(" "));
    lcd.setCursor(2,1);
    lcd.print(F("D"));
    }
