void bem_vindo(){
   lcd_putc('\f'); 
   lcd_gotoxy(1,1); 
   printf(lcd_putc,"   Bem vindo"); 
   delay_ms(700);
   lcd_putc('\f'); 
}

#define BLINK 400
#define CHANGE_NUMBER 200
#define CONFIRM_NUMBER 400
void ajusta_hora(){
   char dia, mes, ano, semana, hora, min, seg;
   int caso = 1;
   boolean ajusta_flag = 1;
   
   rtc_get_date(dia, mes, ano, semana);
   rtc_get_time(hora, min, seg);
   lcd_gotoxy(1,1);
   printf(lcd_putc,"Data: %02u/%02u/%02u",dia,mes,ano);
   lcd_gotoxy(1,2);
   printf(lcd_putc,"Hora: %02u:%02u:%02u",hora,min,seg);  
   
   while(ajusta_flag){
      switch(caso){
         case 1:
            if(!input(pin_d0)){
               delay_ms(1000);
               if(!input(pin_d0)){
                  ajusta_flag = 0;
               }else{
                  caso = 2;
               }
            }
         break;
         case 2:
            lcd_gotoxy(7,1); printf(lcd_putc,"  "); delay_ms(BLINK);
            lcd_gotoxy(7,1); printf(lcd_putc,"%02u",dia); delay_ms(BLINK);
            if(!input(pin_d0)){
            
               delay_ms(CHANGE_NUMBER);               
               if(input(pin_d0)){
                  dia++; if(dia>31) dia = 0;
                  lcd_gotoxy(7,1); printf(lcd_putc,"%02u",dia);
                  break;
               }               
               if(!input(pin_d0)){
                  delay_ms(CONFIRM_NUMBER);
                  if(!input(pin_d0)) caso = 3;
               }
            }
         break;
         
         case 3:
            lcd_gotoxy(10,1); printf(lcd_putc,"  "); delay_ms(BLINK);
            lcd_gotoxy(10,1); printf(lcd_putc,"%02u",mes); delay_ms(BLINK);
            if(!input(pin_d0)){
               delay_ms(CHANGE_NUMBER);
               if(input(pin_d0)){
                  mes++; if(mes>12) mes = 0;
                  lcd_gotoxy(10,1); printf(lcd_putc,"%02u",mes);
                  break;
               }                                                            
               if(!input(pin_d0)){
                  delay_ms(CONFIRM_NUMBER);
                  if(!input(pin_d0)) caso = 4;
               }
            }
         break;
         
         case 4:
            lcd_gotoxy(13,1); printf(lcd_putc,"  "); delay_ms(BLINK);
            lcd_gotoxy(13,1); printf(lcd_putc,"%02u",ano); delay_ms(BLINK);
              if(!input(pin_d0)){
               delay_ms(CHANGE_NUMBER);
               if(input(pin_d0)){
                  ano++; if(ano>99) ano = 0;
                  lcd_gotoxy(13,1); printf(lcd_putc,"%02u",ano);
                  break;
               }                                                            
               if(!input(pin_d0)){
                  delay_ms(CONFIRM_NUMBER);
                  if(!input(pin_d0)) caso = 5;
               }
            }
         break;     

         case 5:
            lcd_gotoxy(7,2); printf(lcd_putc,"  "); delay_ms(BLINK);
            lcd_gotoxy(7,2); printf(lcd_putc,"%02u",hora); delay_ms(BLINK);
            if(!input(pin_d0)){
               delay_ms(CHANGE_NUMBER);
               if(input(pin_d0)){
                  hora++; if(hora>23) hora = 0;
                  lcd_gotoxy(7,2); printf(lcd_putc,"%02u",hora);
                  break;
               }                                                            
               if(!input(pin_d0)){
                  delay_ms(CONFIRM_NUMBER);
                  if(!input(pin_d0)) caso = 6;
               }
            }
         break; 
         
         case 6:
            lcd_gotoxy(10,2); printf(lcd_putc,"  "); delay_ms(BLINK);
            lcd_gotoxy(10,2); printf(lcd_putc,"%02u",min); delay_ms(BLINK);
            if(!input(pin_d0)){
               delay_ms(CHANGE_NUMBER);
               if(input(pin_d0)){
                  min++; if(min>59) min = 0;
                  lcd_gotoxy(10,2); printf(lcd_putc,"%02u",min);
                  break;
               }                                                            
               if(!input(pin_d0)){
                  delay_ms(CONFIRM_NUMBER);
                  if(!input(pin_d0)) caso = 7;
               }
            }
         break;  
         case 7:
            ajusta_flag=0;
         break;
         
         default:
            ajusta_flag=0;
         break;        
      }
   }
   
   
   rtc_set_datetime(dia,mes,ano,1,hora,min);
}

void chama_data_hora(){
   char dia, mes, ano, semana, hora, min, seg;
   rtc_get_date(dia, mes, ano, semana);
   lcd_gotoxy(1,1);
   printf(lcd_putc,"Data: %02u/%02u/%02u",dia,mes,ano);
   rtc_get_time(hora, min, seg);  
   lcd_gotoxy(1,2);
   printf(lcd_putc,"Hora: %02u:%02u:%02u",hora,min,seg); 
}
