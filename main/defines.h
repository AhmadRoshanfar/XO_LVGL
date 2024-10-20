#include "driver/spi_master.h"

#define CONFIG_LCD_TOUCH_ENABLED 1
#define LCD_HOST SPI2_HOST

#define LCD_PIXEL_CLOCK_HZ (20 * 1000 * 1000)
#define LCD_BK_LIGHT_ON_LEVEL 1
#define LCD_BK_LIGHT_OFF_LEVEL !LCD_BK_LIGHT_ON_LEVEL
#define PIN_NUM_SCLK 18
#define PIN_NUM_MOSI 23
#define PIN_NUM_MISO 19
#define PIN_NUM_LCD_DC 2
#define PIN_NUM_LCD_RST 4
#define PIN_NUM_LCD_CS 15
#define PIN_NUM_BK_LIGHT 27
#define PIN_NUM_TOUCH_CS 5
#define PIN_NUM_TOUCH_IRQ 35

// The pixel number in horizontal and vertical
#define LCD_H_RES 240
#define LCD_V_RES 320

// Bit number used to represent command and parameter
#define LCD_CMD_BITS 8
#define LCD_PARAM_BITS 8

#define LVGL_TICK_PERIOD_MS 2