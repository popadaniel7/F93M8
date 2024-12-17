// GEN BLOCK BEGIN Include
#define TSMP_IMPL
#include "TSMaster.h"
#include "MPLibrary.h"
#include "Database.h"
#include "TSMasterBaseInclude.h"
#include "Configuration.h"
// GEN BLOCK END Include

// CODE BLOCK BEGIN Global_Definitions 
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/****************************Info********************************************** 
 * Name:    InvertUint8 
 * Note: 	  invert 0x12 -> 0x48
			0x12: 0001 0010
			0x48: 0100 1000
 *****************************************************************************/
void InvertUint8(unsigned char *dBuf,unsigned char *srcBuf)
{
	int i;
	unsigned char tmp[4]={0};

	for(i=0;i< 8;i++)
	{
		if(srcBuf[0]& (1 << i))
		tmp[0]|=1<<(7-i);
	}
	dBuf[0] = tmp[0];
	
}
void InvertUint16(unsigned short *dBuf,unsigned short *srcBuf)
{
	int i;
	unsigned short tmp[4]={0};

	for(i=0;i< 16;i++)
	{
		if(srcBuf[0]& (1 << i))
		tmp[0]|=1<<(15 - i);
	}
	dBuf[0] = tmp[0];
}
void InvertUint32(unsigned int *dBuf,unsigned int *srcBuf)
{
	int i;
	unsigned int tmp[4]={0};
	
	for(i=0;i< 32;i++)
	{
		if(srcBuf[0]& (1 << i))
		tmp[0]|=1<<(31 - i);
	}
	dBuf[0] = tmp[0];
}
// CODE BLOCK END Global_Definitions 

// GEN BLOCK BEGIN Custom_Function
s32 CRC4_ITU(pu8 data, s32 datalen);
s32 CRC5_EPC(pu8 data, s32 datalen);
s32 CRC5_USB(pu8 data, s32 datalen);
s32 CRC5_ITU(pu8 data, s32 datalen);
s32 CRC6_ITU(pu8 data, s32 datalen);
s32 CRC7_MMC(pu8 data, s32 datalen);
s32 CRC8(pu8 data, s32 datalen);
s32 CRC8_ITU(pu8 data, s32 datalen);
s32 CRC8_ROHC(pu8 data, s32 datalen);
s32 CRC8_MAXIM(pu8 data, s32 datalen);
s32 CRC16_CCITT(pu8 data, s32 datalen);
s32 CRC16_CCITT_FALSE(pu8 data, s32 datalen);
s32 CRC16_XMODEM(pu8 data, s32 datalen);
s32 CRC16_X25(pu8 data, s32 datalen);
s32 CRC16_MODBUS(pu8 data, s32 datalen);
s32 CRC16_IBM(pu8 data, s32 datalen);
s32 CRC16_MAXIM(pu8 data, s32 datalen);
s32 CRC16_USB(pu8 data, s32 datalen);
s32 CRC16_DNP(pu8 data, s32 datalen);
s32 CRC32(pu8 data, s32 datalen);
s32 CRC32_MPEG(pu8 data, s32 datalen);
// GEN BLOCK END Custom_Function

// CODE BLOCK BEGIN Custom_Function CRC4_ITU cHU4IGRhdGEsIHMzMiBkYXRhbGVu
// Custom Function "CRC4_ITU"
s32 CRC4_ITU(pu8 data, s32 datalen) { try { // Custom Function: 
/****************************Info********************************************** 
 * Name:    CRC-4/ITU	x4+x+1 
 * Width:	4
 * Poly:    0x03 
 * Init:    0x00 
 * Refin:   True 
 * Refout:  True 
 * Xorout:  0x00 
 * Note: 
 *****************************************************************************/
 	unsigned char wCRCin = 0x00;
	unsigned char wCPoly = 0x03;
	unsigned char wChar = 0;
	
	while (datalen--) 	
	{
		wChar = *(data++);
		InvertUint8(&wChar,&wChar);
		wCRCin ^= (wChar);
		for(int i = 0;i < 8;i++)
		{
			if(wCRCin & 0x80)
				wCRCin = (wCRCin << 1) ^ (wCPoly << 4);
			else
				wCRCin = wCRCin << 1;
		}
	}
	InvertUint8(&wCRCin,&wCRCin);
	return (wCRCin);

} catch (...) { log_nok("CRASH detected"); app.terminate_application(); return(IDX_ERR_MP_CODE_CRASH); }}
// CODE BLOCK END Custom_Function CRC4_ITU

