#include <Servo.h>

Servo myservo;
int flame = 11;
int smoke = 12;
int red = 2;
int green = 3 ;
int buzzer = 10 ;

void setup ()
{
  pinMode (flame, INPUT) ;
  pinMode (smoke, INPUT) ;
  pinMode (red, OUTPUT) ;
  pinMode (green, OUTPUT) ;
  pinMode (buzzer, OUTPUT) ;
  myservo.attach(8);
  myservo.write(0);
}

void loop ()
{
  float sens_value = analogRead(smoke);
  int f = digitalRead(flame) ;
  int s = digitalRead(smoke);

  Serial.print("Sensor Value: ");
  Serial.print(sens_value);
  
  if ( f == HIGH or s == HIGH)
  {
    digitalWrite(red, HIGH);
    digitalWrite(buzzer, HIGH);
    digitalWrite(green, LOW);
    myservo.write(180);
  }
  else
  {
    digitalWrite(red, LOW);
    digitalWrite(green, HIGH);
    digitalWrite(buzzer, LOW);
    myservo.write(0);
  }
 
  delay(100);
}