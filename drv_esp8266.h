#include <stdint.h>
#include <stdio.h>
#include <string.h>

#ifndef __DRV_ESP8266_H
#define __DRV_ESP8266_H

/** Some constants **/


#define ESP8266_STATION 0x01

#define ESP8266_SOFTAP 0x02

   #define ESP8266_TCP 1
   #define ESP8266_UDP 0

   #define ESP8266_OK         1
   #define ESP8266_READY      2

   #define ESP8266_FAIL       3
   #define ESP8266_NOCHANGE   4

   #define ESP8266_LINKED     5

   #define ESP8266_UNLINK     6
   
   //commands
   #define ATE0               "ATE0\r\n"           // SIN ECO
   #define AT_CWMODE2         "AT+CWMODE=2\r\n"    // ACTUA COMO  ROUTER CREA UNA RED PROPIA
   #define AT_CIPSERVER0      "AT+CIPSERVER=0\r\n" // Cierra sevidores
   #define AT_CIPMUX0         "AT+CIPMUX=0\r\n"    // Conexion un unica
   
   #define AT_CIPMODE0        "AT+CIPMODE=0\r\n"   //Trabaja en modo normal
   
   //Red WIFI como acces point  cana 5  clave tipo WPA2_PSK
   #define AT_CWSAP           "AT+CWSAP=\"ESP8266_ARZ\",\"noconectar\",5,3\r\n"
   //Coloca la IP del acces ponit
   #define AT_CIPSERVER0      "AT+CIPAP=\"192.168.1.254\"\r\n"
   //Crea el servidor y el puerto a escuchar
   #define AT_CIPMUX1         "AT+CIPMUX=1\r\n" //habilita multiples conexiones
   //Activa la escucha por el puerto 200
   #define AT_CIPSERVER      "AT+CIPSERVER=1,200\r\n"
   
   //tiemo en el cual actua como servidor en segundos   
   #define AT_CIPSTO0   "AT+CIPSTO=0\r\n" // siempre activo
   
   void drv_esp8266_init(void);
   
#endif /* __DRV_LCD_H */
