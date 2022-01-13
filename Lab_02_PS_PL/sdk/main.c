/*
 * main.c
 *
 *  Created on: 2022Äê1ÔÂ6ÈÕ
 *      Author: lenovo
 */


#include <stdio.h>
#include "xparameters.h"
#include "sleep.h"
#define IP_ADDR XPAR_PL_PS_IP_0_S00_AXI_BASEADDR

int main(){
	//1B = 8bit // 1reg->32bit ->4B
	unsigned int data1 = (*(volatile unsigned int *)(IP_ADDR + 0 ));
	unsigned int data2 = (*(volatile unsigned int *)(IP_ADDR + 4 ));
	unsigned int data3 = (*(volatile unsigned int *)(IP_ADDR + 8 ));
	unsigned int data4 = (*(volatile unsigned int *)(IP_ADDR + 12 ));

	while(1){
	printf("data1: %d\n ",data1);//520
	printf("data2: %d\n ",data2);//778
	printf("data3: %d\n ",data3);//2022
	printf("data4: %d\n ",data4);//1234
	sleep(1);
	}
}