// CODE BLOCK BEGIN Custom_Function CRC5_EPC cHU4IGRhdGEsIHMzMiBkYXRhbGVu
// Custom Function "CRC5_EPC"
s32 CRC5_EPC(pu8 data, s32 datalen) { try { // Custom Function: 
/****************************Info********************************************** 
 * Name:    CRC-5/EPC	x5+x3+1 
 * Width:	5
 * Poly:    0x09 
 * Init:    0x09 
 * Refin:   False 
 * Refout:  False 
 * Xorout:  0x00 
 * Note: 
 *****************************************************************************/
 	unsigned char wCRCin = 0x09<<3;
	unsigned char wCPoly = 0x09<<3;
	
	while (datalen--) 	
	{
		wCRCin ^= *(data++);
		for(int i = 0;i < 8;i++)
		{
			if(wCRCin & 0x80)
				wCRCin = (wCRCin << 1) ^ (wCPoly);
			else
				wCRCin = wCRCin << 1;
		}
	}
	return (wCRCin >> 3);

} catch (...) { log_nok("CRASH detected"); app.terminate_application(); return(IDX_ERR_MP_CODE_CRASH); }}
// CODE BLOCK END Custom_Function CRC5_EPC

// CODE BLOCK BEGIN Custom_Function CRC5_USB cHU4IGRhdGEsIHMzMiBkYXRhbGVu
// Custom Function "CRC5_USB"
s32 CRC5_USB(pu8 data, s32 datalen) { try { // Custom Function: 
/****************************Info********************************************** 
 * Name:    CRC-5/USB	x5+x2+1 
 * Width:	5
 * Poly:    0x05 
 * Init:    0x1F 
 * Refin:   True 
 * Refout:  True 
 * Xorout:  0x1F 
 * Note: 
 *****************************************************************************/
	unsigned char wCRCin = 0x1F;
	unsigned char wCPoly = 0x05;
	
	InvertUint8(&wCPoly,&wCPoly);
	while (datalen--) 	
	{
		wCRCin ^= *(data++);
		for(int i = 0;i < 8;i++)
		{
			if(wCRCin & 0x01)
				wCRCin = (wCRCin >> 1) ^ (wCPoly >> 3);
			else
				wCRCin = wCRCin >> 1;
		}
	}
	return (wCRCin^0x1F); 

} catch (...) { log_nok("CRASH detected"); app.terminate_application(); return(IDX_ERR_MP_CODE_CRASH); }}
// CODE BLOCK END Custom_Function CRC5_USB

// CODE BLOCK BEGIN Custom_Function CRC5_ITU cHU4IGRhdGEsIHMzMiBkYXRhbGVu
// Custom Function "CRC5_ITU"
s32 CRC5_ITU(pu8 data, s32 datalen) { try { // Custom Function: 
/****************************Info********************************************** 
 * Name:    CRC-5/ITU	x5+x4+x2+1  
 * Width:	5
 * Poly:    0x15 
 * Init:    0x00 
 * Refin:   True 
 * Refout:  True 
 * Xorout:  0x00 
 * Note: 
 *****************************************************************************/
	unsigned char wCRCin = 0x00;
	unsigned char wCPoly = 0x15;
	
	InvertUint8(&wCPoly,&wCPoly);
	while (datalen--) 	
	{
		wCRCin ^= *(data++);
		for(int i = 0;i < 8;i++)
		{
			if(wCRCin & 0x01)
				wCRCin = (wCRCin >> 1) ^ (wCPoly >> 3);
			else
				wCRCin = wCRCin >> 1;
		}
	}
	return (wCRCin); 

} catch (...) { log_nok("CRASH detected"); app.terminate_application(); return(IDX_ERR_MP_CODE_CRASH); }}
// CODE BLOCK END Custom_Function CRC5_ITU

