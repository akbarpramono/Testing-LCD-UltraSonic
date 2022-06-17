#include <HCSR04.h>
#include<LiquidCrystal_I2C_Hangul.h>
#include<Wire.h>

LiquidCrystal_I2C_Hangul lcd(0x3F,16,2); //LCD 클래스 초기화
#define echoPin 13
#define trigPin 12
float reading;
long duration;
int distance;
int MAX;

void setup() {
  pinMode(trigPin,OUTPUT);
  pinMode(echoPin,INPUT);
  
  Serial.begin(9600);
  lcd.init();
  lcd.backlight();
  
}

void loop() {
  digitalWrite(trigPin, LOW);
  delayMicroseconds(5);
  digitalWrite(trigPin, HIGH);
  delayMicroseconds(10);
  digitalWrite(trigPin, LOW);
  duration = pulseIn(echoPin, HIGH);
  MAX = duration * 0.034 / 2*0;
  distance = duration * 0.034 / 2; 
  if (distance > 200){
    lcd.setCursor(0,0);
    lcd.print("Distance: ");
    lcd.print(MAX);
    lcd.println("Cm   ");
    delay(1000);
    }
  else{
    lcd.setCursor(0,0);
    lcd.print("Distance: ");
    lcd.print(distance);
    lcd.println("Cm   ");
    delay(1000);
  }
  
}
