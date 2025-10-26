#pragma once

//******************własna nazwa*****************************
  Supla::Storage::Init();
  auto cfg = Supla::Storage::ConfigInstance();
  if (cfg->getString(DEV_NAME, devName, 30)) {
    SUPLA_LOG_DEBUG("# Param[%s]: %s", DEV_NAME, devName);
  } else {
    cfg->setString(DEV_NAME, "Supla-Dimmer");
  }
//****************************************************************
if (cfg->getUInt32(SELECT_MODE, &selectMode)) {} else {}
if (cfg->getUInt32(TYP_TASMY, &typ_tasmy)) {} else {}
if (cfg->getUInt32(TYP_WLACZNIKA, &Typ_Wlacznika)) {} else {}
if (cfg->getUInt32(ILOSC_DIOD, &ilosc_diod)) {
  if (ilosc_diod < 0 || ilosc_diod > 600) {
    ilosc_diod = 180;
  }
  cfg->setUInt32(ILOSC_DIOD, ilosc_diod);
  SUPLA_LOG_DEBUG("# Param[%s]: %d", ILOSC_DIOD, ilosc_diod);
} else {
  SUPLA_LOG_DEBUG("# Param[%s] is not set", ILOSC_DIOD);
}
if (Supla::Storage::ConfigInstance()->getInt32(BUTTON_STEP, &btnStep)) {
    if (btnStep <= 0 || btnStep > 20) {
      btnStep = 1;
      Supla::Storage::ConfigInstance()->setInt32(BUTTON_STEP, btnStep);
    }
    SUPLA_LOG_DEBUG("# Param[%s]: %d", BUTTON_STEP, btnStep);
  } else {
    SUPLA_LOG_DEBUG("# Param[%s] is not set", BUTTON_STEP);
  }

  if (Supla::Storage::ConfigInstance()->getInt32(FADE_EFFECT, &fadeEffect_)) {
    if (fadeEffect_ <= 0 || fadeEffect_ > 3000) {
      fadeEffect_ = 2000;
      Supla::Storage::ConfigInstance()->setInt32(FADE_EFFECT, fadeEffect_);
    }
    SUPLA_LOG_DEBUG("# Param[%s]: %d", FADE_EFFECT, fadeEffect_);
  } else {
    SUPLA_LOG_DEBUG("# Param[%s] is not set", FADE_EFFECT);
  }

if (Supla::Storage::ConfigInstance()->getInt32(ITERATION_DELAY,
                                                            &iterationDelay)) {
    if (iterationDelay <= 0 || iterationDelay > 5000) {
      iterationDelay = 2000;
      Supla::Storage::ConfigInstance()->setInt32(ITERATION_DELAY,
                                                               iterationDelay);
    }
    SUPLA_LOG_DEBUG("# Param[%s]: %d", ITERATION_DELAY, iterationDelay);
} else {
    SUPLA_LOG_DEBUG("# Param[%s] is not set", ITERATION_DELAY);
}
if (cfg->getUInt32(PARAM3, &Predkosc)) {
  if (Predkosc < 0 || Predkosc > 1000) {
    Predkosc = 10;
  }
  cfg->setUInt32(PARAM3, Predkosc);
} else {}