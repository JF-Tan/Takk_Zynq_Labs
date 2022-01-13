#include "xparameters.h"
#include "xil_cache.h"
#include "img1.h"

#define VDMA_ADDR XPAR_AXI_VDMA_0_BASEADDR
#define FRAME_ADDR 0x01000000

#define HSIZE 1280
#define VSIZE 1024

typedef struct{
	unsigned char b;
	unsigned char g;
	unsigned char r;
}Pixel;

int main(){

	//--------------- 配置VDMA --------------------------------
	*(volatile unsigned int *)(VDMA_ADDR + 0x00 ) = 0x01 ;//enable mm2s channel
	*(volatile unsigned int *)(VDMA_ADDR + 0x5c ) = FRAME_ADDR ;// frame buffer start address
	*(volatile unsigned int *)(VDMA_ADDR + 0x58 ) = HSIZE*3 ;// frame delay
	*(volatile unsigned int *)(VDMA_ADDR + 0x54 ) = HSIZE*3 ;// HSIZE
	*(volatile unsigned int *)(VDMA_ADDR + 0x50 ) = VSIZE ;//   VSIZE
	//---------- Step.2 显示纯色  ------------------------------
	//0x01000000 --> 0000 0000  0x01000001 --> 0000 0000  0x01000002 --> 0000 0000
//	unsigned char *pixel_b = FRAME_ADDR ;
//	unsigned char *pixel_g = FRAME_ADDR + 1;
//	unsigned char *pixel_r = FRAME_ADDR + 2;
//
//	for(int i=0;i<VSIZE;i++){
//		for(int j=0;j<HSIZE;j++){
//			*pixel_b = 0xff;
//			*pixel_g = 0xff;
//			*pixel_r = 0x00;
//
//			pixel_b = pixel_b + 3;
//			pixel_g = pixel_g + 3;
//			pixel_r = pixel_r + 3;
//
//		}
//	}
	//Xil_DCacheFlush();
	//---------- Step.3 显示彩色  ---------------------
	Pixel* pixel = (volatile Pixel*)FRAME_ADDR;
	long long o = 0;
		for(long long i=0;i<VSIZE;i++){
			for(long long j=0;j<HSIZE;j++){
				pixel->r = img_r[o];
				pixel->g = img_g[o];
				pixel->b = img_b[o];

				o++;
				pixel++;

			}
		}



	Xil_DCacheFlush();



	while(1);

	return 0;

}
