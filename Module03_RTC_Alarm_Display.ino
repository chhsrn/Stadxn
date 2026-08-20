/*
  ========================================================================
  FILE NAME:    Module03_RTC_Alarm_Display.ino
  MODULE:       Module 03 - DS3231 RTC + Display + Active Buzzer
  TARGET BOARD: ESP32 DevKit V1
  CODE ID:      M03-002
  ========================================================================
  
  [ WIRING DIAGRAM ]
  - Buzzer (+) -> ESP32 GPIO 12
  - Buzzer (-) -> ESP32 GND
  - SDA (RTC & Display) -> ESP32 GPIO 21
  - SCL (RTC & Display) -> ESP32 GPIO 22
  ========================================================================
*/

#include <Wire.h>
#include <Adafruit_GFX.h>
#include <Adafruit_SSD1306.h>
#include <RTClib.h>

#define SCREEN_WIDTH 128
#define SCREEN_HEIGHT 64
#define OLED_RESET    -1
#define BUZZER_PIN    12  // ជើង Active Buzzer

Adafruit_SSD1306 display(SCREEN_WIDTH, SCREEN_HEIGHT, &Wire, OLED_RESET);
RTC_DS3231 rtc;

// កំណត់ម៉ោងរោទិ៍ (17:25)
const int ALARM_HOUR = 17;
const int ALARM_MINUTE = 25;
const int ALARM_DURATION = 12; // រយៈពេលរោទិ៍ ១២ វិនាទី

void setup() {
  Serial.begin(115200);

  pinMode(BUZZER_PIN, OUTPUT);
  digitalWrite(BUZZER_PIN, LOW); // បិទ Buzzer ជាមុន

  Wire.begin(21, 22);

  if(!display.begin(SSD1306_SWITCHCAPVCC, 0x3C)) {
    for(;;);
  }

  if (!rtc.begin()) {
    for(;;);
  }

  if (rtc.lostPower()) {
    rtc.adjust(DateTime(F(__DATE__), F(__TIME__)));
  }

  display.setTextColor(SSD1306_WHITE);
}

void loop() {
  DateTime now = rtc.now();

  display.clearDisplay();

  // --- បង្ហាញ Header (ទំហំ Size 2 ថេរ គ្មានចលនា) ---
  display.setTextSize(2);
  display.setCursor(10, 16);
  display.print("REAL TIME");

  // --- បង្ហាញ ម៉ោង : នាទី : វិនាទី (ទំហំ Size 2 ថេរ) ---
  display.setTextSize(2);
  display.setCursor(16, 40);
  char timeBuffer[9];
  sprintf(timeBuffer, "%02d:%02d:%02d", now.hour(), now.minute(), now.second());
  display.print(timeBuffer);

  // --- ប្រព័ន្ធពិនិត្យ និងបញ្ជាសម្លេងរោទិ៍ (Alarm Logic 17:25) ---
  if (now.hour() == ALARM_HOUR && now.minute() == ALARM_MINUTE && now.second() < ALARM_DURATION) {
    digitalWrite(BUZZER_PIN, (now.second() % 2 == 0) ? HIGH : LOW);
  } else {
    digitalWrite(BUZZER_PIN, LOW);
  }

  display.display();
  delay(100);
}
