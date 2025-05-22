#include "LCD.h"


sbit sw1 = P3^2; // Most
sbit sw2 = P3^3;
sbit sw3 = P3^4;
sbit sw4 = P3^5; // Least

unsigned char read_switch_input() {
    unsigned char s1 = !sw1; 
    unsigned char s2 = !sw2;
    unsigned char s3 = !sw3;
    unsigned char s4 = !sw4;

    return (s1 << 3) | (s2 << 2) | (s3 << 1) | s4;
}

unsigned long factorial(unsigned char num) {
	unsigned  long result = 1;
	unsigned long i;
	for(i = 1; i <= num; i++) {
		result *= i;
	}
	return result;
}

void intToStr(unsigned  long num, char *str) {
	char temp[20];
	char i = 0, j, k = 0;

	if(num == 0) {
		str[0] = '0';
		str[1] = '\0';
		return;
	}

	while(num > 0) {
		temp[i++] = (num % 10) + '0';
		num /= 10;
	}

	for(j = i - 1; j >= 0; j--) {
		str[k++] = temp[j];
	}
	str[k] = '\0';
}

void main() {
	unsigned char input;
	unsigned long  fact;
	char inputStr[5];
	char factStr[32];

	LCD_INIT();
	LCD_CMD(LCD_CLEAR);

	while(1) {
		input = read_switch_input();     
		fact = factorial(input);         
		intToStr(input, inputStr);       
		intToStr(fact, factStr);         

		LCD_CMD(LCD_CLEAR);

		LCD_WRITE("Num: ", 0, 0);
		LCD_WRITE(inputStr, 0, 5);

		LCD_WRITE("Fact: ", 1, 0);
		LCD_WRITE(factStr, 1, 5);

		delay(1000); // Wait before next update
	}
}