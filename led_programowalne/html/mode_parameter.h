#pragma once

namespace Supla {
namespace Html {

class ModeParameter : public Supla::HtmlElement {
 public:
  ModeParameter() : HtmlElement(HTML_SECTION_FORM) {}

  void send(Supla::WebSender* sender) {
    auto cfg = Supla::Storage::ConfigInstance();
    if (cfg) {
      

      // form-field BEGIN
      cfg->getUInt32(TYP_WLACZNIKA, &wlacznik);
      sender->send("<div class=\"form-field\">");
      sender->sendLabelFor(TYP_WLACZNIKA, "Typ włącznika");
      sender->send("<select");
      sender->sendNameAndId(TYP_WLACZNIKA);
      sender->send(">"); //nowe dodane
      sender->send("<option value=\"0\"");
      sender->send(selected(wlacznik == 0));
      sender->send(">Bistabilny</option>");
      sender->send("<option value=\"1\"");
      sender->send(selected(wlacznik == 1));
      sender->send(">Monostabilny</option>");
      sender->send("</select>");
      sender->send("</div>");
      // form-field END

      sender->send("<div class=\"form-field\">");
      sender->sendLabelFor(ILOSC_DIOD, "Ilość pikseli na pasku ");
      sender->send(
              "<input type=\"number\" min=\"0\" max=\"600\" step=\"1\" ");
      sender->sendNameAndId(ILOSC_DIOD);
      sender->send(" value=\"");
      inCfgValue = 90; // default value
      cfg->getUInt32(ILOSC_DIOD, &inCfgValue);
      sender->send(inCfgValue);
      sender->send("\">");
      sender->send("</div>");

      sender->send("<div class=\"form-field\">");
      sender->sendLabelFor(PARAM3, "Przerwa czasowa pomiędzy pikselami (prędkość animacji) [ms] ");
      sender->send("<input type=\"number\" min=\"0\" max=\"1000\" step=\"1\" ");
      sender->sendNameAndId(PARAM3);
      sender->send(" value=\"");
      inCfgValue = 10; // default value
      cfg->getUInt32(PARAM3, &inCfgValue);
      sender->send(inCfgValue);
      sender->send("\">");
      sender->send("</div>");

      // form-field BEGIN
      cfg->getUInt32(TYP_TASMY, &wybor_tasmy);
      sender->send("<div class=\"form-field\">");
      sender->sendLabelFor(TYP_TASMY, "Typ Taśmy LED");
      sender->send("<select");
      sender->sendNameAndId(TYP_TASMY);
      sender->send("onchange=\"modeToggle();\">");
      sender->send("<option value=\"0\"");
      sender->send(selected(wybor_tasmy == 0));
      sender->send(">Monochromatyczna</option>");
      sender->send("<option value=\"1\"");
      sender->send(selected(wybor_tasmy == 1));
      sender->send(">Kolorowa</option>");
      sender->send("</select>");
      sender->send("</div>");
      // form-field END


      // switch hidden div begin
      sender->send("<div id=\"hide_rgb_options\" style=\"display: ");
      sender->send(displayed(wybor_tasmy));

      // form-field BEGIN
      cfg->getUInt32(SELECT_MODE, &opcja_tasmy);
      sender->send("<div class=\"form-field\">");
      sender->sendLabelFor(SELECT_MODE, "Rodzaj Taśmy LED");
      sender->send("<select");
      sender->sendNameAndId(SELECT_MODE);
      sender->send(">"); //nowe dodane
      sender->send("<option value=\"0\"");
      sender->send(selected(opcja_tasmy == 0));
      sender->send(">RGB</option>");
      sender->send("<option value=\"1\"");
      sender->send(selected(opcja_tasmy == 1));
      sender->send(">GRB</option>");
      sender->send("</select>");
      sender->send("</div>");
      // form-field END
      sender->send("</div>");
      // hidden div end
/*
      sender->send("<script>"
        "function modeToggle() {"
          "var led_strip_type = document.getElementById(\"");
      sender->send(TYP_TASMY);
      sender->send("\");"
          "var led_rgb_mode = document.getElementById(\"hide_rgb_options\");"
          "if (led_strip_type.value == 1) {"
            "led_rgb_mode.display = \"block\";" 
          "} else {"
            "led_rgb_mode.display = \"none\";"
          "}"
        "}"
      "</script>");
   */   
    }  
  }
  bool handleResponse(const char* key, const char* value) {
    auto cfg = Supla::Storage::ConfigInstance();
    if (cfg && strcmp(key, SELECT_MODE) == 0) {
      int inFormValue = stringToUInt(value);
      cfg->setUInt32(SELECT_MODE, inFormValue);
      selectMode = inFormValue;
      return true;
    }
     if (cfg && strcmp(key, TYP_WLACZNIKA) == 0) {
      int inFormValue = stringToUInt(value);
      cfg->setUInt32(TYP_WLACZNIKA, inFormValue);
      Typ_Wlacznika = inFormValue;
      return true;
    }
    if (cfg && strcmp(key, ILOSC_DIOD) == 0) {
      int inFormValue = stringToUInt(value);
      if (inFormValue >= 0 && inFormValue <= 600) {
        cfg->setUInt32(ILOSC_DIOD, inFormValue);
        ilosc_diod = inFormValue;
      }
      return true;
    }
    if (cfg && strcmp(key, TYP_TASMY) == 0) {
      int inFormValue = stringToUInt(value);
      cfg->setUInt32(TYP_TASMY, inFormValue);
      typ_tasmy = inFormValue;
      return true;
    }
    if (cfg && strcmp(key, PARAM3) == 0) {
      int inFormValue = stringToUInt(value);
      if (inFormValue >= 0 && inFormValue <= 1000) {
        cfg->setUInt32(PARAM3, inFormValue);
        Predkosc = inFormValue;
      }
      return true;
    }
    return false;    
  }
  
 protected:
  
  uint32_t inCfgValue;
  uint32_t opcja_tasmy = 0;
  uint32_t wybor_tasmy = 0;
  uint32_t wlacznik = 0;

}; // ModeParameter

}; // namespace Html
}; // namespace Supla
