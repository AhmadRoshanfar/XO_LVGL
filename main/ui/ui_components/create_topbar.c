#include "lvgl.h"
#include "ui_defines.h"

lv_obj_t *player1_bg;
lv_obj_t *player2_bg;
extern lv_obj_t *scr;

void create_topbar()
{
    lv_obj_t *top_container = lv_obj_create(scr);
    lv_obj_set_size(top_container, 240, 60);
    lv_obj_set_style_bg_color(top_container, lv_color_hex(TOPBAR_BG), LV_PART_MAIN);
    lv_obj_align(top_container, LV_ALIGN_TOP_MID, 0, 0);
    lv_obj_set_scrollbar_mode(top_container, LV_SCROLLBAR_MODE_OFF);

    player1_bg = lv_obj_create(top_container);
    lv_obj_set_style_bg_color(player1_bg, lv_color_hex(PLAYER_ACTIVE_BG), LV_PART_MAIN);
    lv_obj_set_size(player1_bg, 100, 40);
    lv_obj_align(player1_bg, LV_ALIGN_LEFT_MID, 0, 0);
    lv_obj_set_scrollbar_mode(player1_bg, LV_SCROLLBAR_MODE_OFF);

    lv_label_t *first_player = lv_label_create(player1_bg);
    lv_label_set_text(first_player, PLAYER1_SYMBOL "  Player 1");
    lv_obj_center(first_player);

    player2_bg = lv_obj_create(top_container);
    lv_obj_set_style_bg_color(player2_bg, lv_color_hex(PLAYER_BG), LV_PART_MAIN);
    lv_obj_align(player2_bg, LV_ALIGN_RIGHT_MID, 0, 0);
    lv_obj_set_size(player2_bg, 100, 40);
    lv_obj_set_scrollbar_mode(player2_bg, LV_SCROLLBAR_MODE_OFF);

    lv_label_t *second_player = lv_label_create(player2_bg);
    lv_label_set_text(second_player, PLAYER2_SYMBOL "  Player 2");
    lv_obj_center(second_player);
}