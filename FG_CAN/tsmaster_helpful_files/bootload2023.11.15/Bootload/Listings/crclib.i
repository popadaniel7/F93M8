# 1 "Uds_server/crcLib.c"
# 1 "<built-in>" 1
# 1 "<built-in>" 3
# 379 "<built-in>" 3
# 1 "<command line>" 1
# 1 "<built-in>" 2
# 1 "Uds_server/crcLib.c" 2
# 33 "Uds_server/crcLib.c"
# 1 "./Uds_server/crcLib.h" 1




# 1 "./RTE/Device/TLE9893_2QKW62S\\types.h" 1
# 98 "./RTE/Device/TLE9893_2QKW62S\\types.h"
# 1 "C:\\Keil_v5\\ARM\\ARMCLANG\\Bin\\..\\include\\stdint.h" 1 3
# 56 "C:\\Keil_v5\\ARM\\ARMCLANG\\Bin\\..\\include\\stdint.h" 3
typedef signed char int8_t;
typedef signed short int int16_t;
typedef signed int int32_t;
typedef signed long long int int64_t;


typedef unsigned char uint8_t;
typedef unsigned short int uint16_t;
typedef unsigned int uint32_t;
typedef unsigned long long int uint64_t;





typedef signed char int_least8_t;
typedef signed short int int_least16_t;
typedef signed int int_least32_t;
typedef signed long long int int_least64_t;


typedef unsigned char uint_least8_t;
typedef unsigned short int uint_least16_t;
typedef unsigned int uint_least32_t;
typedef unsigned long long int uint_least64_t;




typedef signed int int_fast8_t;
typedef signed int int_fast16_t;
typedef signed int int_fast32_t;
typedef signed long long int int_fast64_t;


typedef unsigned int uint_fast8_t;
typedef unsigned int uint_fast16_t;
typedef unsigned int uint_fast32_t;
typedef unsigned long long int uint_fast64_t;






typedef signed int intptr_t;
typedef unsigned int uintptr_t;



typedef signed long long intmax_t;
typedef unsigned long long uintmax_t;
# 99 "./RTE/Device/TLE9893_2QKW62S\\types.h" 2
# 1 "./RTE/Device/TLE9893_2QKW62S/error_codes.h" 1
# 61 "./RTE/Device/TLE9893_2QKW62S/error_codes.h"
# 1 "./RTE/_Bootload\\RTE_Components.h" 1
# 62 "./RTE/Device/TLE9893_2QKW62S/error_codes.h" 2
# 100 "./RTE/Device/TLE9893_2QKW62S\\types.h" 2
# 122 "./RTE/Device/TLE9893_2QKW62S\\types.h"
# 1 "C:\\Keil_v5\\ARM\\ARMCLANG\\Bin\\..\\include\\stdbool.h" 1 3
# 123 "./RTE/Device/TLE9893_2QKW62S\\types.h" 2
# 220 "./RTE/Device/TLE9893_2QKW62S\\types.h"
typedef uint8_t uint8;
typedef uint16_t uint16;
typedef uint32_t uint32;
typedef uint64_t uint64;

typedef int8_t sint8;
typedef int16_t sint16;
typedef int32_t sint32;
typedef int64_t sint64;

typedef float float32;
typedef double float64;

typedef short FixPoint16;
typedef long FixPoint32;





  typedef FixPoint16 TStdReal;
  typedef FixPoint32 TLongStdReal;
# 253 "./RTE/Device/TLE9893_2QKW62S\\types.h"
typedef struct StdRealComplex
{
  TStdReal imag;
  TStdReal real;
} TStdRealComplex;



typedef struct
{
  sint16 Real;
  sint16 Imag;
} TComplex;



typedef struct
{
  sint16 A;
  sint16 B;
} TPhaseCurr;
# 6 "./Uds_server/crcLib.h" 2
uint8_t crc4_itu(uint8_t *data, uint16_t length);
uint8_t crc5_epc(uint8_t *data, uint16_t length);
uint8_t crc5_itu(uint8_t *data, uint16_t length);
uint8_t crc5_usb(uint8_t *data, uint16_t length);
uint8_t crc6_itu(uint8_t *data, uint16_t length);
uint8_t crc7_mmc(uint8_t *data, uint16_t length);
uint8_t crc8(uint8_t *data, uint16_t length);
uint8_t crc8_itu(uint8_t *data, uint16_t length);
uint8_t crc8_rohc(uint8_t *data, uint16_t length);
uint8_t crc8_maxim(uint8_t *data, uint16_t length);
uint16_t crc16_ibm(uint8_t *data, uint16_t length);
uint16_t crc16_maxim(uint8_t *data, uint16_t length);
uint16_t crc16_usb(uint8_t *data, uint16_t length);
uint16_t crc16_modbus(uint8_t *data, uint16_t length);
uint16_t crc16_ccitt(uint8_t *data, uint16_t length);
uint16_t crc16_ccitt_false(uint8_t *data, uint16_t length);
uint16_t crc16_x25(uint8_t *data, uint16_t length);
uint16_t crc16_xmodem(uint8_t *data, uint16_t length);
uint16_t crc16_dnp(uint8_t *data, uint16_t length);
uint32_t crc32(uint8_t *data, uint32_t length);
uint32_t crc32_mpeg_2(uint8_t *data, uint16_t length);

