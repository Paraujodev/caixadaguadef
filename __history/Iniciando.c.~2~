#define _XTAL_FREQ 4000000 
#include <xc.h> 
#include <pic16f877a.h> 
//CONFIG
#pragma config FOSC = HS // selecionando o oscilador de bits (HS Oscilator)
#pragma config WDTE = OFF // Watchdog timer enable bit (WDT disabled)
#pragma config PWRTE = ON // Power-up Timer Enable bit (PWRT enabled)
#pragma config CP = OFF // Flash progrma memory code protection bit (codeprotection off)

void main(){ 
 TRISD = 0x00;//Saida de dados 
 

while(1){//Loop infinito 
    PORTD = 0b00000000;//Acende LEDs 
    __delay_ms(1000);//Espera 1s 
    PORTD = 0b11111111;//Apaga LEDs 
    __delay_ms(1000);//Espera 1s 
 }
}
