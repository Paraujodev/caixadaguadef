#include<16F877A.h>
//XT - utiliza??o de um oscilador externo com velocidade m?dia.
//NOLVP - Desabilitando  modulo de baixa tens?o, habilitando o pino RB4
//NOWDT - desabilitando configura??o de watchdog
#fuses XT, NOLVP, NOWDT
#use delay(clock=4000000)
//#use fast_io(c) //modo manual, por?m mais r?pido e eficaz...? necess?rio setar o tris

#define rs pin_a0 // caractere de comando
#define enable pin_a1 // pulso de habilita??o 
#define limpaLCD 0x01   //limpa tela
#define Linha_2 0xc0 //vai pra linha 2
#define Linha_1 0x80 // vai pra linha 1

void inicia_lcd(void);
void LCD_texto(char letra);
void LCD_comando (int comando);



/**************************************************************************************
         Fun??o principal
**************************************************************************************/

void main (){
   set_tris_c(0x00); //configura PORTC como saida
   set_tris_d(0x00);
   set_tris_b(0x01);
   set_tris_a(0x00);
   inicia_lcd(); //chama a fun??o LCD
  
  /************* Inicializa as saidas em 0 ***********/
  output_low(pin_d0);
  output_low(pin_d1);
  output_low(pin_d2);
  output_low(pin_d3);
  output_low(pin_d4);
  output_low(pin_d5);
  output_low(pin_d6);
  output_low(pin_d7);
  output_low(pin_d8);
  
   
   //comando para o LCD
   LCD_comando(Linha_1);
   printf(LCD_texto,"Servwork");
   LCD_comando(Linha_2);
   printf(LCD_texto,"Automacao");
   delay_ms(1500);
   LCD_comando(LimpaLCD);
   delay_ms(20);
   
   LCD_comando(Linha_1);
   printf(LCD_texto,"Inicializando");
   LCD_comando(Linha_2);
   printf(LCD_texto,"*");
   delay_ms(1000);
   printf(LCD_texto,"*");
   delay_ms(1000);
   printf(LCD_texto,"*");
   delay_ms(1000);
   printf(LCD_texto,"*");
   delay_ms(1000);
   
   LCD_comando(LimpaLCD);
   delay_ms(20);

   while (TRUE){
      
      //inicia_lcd(); //chama a fun??o LCD
   
      LCD_comando(Linha_1);
      printf(LCD_texto,"Sistema Ativo");
      delay_ms(1500);
      LCD_comando(LimpaLCD);
      delay_ms(20);


      if (!input(pin_b0)){
      //delay_ms(300);//utilizado para retirar um ru?do
         output_high(pin_d0);
         
         LCD_comando(Linha_1);
         printf(LCD_texto,"Nivel");
         LCD_comando(Linha_2);
         printf(LCD_texto, "25 porcento");
         delay_ms(1500);
         LCD_comando(LimpaLCD);
         delay_ms(20);
         
         }
      else { 
         output_low(pin_d0);
         output_high(pin_a2); //aciona alarme cisterna vazia

      }

       if (!input(pin_b1)&!input(pin_b2)){
         output_high(pin_d1);
         
         LCD_comando(Linha_1);
         printf(LCD_texto,"Nivel Baixo sis");
         LCD_comando(Linha_2);
         printf(LCD_texto, "50 porcento");
         delay_ms(1500);
         LCD_comando(LimpaLCD);
         delay_ms(20);
         }
      else { 
         output_low(pin_d1);
         output_high(pin_a3);
         
      }

      if (!input(pin_b2)){
         output_high(pin_d2);
      }
      else output_low(pin_d2);

      if (!input(pin_b3)){
         output_high(pin_d3);
      }
      else output_low(pin_d3);

      if (!input(pin_b4)){
      //delay_ms(300);//utilizado para retirar um ru?do
         output_high(pin_d4);
      }
      else output_low(pin_d4);

       if (!input(pin_b5)){
         output_high(pin_d5);
      }
      else output_low(pin_d5);

      if (!input(pin_b6)){
         output_high(pin_d6);
      }
      else output_low(pin_d6);

      if (!input(pin_b7)){
         output_high(pin_d7);
      }
      else output_low(pin_d7);
       
   }//end while

}//end main


/**************************************************************************************
         Fun??o Inicia LCD
**************************************************************************************/

void inicia_lcd(){
   output_low(RS); //coloca LCD no modo de comando
   output_c(0x38); //configura o modo 8bits, 2 linhas e 5x7 pixels.
   output_high(enable); //pulso enable
   output_low(enable);
   delay_ms(20); //timing do display
   output_c(0x0c); //configura o cursor
   output_high(enable); //pulso em enable
   output_low(enable); 
   output_c(0x06);  //incremento a direita do cursor
   output_high(enable); //pulso em enable
   output_low(enable);
   output_c(limpaLCD); //limpa display
   output_high(enable); //pulso em enable
   output_low(enable);
   delay_ms(5);
}

/**************************************************************************************
         Fun??o LCD_TEXTO
**************************************************************************************/
void LCD_texto(char letra){
   output_high(rs);//modo de dados
   output_c(letra); //coloca o caractere recebido no PORTC
   output_high(enable); //pulso enable
   delay_us(500);
   output_low(enable);
}

/**************************************************************************************
         Fun??o LCD_COMANDO
**************************************************************************************/
void LCD_comando(int comando){
   output_low(rs);   //modo de comando 
   output_c(comando); //coloca o comando recebido no PORTC
   output_high(enable); // pulso no enable
   delay_us(500);
   output_low(enable);
}