uint16_t CRC_16_table(uint8_t* aData, unsigned int aSize);
uint8_t crc8_table(uint8_t* ptr, unsigned int len);
# 34 "Uds_server/crcLib.c" 2
# 44 "Uds_server/crcLib.c"
uint8_t crc4_itu(uint8_t *data, uint16_t length)
{
    uint8_t i;
    uint8_t crc = 0;
    while(length--)
    {
        crc ^= *data++;
        for (i = 0; i < 8; ++i)
        {
            if (crc & 1)
                crc = (crc >> 1) ^ 0x0C;
            else
                crc = (crc >> 1);
        }
    }
    return crc;
}
# 71 "Uds_server/crcLib.c"
uint8_t crc5_epc(uint8_t *data, uint16_t length)
{
    uint8_t i;
    uint8_t crc = 0x48;
    while(length--)
    {
        crc ^= *data++;
        for ( i = 0; i < 8; i++ )
        {
            if ( crc & 0x80 )
                crc =(uint8_t)((crc << 1) ^ 0x48);
            else
                crc <<= 1;
        }
    }
    return crc >> 3;
}
# 98 "Uds_server/crcLib.c"
uint8_t crc5_itu(uint8_t *data, uint16_t length)
{
    uint8_t i;
    uint8_t crc = 0;
    while(length--)
    {
        crc ^= *data++;
        for (i = 0; i < 8; ++i)
        {
            if (crc & 1)
                crc = (crc >> 1) ^ 0x15;
            else
                crc = (crc >> 1);
        }
    }
    return crc;
}
# 125 "Uds_server/crcLib.c"
uint8_t crc5_usb(uint8_t *data, uint16_t length)
{
    uint8_t i;
    uint8_t crc = 0x1F;
    while(length--)
    {
        crc ^= *data++;
        for (i = 0; i < 8; ++i)
        {
            if (crc & 1)
                crc = (crc >> 1) ^ 0x14;
            else
                crc = (crc >> 1);
        }
    }
    return crc ^ 0x1F;
}
# 152 "Uds_server/crcLib.c"
uint8_t crc6_itu(uint8_t *data, uint16_t length)
{
    uint8_t i;
    uint8_t crc = 0;
    while(length--)
    {
        crc ^= *data++;
        for (i = 0; i < 8; ++i)
        {
            if (crc & 1)
                crc = (crc >> 1) ^ 0x30;
            else
                crc = (crc >> 1);
        }
    }
    return crc;
}
# 179 "Uds_server/crcLib.c"
uint8_t crc7_mmc(uint8_t *data, uint16_t length)
{
    uint8_t i;
    uint8_t crc = 0;
    while(length--)
    {
        crc ^= *data++;
        for ( i = 0; i < 8; i++ )
        {
            if ( crc & 0x80 )
                crc =(uint8_t)((crc << 1) ^ 0x12);
            else
                crc <<= 1;
        }
    }
    return crc >> 1;
}
static const unsigned char crc_table[] =
{
0x00,0x31,0x62,0x53,0xc4,0xf5,0xa6,0x97,0xb9,0x88,0xdb,0xea,0x7d,0x4c,0x1f,0x2e,0x43,0x72,0x21,0x10,0x87,0xb6,0xe5,0xd4,0xfa,0xcb,0x98,0xa9,0x3e,0x0f,0x5c,0x6d,0x86,0xb7,0xe4,0xd5,0x42,0x73,0x20,0x11,0x3f,0x0e,0x5d,0x6c,0xfb,0xca,0x99,0xa8,0xc5,0xf4,0xa7,0x96,0x01,0x30,0x63,0x52,0x7c,0x4d,0x1e,0x2f,0xb8,0x89,0xda,0xeb,0x3d,0x0c,0x5f,0x6e,0xf9,0xc8,0x9b,0xaa,0x84,0xb5,0xe6,0xd7,0x40,0x71,0x22,0x13,0x7e,0x4f,0x1c,0x2d,0xba,0x8b,0xd8,0xe9,0xc7,0xf6,0xa5,0x94,0x03,0x32,0x61,0x50,0xbb,0x8a,0xd9,0xe8,0x7f,0x4e,0x1d,0x2c,0x02,0x33,0x60,0x51,0xc6,0xf7,0xa4,0x95,0xf8,0xc9,0x9a,0xab,0x3c,0x0d,0x5e,0x6f,0x41,0x70,0x23,0x12,0x85,0xb4,0xe7,0xd6,0x7a,0x4b,0x18,0x29,0xbe,0x8f,0xdc,0xed,0xc3,0xf2,0xa1,0x90,0x07,0x36,0x65,0x54,0x39,0x08,0x5b,0x6a,0xfd,0xcc,0x9f,0xae,0x80,0xb1,0xe2,0xd3,0x44,0x75,0x26,0x17,0xfc,0xcd,0x9e,0xaf,0x38,0x09,0x5a,0x6b,0x45,0x74,0x27,0x16,0x81,0xb0,0xe3,0xd2,0xbf,0x8e,0xdd,0xec,0x7b,0x4a,0x19,0x28,0x06,0x37,0x64,0x55,0xc2,0xf3,0xa0,0x91,0x47,0x76,0x25,0x14,0x83,0xb2,0xe1,0xd0,0xfe,0xcf,0x9c,0xad,0x3a,0x0b,0x58,0x69,0x04,0x35,0x66,0x57,0xc0,0xf1,0xa2,0x93,0xbd,0x8c,0xdf,0xee,0x79,0x48,0x1b,0x2a,0xc1,0xf0,0xa3,0x92,0x05,0x34,0x67,0x56,0x78,0x49,0x1a,0x2b,0xbc,0x8d,0xde,0xef,0x82,0xb3,0xe0,0xd1,0x46,0x77,0x24,0x15,0x3b,0x0a,0x59,0x68,0xff,0xce,0x9d,0xac
};
uint8_t crc8_table(uint8_t* ptr, unsigned int len)
{
    uint8_t crc = 0x00;
    while (len--)
    {
        crc = crc_table[crc ^ *ptr++];
    }
    return (crc);
}
static const uint16_t CRC16_TABLE[256] =
{
    0x0000,0x1021,0x2042,0x3063,0x4084,0x50a5,0x60c6,0x70e7,
    0x8108,0x9129,0xa14a,0xb16b,0xc18c,0xd1ad,0xe1ce,0xf1ef,
    0x1231,0x0210,0x3273,0x2252,0x52b5,0x4294,0x72f7,0x62d6,
    0x9339,0x8318,0xb37b,0xa35a,0xd3bd,0xc39c,0xf3ff,0xe3de,
    0x2462,0x3443,0x0420,0x1401,0x64e6,0x74c7,0x44a4,0x5485,
    0xa56a,0xb54b,0x8528,0x9509,0xe5ee,0xf5cf,0xc5ac,0xd58d,
    0x3653,0x2672,0x1611,0x0630,0x76d7,0x66f6,0x5695,0x46b4,
    0xb75b,0xa77a,0x9719,0x8738,0xf7df,0xe7fe,0xd79d,0xc7bc,
    0x48c4,0x58e5,0x6886,0x78a7,0x0840,0x1861,0x2802,0x3823,
    0xc9cc,0xd9ed,0xe98e,0xf9af,0x8948,0x9969,0xa90a,0xb92b,
    0x5af5,0x4ad4,0x7ab7,0x6a96,0x1a71,0x0a50,0x3a33,0x2a12,
    0xdbfd,0xcbdc,0xfbbf,0xeb9e,0x9b79,0x8b58,0xbb3b,0xab1a,
    0x6ca6,0x7c87,0x4ce4,0x5cc5,0x2c22,0x3c03,0x0c60,0x1c41,
    0xedae,0xfd8f,0xcdec,0xddcd,0xad2a,0xbd0b,0x8d68,0x9d49,
    0x7e97,0x6eb6,0x5ed5,0x4ef4,0x3e13,0x2e32,0x1e51,0x0e70,
    0xff9f,0xefbe,0xdfdd,0xcffc,0xbf1b,0xaf3a,0x9f59,0x8f78,
    0x9188,0x81a9,0xb1ca,0xa1eb,0xd10c,0xc12d,0xf14e,0xe16f,
    0x1080,0x00a1,0x30c2,0x20e3,0x5004,0x4025,0x7046,0x6067,
    0x83b9,0x9398,0xa3fb,0xb3da,0xc33d,0xd31c,0xe37f,0xf35e,
    0x02b1,0x1290,0x22f3,0x32d2,0x4235,0x5214,0x6277,0x7256,
    0xb5ea,0xa5cb,0x95a8,0x8589,0xf56e,0xe54f,0xd52c,0xc50d,
    0x34e2,0x24c3,0x14a0,0x0481,0x7466,0x6447,0x5424,0x4405,
    0xa7db,0xb7fa,0x8799,0x97b8,0xe75f,0xf77e,0xc71d,0xd73c,
    0x26d3,0x36f2,0x0691,0x16b0,0x6657,0x7676,0x4615,0x5634,
    0xd94c,0xc96d,0xf90e,0xe92f,0x99c8,0x89e9,0xb98a,0xa9ab,
    0x5844,0x4865,0x7806,0x6827,0x18c0,0x08e1,0x3882,0x28a3,
    0xcb7d,0xdb5c,0xeb3f,0xfb1e,0x8bf9,0x9bd8,0xabbb,0xbb9a,
    0x4a75,0x5a54,0x6a37,0x7a16,0x0af1,0x1ad0,0x2ab3,0x3a92,
    0xfd2e,0xed0f,0xdd6c,0xcd4d,0xbdaa,0xad8b,0x9de8,0x8dc9,
    0x7c26,0x6c07,0x5c64,0x4c45,0x3ca2,0x2c83,0x1ce0,0x0cc1,
    0xef1f,0xff3e,0xcf5d,0xdf7c,0xaf9b,0xbfba,0x8fd9,0x9ff8,
    0x6e17,0x7e36,0x4e55,0x5e74,0x2e93,0x3eb2,0x0ed1,0x1ef0
};

