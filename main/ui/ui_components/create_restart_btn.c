#include "lvgl.h"
#include "ui_defines.h"

extern lv_obj_t *scr;

void create_restart_btn(lv_event_cb_t btn_event_handler)
{
    lv_obj_t *bottom_container = lv_obj_create(scr);
    lv_obj_set_size(bottom_container, 240, 55);
    lv_obj_set_style_bg_color(bottom_container, lv_color_hex(BUTTON_BG), LV_PART_MAIN);
    lv_obj_align(bottom_container, LV_ALIGN_BOTTOM_MID, 0, 0);
    lv_obj_set_scrollbar_mode(bottom_container, LV_SCROLLBAR_MODE_OFF);

    lv_btn_t *button = lv_btn_create(bottom_container);
    lv_obj_add_event_cb(button, btn_event_handler, LV_EVENT_CLICKED, NULL);
    lv_obj_align(button, LV_ALIGN_CENTER, 0, 0);
    lv_obj_set_size(button, 240, 55);
    lv_obj_set_scrollbar_mode(button, LV_SCROLLBAR_MODE_OFF);

    lv_obj_set_style_bg_color(button, lv_color_hex(BUTTON_BG), LV_PART_MAIN);
    lv_label_t *btn_label = lv_label_create(button);
    lv_label_set_text(btn_label, "RESTART");
    lv_obj_center(btn_label);
    lv_obj_set_scrollbar_mode(btn_label, LV_SCROLLBAR_MODE_OFF);
}