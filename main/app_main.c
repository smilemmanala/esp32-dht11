#include <stdio.h>
#include "esp_system.h"
#include "esp_spi_flash.h"
#include "esp_wifi.h"
#include "esp_event_loop.h"
#include "esp_log.h"
#include "esp_err.h"
#include "nvs_flash.h"
#include "freertos/FreeRTOS.h"
#include "freertos/task.h"
#include "driver/ledc.h"
#include <stdio.h>
#include "driver/uart.h"
#include "driver/gpio.h"
#include "string.h"
#include "Lcd.h"
#include "dht11.h"


//用户函数入口，相当于main函数
void app_main()
{
    char dht11_buff[50]={0};

    //显示屏初始化
    Lcd_Init();

    //显示屏提示信息
    Gui_DrawFont_GBK24(15,0,RED,WHITE,(u8 *)"悦为电子");
    Gui_DrawFont_GBK16(16,34,VIOLET,WHITE,(u8 *)"深圳悦为电子");
    Gui_DrawFont_GBK16(32,50,BLUE,WHITE,(u8 *)"欢迎您");
    Gui_DrawFont_GBK16(20,70,RED,WHITE,(u8 *)"1.44彩色TFT");

    while(1)
    {
      DHT11(); //读取温湿度
      sprintf(dht11_buff, "   温度=%d度   ", wendu);
      Gui_DrawFont_GBK16(6,90,VIOLET,BLACK,(u8 *)dht11_buff);

      sprintf(dht11_buff, "   湿度=%d%%    ", shidu);
      Gui_DrawFont_GBK16(6,110,VIOLET,BLACK,(u8 *)dht11_buff);

      printf("T=%d,H=%d %%.\r\n", wendu, shidu);
      vTaskDelay(300);
    }
}

    

