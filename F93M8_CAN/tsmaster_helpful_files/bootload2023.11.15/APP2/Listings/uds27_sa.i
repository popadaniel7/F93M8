# 1 "Uds_server/UDS27_SA.c"
# 1 "<built-in>" 1
# 1 "<built-in>" 3
# 379 "<built-in>" 3
# 1 "<command line>" 1
# 1 "<built-in>" 2
# 1 "Uds_server/UDS27_SA.c" 2
# 35 "Uds_server/UDS27_SA.c"
# 1 "./Uds_server/UDS27_SA.h" 1
# 30 "./Uds_server/UDS27_SA.h"
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
# 1 "./RTE/_APP2\\RTE_Components.h" 1
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
# 31 "./Uds_server/UDS27_SA.h" 2

extern uint8_t UDS_SericeAccess_Seed[4];
extern uint8_t UDS_SericeAccess_Key[4];
extern uint32_t UDS27_RN;

void Creating_Seed(uint8_t UDS_SericeAccess_Seed[],uint8_t keynum);
void PasswordGenerator(const uint8_t UDS_SericeAccess_Seednum[],uint8_t UDS_SericeAccess_keynum[],uint8_t keynum);
uint8_t SecurityAccess_unlock(uint8_t UDS_SericeAccess_TX[],uint8_t UDS_SericeAccess_Keynum[],uint8_t keynum);
# 36 "Uds_server/UDS27_SA.c" 2

uint32_t UDS27_RN=0;


uint8_t UDS_SericeAccess_Seed[4]={0};
uint8_t UDS_SericeAccess_Key[4]={0};
# 50 "Uds_server/UDS27_SA.c"
void Creating_Seed(uint8_t UDS_SericeAccess_Seednum[],uint8_t keynum)
{

 if(keynum==4)
 {
 UDS_SericeAccess_Seednum[0]=(uint8_t)(UDS27_RN%256);
 UDS_SericeAccess_Seednum[1]=(uint8_t)(UDS27_RN%100);
 UDS_SericeAccess_Seednum[2]=(uint8_t)(UDS27_RN%55);
 UDS_SericeAccess_Seednum[3]=(uint8_t)(UDS27_RN%8);
 }
}







 void PasswordGenerator(const uint8_t UDS_SericeAccess_Seednum[],uint8_t UDS_SericeAccess_keynum[],uint8_t keynum)
{

 for(int i=0;i<keynum;i++)
 {
 UDS_SericeAccess_keynum[i]=UDS_SericeAccess_Seednum[i];
 }
}
# 84 "Uds_server/UDS27_SA.c"
uint8_t SecurityAccess_unlock(uint8_t UDS_SericeAccess_TX[],uint8_t UDS_SericeAccess_Keynum[],uint8_t keynum)
{

 for(int i=0;i<keynum;i++)
 {
  if (UDS_SericeAccess_TX[i]==UDS_SericeAccess_Keynum[i])
  {

 }
  else
  {
   return 1;
  }
 }

 return 0;

}
