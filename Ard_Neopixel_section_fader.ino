#include <Adafruit_NeoPixel.h>

#define PIN            6
#define NUMPIXELS      20

Adafruit_NeoPixel pixels = Adafruit_NeoPixel(NUMPIXELS, PIN, NEO_GRB + NEO_KHZ800);

// The sections needed
/*
  |  Top   |
_  _ _ _ _ _ _  _
L |           | R
E |           | G
F |           | H
T |           | T
_ | _ _ _ _ _ | _
*/
 

 
int bottom[2] = {0,4};
int right[2] = {5, 9};
int top[2] = {10, 14}; 
int left[2] = {15, 19};

const int bot_len = bottom[1] - bottom[0];
const int rht_len = right[1]  - right[0];
const int top_len = top[1]    - top[0];
const int lft_len = left[1]   - left[0];
const int ttl_len = bot_len + rht_len + top_len + lft_len;


int i;


void setup() {
  pixels.begin();

}

void loop() {

all_fade(bottom,true, 1);
all_fade(bottom, false, 1);


}



void all_fade(int strip[2], bool flip, int spd)
{
  if(!flip)
  {
    for(int c=0;c<=255;c++)
    {
     set_all(strip, c, c, c);
     delay(spd);
    }
  }
  else if(flip)
  {
    for(int c=255;c>=0;c--)
    {
       set_all(strip, c, c, c);
       delay(spd);
    }
  }
}



void cross_fade(int strip[2], bool flip, int spd)
{

  int led_range = (strip[1] - strip[0] + 1) ;
 
  if(!flip)
  {
    for(int c=0;c<=255;c++)
    {
      for(i=strip[0];i<=strip[1];i++)
      {
        
      pixels.setPixelColor(i, pixels.Color(0,c,c));
      }
      pixels.show();
     delay(spd);
    }
  }
}

void set_all(int strip[2], byte R, byte G, byte B)
{

  for(i=strip[0];i<=strip[1];i++)
  {
   pixels.setPixelColor(i, pixels.Color(R, G, B));
  }
  pixels.show();

}


