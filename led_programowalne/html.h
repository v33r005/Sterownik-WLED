#pragma once

new Supla::Html::DeviceInfo(&SuplaDevice);
new Supla::Html::WifiParameters;
new Supla::Html::ProtocolParameters;
new Supla::Html::StatusLedParameters;
new Supla::Html::DivEnd();
new Supla::Html::DivBegin("box");
new Supla::Html::H3Tag("Regulacja Parametrów");
new Supla::Html::CustomParameter(BUTTON_STEP, "Krok regulacji jasności", 1);
new Supla::Html::CustomParameter(FADE_EFFECT, "Efekt wygaszania (ms) (1-3000)", 2000);
new Supla::Html::CustomParameter(ITERATION_DELAY, "Opóźnienie powtarzania (ms) (1-5000)", 2000);
new Supla::Html::DivEnd();
new Supla::Html::DivBegin("box");
new Supla::Html::H3Tag("Ustawienia Urządzenia");
new Supla::Html::CustomTextParameter(DEV_NAME, "Nazwa urządzenia", 30);
new Supla::Html::ModeParameter;
auto selectCmd = new Supla::Html::SelectCmdInputParameter(PARAM_CMD1, "Reset do ustawień fabrycznych");
selectCmd->registerCmd("RESET", Supla::ON_EVENT_1);
selectCmd->addAction(Supla::RESET_TO_FACTORY_SETTINGS, SuplaDevice, Supla::ON_EVENT_1, true);
new Supla::Html::UpdateParameter;