// CODE BLOCK BEGIN Custom_Function CRC6_ITU cHU4IGRhdGEsIHMzMiBkYXRhbGVu
// Custom Function "CRC6_ITU"
s32 CRC6_ITU(pu8 data, s32 datalen) { try { // Custom Function: 
/****************************Info********************************************** 
 * Name:    CRC-6/ITU	x6+x+1 
 * Width:	6
 * Poly:    0x03 
 * Init:    0x00 
 * Refin:   True 
 * Refout:  True 
 * Xorout:  0x00 
 * Note: 
 *****************************************************************************/
	unsigned char wCRCin = 0x00;
	unsigned char wCPoly = 0x03;
	unsigned char wChar = 0;
	
	while (datalen--) 	
	{
		wChar = *(data++);
		InvertUint8(&wChar,&wChar);
		wCRCin ^= (wChar);
		for(int i = 0;i < 8;i++)
		{
			if(wCRCin & 0x80)
				wCRCin = (wCRCin << 1) ^ (wCPoly << 2);
			else
				wCRCin = wCRCin << 1;
		}
	}
	InvertUint8(&wCRCin,&wCRCin);
	return (wCRCin);

} catch (...) { log_nok("CRASH detected"); app.terminate_application(); return(IDX_ERR_MP_CODE_CRASH); }}
// CODE BLOCK END Custom_Function CRC6_ITU

// CODE BLOCK BEGIN Custom_Function CRC7_MMC cHU4IGRhdGEsIHMzMiBkYXRhbGVu
// Custom Function "CRC7_MMC"
s32 CRC7_MMC(pu8 data, s32 datalen) { try { // Custom Function: 
/****************************Info********************************************** 
 * Name:    CRC-7/MMC           x7+x3+1  
 * Width:	7
 * Poly:    0x09 
 * Init:    0x00 
 * Refin:   False 
 * Refout:  False 
 * Xorout:  0x00 
 * Use:     MultiMediaCard,SD,ect. 
 *****************************************************************************/
	unsigned char wCRCin = 0x00;
	unsigned char wCPoly = 0x09;
	
	while (datalen--) 	
	{
		wCRCin ^= *(data++);
		for(int i = 0;i < 8;i++)
		{
			if(wCRCin & 0x80)
				wCRCin = (wCRCin << 1) ^ (wCPoly<<1);
			else
				wCRCin = wCRCin << 1;
		}
	}
	return (wCRCin>>1);

} catch (...) { log_nok("CRASH detected"); app.terminate_application(); return(IDX_ERR_MP_CODE_CRASH); }}
// CODE BLOCK END Custom_Function CRC7_MMC

// CODE BLOCK BEGIN Custom_Function CRC8 cHU4IGRhdGEsIHMzMiBkYXRhbGVu
// Custom Function "CRC8"
s32 CRC8(pu8 data, s32 datalen) { try { // Custom Function: 
/****************************Info********************************************** 
 * Name:    CRC-8               x8+x2+x+1 
 * Width:	8 
 * Poly:    0x07 
 * Init:    0x00 
 * Refin:   False 
 * Refout:  False 
 * Xorout:  0x00 
 * Note: 
 *****************************************************************************/
	unsigned char wCRCin = 0x00;
	unsigned char wCPoly = 0x07;
	
	while (datalen--) 	
	{
		wCRCin ^= *(data++);
		for(int i = 0;i < 8;i++)
		{
			if(wCRCin & 0x80)
				wCRCin = (wCRCin << 1) ^ wCPoly;
			else
				wCRCin = wCRCin << 1;
		}
	}
	return (wCRCin);

} catch (...) { log_nok("CRASH detected"); app.terminate_application(); return(IDX_ERR_MP_CODE_CRASH); }}
// CODE BLOCK END Custom_Function CRC8

