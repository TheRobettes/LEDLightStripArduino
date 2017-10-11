 #include <Adafruit_NeoPixel.h>
  #define PIN 6
  #define NUM_LEDS 150
  Adafruit_NeoPixel strip = Adafruit_NeoPixel(NUM_LEDS, PIN, NEO_GRB + NEO_KHZ800);
  int sensorPinA5 = 5;
  int sensorValue = 0;
  int sensorValue2 = 0;
  int sensorValue3 = 0;
  int sensorValue4 = 0; 
  int sensorPin2 = 2;
  int state = 0;
  int sensorPin3 = 3;
  int sensorPin4 = 4; 
  /*Pins: 
   * A5 is potentiometer
   * 1 is the blue button
   * 6 is the light 
   */

void setup() {
  // put your setup code here, to run once:
  strip.begin();
  strip.show();
  Serial.begin(9600);
  while (!Serial);
  //pinMode(buttonPin,IMPUT);
}

void loop() {
  // put your main code here, to run repeatedly:
  //reads potetiometer and prints the value
    /* used for color intensity
    sensorValue = analogRead(sensorPin) / 4; */
    //Used for brightness
    sensorValue = digitalRead(sensorPin2);
    sensorValue3 = digitalRead(sensorPin3);
    sensorValue4 = digitalRead(sensorPin4);
    //prints line
    Serial.println(sensorValue);

strip.setBrightness(60);
if (sensorValue == 0) {
  state = 1;
}

if (state == 0) {
    setAll(254.5, 10, 10);
    strip.show();
}
else if (state == 1){
    setAll(30, 5, 255);
    strip.show();
}
else if (state == 2) {
  setAll(220, 20, 70);
  strip.show();
}
if (sensorValue3 == 0) {
  state = 2;
}
if (sensorValue4 == 0) {
  state = 0;
}
/*else {
  setAll(2, 50, 40);
  strip.show();
 */
//defaultColors(1, 0, 255, 0);
//strip.setBrightness(10);
//strip.show();



}

void setAll(byte red, byte green, byte blue) {
  for(int i = 0; i < NUM_LEDS; i++ ) {
    setPixel(i, red, green, blue);
  }
  strip.show();
}



void setPixel(int Pixel, byte red, byte green, byte blue)  {
  #ifdef ADAFRUIT_NEOPIXEL_H
  strip.setPixelColor(Pixel, strip.Color(red, green, blue));
  #endif
  #ifndef ADAFRUIT_NEOPIXEL_H
  leds[Pixel].r = red;
  leds[Pixel].g = green;
  leds[Pixel].b = blue;
  #endif
}


void defaultColors(int pixelNum, int redValue, int greenValue,  int blueValue) {
  strip.setPixelColor(pixelNum, redValue, greenValue, blueValue);
}


