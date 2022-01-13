/*
 * main.c
 *
 *  Created on: 2022年1月6日
 *      Author: lenovo
 */

#include <stdio.h>
#include "xparameters.h"
#include "sleep.h"

#define IO_CTRL_IP_ADDR XPAR_IO_CONTROLLER_0_S00_AXI_BASEADDR
#define MIO_DIR  0xE000A244
#define MIO_DATA 0xE000A064
//---------------------------
void sw_update();
//--------------------------
int sw[8]={0,0,0,0,0,0,0,0};
int btn[5]={0,0,0,0,0};
int sw_state;
int btn_state;
//--------------------------
int main(){
	//Setp.1 检查开关数据 ---->对应寄存器slv_reg0
//	while(1){
//			sw_update();
//			for(int i=0;i<8;i++){
//				printf("%d ",sw[i]);
//			}
//			printf("\n");
//			sleep(1);
//		}
	//Setp.2 检查按钮数据
//	while(1){
//			btn_update();
//			for(int i=0;i<5;i++){
//				printf("%d ",btn[i]);
//			}
//			printf("\n");
//			sleep(1);
//		}
	//Setp.3 点亮LED
//	while(1){
//		*((volatile unsigned int *)(IO_CTRL_IP_ADDR + 8 ))=0x01;
//		sleep(1);
//		*((volatile unsigned int *)(IO_CTRL_IP_ADDR + 8 ))=0x02;
//		sleep(1);
//		*((volatile unsigned int *)(IO_CTRL_IP_ADDR + 8 ))=0x04;
//		sleep(1);
//		*((volatile unsigned int *)(IO_CTRL_IP_ADDR + 8 ))=0x08;
//		sleep(1);
//		*((volatile unsigned int *)(IO_CTRL_IP_ADDR + 8 ))=0x10;
//		sleep(1);
//		*((volatile unsigned int *)(IO_CTRL_IP_ADDR + 8 ))=0x20;
//		sleep(1);
//		*((volatile unsigned int *)(IO_CTRL_IP_ADDR + 8 ))=0x40;
//		sleep(1);
//		*((volatile unsigned int *)(IO_CTRL_IP_ADDR + 8 ))=0x80;
//		sleep(1);
//	}
	//Step4. 读取PS端 BTN的数据-->MIO
//	unsigned int mio50_data;
//	*((volatile unsigned int *)MIO_DIR) &= 0xfbffff;
//
//	while(1){
//		mio50_data = (((*(volatile unsigned int *)MIO_DATA)>>18)&0x01);
//		printf("%d\n",mio50_data);
//		sleep(1);
//	}



}
void sw_update(){
	sw_state = *((volatile unsigned int *)(IO_CTRL_IP_ADDR + 0 ));
	//掩码操作去取出每个开关的信息
	sw[0] = ((sw_state&0x00000001)==1);
	sw[1] = ((sw_state&0x00000002)==2);
	sw[2] = ((sw_state&0x00000004)==4);
	sw[3] = ((sw_state&0x00000008)==8);
	sw[4] = ((sw_state&0x00000010)==16);
	sw[5] = ((sw_state&0x00000020)==32);
	sw[6] = ((sw_state&0x00000040)==64);
	sw[7] = ((sw_state&0x00000080)==128);
}

void btn_update(){
	btn_state = *((volatile unsigned int *)(IO_CTRL_IP_ADDR + 4 ));
	//掩码操作去取出每个按钮的信息
	btn[0] = ((btn_state&0x00000001)==1);
	btn[1] = ((btn_state&0x00000002)==2);
	btn[2] = ((btn_state&0x00000004)==4);
	btn[3] = ((btn_state&0x00000008)==8);
	btn[4] = ((btn_state&0x00000010)==16);
}
