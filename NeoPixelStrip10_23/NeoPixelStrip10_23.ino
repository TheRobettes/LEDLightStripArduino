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

void TwinklePink(int Count, int SpeedDelay, boolean OnlyOne) {
  setAll(220,20,70);
  for (int i=0; i<Count; i++) {
     //setPixel(random(NUM_LEDS),random(0,255),random(0,255),random(0,255)); all colors
     setPixel(random(NUM_LEDS),0, 0, 0); 
     //showStrip();
     strip.show();
     delay(SpeedDelay);
     if(OnlyOne) { 
       setAll(220,20,70); 
     }
   }
   for (int i=0; i<Count; i++) {
     //setPixel(random(NUM_LEDS),random(0,255),random(0,255),random(0,255)); all colors
     setPixel(random(NUM_LEDS),220, 20, 70); 
     //showStrip();
     strip.show(); 
     delay(SpeedDelay);
     if(OnlyOne) { 
       setAll(0,0,0); 
     }
   }
//  delay(SpeedDelay);
}


void rainbowCycle(int SpeedDelay) {
  byte *c;
  uint16_t i, j;

  for(j=0; j<256*5; j++) { // 5 cycles of all colors on wheel
    for(i=0; i< NUM_LEDS; i++) {
      c=Wheel(((i * 256 / NUM_LEDS) + j)& 206);
      setPixel(i, *c, *(c+1), *(c+2));
    }
    strip.show();
    delay(SpeedDelay);
  }
}
byte * Wheel(byte WheelPos) {
  static byte c[3];
  
  WheelPos = WheelPos + 142;
    
  if(WheelPos > 206) {
  WheelPos = WheelPos - 206;
  }

//if(WheelPos < 255) {
   c[0]=255;
   c[1]=WheelPos/4.89;
   c[2]=WheelPos;
  //} 
Serial.println(WheelPos);
Serial.print(c[0]);
Serial.print(" ");
Serial.print(c[1]);
Serial.print(" ");
Serial.println(c[2]);
  return c;
}
//
void gradient(int red1, int green1, int blue1, int red2, int green2, int blue2) {
    exit;
}


//byte * Wheel(byte WheelPos) {
//  static byte c[3];
//  
//  if(WheelPos < 85) {
//   c[0]=WheelPos * 3;
//   c[1]=255 - WheelPos * 3;
//   c[2]=0;
//  } else if(WheelPos < 170) {
//   WheelPos -= 85;
//   c[0]=255 - WheelPos * 3;
//   c[1]=0;
//   c[2]=WheelPos * 3;
//  } else {
//   WheelPos -= 170;
//   c[0]=0;
//   c[1]=WheelPos * 3;
//   c[2]=255 - WheelPos * 3;
//  }
//
//  return c;
//}

void setAll(byte red, byte green, byte blue) {
  for(int i = 0; i < NUM_LEDS; i++ ) {
    setPixel(i, red, green, blue);
  }
  strip.show();
}

void loop() {
  // put your main code here, to run repeatedly:
  //reads potetiometer and prints the value
    /* used for color intensity
    sensorValue = analogRead(sensorPin) / 4; */
    //Used for brightness
    //sensorValue = digitalRead(sensorPin2);
    sensorValue3 = digitalRead(sensorPin3);
    //sensorValue4 = digitalRead(sensorPin4);
    //prints line
    Serial.println(sensorValue3);

    strip.setBrightness(60);
    
    
    if (sensorValue3 == 0) {
      state = (state+1)%4;
      delay(200);
    }
    //if (sensorValue == 0) {
    //  state = 1;
    //}
    //if (sensorValue4 == 0) {
    //  state = 0;
    //}
    
    if (state == 0) {
        setAll(255, 0, 0);
        strip.show();
    }
    else if (state == 1){
        setAll(30, 5, 255);
        strip.show();
    }
    else if (state == 2) {
        //gradient(220,20,70,255,0,0);
        TwinklePink(50, 10, false);
        //rainbowCycle(10);
        setAll(200, 20, 70);
        strip.show();
    }
    else {
        setAll(0,0,0);
        strip.show();
    }
}