// CODE BLOCK BEGIN Custom_Function CRC8_ITU cHU4IGRhdGEsIHMzMiBkYXRhbGVu
// Custom Function "CRC8_ITU"
s32 CRC8_ITU(pu8 data, s32 datalen) { try { // Custom Function: 
/****************************Info********************************************** 
 * Name:    CRC-8/ITU           x8+x2+x+1 
 * Width:	8 
 * Poly:    0x07 
 * Init:    0x00 
 * Refin:   False 
 * Refout:  False 
 * Xorout:  0x55 
 * Alias:   CRC-8/ATM 
 *****************************************************************************/
	unsigned char wCRCin = 0x00;
	unsigned char wCPoly = 0x07;
	
	while (datalen--) 	
	{
		wCRCin ^= *(data++);
		for(int i = 0;i < 8;i++)
		{
			if(wCRCin & 0x80)
				wCRCin = (wCRCin << 1) ^ wCPoly;
			else
				wCRCin = wCRCin << 1;
		}
	}
	return (wCRCin^0x55);

} catch (...) { log_nok("CRASH detected"); app.terminate_application(); return(IDX_ERR_MP_CODE_CRASH); }}
// CODE BLOCK END Custom_Function CRC8_ITU

// CODE BLOCK BEGIN Custom_Function CRC8_ROHC cHU4IGRhdGEsIHMzMiBkYXRhbGVu
// Custom Function "CRC8_ROHC"
s32 CRC8_ROHC(pu8 data, s32 datalen) { try { // Custom Function: 
/****************************Info********************************************** 
 * Name:    CRC-8/ROHC          x8+x2+x+1 
 * Width:	8 
 * Poly:    0x07 
 * Init:    0xFF 
 * Refin:   True 
 * Refout:  True 
 * Xorout:  0x00 
 * Note: 
 *****************************************************************************/
	unsigned char wCRCin = 0xFF;
	unsigned char wCPoly = 0x07;
	
	InvertUint8(&wCPoly,&wCPoly);
	while (datalen--) 	
	{
		wCRCin ^= *(data++);
		for(int i = 0;i < 8;i++)
		{
			if(wCRCin & 0x01)
				wCRCin = (wCRCin >> 1) ^ wCPoly;
			else
				wCRCin = wCRCin >> 1;
		}
	}
	return (wCRCin);

} catch (...) { log_nok("CRASH detected"); app.terminate_application(); return(IDX_ERR_MP_CODE_CRASH); }}
// CODE BLOCK END Custom_Function CRC8_ROHC

// CODE BLOCK BEGIN Custom_Function CRC8_MAXIM cHU4IGRhdGEsIHMzMiBkYXRhbGVu
// Custom Function "CRC8_MAXIM"
s32 CRC8_MAXIM(pu8 data, s32 datalen) { try { // Custom Function: 
/****************************Info********************************************** 
 * Name:    CRC-8/MAXIM         x8+x5+x4+1 
 * Width:	8 
 * Poly:    0x31 
 * Init:    0x00 
 * Refin:   True 
 * Refout:  True 
 * Xorout:  0x00 
 * Alias:   DOW-CRC,CRC-8/IBUTTON 
 * Use:     Maxim(Dallas)'s some devices,e.g. DS18B20 
 *****************************************************************************/ 
	unsigned char wCRCin = 0x00;
	unsigned char wCPoly = 0x31;
	
	InvertUint8(&wCPoly,&wCPoly);
	while (datalen--) 	
	{
		wCRCin ^= *(data++);
		for(int i = 0;i < 8;i++)
		{
			if(wCRCin & 0x01)
				wCRCin = (wCRCin >> 1) ^ wCPoly;
			else
				wCRCin = wCRCin >> 1;
		}
	}
	return (wCRCin);

} catch (...) { log_nok("CRASH detected"); app.terminate_application(); return(IDX_ERR_MP_CODE_CRASH); }}
// CODE BLOCK END Custom_Function CRC8_MAXIM

