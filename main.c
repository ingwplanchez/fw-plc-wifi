#include "system.h"

int1 timetm1 = 0;
void drv_start();
void main_config();

//INTERRUPCIONES
/*
#int_rb
Void Rb4_Rb7_ISR(){
   //drv_rpm_int_rb();
}
 */
/*Interrupcion por RB4-RB7*/
#int_ext
void RB0_ISR(){

   if (Select == 0 && Flag_Alarmas==0 && Status_modo == MODO_ARRANQUE){
     drv_rpm_int_ext();
     drv_rpm_capture();
   }
 }

/*Interrupcion por timer1*/

#int_timer1
void timer1_isr(void)
{

//drv_gpio_ticks();
/*
   if(timetm1==1){   
      drv_gpio_ticks();
   }       
   timetm1++; 
*/

}


void main(){
   
   main_config(); // Configuracion inicial
   delay_us(50);
   drv_lcd_show();
   delay_ms(1000);
   drv_esp8266_init();
   //drv_gpio_adc_lcd();
   //Status_modo = MODO_INICIO;

   while(1){
      
      // drv_rpm_capture(); 
      switch(Status_modo){
      
         case SIN_MODO:
            if(drv_gpio_alarmas()==0){
               drv_gpio_modo();
               delay_ms(100);
            }
            break;
            
         case MODO_INICIO:
            if(drv_gpio_alarmas()==0){
               delay_ms(100);
               drv_gpio_modo();
               drv_gpio_arranque();
               
            }
            break;
                
         case MODO_ARRANQUE:
            if(drv_gpio_alarmas()==0){
               delay_ms(100);
               drv_activar_transfer();
               drv_gpio_generador_activo();
               drv_gpio_adc_select();
               drv_gpio_adc_show(Select);    
               
            }
            break;           
      }
   } 
}

void main_config(){

   set_tris_d(0b00000000);   // Manejo de pantalla LCD
   set_tris_c(0b00100000);   // Manejo de Salidas Digitales
   set_tris_b(0b11111111);   // Entradas Digitales
   //set_tris_e(0b00000010);   // Entrada para Cambiar lo que se muestra en Pantalla
   
   enable_interrupts(int_ext);      // Habilito las interrupcio por RB0
   //enable_interrupts(int_rb);       // Habilito innterrupcion RB4 - RB7
   enable_interrupts(int_timer1);   // Habilito la interrupcion por timer1
   enable_interrupts(global);       // Habilitacion Global de interruociones
   
   //ext_int_edge(0,H_TO_L);          // Config. Ext RB0  por flanco de subida
   ext_int_edge(0,L_TO_H);          // Config. Ext RB0  por flanco de subida
   setup_timer_0(rtcc_ext_h_to_l | rtcc_div_2); /* Configuracion del timer 0
                                             como contador para detectar por
                                             flanco de bajada con un 
                                             preescaler de 2 (Cuenta cada
                                             2us)*/
   //setup_timer_1(t1_internal | t1_div_by_8); 
   /* configuracion del timer 1 como           
   Temporizador con un preescalerde 8 (cuenta cada 8us)*/
                                             
   //setup_timer_1(t1_internal | t1_div_by_1);  
   setup_timer_1(t1_internal | t1_div_by_8); /* configuracion del timer 1 como
                                             Temporizador con un preescaler
                                             de 8 (cuenta cada 8us)*/
   // Duty minimo = 5(1%), Duty Max = 500(100%)  
   //Preescaler Timer 2 = 4
   //Frecuencia PWM 2000HZ
   setup_timer_2(T2_DIV_BY_4, 124, 1);
   //setup_ccp1(CCP_PWM);                // Inicializacion del modulo PWM
   
   set_timer0(0);    //inicializacion del timer 0
   //set_pwm1_duty(5);
   
   lcd_init(); // Inicializacion de pantalla LCD
   
   //output_b(0b00000000);
   output_c(0b00000000);
   //output_e(0b00000000);
}


