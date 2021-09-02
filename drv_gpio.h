#ifndef __DRV_GPIO_H
#define __DRV_GPIO_H

   //PINES PUERTO A
   #define NIVEL_COMBUSTIBLE        pin_a0
   #define V_ALTERMADOR             pin_a1
   #define V_GENERADOR_F1           pin_a2
   #define V_GENERADOR_F2           pin_a3
   #define V_CALLE_F1               pin_a5
   
   //PINES PUERTO E
   // #define V_CALLE_F2            pin_e0
   //#define BOTON_SELECT           pin_e1
  
   //PINES PUERTO B
   // #define                       pin_b0
   #define TEMP_ALARMA              pin_b1
   #define PRESION_ALARMA           pin_b2
   #define A_MANUAL                 pin_b3
   #define A_AUTOMATICO             pin_b4
   #define F_AUTOMATICO             pin_b5
   #define P_EMERGENCIA             pin_b6  
   #define STOP_RESET               pin_b7 

   //PINES PUERTO C
   #define ARRANQUE_ENCENDIDO       pin_c0
   #define SOLENOIDE                pin_c1
   #define E_ALTERNADOR             pin_c2
   #define BUZZER                   pin_c3
   #define TRANSFER                 pin_c4
   #define BOTON_MOSTRAR            pin_c5
   #define SOLENOIDE3               pin_c6
   #define SOLENOIDE4               pin_c7
   
   #define SIN_MODO                 0x00
   #define MODO_INICIO              0x01
   #define MODO_ARRANQUE            0x02
   #define MODO_ARRANQUE_A          0x03
   #define MODO_ARRANQUE_M          0x04  
   

   // FUNCIONES D USO GNERAL
   
   //void drv_gpio_int_rb();
   //void drv_gpio_int_rb0();

   void drv_gpio_seg(int segundos);
   /*
   void drv_gpio_finish0();
   void drv_gpio_finish1();
   void drv_gpio_off();
   //void drv_gpio_clear();
*/
   
   //GPIO ADC
   
   int16 drv_gpio_adc_read(int channel);
   
   void drv_gpio_adc_lcd();
   void drv_gpio_adc_show(int channel);
   void drv_gpio_adc_select();
   
   void drv_rpm_int_rb(void);
   void drv_rpm_int_ext(void);
   void drv_rpm_show(void);
   void drv_rpm_capture(void);
   int1 drv_gpio_alarmas(void);
   void drv_gpio_modo(void);
   void drv_gpio_arranque(void);  
  
   void drv_gpio_control_time();
   
   void drv_gpio_lcd_show1(char * cmd);
   void drv_gpio_lcd_show2(char * cmd,char * cmd1);   
   void drv_gpio_pulsadores();
   
   void drv_gpio_arranque_P_on(void); // Arranque Planta
   void drv_gpio_arranque_P_off(void);
   void drv_gpio_arranque_A_on(void); //Exitacion alternador
   void drv_gpio_arranque_A_off(void);
   void drv_gpio_solenoide_on(void); //Exitacion alternador
   void drv_gpio_solenoide_off(void);
   void drv_gpio_transfer_on(void); //Activar transfer alternador
   void drv_gpio_transfer_off(void);
   void drv_activar_transfer(void);
   void drv_gpio_generador_activo(void);
   
   

#endif /* __DRV_LCD_H */


