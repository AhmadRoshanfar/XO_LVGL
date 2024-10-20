#include <stdio.h>
#include "freertos/FreeRTOS.h"
#include "freertos/task.h"
#include "esp_timer.h"
#include "esp_lcd_panel_io.h"
#include "esp_lcd_panel_vendor.h"
#include "esp_lcd_panel_ops.h"
#include "driver/gpio.h"
#include "driver/spi_master.h"
#include "esp_lcd_touch_xpt2046.h"
#include "esp_err.h"
#include "esp_log.h"
#include "lvgl.h"

#include "esp_lcd_ili9341.h"
#include <esp_lcd_touch.h>

#include "ui/ui_init.h"

static const char *TAG = "MAIN";

void app_main(void)
{
    ui_init();
    while (1)
    {
        vTaskDelay(pdMS_TO_TICKS(10));
        lv_timer_handler();
    }
}
