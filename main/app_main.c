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


//�û�������ڣ��൱��main����
void app_main()
{
    char dht11_buff[50]={0};

    //��ʾ����ʼ��
    Lcd_Init();

    //��ʾ����ʾ��Ϣ
    Gui_DrawFont_GBK24(15,0,RED,WHITE,(u8 *)"��Ϊ����");
    Gui_DrawFont_GBK16(16,34,VIOLET,WHITE,(u8 *)"������Ϊ����");
    Gui_DrawFont_GBK16(32,50,BLUE,WHITE,(u8 *)"��ӭ��");
    Gui_DrawFont_GBK16(20,70,RED,WHITE,(u8 *)"1.44��ɫTFT");

    while(1)
    {
      DHT11(); //��ȡ��ʪ��
      sprintf(dht11_buff, "   �¶�=%d��   ", wendu);
      Gui_DrawFont_GBK16(6,90,VIOLET,BLACK,(u8 *)dht11_buff);

      sprintf(dht11_buff, "   ʪ��=%d%%    ", shidu);
      Gui_DrawFont_GBK16(6,110,VIOLET,BLACK,(u8 *)dht11_buff);

      printf("T=%d,H=%d %%.\r\n", wendu, shidu);
      vTaskDelay(300);
    }
}

    

