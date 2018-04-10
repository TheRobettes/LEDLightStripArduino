#include <Adafruit_NeoPixel.h>
#define PIN 6
#define NUM_LEDS 300
Adafruit_NeoPixel strip = Adafruit_NeoPixel(NUM_LEDS, PIN, NEO_GRB + NEO_KHZ800);
int sensorPin = 9;  //input sensor (limit switch)
int sensorValue = 0;
int state = 0;


void setup() {
    // put your setup code here, to run once:
    strip.begin();
    strip.show();
    Serial.begin(9600);
    while (!Serial);
    //pinMode(buttonPin,IMPUT);
}

//Set a singular pixel a given color
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

//Set all LEDs to a given color
void setAll(byte red, byte green, byte blue) {
    for(int i = 0; i < NUM_LEDS; i++ ) {
        setPixel(i, red, green, blue);
    }
    strip.show();
}


// put your main code here
void loop() {
    sensorValue = digitalRead(sensorPin);
    //0 if button pushed and 1 if not 
    Serial.println(sensorValue);
    strip.setBrightness(90);

    //button is pressed, turn green  
    if (sensorValue == 0) {
        setAll(0,255,0);
    }

    //button is not pressed, turn pink
    else {
        setAll(220,20,70);
    }
}


