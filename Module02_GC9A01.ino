/*
  ========================================================================
  FILE NAME:    Module02_TextScroll.ino
  MODULE:       Module 02 - GC9A01 / OLED 4-Pin Display Text Scroll Test
  TARGET BOARD: ESP32 DevKit V1
  ========================================================================
  
  [ របៀបតខ្សែ / WIRING DIAGRAM ]
  - VCC -> ESP32 3.3V
  - GND -> ESP32 GND
  - SCK -> ESP32 GPIO 22 (D22)
  - SDA -> ESP32 GPIO 21 (D21)
  ========================================================================
*/

#include <Wire.h>
#include <Adafruit_GFX.h>
#include <Adafruit_SSD1306.h>

#define SCREEN_WIDTH 128
#define SCREEN_HEIGHT 64  // ប្រសិនបើអេក្រង់ធំជាងនេះ អាចដូរជា 128 ឬ 240
#define OLED_RESET    -1

Adafruit_SSD1306 display(SCREEN_WIDTH, SCREEN_HEIGHT, &Wire, OLED_RESET);

// កំណត់ពាក្យដែលត្រូវរត់
String scrollText = "Try To Be Different";
int xPos = SCREEN_WIDTH; // ចាប់ផ្តើមចេញពីគែមខាងស្តាំបង្អស់

void setup() {
  Wire.begin(21, 22); // SDA = GPIO 21, SCL = GPIO 22

  // 0x3C គឺជា I2C Address ស្ដង់ដារ
  if(!display.begin(SSD1306_SWITCHCAPVCC, 0x3C)) {
    for(;;); // ប្រសិនបើមិនឃើញអេក្រង់ វានឹងឈប់ត្រឹមនេះ
  }

  display.clearDisplay();
  display.setTextWrap(false); // បិទការចុះបន្ទាត់ស្វ័យប្រវត្តិ ដើម្បីឱ្យអក្សររត់ជាបន្ទាត់ត្រង់
}

void loop() {
  display.clearDisplay(); // លុបរូបចាស់ចេញមុននឹងគូរអក្សរនៅតំណែងថ្មី

  // កំណត់ទំហំ និងពណ៌អក្សរ
  display.setTextSize(2);
  display.setTextColor(SSD1306_WHITE);
  
  // កំណត់ទីតាំងអក្សរ (X, Y)
  display.setCursor(xPos, 20);
  display.print(scrollText);
  display.display();

  // រំកិលអក្សរទៅខាងឆ្វេង ២ pixel រៀងរាល់ជុំ
  xPos -= 2;

  // ប្រសិនបើអក្សររត់ផុតអេក្រង់ខាងឆ្វេង ឱ្យវាចាប់ផ្តើមសារថ្មីពីខាងស្តាំ
  // (ទំហំអក្សរ Size 2 មានប្រវែងប្រហែល 12 Pixel ក្នុងមួយតួអក្សរ)
  int textWidth = scrollText.length() * 12;
  if (xPos < -textWidth) {
    xPos = SCREEN_WIDTH;
  }

  delay(30); // សម្រួលល្បឿនរត់ (ទាបជាងនេះរត់លឿន ខ្ពស់ជាងនេះរត់យឺត)
}
