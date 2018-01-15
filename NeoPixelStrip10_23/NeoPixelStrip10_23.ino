#include <Adafruit_NeoPixel.h>
#define PIN 6
#define NUM_LEDS 150
Adafruit_NeoPixel strip = Adafruit_NeoPixel(NUM_LEDS, PIN, NEO_GRB + NEO_KHZ800);
int sensorPin3 = 3;  //button pin 3
int sensorValue3 = 0;
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


//Twinkle on/off pink
void TwinklePink(int Count, int SpeedDelay) {
    setAll(220,20,70);
    for (int i=0; i<Count; i++) {
        //setPixel(random(NUM_LEDS),random(0,255),random(0,255),random(0,255)); all colors
        setPixel(random(NUM_LEDS),0, 0, 0); 
        //showStrip();
        strip.show();
        delay(SpeedDelay);
        //check periodically if button is pressed; if it is, quit out of this loop so state can change
        sensorValue3 = digitalRead(sensorPin3);
        if (sensorValue3 == 0) {
            return;
        }
    }
    for (int i=0; i<Count; i++) {
        //setPixel(random(NUM_LEDS),random(0,255),random(0,255),random(0,255)); all colors
        setPixel(random(NUM_LEDS),220, 20, 70); 
        //showStrip();
        strip.show(); 
        delay(SpeedDelay);
        //check periodically if button is pressed; if it is, quit out of this loop so state can change
        sensorValue3 = digitalRead(sensorPin3);
        if (sensorValue3 == 0) {
            return;
      }
    }
}


// put your main code here
void loop() {
    sensorValue3 = digitalRead(sensorPin3);
    //prints 0 if button pushed and 1 if not 
    Serial.println(sensorValue3);
    strip.setBrightness(60);
    
    //button is pressed, change state  
    if (sensorValue3 == 0) {
        state = (state+1)%4;
        delay(200);
    }
    //red
    if (state == 0) {
        setAll(255, 0, 0);
        strip.show();
    }
    //blue
    else if (state == 1){
        setAll(30, 5, 255);
        strip.show();
    }
    //twinkling pink
    else if (state == 2) {
        TwinklePink(50, 10, false);
        setAll(200, 20, 70);
        strip.show();
    }
    //off
    else {
        setAll(0,0,0);
        strip.show();
    }
}


