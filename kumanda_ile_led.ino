#include <IRremote.hpp>
int kumandaPin = 9;
int s1=0;
int m1=1;
int s2=9;
int m2=10;
int s3=11;
int m3=12;
int s4=13;
int m4=A3;
int s5=A4;
int m5=A5;

IRrecv kumanda(kumandaPin);
decode_results sonuclar;

void setup()
{
  kumanda.enableIRIn();
 pinMode(s1,OUTPUT);
 pinMode(m1,OUTPUT);
 pinMode(s2,OUTPUT);
 pinMode(m2,OUTPUT);
 pinMode(s3,OUTPUT);
 pinMode(m3,OUTPUT);
 pinMode(s4,OUTPUT);
 pinMode(m4,OUTPUT);
 pinMode(s5,OUTPUT);
 pinMode(m5,OUTPUT);
  Serial.begin(9600);
}
 
void loop()
{
  if(kumanda.decode(&sonuclar))
  {
    Serial.print("Tuş kodu: ");
    Serial.println(sonuclar.value, HEX);
    kumanda.resume();

    if(sonuclar.value == 0xFFA25D)
    {
      digitalWrite(kirmiziledPin, HIGH);
    }
    if(sonuclar.value == 0xFF629D)
    {
      digitalWrite(yesilledPin, HIGH);
    }
    if(sonuclar.value == 0xFFE21D)
    {
      digitalWrite(maviledPin, HIGH);
    }
    if(sonuclar.value == 0xFF6897)
    {
      digitalWrite(kirmiziledPin, LOW);
      digitalWrite(yesilledPin, LOW);
      digitalWrite(maviledPin, LOW);
    }
    if(sonuclar.value == 0xFFB04F)
    {
      digitalWrite(kirmiziledPin, HIGH);
      digitalWrite(yesilledPin, HIGH);
      digitalWrite(maviledPin, HIGH);
    }
    
  }

  delay(100);
}
