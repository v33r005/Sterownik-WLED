#pragma once

class CustomIterate : public Supla::Element {
 public:
  CustomIterate() {}

  void iterateAlways() {
    if (typ_tasmy == 1){
      Tasma_RGB();
    }else{
      Tasma_MONO();
    }
  }
};  // CustomIterate
CustomIterate cIterate;