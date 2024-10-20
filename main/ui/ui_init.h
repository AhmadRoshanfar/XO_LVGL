#include <stdio.h>
#include "esp_lcd_panel_io.h"
#include "esp_lcd_panel_vendor.h"
#include "esp_lcd_panel_ops.h"
#include "driver/gpio.h"
#include "driver/spi_master.h"
#include "esp_lcd_touch_xpt2046.h"
#include "esp_err.h"
#include "esp_log.h"
#include "lvgl.h"
#include "esp_timer.h"

#include "esp_lcd_ili9341.h"
#include <esp_lcd_touch.h>

#include "defines.h"

void ui_init();
