#include "system.h"

//int me = 0;
void drv_lcd_show(){
      printf(lcd_putc,"\f<<EVOLUTRONICA>>\n");
      printf(lcd_putc,"   (PLC WIFI)");
      delay_ms(1000);
     
}

void drv_lcd_show1(char * cmd){
      printf(lcd_putc,"\f");
      printf(lcd_putc,(char *)cmd);
      printf(lcd_putc,"\n");

}