// CODE BLOCK BEGIN Custom_Function CRC16_CCITT cHU4IGRhdGEsIHMzMiBkYXRhbGVu
// Custom Function "CRC16_CCITT"
s32 CRC16_CCITT(pu8 data, s32 datalen) { try { // Custom Function: 
/****************************Info********************************************** 
 * Name:    CRC-16/CCITT        x16+x12+x5+1 
 * Poly:    0x1021 
 * Init:    0x0000 
 * Refin:   True 
 * Refout:  True 
 * Xorout:  0x0000 
 * Alias:   CRC-CCITT,CRC-16/CCITT-TRUE,CRC-16/KERMIT 
 *****************************************************************************/ 
	unsigned short wCRCin = 0x0000;
	unsigned short wCPoly = 0x1021;
	unsigned char wChar = 0;
	
	InvertUint16(&wCPoly,&wCPoly);
	while (datalen--) 	
	{
		wCRCin ^= *(data++);
		for(int i = 0;i < 8;i++)
		{
			if(wCRCin & 0x01)
				wCRCin = (wCRCin >> 1) ^ wCPoly;
			else
				wCRCin = wCRCin >> 1;
		}
	}
	return (wCRCin);

} catch (...) { log_nok("CRASH detected"); app.terminate_application(); return(IDX_ERR_MP_CODE_CRASH); }}
// CODE BLOCK END Custom_Function CRC16_CCITT

// CODE BLOCK BEGIN Custom_Function CRC16_CCITT_FALSE cHU4IGRhdGEsIHMzMiBkYXRhbGVu
// Custom Function "CRC16_CCITT_FALSE"
s32 CRC16_CCITT_FALSE(pu8 data, s32 datalen) { try { // Custom Function: 
/****************************Info********************************************** 
 * Name:    CRC-16/CCITT-FALSE   x16+x12+x5+1 
 * Width:	16 
 * Poly:    0x1021 
 * Init:    0xFFFF 
 * Refin:   False 
 * Refout:  False 
 * Xorout:  0x0000 
 * Note: 
 *****************************************************************************/ 
	unsigned short wCRCin = 0xFFFF;
	unsigned short wCPoly = 0x1021;
	
	while (datalen--) 	
	{
		wCRCin ^= *(data++) << 8;
		for(int i = 0;i < 8;i++)
		{
			if(wCRCin & 0x8000)
				wCRCin = (wCRCin << 1) ^ wCPoly;
			else
				wCRCin = wCRCin << 1;
		}
	}
	return (wCRCin);

} catch (...) { log_nok("CRASH detected"); app.terminate_application(); return(IDX_ERR_MP_CODE_CRASH); }}
// CODE BLOCK END Custom_Function CRC16_CCITT_FALSE

// CODE BLOCK BEGIN Custom_Function CRC16_XMODEM cHU4IGRhdGEsIHMzMiBkYXRhbGVu
// Custom Function "CRC16_XMODEM"
s32 CRC16_XMODEM(pu8 data, s32 datalen) { try { // Custom Function: 
/****************************Info********************************************** 
 * Name:    CRC-16/XMODEM       x16+x12+x5+1 
 * Width:	16 
 * Poly:    0x1021 
 * Init:    0x0000 
 * Refin:   False 
 * Refout:  False 
 * Xorout:  0x0000 
 * Alias:   CRC-16/ZMODEM,CRC-16/ACORN 
 *****************************************************************************/ 
	unsigned short wCRCin = 0x0000;
	unsigned short wCPoly = 0x1021;
	
	while (datalen--) 	
	{
		wCRCin ^= (*(data++) << 8);
		for(int i = 0;i < 8;i++)
		{
			if(wCRCin & 0x8000)
				wCRCin = (wCRCin << 1) ^ wCPoly;
			else
				wCRCin = wCRCin << 1;
		}
	}
	return (wCRCin);

} catch (...) { log_nok("CRASH detected"); app.terminate_application(); return(IDX_ERR_MP_CODE_CRASH); }}
// CODE BLOCK END Custom_Function CRC16_XMODEM

