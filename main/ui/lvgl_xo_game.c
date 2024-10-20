#include "lvgl.h"
#include "esp_err.h"
#include "esp_log.h"

#include "ui_defines.h"

static const char *TAG = "XO_GAME";

/* Extern */
extern void create_xo(lv_event_cb_t table_clicked_event);
extern void create_restart_btn(lv_event_cb_t btn_event_handler);
extern void create_message_box(char *topic, char *body);
extern void create_topbar();

extern lv_obj_t *player1_bg;
extern lv_obj_t *player2_bg;

/* Gloabal Variables */
lv_obj_t *table;
int count = 0;
lv_obj_t *scr;

/* Prototypes */
bool checkWin(const char *symbol);
void restart();

static void btn_event_handler(lv_event_t *e)
{
    lv_event_code_t code = lv_event_get_code(e);
    restart();
}
static void table_clicked_event_cb(lv_event_t *e)
{
    char *message = "";
    uint16_t row, col;
    lv_table_get_selected_cell(table, &row, &col);
    if (count % 2 == 0)
    {
        message = PLAYER1_SYMBOL;
        lv_obj_set_style_bg_color(player1_bg, lv_color_hex(PLAYER_BG), LV_PART_MAIN);
        lv_obj_set_style_bg_color(player2_bg, lv_color_hex(PLAYER_ACTIVE_BG), LV_PART_MAIN);
    }
    else
    {
        message = PLAYER2_SYMBOL;
        lv_obj_set_style_bg_color(player1_bg, lv_color_hex(PLAYER_ACTIVE_BG), LV_PART_MAIN);
        lv_obj_set_style_bg_color(player2_bg, lv_color_hex(PLAYER_BG), LV_PART_MAIN);
    }

    if (strcmp(lv_table_get_cell_value(table, row, col), "") == 0)
    {
        lv_table_set_cell_value(table, row, col, message);
        count++;
    }

    if (checkWin(PLAYER2_SYMBOL) == true)
        create_message_box("WIN", "PLAYER 2 WINS!");

    if (checkWin(PLAYER1_SYMBOL) == true)
        create_message_box("WIN", "PLAYER 1 WINS!");

    if (count == 9 && (checkWin(PLAYER1_SYMBOL) == false) && (checkWin(PLAYER2_SYMBOL) == false))
        create_message_box("DRAW", "NOBODY WINS!");
}

bool checkTable(int row, int col, char *symbol)
{
    if (strcmp(lv_table_get_cell_value(table, row, col), symbol) == 0)
        return true;
    else
        return false;
}
bool checkWin(const char *symbol)
{
    for (int row = 0; row < 3; row++)
    {
        if (checkTable(row, 0, symbol) && checkTable(row, 1, symbol) && checkTable(row, 2, symbol))
            return true;
    }
    for (int col = 0; col < 3; col++)
    {
        if (checkTable(0, col, symbol) && checkTable(1, col, symbol) && checkTable(2, col, symbol))
            return true;
    }

    if (checkTable(0, 0, symbol) && checkTable(1, 1, symbol) && checkTable(2, 2, symbol))
        return true;

    if (checkTable(0, 2, symbol) && checkTable(1, 1, symbol) && checkTable(2, 0, symbol))
        return true;

    return false;
}
void restart()
{
    count = 0;
    lv_obj_set_style_bg_color(player1_bg, lv_color_hex(PLAYER_ACTIVE_BG), LV_PART_MAIN);
    lv_obj_set_style_bg_color(player2_bg, lv_color_hex(PLAYER_BG), LV_PART_MAIN);
    for (int row = 0; row < 3; row++)
        for (int col = 0; col < 3; col++)
            lv_table_set_cell_value(table, row, col, "");
}

void lvgl_xo_game(lv_disp_t *disp)
{
    scr = lv_disp_get_scr_act(disp);
    lv_obj_set_style_bg_color(scr, lv_color_hex(SCREEN_BG), LV_PART_MAIN);
    create_topbar();
    create_xo(table_clicked_event_cb);
    create_restart_btn(btn_event_handler);
}