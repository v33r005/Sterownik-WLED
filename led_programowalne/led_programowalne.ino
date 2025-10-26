#include "definicje.h"
#include "biblioteki.h"
#include "zmienne.h"
#include "html_classes.h"
#include "Klasy.h"
#include "funkcje.h"
#include "C_Iterate.h"
#include "RGB_IC.h"

void setup() {
  Serial.begin(115200);
  #include "storage_init.h"
  auto buttonCfgRelay = new Supla::Control::Button(BUTTON_CFG_RELAY_GPIO, true, true);
  buttonCfgRelay->configureAsConfigButton(&SuplaDevice);
  auto guziczek = new Supla::Control::Button(PRZYCISK, true, true);
  guziczek->setMulticlickTime(200);
  guziczek->setHoldTime(400);
  guziczek->repeatOnHoldEvery(35);

  if (typ_tasmy == 1){
    ledyProgramowalne = new RgbLeds(0);
    ledyProgramowalne->setStep(btnStep);
    ledyProgramowalne->setFadeEffectTime(fadeEffect_);
    ledyProgramowalne->setMinMaxIterationDelay(iterationDelay);
    if (Typ_Wlacznika == 1){
      guziczek->addAction(Supla::ITERATE_DIM_ALL, ledyProgramowalne, Supla::ON_HOLD);
      guziczek->addAction(Supla::TOGGLE, ledyProgramowalne, Supla::ON_CLICK_1);
    }else{
      guziczek->addAction(Supla::TURN_ON, ledyProgramowalne, Supla:: ON_PRESS);
      guziczek->addAction(Supla::TURN_OFF, ledyProgramowalne, Supla:: ON_RELEASE);
    }
    pixels2.begin();
  }else{
    sciemniacz = new Dimm(0);
    sciemniacz->setStep(btnStep);
    sciemniacz->setFadeEffectTime(fadeEffect_);
    sciemniacz->setMinMaxIterationDelay(iterationDelay);
    if (Typ_Wlacznika == 1){
      guziczek->addAction(Supla::ITERATE_DIM_ALL, sciemniacz, Supla::ON_HOLD);
      guziczek->addAction(Supla::TOGGLE, sciemniacz, Supla::ON_CLICK_1);
    }else{
      guziczek->addAction(Supla::TURN_ON, sciemniacz, Supla:: ON_PRESS);
      guziczek->addAction(Supla::TURN_OFF, sciemniacz, Supla::  ON_RELEASE);
    }
    pixels1.begin();
  }
  
  #include "html.h"
  
  httpUpdater.setup(suplaServer.getServerPtr(), "/update");
  SuplaDevice.allowWorkInOfflineMode(0); 
  SuplaDevice.setLeaveCfgModeAfterInactivityMin(0);
  SuplaDevice.setName(devName);
  SuplaDevice.setSwVersion(SOFT_VERSION);
  SuplaDevice.setSuplaCACert(suplaCACert);
  SuplaDevice.setSupla3rdPartyCACert(supla3rdCACert);
  SuplaDevice.setProtoVerboseLog(false);
  SuplaDevice.begin();
}

void loop() {
  SuplaDevice.iterate();
  
}
