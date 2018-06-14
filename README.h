# RGB-breathing-light
#from Adafruit_NeoPixel to lamp ring breathing light
#include <Adafruit_NeoPixel.h>
const int i;


#define PIN 12
#define NB 12

Adafruit_NeoPixel  LED = Adafruit_NeoPixel(NB, PIN, NEO_GRB + NEO_KHZ800);

void setup() {
  LED.begin();
  LED.show();
}

// In typical easy Arduino fashion loop() is the main body, all other functions are called within here 
void loop(){
   breathLED();
}

void colorWipe(uint32_t c, uint8_t wait) {
  for( uint16_t i=0; i<LED.numPixels(); i++) {
    LED.setPixelColor(i, c);
    LED.show();
    delay(wait);
  }
}

void breathLED() {
  for (int j; j < 255 ; j=j+4) {
   for(int i=0;i<NB;i++){
    LED.setPixelColor(i, LED.Color(j,0,0)); // lighting  in turn
    LED.show();
    delay(2); //time
  }
  }
  for (int j= 255; j> 0; j=j-4) {
    for(int i=0;i<NB;i++){
    LED.setPixelColor(i, LED.Color(j,0,0));
    LED.show();
    delay(2);
  }
}
}
