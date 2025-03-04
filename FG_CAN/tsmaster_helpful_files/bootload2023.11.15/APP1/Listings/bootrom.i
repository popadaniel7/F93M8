# 1 "RTE/Device/TLE9893_2QKW62S/bootrom.c"
# 1 "<built-in>" 1
# 1 "<built-in>" 3
# 379 "<built-in>" 3
# 1 "<command line>" 1
# 1 "<built-in>" 2
# 1 "RTE/Device/TLE9893_2QKW62S/bootrom.c" 2
# 33 "RTE/Device/TLE9893_2QKW62S/bootrom.c"
# 1 "./RTE/Device/TLE9893_2QKW62S/bootrom.h" 1
# 78 "./RTE/Device/TLE9893_2QKW62S/bootrom.h"
# 1 "./RTE/Device/TLE9893_2QKW62S/types.h" 1
# 98 "./RTE/Device/TLE9893_2QKW62S/types.h"
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
# 99 "./RTE/Device/TLE9893_2QKW62S/types.h" 2
# 1 "./RTE/Device/TLE9893_2QKW62S/error_codes.h" 1
# 61 "./RTE/Device/TLE9893_2QKW62S/error_codes.h"
# 1 "./RTE/_APP1\\RTE_Components.h" 1
# 62 "./RTE/Device/TLE9893_2QKW62S/error_codes.h" 2
# 100 "./RTE/Device/TLE9893_2QKW62S/types.h" 2
# 122 "./RTE/Device/TLE9893_2QKW62S/types.h"
# 1 "C:\\Keil_v5\\ARM\\ARMCLANG\\Bin\\..\\include\\stdbool.h" 1 3
# 123 "./RTE/Device/TLE9893_2QKW62S/types.h" 2
# 220 "./RTE/Device/TLE9893_2QKW62S/types.h"
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
# 253 "./RTE/Device/TLE9893_2QKW62S/types.h"
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
# 79 "./RTE/Device/TLE9893_2QKW62S/bootrom.h" 2
# 164 "./RTE/Device/TLE9893_2QKW62S/bootrom.h"
typedef struct user_100tp_read_t
{
  uint32_t offset;
  uint8_t *data;
  uint16_t nbyte;
} user_100tp_read_t;

typedef struct user_100tp_write_t
{
  uint32_t offset;
  uint8_t *data;
  uint8_t nbyte;
  uint8_t counter;
} user_100tp_write_t;


typedef struct user_key_t
{
  uint8_t key[((0x20u))];
  uint16_t version;
  uint8_t length;
  uint8_t protection;
} user_key_t;

typedef enum user_crypto_fid_t
{
  CRYPTO_ECB_ENCRYPT = 0,
  CRYPTO_ECB_DECRYPT = 1,
  CRYPTO_CBC_ENCRYPT = 2,
  CRYPTO_CBC_DECRYPT = 3
} user_crypto_fid_t;

typedef struct user_crypto_inp_buf_t
{
  uint8_t *buffer;
  uint32_t length;
} user_crypto_inp_buf_t;

typedef struct user_crypto_out_buf_t
{
  uint8_t *buffer;
  uint32_t *length;
} user_crypto_out_buf_t;

typedef struct user_crypto_io_buf_t
{
  user_crypto_inp_buf_t inp;
  user_crypto_out_buf_t out;
} user_crypto_io_buf_t;

typedef struct user_crypto_cmac_t
{
  user_crypto_inp_buf_t inp;
  user_crypto_inp_buf_t mac;
} user_crypto_cmac_t;

typedef struct user_crypto_cbc_t
{
  void *iv;
  uint32_t iv_length;
} user_crypto_cbc_t;


typedef struct user_key_write_params_t
{
  uint8_t encrypted_key_buf[(0x40u)];
  uint16_t target_key_id;
  uint16_t encrypt_key_id;
} user_key_write_params_t;


typedef struct user_key_write_t
{
  user_key_write_params_t params;
  uint8_t signature[(0x10u)];
} user_key_write_t;

typedef struct user_key_erase_params_t
{
  uint16_t target_key_id;
  uint16_t version;
} user_key_erase_params_t;


typedef struct user_key_erase_t
{
  user_key_erase_params_t params;
  uint8_t signature[(0x10u)];
} user_key_erase_t;

typedef struct user_nvm_page_write_t
{
  uint8_t *data;
  uint32_t nbyte;
  uint32_t options;
} user_nvm_page_write_t;

typedef enum user_cache_op_t
{
  CACHE_OP_AC = 0,
  CACHE_OP_SC = 1,
  CACHE_OP_BC = 2,
  CACHE_OP_BT = 3,
  CACHE_OP_BL = 4,
  CACHE_OP_BU = 5,
  CACHE_OP_EN = 6,
  CACHE_OP_DIS = 7
} user_cache_op_t;


typedef enum user_nvm_segment_t
{
  NVM_PASSWORD_SEGMENT_BOOT = 0,
  NVM_PASSWORD_SEGMENT_CODE = 1,
  NVM_PASSWORD_SEGMENT_DATA = 2,
  NVM_PASSWORD_SEGMENT_TOTAL = 3
} user_nvm_segment_t;
# 34 "RTE/Device/TLE9893_2QKW62S/bootrom.c" 2

