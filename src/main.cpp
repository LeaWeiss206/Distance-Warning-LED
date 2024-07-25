#include <Arduino.h>
#include <WiFi.h>
#include <HTTPClient.h>
#include <ArduinoJson.h>



// הגדרות החיישן וה-WiFi
const int trigPin = 5;
const int echoPin = 18;
const int ledPin = 2;
const int dangerousDistance = 10;
const int forbiddenDistance = 20;
const char* ssid = "Wokwi-GUEST";
const char* password = "";



float distance = 0;

void setup() {
  Serial.begin(9600);
  pinMode(trigPin, OUTPUT);
  pinMode(echoPin, INPUT);
  pinMode(ledPin, OUTPUT);

  // התחברות לרשת ה-WiFi
  WiFi.begin(ssid, password);
  while (WiFi.status() != WL_CONNECTED) {
    delay(1000);
    Serial.println("Connecting to WiFi...");
  }
  Serial.println("Connected to WiFi");
}

void loop() {
  // שליחת פולס קצר להפעלת החיישן
  digitalWrite(trigPin, LOW);
  delayMicroseconds(2);
  digitalWrite(trigPin, HIGH);
  delayMicroseconds(10);
  digitalWrite(trigPin, LOW);

  // מדידת הזמן שלוקח לפולס לחזור
  long duration = pulseIn(echoPin, HIGH);
  
  // חישוב המרחק בסנטימטרים
  distance = duration * 0.0344 / 2;

  // הצגת הערך שהתקבל
  Serial.print("Distance: ");
  Serial.print(distance);
  Serial.println(" cm");

  // externalDistance = distance;
  // Serial.print("Speed: ");
  // Serial.print(distance);
  // Serial.println(" cm/s");

  // השוואת המרחק לערך הסף והפעלת ה-LED אם המרחק גדול
   if (distance <= forbiddenDistance) {
    digitalWrite(ledPin, HIGH); // הפעלת ה-LED
    if(distance <= dangerousDistance)
    Serial.println("Break");

  } else {
    digitalWrite(ledPin, LOW); // כיבוי ה-LED
  }

  delay(1000); // המתנה של שנייה לפני קריאה נוספת
}
