// This code is for ESP32 NodeMCU-32S
#include <Wire.h>
#include <Adafruit_GFX.h>
#include <Adafruit_SSD1306.h>
#include <FluxGarage_RoboEyes.h>

#define OLED_RST_PIN -1
#define SCREEN_I2C_ADDR 0x3C
#define SCREEN_WIDTH 128
#define SCREEN_HEIGHT 64

Adafruit_SSD1306 display(SCREEN_WIDTH, SCREEN_HEIGHT, &Wire, OLED_RST_PIN);
RoboEyes<Adafruit_SSD1306> roboEyes(display);

int buttonState = 0, lastButtonState = 0, pressCount = 0;
unsigned long lastPressTime = 0,doubleClickGap = 500;

void setup() {

  Wire.begin(21, 22);
  Serial.begin(115200);

  if (!display.begin(SSD1306_SWITCHCAPVCC, SCREEN_I2C_ADDR)) {
    Serial.println(F("SSD1306 allocation failed"));
    while (true);
  }

  roboEyes.begin(SCREEN_WIDTH, SCREEN_HEIGHT, 100);

  roboEyes.setWidth(36, 36);
  roboEyes.setHeight(40, 40);
  roboEyes.setBorderradius(10, 10);
  roboEyes.setSpacebetween(15);

  roboEyes.setAutoblinker(ON, 3, 3);
  roboEyes.setIdleMode(ON, 5, 5);

  pinMode(14, INPUT_PULLUP);
pinMode(17, INPUT_PULLUP);
pinMode(33, OUTPUT);

  Serial.println("Welcome");

  hi();
  normal();
}

void loop() {
  roboEyes.update();
 buttonState = digitalRead(14);
    if (buttonState == LOW && lastButtonState == HIGH) {
    unsigned long currentTime = millis();

    if (currentTime - lastPressTime <= doubleClickGap) {
      pressCount++;
    } else {
      pressCount = 1;
    }

    lastPressTime = currentTime;
    delay(50);
  }
 if (pressCount > 0 && (millis() - lastPressTime > doubleClickGap)) {
    if (pressCount == 2) {
      happy();
    }
    else if (pressCount >= 1) {
   angry();
  }
pressCount = 0;
   }
   
   lastButtonState = buttonState;
  if (digitalRead(17) == LOW) {
    pormodo();
  } 
}
void hi() {

  display.clearDisplay();
  display.setTextSize(2);
  display.setTextColor(SSD1306_WHITE);
  display.setCursor(20, 20);
  display.println(F("Welcome!"));
  display.display();

  delay(1000);
   Serial.println("hi");
}

void normal() {
    roboEyes.update();
  roboEyes.setMood(DEFAULT);
  delay(3000);
    Serial.println("normal");
}

void happy() {
   roboEyes.update();
   roboEyes.setMood(HAPPY);

  tone(33, 1500, 100);
  delay(150);
  tone(33, 2000, 100); 
  delay(150);
  tone(33, 2500, 300); 
  delay(350);

   normal();
   Serial.println("happy");
}

void angry() {
   roboEyes.update();
  roboEyes.setMood(ANGRY);

for (int i = 0; i < 4; i++) {
    tone(33, 250, 60); 
    delay(70);
    tone(33, 150, 60); 
    delay(70);
  }
  normal();
    Serial.println("angry");
  }
void tired() {
    roboEyes.update();
  roboEyes.setMood(TIRED);
 
 for (int freq = 800; freq >= 200; freq -= 15) {
    tone(33, freq, 25); 
    delay(20);
  }
  noTone(33);
  delay(50);
    Serial.println("tired");
}

void pormodo() {
  roboEyes.update();
  for (int x = 25; x >= 0; x--) {

    display.clearDisplay();
    display.setTextSize(4);
    display.setTextColor(SSD1306_WHITE);
    display.setCursor(40, 20);
    display.println(x);
    display.display();

    delay(60000);
  }
  tired();
  delay(500);
  happy();
    Serial.println("pormodo");
}
