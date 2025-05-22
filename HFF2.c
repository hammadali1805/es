#include<p89v51rx2.h>

void delay(unsigned int delay){
	unsigned int i,j;
	for(i=0;i<10000;i++){
		for(j=0;j<delay;j++){
		}
	}
}
/*
void main(void){
	while(1){
		RxD = 0;
		delay(1);
		RxD = 1;
	}
}
*/
void main(void){
	unsigned int i;
	while(1){
		RxD=0;
		TxD=0;
		WR=1;
		RD=1;
		for(i=0;i<16;i++){
			if(i%2==1){
				RxD = 1;
			}
			else{
				RxD = 0;
			}
			if((i%4) >= 2){
				TxD = 1;
			}
			else{
				TxD = 0;
			}			
			if((i%8) >= 4){
				WR = 0;
			}
			else{
				WR = 1;
			}
			if(i >= 8){
				RD = 0;
			}
			else{
				RD = 1;
			}
			delay(10);
		}
	}
}