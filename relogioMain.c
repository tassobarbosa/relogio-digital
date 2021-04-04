//main.c File 
#include <16F887.h> 
#use delay(crystal=4000000)//Set frequency at 4Mhz 
#include <C_LCD.h>//2x16 Character LCD driver 
#include <DS1302.h>
#include <util.h>


void main() {
   
   lcd_init(); 
   rtc_init();     
   rtc_set_datetime(1,3,21,1,9,37);
   bem_vindo();
   
   ajusta_hora();
   
   
   
   while(1){
      chama_data_hora();
   }
}
