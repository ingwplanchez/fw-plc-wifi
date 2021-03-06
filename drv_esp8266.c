#include "system.h"

void drv_esp8266_init(void){

   Printf(ATE0);           // SIN ECO
   delay_ms(2000);
   
   Printf(AT_CWMODE2);     // ACTUA COMO  ROUTER CREA UNA RED PROPIA
   delay_ms(200);
   
   Printf(AT_CIPSERVER0);  // Cierra sevidores
   delay_ms(200);
   
   Printf(AT_CIPMUX0);     // Conexion un unica
   delay_ms(200);
   
   Printf(AT_CIPMODE0);    //Trabaja en modo normal
   delay_ms(200);
   
   //Red WIFI como acces point  cana 5  clave tipo WPA2_PSK
   Printf(AT_CWSAP);
   delay_ms(600);
   
   //Coloca la IP del acces ponit
   Printf(AT_CIPSERVER0);
   delay_ms(200);
   
   //Crea el servidor y el puerto a escuchar
   Printf(AT_CIPMUX1);  //Habilita multiples conexiones
   delay_ms(200);
   
   //Activa la escucha por el puerto 200
   Printf(AT_CIPSERVER);
   delay_ms(200);
   
   //tiemo en el cual actua como servidor en segundos 
   Printf(AT_CIPSTO0); // siempre activo
   delay_ms(200);
   
}