// CODE BLOCK BEGIN Custom_Function CRC16_X25 cHU4IGRhdGEsIHMzMiBkYXRhbGVu
// Custom Function "CRC16_X25"
s32 CRC16_X25(pu8 data, s32 datalen) { try { // Custom Function: 
/****************************Info********************************************** 
 * Name:    CRC-16/X25          x16+x12+x5+1 
 * Width:	16 
 * Poly:    0x1021 
 * Init:    0xFFFF 
 * Refin:   True 
 * Refout:  True 
 * Xorout:  0XFFFF 
 * Note: 
 *****************************************************************************/
	unsigned short wCRCin = 0xFFFF;
	unsigned short wCPoly = 0x1021;
	
	InvertUint16(&wCPoly,&wCPoly);
	while (datalen--) 	
	{
		wCRCin ^= *(data++);
		for(int i = 0;i < 8;i++)
		{
			if(wCRCin & 0x01)
				wCRCin = (wCRCin >> 1) ^ wCPoly;
			else
				wCRCin = wCRCin >> 1;
		}
	}
	return (wCRCin^0xFFFF);

} catch (...) { log_nok("CRASH detected"); app.terminate_application(); return(IDX_ERR_MP_CODE_CRASH); }}
// CODE BLOCK END Custom_Function CRC16_X25

// CODE BLOCK BEGIN Custom_Function CRC16_MODBUS cHU4IGRhdGEsIHMzMiBkYXRhbGVu
// Custom Function "CRC16_MODBUS"
s32 CRC16_MODBUS(pu8 data, s32 datalen) { try { // Custom Function: 
/****************************Info********************************************** 
 * Name:    CRC-16/MODBUS       x16+x15+x2+1 
 * Width:	16 
 * Poly:    0x8005 
 * Init:    0xFFFF 
 * Refin:   True 
 * Refout:  True 
 * Xorout:  0x0000 
 * Note: 
 *****************************************************************************/
	unsigned short wCRCin = 0xFFFF;
	unsigned short wCPoly = 0x8005;
	
	InvertUint16(&wCPoly,&wCPoly);
	while (datalen--) 	
	{
		wCRCin ^= *(data++);
		for(int i = 0;i < 8;i++)
		{
			if(wCRCin & 0x01)
				wCRCin = (wCRCin >> 1) ^ wCPoly;
			else
				wCRCin = wCRCin >> 1;
		}
	}
	return (wCRCin);

} catch (...) { log_nok("CRASH detected"); app.terminate_application(); return(IDX_ERR_MP_CODE_CRASH); }}
// CODE BLOCK END Custom_Function CRC16_MODBUS

// CODE BLOCK BEGIN Custom_Function CRC16_IBM cHU4IGRhdGEsIHMzMiBkYXRhbGVu
// Custom Function "CRC16_IBM"
s32 CRC16_IBM(pu8 data, s32 datalen) { try { // Custom Function: 
/****************************Info********************************************** 
 * Name:    CRC-16/IBM          x16+x15+x2+1 
 * Width:	16 
 * Poly:    0x8005 
 * Init:    0x0000 
 * Refin:   True 
 * Refout:  True 
 * Xorout:  0x0000 
 * Alias:   CRC-16,CRC-16/ARC,CRC-16/LHA 
 *****************************************************************************/ 
	unsigned short wCRCin = 0x0000;
	unsigned short wCPoly = 0x8005;
	
	InvertUint16(&wCPoly,&wCPoly);
	while (datalen--) 	
	{
		wCRCin ^= *(data++);
		for(int i = 0;i < 8;i++)
		{
			if(wCRCin & 0x01)
				wCRCin = (wCRCin >> 1) ^ wCPoly;
			else
				wCRCin = wCRCin >> 1;
		}
	}
	return (wCRCin);

} catch (...) { log_nok("CRASH detected"); app.terminate_application(); return(IDX_ERR_MP_CODE_CRASH); }}
// CODE BLOCK END Custom_Function CRC16_IBM

