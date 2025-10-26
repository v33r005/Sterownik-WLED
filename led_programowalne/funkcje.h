#pragma once

void Tasma_RGB(){
  if (ledyProgramowalne->isOn() && zapal_raz == false){
    if (trwa_animacja == true){
      tylko_raz = true;
      zapal_raz = false;
      zgas_raz = false;
    }
    trwa_animacja = true;
    if (tylko_raz == false){
      licznik = (0);
      tylko_raz = true;
    }
    if ((millis() - czasowka >= Predkosc) || (millis() < czasowka)){ 
      czasowka = millis();
      if (licznik <= ilosc_diod){
        if (selectMode == 1){
          pixels2.setPixelColor((licznik-1), pixels2.Color(redWSLED, greenWSLED, blueWSLED));
          pixels2.show();
        }else{
          pixels2.setPixelColor((licznik-1), pixels2.Color(greenWSLED, redWSLED, blueWSLED));
          pixels2.show();
        }
        licznik = licznik + 1;
      }
    }
    if (licznik >= ilosc_diod){
      zapal_raz = true;
      zgas_raz = false;
      tylko_raz = false;
      trwa_animacja = false;
    }
  }
  if (ledyProgramowalne->isOn() && zapal_raz == true && zgas_raz == false){
    if (tylko_raz == false){
      licznik = (ilosc_diod - 1);
      tylko_raz = true;
    }
    for (int i = 0; i < ilosc_diod; i ++){
      if (selectMode == 1){
        pixels2.setPixelColor(i, pixels2.Color(redWSLED, greenWSLED, blueWSLED));
      }else{
        pixels2.setPixelColor(i, pixels2.Color(greenWSLED, redWSLED, blueWSLED));
      }
    }
    pixels2.show();
  } 

  if ((ledyProgramowalne->isOn() == false) && zgas_raz == false && (zapal_raz == true || trwa_animacja == true)){
    if (trwa_animacja == true){
      tylko_raz = true;
      zapal_raz = false;
      zgas_raz = false;
    }
    trwa_animacja = true;
    if (tylko_raz == false){
      licznik = (ilosc_diod - 1);
      tylko_raz = true;
    }
    if ((millis() - czasowka >= Predkosc) || (millis() < czasowka)){ 
      czasowka = millis();
      if (licznik >= 0){
        pixels2.setPixelColor(licznik, pixels2.Color(0,0,0));
        pixels2.show();
        licznik = licznik - 1;
      }
      if (licznik < 0){
        zapal_raz = false;
        zgas_raz = true;
        tylko_raz = false;
        trwa_animacja = false;
      }
    }
  }
}

void Tasma_MONO(){
  if (sciemniacz->isOn() && zapal_raz == false){
    if (trwa_animacja == true){
      tylko_raz = true;
      zapal_raz = false;
      zgas_raz = false;
    }
    trwa_animacja = true;
    if (tylko_raz == false){
      licznik = 0;
      tylko_raz = true;
    }
    if ((millis() - czasowka >= Predkosc) || (millis() < czasowka)){ 
      czasowka = millis();
      if (licznik <= ilosc_diod){
        pixels1.setPixelColor((licznik-1), pixels1.Color(regulacja, regulacja, regulacja));
        pixels1.show();
        licznik = licznik + 1;
      }
    }
    if (licznik >= ilosc_diod){
      zapal_raz = true;
      zgas_raz = false;
      tylko_raz = false;
      trwa_animacja = false;
    }
  }

  if (sciemniacz->isOn() && zapal_raz == true && zgas_raz == false){
    for (int i = 0; i < ilosc_diod; i ++){
      pixels1.setPixelColor(i, pixels1.Color(regulacja, regulacja, regulacja));
    } 
    pixels1.show();
  }

  if ((sciemniacz->isOn() == false) && zgas_raz == false && (zapal_raz == true || trwa_animacja == true)){
    if (trwa_animacja == true){
      tylko_raz = true;
      zapal_raz = false;
      zgas_raz = false;
    }
    trwa_animacja = true;
    if (tylko_raz == false){
      licznik = (ilosc_diod - 1);
      tylko_raz = true;
    }
    if ((millis() - czasowka >= Predkosc) || (millis() < czasowka)){ 
      czasowka = millis();
      if (licznik >= 0){
        pixels1.setPixelColor(licznik, pixels1.Color(0,0,0));
        pixels1.show();
        licznik = licznik - 1;
      }
      if (licznik < 0){
        zapal_raz = false;
        zgas_raz = true;
        tylko_raz = false;
        trwa_animacja = false;
      }
    }
  }
}