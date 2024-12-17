#ifndef DCMIH_OV7670_H_
#define DCMIH_OV7670_H_

#include "Std_Types.h"

#define OV7670_QVGA_WIDTH  		300
#define OV7670_QVGA_HEIGHT 		200
#define OV7670_MODE_QVGA_RGB565 0
#define OV7670_MODE_QVGA_YUV    1
#define OV7670_CAP_CONTINUOUS   0
#define OV7670_CAP_SINGLE_FRAME 1
#define SLAVE_ADDR 				0x42
#define REG_BATT 				0xFF

extern void DcmiH_MainFunction(void);

#endif /* DCMIH_OV7670_H_ */
