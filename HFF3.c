#include <p89v51rx2.h>

sbit led1 = P3^0;
sbit led2 = P3^1;
sbit led3 = P3^6;
sbit led4 = P3^7;

sbit sw1 = P3^2; //most
sbit sw2 = P3^3;
sbit sw3 = P3^4;
sbit sw4 = P3^5; //least

unsigned char counter = 0;
unsigned char limit = 0;

void delay(unsigned int dela) {
    unsigned int i, j; 
    for(i = 0; i <= 10000; i++) {
        for(j = 0; j <= dela; j++);
    }
}

void main() {
    while(1) {
			delay(5);
        counter++;
			limit =(unsigned char)((!(sw1)) * 8) + (unsigned char)((!(sw2)) * 4) + (unsigned char)((!(sw3)) * 2) + (unsigned char)(!(sw4));
			if (counter-1 >= limit) {
			counter = 0;
			}
			counter &= 0x0f;
			led1=(counter & 0x01)?0:1;
			led2=(counter & 0x02)?0:1;
			led3=(counter & 0x04)?0:1;
			led4=(counter & 0x08)?0:1;
			
			
			delay(5);
    }
}