// CODE BLOCK BEGIN Custom_Function CRC16_MAXIM cHU4IGRhdGEsIHMzMiBkYXRhbGVu
// Custom Function "CRC16_MAXIM"
s32 CRC16_MAXIM(pu8 data, s32 datalen) { try { // Custom Function: 
/****************************Info********************************************** 
 * Name:    CRC-16/MAXIM        x16+x15+x2+1 
 * Width:	16 
 * Poly:    0x8005 
 * Init:    0x0000 
 * Refin:   True 
 * Refout:  True 
 * Xorout:  0xFFFF 
 * Note: 
 *****************************************************************************/
	unsigned short wCRCin = 0x0000;
	unsigned short wCPoly = 0x8005;
	
	InvertUint16(&wCPoly,&wCPoly);
	while (datalen--) 	
	{
		wCRCin ^= *(data++);
		for(int i = 0;i < 8;i++)
		{
			if(wCRCin & 0x01)
				wCRCin = (wCRCin >> 1) ^ wCPoly;
			else
				wCRCin = wCRCin >> 1;
		}
	}
	return (wCRCin^0xFFFF);

} catch (...) { log_nok("CRASH detected"); app.terminate_application(); return(IDX_ERR_MP_CODE_CRASH); }}
// CODE BLOCK END Custom_Function CRC16_MAXIM

// CODE BLOCK BEGIN Custom_Function CRC16_USB cHU4IGRhdGEsIHMzMiBkYXRhbGVu
// Custom Function "CRC16_USB"
s32 CRC16_USB(pu8 data, s32 datalen) { try { // Custom Function: 
/****************************Info********************************************** 
 * Name:    CRC-16/USB          x16+x15+x2+1 
 * Width:	16 
 * Poly:    0x8005 
 * Init:    0xFFFF 
 * Refin:   True 
 * Refout:  True 
 * Xorout:  0xFFFF 
 * Note: 
 *****************************************************************************/ 
	unsigned short wCRCin = 0xFFFF;
	unsigned short wCPoly = 0x8005;
	
	InvertUint16(&wCPoly,&wCPoly);
	while (datalen--) 	
	{
		wCRCin ^= *(data++);
		for(int i = 0;i < 8;i++)
		{
			if(wCRCin & 0x01)
				wCRCin = (wCRCin >> 1) ^ wCPoly;
			else
				wCRCin = wCRCin >> 1;
		}
	}
	return (wCRCin^0xFFFF);

} catch (...) { log_nok("CRASH detected"); app.terminate_application(); return(IDX_ERR_MP_CODE_CRASH); }}
// CODE BLOCK END Custom_Function CRC16_USB