uint16_t CRC_16_table(uint8_t* aData, unsigned int aSize)
{
    unsigned int i;
    uint16_t nAccum = 0;

    for (i = 0; i < aSize; i++)
        nAccum =(uint16_t) ((nAccum << 8) ^ (unsigned short)CRC16_TABLE[((nAccum >> 8) ^ *aData++) & 0x00FF]);
    return nAccum;
}
# 263 "Uds_server/crcLib.c"
uint8_t crc8(uint8_t *data, uint16_t length)
{
    uint8_t i;
    uint8_t crc = 0;
    while(length--)
    {
        crc ^= *data++;
        for ( i = 0; i < 8; i++ )
        {
            if ( crc & 0x80 )
                crc =(uint8_t) ((crc << 1) ^ 0x07);
            else
                crc <<= 1;
        }
    }
    return crc;
}
# 290 "Uds_server/crcLib.c"
uint8_t crc8_itu(uint8_t *data, uint16_t length)
{
    uint8_t i;
    uint8_t crc = 0;
    while(length--)
    {
        crc ^= *data++;
        for ( i = 0; i < 8; i++ )
        {
            if ( crc & 0x80 )
                crc =(uint8_t) ((crc << 1) ^ 0x07);
            else
                crc <<= 1;
        }
    }
    return crc ^ 0x55;
}
# 317 "Uds_server/crcLib.c"
uint8_t crc8_rohc(uint8_t *data, uint16_t length)
{
    uint8_t i;
    uint8_t crc = 0xFF;
    while(length--)
    {
        crc ^= *data++;
        for (i = 0; i < 8; ++i)
        {
            if (crc & 1)
                crc = (crc >> 1) ^ 0xE0;
            else
                crc = (crc >> 1);
        }
    }
    return crc;
}
# 345 "Uds_server/crcLib.c"
uint8_t crc8_maxim(uint8_t *data, uint16_t length)
{
    uint8_t i;
    uint8_t crc = 0;
    while(length--)
    {
        crc ^= *data++;
        for (i = 0; i < 8; i++)
        {
            if (crc & 1)
                crc = (crc >> 1) ^ 0x8C;
            else
                crc >>= 1;
        }
    }
    return crc;
}
# 372 "Uds_server/crcLib.c"
uint16_t crc16_ibm(uint8_t *data, uint16_t length)
{
    uint8_t i;
    uint16_t crc = 0;
    while(length--)
    {
        crc ^= *data++;
        for (i = 0; i < 8; ++i)
        {
            if (crc & 1)
                crc = (crc >> 1) ^ 0xA001;
            else
                crc = (crc >> 1);
        }
    }
    return crc;
}
# 399 "Uds_server/crcLib.c"
uint16_t crc16_maxim(uint8_t *data, uint16_t length)
{
    uint8_t i;
    uint16_t crc = 0;
    while(length--)
    {
        crc ^= *data++;
        for (i = 0; i < 8; ++i)
        {
            if (crc & 1)
                crc = (crc >> 1) ^ 0xA001;
            else
                crc = (crc >> 1);
        }
    }
    return ~crc;
}
# 426 "Uds_server/crcLib.c"
uint16_t crc16_usb(uint8_t *data, uint16_t length)
{
    uint8_t i;
    uint16_t crc = 0xffff;
    while(length--)
    {
        crc ^= *data++;
        for (i = 0; i < 8; ++i)
        {
            if (crc & 1)
                crc = (crc >> 1) ^ 0xA001;
            else
                crc = (crc >> 1);
        }
    }
    return ~crc;
}
# 453 "Uds_server/crcLib.c"
uint16_t crc16_modbus(uint8_t *data, uint16_t length)
{
    uint8_t i;
    uint16_t crc = 0xffff;
    while(length--)
    {
        crc ^= *data++;
        for (i = 0; i < 8; ++i)
        {
            if (crc & 1)
                crc = (crc >> 1) ^ 0xA001;
            else
                crc = (crc >> 1);
        }
    }
    return crc;
}
# 480 "Uds_server/crcLib.c"
uint16_t crc16_ccitt(uint8_t *data, uint16_t length)
{
    uint8_t i;
    uint16_t crc = 0;
    while(length--)
    {
        crc ^= *data++;
        for (i = 0; i < 8; ++i)
        {
            if (crc & 1)
                crc = (crc >> 1) ^ 0x8408;
            else
                crc = (crc >> 1);
        }
    }
    return crc;
}
# 507 "Uds_server/crcLib.c"
uint16_t crc16_ccitt_false(uint8_t *data, uint16_t length)
{
    uint8_t i;
    uint16_t crc = 0xffff;
    while(length--)
    {
        crc ^= (uint16_t)(*data++) << 8;
        for (i = 0; i < 8; ++i)
        {
            if ( crc & 0x8000 )
                crc =(uint16_t)((crc << 1) ^ 0x1021);
            else
                crc <<= 1;
        }
    }
    return crc;
}
# 534 "Uds_server/crcLib.c"
uint16_t crc16_x25(uint8_t *data, uint16_t length)
{
    uint8_t i;
    uint16_t crc = 0xffff;
    while(length--)
    {
        crc ^= *data++;
        for (i = 0; i < 8; ++i)
        {
            if (crc & 1)
                crc = (crc >> 1) ^ 0x8408;
            else
                crc = (crc >> 1);
        }
    }
    return ~crc;
}
# 561 "Uds_server/crcLib.c"
uint16_t crc16_xmodem(uint8_t *data, uint16_t length)
{
    uint8_t i;
    uint16_t crc = 0;
    while(length--)
    {
        crc ^= (uint16_t)(*data++) << 8;
        for (i = 0; i < 8; ++i)
        {
            if ( crc & 0x8000 )
                crc =(uint16_t)((crc << 1) ^ 0x1021);
            else
                crc <<= 1;
        }
    }
    return crc;
}
# 588 "Uds_server/crcLib.c"
uint16_t crc16_dnp(uint8_t *data, uint16_t length)
{
    uint8_t i;
    uint16_t crc = 0;
    while(length--)
    {
        crc ^= *data++;
        for (i = 0; i < 8; ++i)
        {
            if (crc & 1)
                crc = (crc >> 1) ^ 0xA6BC;
            else
                crc = (crc >> 1);
        }
    }
    return ~crc;
}
# 616 "Uds_server/crcLib.c"
uint32_t crc32(uint8_t *data, uint32_t length)
{
    uint8_t i;
    uint32_t crc = 0xffffffff;
    while(length--)
    {
        crc ^= *data++;
        for (i = 0; i < 8; ++i)
        {
            if (crc & 1)
                crc = (crc >> 1) ^ 0xEDB88320;
            else
                crc = (crc >> 1);
        }
    }
    return ~crc;
}
# 643 "Uds_server/crcLib.c"
uint32_t crc32_mpeg_2(uint8_t *data, uint16_t length)
{
    uint8_t i;
    uint32_t crc = 0xffffffff;
    while(length--)
    {
        crc ^= (uint32_t)(*data++) << 24;
        for (i = 0; i < 8; ++i)
        {
            if ( crc & 0x80000000 )
                crc = (crc << 1) ^ 0x04C11DB7;
            else
                crc <<= 1;
        }
    }
    return crc;
}
