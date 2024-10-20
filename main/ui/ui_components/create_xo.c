#include "lvgl.h"
#include "ui_defines.h"

extern lv_obj_t *table;
extern lv_obj_t *scr;

static void draw_part_event_cb(lv_event_t *e)
{
    lv_obj_t *obj = lv_event_get_target(e);
    lv_obj_draw_part_dsc_t *dsc = lv_event_get_draw_part_dsc(e);
    /*If the cells are drawn...*/
    if (dsc->part == LV_PART_ITEMS)
    {
        uint32_t row = dsc->id / lv_table_get_col_cnt(obj);
        uint32_t col = dsc->id - row * lv_table_get_col_cnt(obj);
        dsc->label_dsc->align = LV_TEXT_ALIGN_CENTER;
        dsc->rect_dsc->border_color = lv_color_hex(TABLE_BORDER_COLOR);
        dsc->rect_dsc->border_width = 1;
        dsc->rect_dsc->outline_pad = 10;
        dsc->rect_dsc->border_side = LV_BORDER_SIDE_FULL | LV_STATE_DEFAULT;
    }
}
void create_xo(lv_event_cb_t table_clicked_event)
{
    static lv_style_t table_style;

    lv_style_init(&table_style);
    lv_style_set_min_height(&table_style, 60);
    lv_style_set_min_width(&table_style, 100);
    lv_style_set_max_width(&table_style, 200);
    lv_style_set_pad_all(&table_style, 5);
    lv_style_set_text_align(&table_style, LV_TEXT_ALIGN_CENTER);
    lv_style_set_text_font(&table_style, &lv_font_montserrat_24);

    table = lv_table_create(scr);
    lv_obj_add_style(table, &table_style, LV_PART_ITEMS);

    lv_obj_center(table);
    lv_table_set_row_cnt(table, 3);
    lv_table_set_col_cnt(table, 3);
    lv_table_set_col_width(table, 0, 80);
    lv_table_set_col_width(table, 1, 80);
    lv_table_set_col_width(table, 2, 80);
    lv_obj_set_size(table, LV_SIZE_CONTENT, LV_SIZE_CONTENT);
    lv_obj_add_event_cb(table, draw_part_event_cb, LV_EVENT_DRAW_PART_BEGIN, NULL);
    lv_obj_add_event_cb(table, table_clicked_event, LV_EVENT_VALUE_CHANGED, NULL);
}