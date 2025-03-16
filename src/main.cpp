#include <Arduino.h>
#include <lvgl.h>
#include <ATD-S3_Driver.h>
#include "gui/ui.h"

void setup() {
  Serial.begin(115200);
  
  // Setup peripherals
  Display.begin(LCD_SIZE_800x480, 0); // rotation number 0
  Touch.begin();

  // Map peripheral to LVGL
  Display.useLVGL(); // Map display to LVGL
  Touch.useLVGL(); // Map touch screen to LVGL

  Display.enableAutoSleep(120); // Auto off display if not touch in 2 min
  
  // Add load your UI function
  ui_init();

  // Add event handle
  lv_obj_add_event_cb(ui_test_switch, [](lv_event_t * e) { // Add click LED switch event handle
    lv_obj_t * target = lv_event_get_target(e);
    if (lv_obj_has_state(target, LV_STATE_CHECKED)) { // if switch on
      lv_obj_set_style_text_color(ui_test_switch_label, lv_color_hex(0x000000), LV_PART_MAIN | LV_STATE_DEFAULT); // set text color to black
    } else {
      lv_obj_set_style_text_color(ui_test_switch_label, lv_color_hex(0xFF9600), LV_PART_MAIN | LV_STATE_DEFAULT); // set text color to orange
    }
  }, LV_EVENT_CLICKED, NULL);
}

void loop() {
  Display.loop(); // Keep GUI work
}
