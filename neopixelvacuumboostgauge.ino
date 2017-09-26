#include <Adafruit_NeoPixel.h>

Adafruit_NeoPixel pixels = Adafruit_NeoPixel(40, 6, NEO_GRB + NEO_KHZ800);

int pressure;

void setup() {
  // put your setup code here, to run once:
  pixels.begin();
  Serial.begin(9600);
  
}

void loop() {

  pressure = map(analogRead(A0), 41, 940, 0, 1000);
  Serial.println(pressure);

  if (pressure < 140) {
    pixels.clear();
    for (int i = 0; i < 140 - pressure; i++) {
      pixels.setPixelColor(i, pixels.Color(0,50,0));  
    }
    pixels.show();
  } else if (pressure > 142) {
    pixels.clear();
    for (int i = 0; i < pressure - 142; i++) {
      pixels.setPixelColor(i, pixels.Color(50,0,0));  
    }
    pixels.show();
  } else {
    pixels.clear();
    pixels.setPixelColor(0, pixels.Color(0,0,50));
    pixels.show();
  }

  delay(200);
}
