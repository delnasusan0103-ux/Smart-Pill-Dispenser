#include <Wire.h>
#include <RTClib.h>
#include <LiquidCrystal_I2C.h>
#include <Servo.h> 

// Initialize objects
RTC_DS3231 rtc;
LiquidCrystal_I2C lcd(0x27, 16, 2);
Servo dispenserServo; 

// Define pins
const int buzzerPin = 8;
const int ledPin = 9;
const int servoPin = 10; 

// Define medicine delivery times
const int medHours[] = {16, 16, 16}; // 8 AM, 2 PM, 8 PM
const int medMinutes[] = {24, 24, 25};
const int totalDoses = sizeof(medHours) / sizeof(medHours[0]); 

bool triggered[3] = {false, false, false}; // Flag to prevent repeat 

void setup() {
  Serial.begin(9600); 

  lcd.init();
  lcd.backlight();
  lcd.clear(); 

  dispenserServo.attach(servoPin);
pinMode(buzzerPin, OUTPUT);
  pinMode(ledPin, OUTPUT); 

  if (!rtc.begin()) {
    lcd.setCursor(0, 0);
    lcd.print("RTC Not Found");
    while (1);
  } 

  // Uncomment only once to set time
  //rtc.adjust(DateTime(2025, 5, 19, 16, 8, 0)); 

  lcd.setCursor(0, 0);
  lcd.print("Pill Dispenser");
  delay(2000);
  lcd.clear();
} 

void loop() {
  DateTime now = rtc.now(); 

    // Print Time
  lcd.setCursor(0, 0);
  lcd.print("Time: ");
  if (now.hour() < 10) lcd.print("0");
  lcd.print(now.hour());
  lcd.print(":");
if (now.minute() < 10) lcd.print("0");
  lcd.print(now.minute());
  lcd.print(":");
  if (now.second() < 10) lcd.print("0");
  lcd.print(now.second()); 

  // Print Date
  lcd.setCursor(0, 1);
  lcd.print("Date: ");
  if (now.day() < 10) lcd.print("0");
  lcd.print(now.day());
  lcd.print("-");
  if (now.month() < 10) lcd.print("0");
  lcd.print(now.month());
  lcd.print("-");
  lcd.print(now.year()); 

  // Check each scheduled time
  for (int i = 0; i < totalDoses; i++) {
    if (now.hour() == medHours[i] && now.minute() == medMinutes[i]) {
      if (!triggered[i]) {
        dispensePill();
        triggered[i] = true;
      }
    } else {
      triggered[i] = false; // Reset trigger for next day
    }
  } 

  delay(1000);
} 

void dispensePill() {
  lcd.clear();
  lcd.setCursor(0, 0);
  lcd.print("Take Medicine!"); 

  digitalWrite(ledPin, HIGH);
  digitalWrite(buzzerPin, HIGH);
  delay(3000);
  digitalWrite(buzzerPin, LOW); 

  // Servo action
dispenserServo.write(90); // Rotate to release
  delay(2000);
  dispenserServo.write(0);  // Return to original
  delay(1000); 

  digitalWrite(ledPin, LOW); 

  lcd.clear();
}