// This is the port from FastLed lib to Adafruit_Neopixel lib
// which is working well with Banggood RGBW WS2812B product link in Readme file.
// thach@facebit.net

#include <Adafruit_NeoPixel.h>
 
// TODO: EDIT YOUR PINOUT HERE
#define PIN        3
// TODO: EDIT YOUR LED HERE
#define NUMPIXELS 150
#define serialRate 115200

// Banggood led NEO_GRBW
Adafruit_NeoPixel pixels(NUMPIXELS, PIN, NEO_GRBW + NEO_KHZ800);

void setup() {
  pixels.begin();
  Serial.begin(serialRate);
 
  // Send "Magic Word" string to host
  Serial.print("Ada\n");

  // flash red then green then blue for testing
  for (int i = 0; i < NUMPIXELS; i++){
      pixels.setPixelColor(i, pixels.Color(80, 0, 0));
  }
  pixels.show();
  delay(500);

  for (int i = 0; i < NUMPIXELS; i++){
      pixels.setPixelColor(i, pixels.Color(0, 80, 0));
  }
  pixels.show();
  delay(500);

  for (int i = 0; i < NUMPIXELS; i++){
      pixels.setPixelColor(i, pixels.Color(0, 0, 80));
  }
  pixels.show();
  delay(500);
  
  // clear all leds
  pixels.clear();
  pixels.show();
}

// Baudrate, higher rate allows faster refresh rate and more LEDs
#define serialRate 115200

// Adalight sends a "Magic Word" before sending the pixel data
uint8_t prefix[] = {'A', 'd', 'a'}, hi, lo, chk, i;

void loop() { 
  // Wait for first byte of Magic Word
  for(i = 0; i < sizeof prefix; ++i) {
    waitLoop: while (!Serial.available()) ;;
    // Check next byte in Magic Word
    if(prefix[i] == Serial.read()) continue;
    // otherwise, start over
    i = 0;
    goto waitLoop;
  }
  
  // Hi, Lo, Checksum  
  while (!Serial.available()) ;;
  hi=Serial.read();
  while (!Serial.available()) ;;
  lo=Serial.read();
  while (!Serial.available()) ;;
  chk=Serial.read();
  
  // If checksum does not match go back to wait
  if (chk != (hi ^ lo ^ 0x55)) {
    i=0;
    goto waitLoop;
  }
  
  // Read the transmission data and set LED values
  for (uint8_t i = 0; i < NUMPIXELS; i++) {
    byte r, g, b;    
    while(!Serial.available());
    r = Serial.read();
    while(!Serial.available());
    g = Serial.read();
    while(!Serial.available());
    b = Serial.read();
    
    pixels.setPixelColor(i, pixels.Color(r, g, b));
  }
  
  pixels.show();
}
