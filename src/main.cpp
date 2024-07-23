#include <Arduino.h>
const int trigPin = 5; // פין Trig של HC-SR04
const int echoPin = 18; // פין Echo של HC-SR04
const int ledPin = 2; // פין ה-LED
const int speedThreshold = 50; // ערך סף למהירות (במטרים לשנייה)



void setup() {
  pinMode(trigPin, OUTPUT); // הגדר את פין Trig כקלט
  pinMode(echoPin, INPUT);  // הגדר את פין Echo כקלט
  pinMode(ledPin, OUTPUT);  // הגדר את פין ה-LED כהוצאה
   Serial.begin(9600);
  Serial.println("Hello, ESP32!");
}

void loop() {
  // שלח פולס קצר כדי להפעיל את החיישן
  digitalWrite(trigPin, LOW);
  delayMicroseconds(2);
  digitalWrite(trigPin, HIGH);
  delayMicroseconds(10);
  digitalWrite(trigPin, LOW);

  // מדוד את הזמן שהאולטרה-סוניק לוקח לחזור
  long duration = pulseIn(echoPin, HIGH);

  // המר את הזמן למטרים
  float distance = duration * 0.0344 / 2; // המר לחישוב מטרים

  // חישוב מהירות על פי מרחק
  // נניח שנעשית קריאה כל 1 שנייה
  float speed = distance; // אם היית מדוד מרחק מדי פעם, תוכל לחשב מהירות על פי שינוי מרחק בזמן

  Serial.print("Distance: ");
  Serial.print(distance);
  Serial.print(" meters");
  Serial.print(" Speed: ");
  Serial.print(speed);
  Serial.println(" meters/second");

  // השווה את המהירות לערך הסף והפעל את ה-LED אם המהירות גבוהה
  if (speed > speedThreshold) {
    digitalWrite(ledPin, HIGH); // הפעל את ה-LED
  } else {
    digitalWrite(ledPin, LOW);  // כבה את ה-LED
  }

  delay(1000); // המתן שנייה לפני קריאה נוספת
}