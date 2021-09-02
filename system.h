#ifndef __SYSTEM_H
#define __SYSTEM_H

   #include <16f877a.h>
   #Device adc=10
   #use delay(clock=4000000)
   #fuses XT,NOWDT,NOPROTECT,NOLVP,PUT,NODEBUG,BROWNOUT,NOCPD,NOWRT
   #use RS232(BAUD=9600, BITS=8, PARITY=N, XMIT=PIN_C6, RCV=PIN_C7)
   //#use fast_io(a)
   #use fast_io(b)
   #use fast_io(c)
   #use fast_io(d)
   //#use fast_io(e)
   
   //#define Boton1 pin_b7
   
   
   #include <LCD.c>
   #include <mensajes.h>
   #include <mensajes.c>
   
   #include <drv_lcd.h>
   #include <drv_lcd.c>
   #include <drv_gpio.h>
   #include <drv_gpio.c> 
   #include <drv_esp8266.h>
   #include <drv_esp8266.c>
   //#include <drv_rpm.h>
   //#include <drv_rpm.c>
   #include <system.c>

#endif
