//design and implement an embedded system that toggle pin 3.0 continously every 600ms using 8085 board write c code for this in kelimicrovision , use crystal frequency 11.092MHz and timer1 mode 1
//#include <reg51.h>
//#include <p89v51rx2.h>
#include <LCD.h>

sbit LED = P3^0;  // Define P3.0 as output (toggle pin) 

unsigned char i;
void Timer1_Delay50ms() {
    TMOD &= 0x0F;     
    TMOD |= 0x10;     

    TH1 = 0x4B;
    TL1 = 0xFD;

    TF1 = 0;          
    TR1 = 1;          

    while (TF1 == 0); 

    TR1 = 0;          
    TF1 = 0;          
}

void main() { 
		LCD_INIT();
    while (1) {
			  LCD_WRITE("LED Blinker",0,0);
			  LCD_WRITE("Firoz & Harshit",1,0);
        LED = ~LED;  
		    
        for(i = 0; i < 12; i++) {
            Timer1_Delay50ms();
        }
    }
}

// having delay of 600ms make a timerdelay function that runs for 50ms and call it in a loop for 12 times