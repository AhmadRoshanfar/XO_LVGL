#include "lvgl.h"
#include "ui_defines.h"

static void message_event_cb(lv_event_t *e)
{
    lv_obj_t *msgbox = lv_event_get_current_target(e);
    lv_msgbox_close(msgbox);
}

static void messageBox_style(lv_obj_t *messageBox)
{
    static lv_style_t style_msgbox;
    lv_style_init(&style_msgbox);

    /* Topic Style */
    lv_obj_t *msg_title = lv_msgbox_get_title(messageBox);
    lv_obj_set_style_text_color(msg_title, lv_color_hex(0x1C315E), 0);

    /* Background */
    lv_style_set_text_color(&style_msgbox, lv_color_hex(0x1C315E));
    lv_style_set_bg_color(&style_msgbox, lv_color_hex(0xF2DEBA));
    lv_style_set_border_width(&style_msgbox, 2);
    lv_style_set_border_color(&style_msgbox, lv_color_hex(0x008983));
    lv_obj_add_style(messageBox, &style_msgbox, 0);

    /* Buttons */
    lv_obj_t *msg_buttons = lv_msgbox_get_btns(messageBox);
    lv_obj_set_height(msg_buttons, 40);
    lv_obj_set_width(msg_buttons, 180);
    // lv_obj_set_style_bg_color(msg_buttons, lv_palette_main(LV_PALETTE_RED), 0);
    lv_group_focus_obj(lv_msgbox_get_btns(messageBox));
    lv_obj_add_state(lv_msgbox_get_btns(messageBox), LV_STATE_FOCUS_KEY);

    static lv_style_t style_btn;
    lv_style_init(&style_btn);
    lv_style_set_radius(&style_btn, LV_RADIUS_CIRCLE);
    lv_style_set_border_width(&style_btn, 2);
    lv_style_set_border_color(&style_btn, lv_color_hex(0x1C315E));
    lv_style_set_bg_color(&style_btn, lv_color_hex(0x1C315E));
    lv_style_set_text_color(&style_btn, lv_color_hex(0xE6E2C3));
    lv_obj_add_style(msg_buttons, &style_btn, LV_PART_ITEMS);

    /* Close Buttons */
    lv_obj_t *msg_close = lv_msgbox_get_close_btn(messageBox);
    lv_obj_set_style_text_color(msg_close, lv_color_hex(0xE6E2C3), 0); // change icon color
    lv_obj_set_style_bg_color(msg_close, lv_color_hex(0x1C315E), 0);   // change background color

    /* Change parent widget's backgound color */
    lv_obj_t *bg = lv_obj_get_parent(messageBox);
    lv_obj_set_style_bg_opa(bg, LV_OPA_70, 0);
    lv_obj_set_style_bg_color(bg, lv_color_hex(0x3d4e4f), 0);
}

void create_message_box(char *topic, char *body)
{
    static const char *btns[] = {"OK", "", ""};
    lv_obj_t *mbox = lv_msgbox_create(NULL, topic, body, btns, true);
    lv_obj_set_size(mbox, 240, 120);
    lv_obj_add_event_cb(mbox, message_event_cb, LV_EVENT_VALUE_CHANGED, NULL);
    lv_obj_center(mbox);
    messageBox_style(mbox);
}