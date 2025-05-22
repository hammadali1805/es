#include <LCD.h>

void main(){
	
	LCD_INIT();
	
	while(1){
		LCD_WRITE("FILZA  ",0,0);
		LCD_WRITE("22BCS42",1,0);
		delay(5000);
		
		LCD_WRITE("FIROZ  ",0,0);
		LCD_WRITE("22BCS41",1,0);
		delay(6000);
		
		LCD_WRITE("HARSHIT",0,0);
		LCD_WRITE("22BCS40",1,0);
		delay(5000);
	}
}