#include "esphome.h"

class FakeLightOutput : public Component, public LightOutput {
 public:
  void setup() override { }

  LightTraits get_traits() override {
    auto traits = LightTraits();
    traits.set_supported_color_modes({ColorMode::RGB, ColorMode::BRIGHTNESS});
    return traits;
  }

  void write_state(LightState *state) override {
    // Store the current color values
    state->current_values_as_binary(&this->red_, &this->green_, &this->blue_, &this->brightness_);
  }

  // Getters for the current color values
  float get_red() const { return this->red_; }
  float get_green() const { return this->green_; }
  float get_blue() const { return this->blue_; }
  float get_brightness() const { return this->brightness_; }

 protected:
  float red_ = 0.0f;
  float green_ = 0.0f;
  float blue_ = 0.0f;
  float brightness_ = 1.0f;
};