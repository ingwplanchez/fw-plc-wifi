#include "system.h"

// Declaracion de variables
/*
int1 Completado;     // Cuenta del periodo completada
int1 Flanco;         // Variable para la deteccion del flanco:
                     // Flanco = 0 (Espera Flanco de subida)
                     // Flanco = 1 (Espera Flanco de bajada)
int Numero_Flanco;   // Indica el numero de flanco

int16 T1,T2,T3,F,DUTY_Actual;    // Variables para guardar 
                                       //los valores del Timer
int16 T_High,T_Low,T_Total;            // Variables para guardar:
                              // T_Higth ->  Semiperiodo Alto
                              // T_Low -> Semiperiodo Bajo
                              // T_Total -> Priodo total
Float P,P_ms,Ta,Vout;         // P -> Periodo
                              // F -> Frecuencia

int32 rpm,rpm_Old;

void drv_rpm_int_rb(void){

   if (input(Boton1)==0){
      //delay_ms(100);
      F = 0;
      Ta = 0;
      rpm = 0;
      P_ms = 0.00;
      Vout = 0.0;
      DUTY_Actual = 5;
      drv_rpm_show();
      // Mostrar_en_Pantalla();
   }      
}

void drv_rpm_int_ext(void){

  ++Numero_Flanco;         // Cuento flanco que nos llegan
  
   if(Flanco==0){           // He recibido Flanco de Subida
      if(Numero_Flanco == 1){// Primer Flanco Alto
         set_timer1(0);       // Reinicio TMR1
         T1=get_timer1();     // Guardo en T1 el valor de TMR1 al primer 
    }                      // Flanco de Subida
   if(Numero_Flanco == 3){// Segundo Flanco de subida
         T3=get_timer1();     // Guardo en T3 el valor de TMR1 al primer Flanco de Subida
         if(Completado == 0){ // Si los datos anteriores han sido procesados ...
         Completado = 1;    // Indico que ya hay nuevos datos de flancos para calcular
      }
    }
    ext_int_edge(0,H_TO_L); // Configuro para capturar siguiente flanco de Bajada
    Flanco=1;               // Indico que el siguiente flanco ser? de Bajada

  } 
  
  else {                    // He recibido Flanco de Bajada
      T2=get_timer1();          // Guardo en T2 el valor de TMR1 al Flanco de Bajada
      ext_int_edge(0,L_TO_H);   // Configuro para capturar siguiente flanco de subida
      Flanco=0;                 // Indico que el siguiente flanco ser? de Subida
  }
  if(Numero_Flanco == 3){     
    Numero_Flanco =0;
    
    drv_rpm_show();
    //Mostrar_en_Pantalla();
  }
}

void drv_rpm_capture(void)
{
if ((F==0)||(F==1)){ // si la frecuencia es igial a 0 o 1
         set_pwm1_duty(5); // saca el ciclo util minimo
         F = 0;            // y reinicia todas las variables
         Ta = 0;
         rpm = 0;
         P_ms = 0.00;
      }
      
      if(Completado==1){               // Detecto que ya hay datos de flancos ...
         if((T3>T2)&&(T2>T1)){         // Compruebo que estoy en la misma vuelta de TMR1
            T_High = T2 - T1;          // Calculo en Tick's de TMR1 el tiempo en Alto
            T_Low = T3 - T2;           // Calculo en Tick's de TMR1 el tiempo en Bajo
            T_Total = T_High + T_Low;  // Calculo en Tick's de TMR1 el Periodo del Pulso
            P = 8.0  * T_Total;        // Calculo en uS el tiempo.
            P_ms = P/1000;             // Periodo en milisegundos
            F = 1 / (P / 1000000);     // Calculo la Frecuencia en segundos
            F = F + 1;
            rpm = F*60;
         }  // Fin del if anidado
      Completado=0;           // Indico que ya han sido procesados los datos.
      }                       // Fin del if 
      
      if(rpm_Old!=0 && rpm!=0){rpm =(rpm+rpm_Old)/2;} // Saca el promedio
                                                       // de las rpm
      if(rpm==0){rpm_Old=0;}
         rpm_Old=rpm;
      if(rpm >1680){
         rpm = 1680;
      }
      if(rpm >2000){
         set_pwm1_duty(5);
      }
      Ta = rpm*100/1680;
      Vout = Ta*5/100;
      
      DUTY_Actual = Ta*5;  //2khz . Duty = (Ta*500)/100
      //set_pwm1_duty(DUTY_Actual);
}

void drv_rpm_show(void){

   printf(lcd_putc, "\f%ldrpm",rpm);
   printf(lcd_putc, "\n%luhz ->%3.2fms",F,P_ms);
   //printf(lcd_putc, "\n%ldrpm -> %1.2fV",rpm,Vout);
 }
*/