// CODE BLOCK BEGIN Custom_Function CRC16_DNP cHU4IGRhdGEsIHMzMiBkYXRhbGVu
// Custom Function "CRC16_DNP"
s32 CRC16_DNP(pu8 data, s32 datalen) { try { // Custom Function: 
/****************************Info********************************************** 
 * Name:    CRC-16/DNP          x16+x13+x12+x11+x10+x8+x6+x5+x2+1 
 * Width:	16 
 * Poly:    0x3D65 
 * Init:    0x0000 
 * Refin:   True 
 * Refout:  True 
 * Xorout:  0xFFFF 
 * Use:     M-Bus,ect. 
 *****************************************************************************/  
	unsigned short wCRCin = 0x0000;
	unsigned short wCPoly = 0x3D65;
	
	InvertUint16(&wCPoly,&wCPoly);
	while (datalen--) 	
	{
		wCRCin ^= *(data++);
		for(int i = 0;i < 8;i++)
		{
			if(wCRCin & 0x01)
				wCRCin = (wCRCin >> 1) ^ wCPoly;
			else
				wCRCin = (wCRCin >> 1);
		}
	}
	return (wCRCin^0xFFFF);

} catch (...) { log_nok("CRASH detected"); app.terminate_application(); return(IDX_ERR_MP_CODE_CRASH); }}
// CODE BLOCK END Custom_Function CRC16_DNP

// CODE BLOCK BEGIN Custom_Function CRC32 cHU4IGRhdGEsIHMzMiBkYXRhbGVu
// Custom Function "CRC32"
s32 CRC32(pu8 data, s32 datalen) { try { // Custom Function: 
/****************************Info********************************************** 
 * Name:    CRC-32  x32+x26+x23+x22+x16+x12+x11+x10+x8+x7+x5+x4+x2+x+1 
 * Width:	32 
 * Poly:    0x4C11DB7 
 * Init:    0xFFFFFFF 
 * Refin:   True 
 * Refout:  True 
 * Xorout:  0xFFFFFFF 
 * Alias:   CRC_32/ADCCP 
 * Use:     WinRAR,ect. 
 *****************************************************************************/ 
	unsigned int wCRCin = 0xFFFFFFFF;
	unsigned int wCPoly = 0x04C11DB7;

	InvertUint32(&wCPoly,&wCPoly);
	while (datalen--) 	
	{
		wCRCin ^= *(data++);
		for(int i = 0;i < 8;i++)
		{
			if(wCRCin & 0x01)
				wCRCin = (wCRCin >> 1) ^ wCPoly;
			else
				wCRCin = wCRCin >> 1;
		}
	}
	return (wCRCin ^ 0xFFFFFFFF);

} catch (...) { log_nok("CRASH detected"); app.terminate_application(); return(IDX_ERR_MP_CODE_CRASH); }}
// CODE BLOCK END Custom_Function CRC32

// CODE BLOCK BEGIN Custom_Function CRC32_MPEG cHU4IGRhdGEsIHMzMiBkYXRhbGVu
// Custom Function "CRC32_MPEG"
s32 CRC32_MPEG(pu8 data, s32 datalen) { try { // Custom Function: 
/****************************Info********************************************** 
 * Name:    CRC-32/MPEG-2  x32+x26+x23+x22+x16+x12+x11+x10+x8+x7+x5+x4+x2+x+1 
 * Width:	32 
 * Poly:    0x4C11DB7 
 * Init:    0xFFFFFFF 
 * Refin:   False 
 * Refout:  False 
 * Xorout:  0x0000000 
 * Note: 
 *****************************************************************************/ 
	unsigned int wCRCin = 0xFFFFFFFF;
	unsigned int wCPoly = 0x04C11DB7;
	unsigned int wChar = 0;
	while (datalen--) 	
	{
		wChar = *(data++);
		wCRCin ^= (wChar << 24);
		for(int i = 0;i < 8;i++)
		{
			if(wCRCin & 0x80000000)
				wCRCin = (wCRCin << 1) ^ wCPoly;
			else
				wCRCin = wCRCin << 1;
		}
	}
	return (wCRCin);

} catch (...) { log_nok("CRASH detected"); app.terminate_application(); return(IDX_ERR_MP_CODE_CRASH); }}
// CODE BLOCK END Custom_Function CRC32_MPEG

// CODE BLOCK BEGIN Step_Function  NQ__
// Main step function being executed every 5 ms
void step(void) { try { // interval = 5 ms

} catch (...) { log_nok("CRASH detected"); app.terminate_application(); }}
// CODE BLOCK END Step_Function 

