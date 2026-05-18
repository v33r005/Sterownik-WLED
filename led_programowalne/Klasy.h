#pragma once

#include <supla/control/rgb_base.h>
#include <supla/control/dimmer_base.h>

class RgbLeds : public Supla::Control::RGBBase {
  public:
    RgbLeds(int Channel)
      : Channel(Channel) {
    }
    void setRGBWValueOnDevice( uint32_t  red,
                               uint32_t  green,
                               uint32_t  blue,
                               uint32_t  brightness) {
        
        redWSLED             = red;
        greenWSLED           = green;
        blueWSLED            = blue;

    }
  protected:
    int Channel;
};

RgbLeds *ledyProgramowalne = nullptr;

class Dimm : public Supla::Control::DimmerBase {
  public:
    Dimm(int Channel)
      : Channel(Channel) {
    }
    void setRGBWValueOnDevice(uint32_t red,
                              uint32_t green,
                              uint32_t blue,
                              uint32_t brightness) {

        regulacja = map(brightness, 0, 1023, 0, 255);
    }
  protected:
    int Channel;
};
Dimm *sciemniacz = {};
