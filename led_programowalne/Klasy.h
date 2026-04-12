#pragma once

#include <supla/control/rgb_base.h>
#include <supla/control/dimmer_base.h>

class RgbLeds : public Supla::Control::RGBWBase {
  public:
    RgbLeds(int Channel)
      : Channel(Channel) {
    }
    void setRGBWValueOnDevice( uint32_t  red,
                               uint32_t  green,
                               uint32_t  blue//,
                               //uint32_t  brightness) 
                               ){


        
        redWSLED2             = red;
        greenWSLED2           = green;
        blueWSLED2            = blue;
        redWSLED1             = red;//map(red,             0, 1023, 0, 255);
        greenWSLED1           = green;//map(green,           0, 1023, 0, 255);
        blueWSLED1            = blue;//map(blue,            0, 1023, 0, 255);
       // colorBrightnessWSLED1 = map(brightness, 0, 1023, 0, 100);
       // jasnosc = colorBrightnessWSLED1;

       
        redWSLED             = (redWSLED1);// * colorBrightnessWSLED1 ) / 100;
        greenWSLED           = (greenWSLED1);// * colorBrightnessWSLED1) / 100;
        blueWSLED            = (blueWSLED1);// * colorBrightnessWSLED1) / 100;

    }
  protected:
    uint32_t redWSLED1;
    uint32_t greenWSLED1;
    uint32_t blueWSLED1;
    uint32_t colorBrightnessWSLED1;
    uint32_t brightnessWSLED;
    int Channel;
};

RgbLeds *ledyProgramowalne = {};

class Dimm : public Supla::Control::DimmerLeds {
  public:
    Dimm(int Channel)
      : Channel(Channel) {
    }
    void setRGBWValueOnDevice(uint32_t red,
                              uint32_t green,
                              uint32_t blue,
                              //uint32_t colorBrightness,
                              uint32_t brightness) {

        regulacja = brightness;//map(brightness, 0, 1023, 0, 255);
    }
  protected:
    int Channel;
};
Dimm *sciemniacz = {};
