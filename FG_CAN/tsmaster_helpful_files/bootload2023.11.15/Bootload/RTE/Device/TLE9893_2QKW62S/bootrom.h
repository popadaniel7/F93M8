/*
 ***********************************************************************************************************************
 *
 * Copyright (c) Infineon Technologies AG
 * All rights reserved.
 *
 * Redistribution and use in source and binary forms, with or without modification,are permitted provided that the
 * following conditions are met:
 *
 *   Redistributions of source code must retain the above copyright notice, this list of conditions and the  following
 *   disclaimer.
 *
 *   Redistributions in binary form must reproduce the above copyright notice, this list of conditions and the
 *   following disclaimer in the documentation and/or other materials provided with the distribution.
 *
 *   Neither the name of the copyright holders nor the names of its contributors may be used to endorse or promote
 *   products derived from this software without specific prior written permission.
 *
 * THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS "AS IS" AND ANY EXPRESS OR IMPLIED WARRANTIES,
 * INCLUDING, BUT NOT LIMITED TO, THE IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE ARE
 * DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT HOLDER OR CONTRIBUTORS BE LIABLE  FOR ANY DIRECT, INDIRECT, INCIDENTAL,
 * SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR
 * SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY,
 * WHETHER IN CONTRACT, STRICT LIABILITY,OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT  OF THE
 * USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.
 *
 **********************************************************************************************************************/
/**
 * \file     bootrom.h
 *
 * \brief    BootROM low level access library
 *
 * \version  V0.3.1
 * \date     23. Jun 2022
 *
 * \note
 */

/** \addtogroup BOOTROM_api
 *  @{
 */

/*******************************************************************************
**                             Author(s) Identity                             **
********************************************************************************
** Initials     Name                                                          **
** ---------------------------------------------------------------------------**
** DM           Daniel Mysliwitz                                              **
** BG           Blandine Guillot                                              **
** JO           Julia Ott                                                     **
*******************************************************************************/

/*******************************************************************************
**                          Revision Control History                          **
********************************************************************************
** V0.1.0: 2020-08-14, JO:   Initial version                                  **
** V0.1.1: 2020-11-12, JO:   EP-590: Added end of group for doxygen           **
** V0.1.2: 2020-11-27, BG:   EP-610: Corrected MISRA 2012 errors              **
** V0.1.3: 2020-11-27, JO:   EP-624: Removed internal APIs                    **
** V0.1.4: 2021-02-10, JO:   EP-696: Changed from anonymous to named typedefs **
**                           to prevent MISRA warning                         **
** V0.2.0: 2021-04-23, JO:   EP-696: Added artifacts for AB design step       **
** V0.2.1: 2021-07-12, BG:   EP-829: Added API documentation                  **
** V0.2.2: 2021-07-30, BG:   EP-877: Corrected MISRA 2012 errors              **
** V0.2.3: 2021-11-12, JO:   EP-937: Updated copyright and branding           **
** V0.3.0: 2021-11-30, BG:   EP-875: Added artifacts for AK design step       **
**                           Removed error codes for AA and AB design steps   **
** V0.3.1: 2022-06-23, JO:   EP-1150: Removed ARMCC V6.18 warnings            **
*******************************************************************************/

#ifndef _BOOTROM_H
#define _BOOTROM_H

/*******************************************************************************
**                                  Includes                                  **
*******************************************************************************/

#include "types.h"
#include "RTE_Components.h"

/*******************************************************************************
**                       Entry points into the BootROM                        **
*******************************************************************************/

#define addr_user_nvm_isr_handler                 (0xc1u)
#define addr_user_cid_get                         (0xc5u)
#define addr_user_ram_mbist                       (0xc9u)
#define addr_user_nvm_udata_temp_protect_clear    (0xd1u)
#define addr_user_nvm_ucode_temp_protect_clear    (0xd5u)
#define addr_user_nvm_udata_temp_protect_set      (0xd9u)
#define addr_user_nvm_ucode_temp_protect_set      (0xddu)
#define addr_user_nvm_temp_protect_get            (0xe1u)
#define addr_user_nvm_ecc_addr_get                (0xe5u)
#define addr_user_nvm_ecc_check                   (0xe9u)
#define addr_user_nvm_100tp_read                  (0xedu)
#define addr_user_nvm_100tp_write                 (0xf1u)
#define addr_user_nvm_100tp_erase                 (0xf5u)
#define addr_user_nvm_config_get                  (0xf9u)
#define addr_user_nvm_page_erase                  (0xfdu)
#define addr_user_nvm_sector_erase                (0x101u)
#define addr_user_nvm_page_write                  (0x105u)
#define addr_user_nvm_mapram_init                 (0x109u)
#define addr_user_nvm_mapram_recover              (0x10du)
#define addr_user_nvm_service_algorithm           (0x111u)
#define addr_user_crypto_aes_cmac_generate_start  (0x115u)
#define addr_user_crypto_aes_cmac_generate_update (0x119u)
#define addr_user_crypto_aes_cmac_generate_finish (0x11du)
#define addr_user_crypto_aes_cmac_verify_start    (0x121u)
#define addr_user_crypto_aes_cmac_verify_update   (0x125u)
#define addr_user_crypto_aes_cmac_verify_finish   (0x129u)
#define addr_user_crypto_aes_start                (0x12du)
#define addr_user_crypto_aes_update               (0x131u)
#define addr_user_crypto_aes_finish               (0x135u)
#define addr_user_crypto_key_write                (0x139u)
#define addr_user_crypto_key_erase                (0x13du)
#define addr_user_crypto_key_verify               (0x141u)
#define addr_user_nvm_reg_write                   (0x145u)
#define addr_user_nvm_reg_read                    (0x149u)
#define addr_user_secure_download_start           (0x14du)
#define addr_user_secure_download_update          (0x151u)
#define addr_user_secure_download_finish          (0x155u)
#define addr_user_cache_operation                 (0x159u)
#define addr_user_ubsl_size_restore               (0x15du)
#define addr_user_nvm_perm_protect_set            (0x161u)
#define addr_user_nvm_ubsl_temp_protect_clear     (0x201u)
#define addr_user_nvm_ubsl_temp_protect_set       (0x205u)
#define addr_user_secure_dualboot                 (0x209u)

/*******************************************************************************
**                        Global Constant Declarations                        **
*******************************************************************************/

/** @brief 128 bits key length */
#define USER_KEY_SIZE_128          (0x10u)

/** @brief 256 bits key length */
#define USER_KEY_SIZE_256          (0x20u)

/** @brief Maximum length for a key value to read/store */
#define USER_KEY_SIZE_MAX          (USER_KEY_SIZE_256)

/** @brief encrypted key parameter size 64 bytes */
#define USER_KEY_PARAM_SIZE        (0x40u)

/** @brief cmac signature size 16 bytes */
#define USER_CMAC_SIGNATURE_SIZE   (0x10u)

/** @brief Size of key_write decryption buffer */
#define USER_KEY_WRITE_BUFFER_SIZE (0x30u)

/** @brief Maximum User key slot ID */
#define USER_KEY_MAX_ID            (12u)

/** @brief Minimum User key slot ID */
#define USER_KEY_MIN_ID            (1u)

/** @brief IFX key ID */
#define IFX_KEY_ID                 (0u)

/*******************************************************************************
**                          Global Type Declarations                          **
*******************************************************************************/

typedef struct user_100tp_read_t
{
  uint32_t   offset;                                           /** @brief Byte offset inside the selected page address, where to start reading. Maximum is 127 bytes. */
  uint8_t    *data;                                            /** @brief Data pointer where to write data into. Pointer plus valid count must be within valid RAM range or an error code is returned */
  uint16_t   nbyte;                                            /** @brief Amount of data bytes to read. If nbyte is zero, there is no read operation done and an error code is returned. Maximum is 128 bytes. */
} user_100tp_read_t;

typedef struct user_100tp_write_t
{
  uint32_t   offset;                                           /** @brief Byte offset inside the selected page address, where to start writing. Maximum is 123 bytes. */
  uint8_t    *data;                                            /** @brief Data pointer where to read the data to write. Pointer plus valid count must be within valid RAM range or an error code is returned */
  uint8_t    nbyte;                                            /** @brief Amount of data bytes to write. If nbyte is zero, there is no write operation done and an error code is returned. Maximum is 124 bytes. */
  uint8_t    counter;                                          /** @brief Counter value to update internal 100TP counter (only updates if value is greater than current, otherwise is ignored) */
} user_100tp_write_t;

/** @brief Key data structure aligned with CFS page (ignored reserved bytes) */
typedef struct user_key_t
{
  uint8_t    key[USER_KEY_SIZE_MAX];                         /** @brief key value                 */
  uint16_t   version;                                        /** @brief new key version number    */
  uint8_t    length;                                         /** @brief key size in bytes [16|32] */
  uint8_t    protection;                                     /** @brief key protection            */
} user_key_t;

typedef enum user_crypto_fid_t
{
  CRYPTO_ECB_ENCRYPT    = 0,
  CRYPTO_ECB_DECRYPT    = 1,
  CRYPTO_CBC_ENCRYPT    = 2,
  CRYPTO_CBC_DECRYPT    = 3
} user_crypto_fid_t;

typedef struct user_crypto_inp_buf_t
{
  uint8_t   *buffer;                                           /** @brief Crypto algorithm input buffer address  */
  uint32_t   length;                                           /** @brief Crypto algorithm input buffer length   */
} user_crypto_inp_buf_t;

typedef struct user_crypto_out_buf_t
{
  uint8_t   *buffer;                                           /** @brief Crypto algorithm output buffer address */
  uint32_t *length;                                            /** @brief Crypto algorithm output buffer length  */
} user_crypto_out_buf_t;

typedef struct user_crypto_io_buf_t
{
  user_crypto_inp_buf_t inp;                                   /** @brief Crypto algorithm input buffer          */
  user_crypto_out_buf_t out;                                   /** @brief Crypto algorithm output buffer         */
} user_crypto_io_buf_t;

typedef struct user_crypto_cmac_t
{
  user_crypto_inp_buf_t inp;                                   /** @brief CMAC generate input buffer             */
  user_crypto_inp_buf_t mac;                                   /** @brief CMAC generate output buffer            */
} user_crypto_cmac_t;

typedef struct user_crypto_cbc_t
{
  void      *iv;
  uint32_t   iv_length;
} user_crypto_cbc_t;


typedef struct user_key_write_params_t
{
  uint8_t    encrypted_key_buf[USER_KEY_PARAM_SIZE];           /** @brief Encrypted buffer with new key parameters    */
  uint16_t   target_key_id;                                    /** @brief Key slot ID for parameter decryption        */
  uint16_t   encrypt_key_id;                                   /** @brief Key slot ID used for the new key parameters */
} user_key_write_params_t;


typedef struct user_key_write_t
{
  user_key_write_params_t params;                              /** @brief Input parameters (signature checked) */
  uint8_t                 signature[USER_CMAC_SIGNATURE_SIZE]; /** @brief New key CMAC signature               */
} user_key_write_t;

typedef struct user_key_erase_params_t
{
  uint16_t   target_key_id;                                    /** @brief Key slot ID for parameter decryption */
  uint16_t   version;                                          /** @brief new key version number               */
} user_key_erase_params_t;


typedef struct user_key_erase_t
{
  user_key_erase_params_t params;                              /** @brief Input parameters (signature checked) */
  uint8_t                 signature[USER_CMAC_SIGNATURE_SIZE]; /** @brief CMAC signature                       */
} user_key_erase_t;

typedef struct user_nvm_page_write_t
{
  uint8_t    *data;                                            /** @brief Pointer to the data where to read the programming data. Pointer must be within valid RAM range or an error code is returned. */
  uint32_t   nbyte;                                            /** @brief Amount of bytes to program. Range from 1-128 bytes. */
  uint32_t   options;                                          /** @brief NVM programming options (e.g. @ref NVM_OPTIONS_CORR_ACT or @ref NVM_OPTIONS_NO_FAILPAGE_ERASE) */
} user_nvm_page_write_t;

typedef enum user_cache_op_t
{
  CACHE_OP_AC  = 0,                                          /** @brief Cache all clean operation      */
  CACHE_OP_SC  = 1,                                          /** @brief Cache set clean operation      */
  CACHE_OP_BC  = 2,                                          /** @brief Cache block clean operation    */
  CACHE_OP_BT  = 3,                                          /** @brief Cache block touch operation    */
  CACHE_OP_BL  = 4,                                          /** @brief Cache block lock operation     */
  CACHE_OP_BU  = 5,                                          /** @brief Cache block unlock operation   */
  CACHE_OP_EN  = 6,                                          /** @brief Cache enable operation         */
  CACHE_OP_DIS = 7                                           /** @brief Cache disable operation        */
} user_cache_op_t;

/** NVM protection API password segment */
typedef enum user_nvm_segment_t
{
  NVM_PASSWORD_SEGMENT_BOOT = 0,                               /** @brief NVM password for customer segment, used for customer bootloader (NVM flash 0). */
  NVM_PASSWORD_SEGMENT_CODE = 1,                               /** @brief NVM password for customer code segment, which is not used by the customer bootloader (NVM flash 1). */
  NVM_PASSWORD_SEGMENT_DATA = 2,                               /** @brief NVM password for customer data mapped segment (NVM flash 0). */
  NVM_PASSWORD_SEGMENT_TOTAL = 3                               /** @brief Can be ignored and should not be used */
} user_nvm_segment_t;

/*******************************************************************************
**                          Global Macro Declarations                         **
*******************************************************************************/

/*******************************************************************************
**                        Global Function Declarations                        **
*******************************************************************************/

/**
 * @brief This user API function gets the customer identification number.
 *
 * @param customer_id Pointer where to store the customer identification number (CID) read from the device configuration sector.
 * The address indicated by the pointer must be located in RAM.
 *
 * @return Function execution status.
 * @retval #ERR_LOG_SUCCESS
 * @retval #ERR_LOG_CODE_USER_POINTER_RAM_RANGE_INVALID
 */
#define user_cid_get                         ( (int32_t(*)(uint32_t *))                                       addr_user_cid_get                        )

/**
 * @brief This user API function performs a MBIST on the specified SRAM range.
 * Start address shall be smaller than end address.
 *
 * @param start_address RAM memory address at which to start the MBIST test. Range is 0x18000000 + device RAM size.
 * @param end_address RAM memory address up to which to perform the MBIST test. Range is 0x18000000 + device RAM size.
 *
 * @remark The execution of MBIST changes the RAM content in the specified range. Make sure that the user stack does not get destroyed.
 * @remark This function is not interruptible. Interrupts must be disabled before the call and only re-enabled after it has finished.
 * 
 * @return Function execution status.
 * @retval #ERR_LOG_SUCCESS
 * @retval #ERR_LOG_CODE_MBIST_RAM_RANGE_INVALID
 * @retval #ERR_LOG_CODE_MBIST_FAILED
 */
#define user_ram_mbist                       ( (int32_t(*)(uint32_t, uint32_t))                               addr_user_ram_mbist                      )

/**
 * @brief This user API function temporarily clears the write protection of the UDATA segment.
 *
 * @param passphrase The passphrase must be #NVM_SEG_PROT_DATA_NO_ERASE.
 *
 * @remark In an interrupt or multithreaded environment, this function cannot be called in a re-entrant context.
 *
 * @return Function execution status.
 * @retval #ERR_LOG_SUCCESS
 * @retval #ERR_LOG_CODE_USER_PROTECT_WRONG_PASSWORD
 * @retval #ERR_LOG_CODE_SEMAPHORE_RESERVED
 */
#define user_nvm_udata_temp_protect_clear    ( (int32_t(*)(uint32_t))                                         addr_user_nvm_udata_temp_protect_clear   )

/**
 * @brief This user API function temporarily clears the write protection of the UCODE segment.
 *
 * @param passphrase The passphrase must be #NVM_SEG_PROT_CODE_NO_ERASE.
 *
 * @remark In an interrupt or multithreaded environment, this function cannot be called in a re-entrant context.
 *
 * @return Function execution status.
 * @retval #ERR_LOG_SUCCESS
 * @retval #ERR_LOG_CODE_USER_PROTECT_WRONG_PASSWORD
 * @retval #ERR_LOG_CODE_SEMAPHORE_RESERVED
 */
#define user_nvm_ucode_temp_protect_clear    ( (int32_t(*)(uint32_t))                                         addr_user_nvm_ucode_temp_protect_clear   )

/**
 * @brief This user API function temporarily sets the write protection of the UDATA segment.
 *
 * @param passphrase The passphrase must be #NVM_SEG_PROT_DATA_NO_ERASE.
 *
 * @remark In an interrupt or multithreaded environment, this function cannot be called in a re-entrant context.
 *
 * @return Function execution status.
 * @retval #ERR_LOG_SUCCESS
 * @retval #ERR_LOG_CODE_USER_PROTECT_WRONG_PASSWORD
 * @retval #ERR_LOG_CODE_SEMAPHORE_RESERVED
 */
#define user_nvm_udata_temp_protect_set      ( (int32_t(*)(uint32_t))                                         addr_user_nvm_udata_temp_protect_set     )

/**
 * @brief This user API function temporarily sets the write protection of the UCODE segment.
 *
 * @param passphrase The passphrase must be #NVM_SEG_PROT_CODE_NO_ERASE.
 *
 * @remark In an interrupt or multithreaded environment, this function cannot be called in a re-entrant context.
 *
 * @return Function execution status.
 * @retval #ERR_LOG_SUCCESS
 * @retval #ERR_LOG_CODE_USER_PROTECT_WRONG_PASSWORD
 * @retval #ERR_LOG_CODE_SEMAPHORE_RESERVED
 */
#define user_nvm_ucode_temp_protect_set      ( (int32_t(*)(uint32_t))                                         addr_user_nvm_ucode_temp_protect_set     )

/**
 * @brief This user API function gets the current protection status of a specified NVM segment.
 *
 * @param segment The NVM segment for which to report the current protection status. For more information, refer to @ref user_nvm_segment_t.
 *
 * @return The current protection status of the specified NVM segment.
 * @retval #NVM_RET_NOT_PROTECTED Target segment is not protected.
 * @retval #NVM_RET_PROTECTED Target segment is protected.
 */
#define user_nvm_temp_protect_get            ( (uint32_t(*)(user_nvm_segment_t))                              addr_user_nvm_temp_protect_get           )

/**
 * @brief This user API function sets permanent protection on NVM segments.
 *
 * @param passphrase An encoding of the target segment and the erase flag. Refer to the supported passphrase.
 *
 * @remark In an interrupt or multithreaded environment, this function cannot be called in a re-entrant context.
 * @remark It is recommended to disable the interrupt before calling the function.
 *
 * @return Function execution status.
 * @retval #ERR_LOG_SUCCESS
 * @retval #ERR_LOG_CODE_SEMAPHORE_RESERVED
 * @retval #ERR_LOG_CODE_USER_PROTECT_WRONG_PASSWORD
 * @retval #ERR_LOG_CODE_SEGMENT_PROTECTED
 * @retval #ERR_LOG_CODE_NVM_APPLY_PROTECTION_FAIL
 * @retval #ERR_LOG_CODE_ACCESS_AB_MODE_ERROR
 * @retval #ERR_LOG_CODE_NVM_VER_ERROR
 * @retval #ERR_LOG_CODE_ECC2READ_ERROR
 */
#define user_nvm_perm_protect_set            ( (int32_t(*)(uint32_t))                                         addr_user_nvm_perm_protect_set           )

/**
 * @brief This user API function returns the address of a double ECC event that has occurred in the target flash.
 *
 * @param[in] flash Target flash @ref NVM_FLASH_GROUP.
 * @param[out] pNVM_Addr Pointing to ECC2 failure address.
 *
 * The value of pNVM_Addr can be one of below patterns:
 * - 0x11XXXXXX ECC2 failure in FLASH0 area, it indicates the absolute memory address.
 * - 0x12XXXXXX ECC2 failure in FLASH1 area, it indicates the absolute memory address.
 * - 0x100000XY ECC2 in 100TP pages, where X = 100TP page number, Y = block offset inside the page (block granularity: 8 bytes).
 * - 0x01000000 ECC2 in internal NVM CS area, not recoverable.
 *
 * @remark When the function exits, it clears the current ECC2 flag.
 * @remark Any other NVM operations also clear the ECC2 flag.
 * @remark In an interrupt or multithreaded environment, this function cannot be called in a re-entrant context.
 *
 * @return Function execution status.
 * @retval #ERR_LOG_SUCCESS No ECC2 event or event address has been obtained successfully.
 * @retval #ERR_LOG_CODE_SEMAPHORE_RESERVED
 * @retval #ERR_LOG_CODE_USER_POINTER_RAM_RANGE_INVALID
 * @retval #ERR_LOG_CODE_PARAM_INVALID
 */
#define user_nvm_ecc_addr_get                ( (int32_t(*)(uint32_t, uint32_t *))                             addr_user_nvm_ecc_addr_get               )

/**
 * @brief This user API function checks for single and double ECC errors on the target flash.
 *
 * Any existing ECC errors are cleared before the check starts.
 * Upon exit, the function clears the current ECC status.
 *
 * @param flash Target flash @ref NVM_FLASH_GROUP.
 *
 * @remark This routine does not provide the addresses of the ECC errors. In case an ECC error is detected, call @ref user_nvm_ecc_addr_get routine to retrieve the failure address.
 * @remark In an interrupt or multithreaded environment, this function cannot be called in a re-entrant context.
 *
 * @return Function execution status.
 * @retval #ERR_LOG_SUCCESS no single or double ECC events have occurred.
 * @retval #ERR_LOG_CODE_SEMAPHORE_RESERVED
 * @retval #ERR_LOG_CODE_ECC1READ_ERROR
 * @retval #ERR_LOG_CODE_ECC2READ_ERROR
 * @retval #ERR_LOG_CODE_PARAM_INVALID
 */
#define user_nvm_ecc_check                   ( (int32_t(*)(uint32_t))                                         addr_user_nvm_ecc_check                  )

/**
 * @brief This user API function reads data from specified 100TP page.
 *  
 * This function can read a maximum of 128 bytes (including the counter field and checksum field).
 *
 * @param npage The index of the page from which to read. Valid range: 0 to 7.
 * @param params 100tp read parameters. For further information, refer to @ref user_100tp_read_t.
 *
 * @remark In an interrupt or multithreaded environment, this function cannot be called in a re-entrant context.
 *
 * @return Function execution status.
 * @retval #ERR_LOG_SUCCESS
 * @retval #ERR_LOG_CODE_USER_POINTER_RAM_RANGE_INVALID
 * @retval #ERR_LOG_CODE_SEMAPHORE_RESERVED
 * @retval #ERR_LOG_CODE_PARAM_INVALID
 * @retval #ERR_LOG_CODE_100TP_PAGE_INVALID
 * @retval #ERR_LOG_CODE_ECC2READ_ERROR
 */
#define user_nvm_100tp_read                  ( (int32_t(*)(uint32_t, user_100tp_read_t *))                    addr_user_nvm_100tp_read                 )

/**
 * @brief This user API function writes data to a specified 100TP page.
 * 
 * The function can write up to 124 bytes in a data field each time.
 * The function supports maximum 100 times write operation.
 * The function performs an implicit update of the page checksum.
 *
 * @param npage The index of the page to which to write. Valid range: 0 to 7.
 * @param params 100tp write parameters. For further information, refer to @ref user_100tp_write_t.
 *
 * @remark In an interrupt or multithreaded environment, this function cannot be called in a re-entrant context.
 *
 * @return Function execution status.
 * @retval #ERR_LOG_SUCCESS
 * @retval #ERR_LOG_CODE_USER_POINTER_RAM_RANGE_INVALID
 * @retval #ERR_LOG_CODE_SEMAPHORE_RESERVED
 * @retval #ERR_LOG_CODE_PARAM_INVALID
 * @retval #ERR_LOG_CODE_100TP_PAGE_INVALID
 * @retval #ERR_LOG_CODE_SEGMENT_PROTECTED
 * @retval #ERR_LOG_CODE_ECC2READ_ERROR
 * @retval #ERR_LOG_CODE_100TP_WRITE_COUNT_EXCEEDED
 * @retval #ERR_LOG_CODE_ACCESS_AB_MODE_ERROR
 * @retval #ERR_LOG_CODE_NVM_ECC2_DATA_ERROR
 */
#define user_nvm_100tp_write                 ( (int32_t(*)(uint32_t, user_100tp_write_t *))                   addr_user_nvm_100tp_write                )

/**
 * @brief This user API function erases a data field of the specified 100TP page. The write counter field is preserved.
 *
 * The function should be called if the 100TP page is corrupted.
 * Upon successful execution, the page is initialized with an invalid checksum.
 *
 * @param npage The index of the 100TP page to erase. Valid range: 0 to 7.
 *
 * @remark In an interrupt or multithreaded environment, this function cannot be called in a re-entrant context.
 *
 * @return Function execution status.
 * @retval #ERR_LOG_SUCCESS
 * @retval #ERR_LOG_CODE_SEMAPHORE_RESERVED
 * @retval #ERR_LOG_CODE_100TP_PAGE_INVALID
 * @retval #ERR_LOG_CODE_SEGMENT_PROTECTED
 * @retval #ERR_LOG_CODE_ACCESS_AB_MODE_ERROR
 * @retval #ERR_LOG_CODE_NVM_VER_ERROR
 */
#define user_nvm_100tp_erase                 ( (int32_t(*)(uint32_t))                                         addr_user_nvm_100tp_erase                )

/**
 * @brief This user API function returns the size of each NVM segment.
 *
 * @param ubsl_nvm_size Pointer to where to store the retrieved NVM UBSL segment size.
 * @param code_nvm_size Pointer to where to store the retrieved NVM UCODE segment size.
 * @param data_nvm_size Pointer to where to store the retrieved NVM UDATA segment size.
 *
 * @return Function execution status.
 * @retval #ERR_LOG_SUCCESS
 * @retval #ERR_LOG_CODE_USER_POINTER_RAM_RANGE_INVALID
 *
 */
#define user_nvm_config_get                  ( (int32_t(*)(uint32_t *, uint32_t *, uint32_t *))               addr_user_nvm_config_get                 )

/**
 * @brief This user API function erases a specified flash page.
 *
 * When asked to erase an unused (new) page in a mapped sector, the function does nothing and returns success.
 * When asked to erase a page in a linear sector, the function always performs the erase.
 *
 * @param page_address Address of the NVM page to erase. Non-aligned addresses are accepted.
 * @param options Page erase options.
 * Supported \a options:
 * - #NVM_OPTIONS_NONE  The default setting: background read-while-write (RWW) enabled.
 * - #NVM_OPTIONS_RWW_DISABLE Disables background read-while-write.
 *
 * @remark The status of background read-while-write (RWW) is available in the register #MEMCTRL_NVM_OP_STS.
 * @remark The result of background read-while-write (RWW) is available in the register #MEMCTRL_NVM_OP_RESULT.
 * @remark In an interrupt or multithreaded environment, this function cannot be called in a re-entrant context.
 *
 * @return Function execution status.
 * @retval #ERR_LOG_SUCCESS
 * @retval #NVM_OP_STS_FLASH_0_BUSY RWW operation on FLASH0 is triggered successfully. FLASH0 will be busy until the background RWW operation is complete.
 * @retval #NVM_OP_STS_FLASH_1_BUSY RWW operation on FLASH1 is triggered successfully. FLASH1 will be busy until the background RWW operation is complete.
 * @retval #ERR_LOG_CODE_SEMAPHORE_RESERVED
 * @retval #ERR_LOG_CODE_SEGMENT_PROTECTED
 * @retval #ERR_LOG_CODE_MEM_ADDR_RANGE_INVALID
 * @retval #ERR_LOG_CODE_ACCESS_AB_MODE_ERROR
 * @retval #ERR_LOG_CODE_NVM_ECC2_MAPRAM_ERROR
 */
#define user_nvm_page_erase                  ( (int32_t(*)(uint32_t, uint32_t))                               addr_user_nvm_page_erase                 )

/**
 * @brief This user API function erases a specified flash sector.
 *
 * For a mapped sector, upon successful sector erase, the map RAM is initialized and a new spare page is selected.
 *
 * @param sector_address Address of the NVM sector to erase. Non-aligned addresses are accepted.
 * @param options Sector erase options.
 * Supported \a options:
 * - #NVM_OPTIONS_NONE  The default setting: RWW enabled.
 * - #NVM_OPTIONS_RWW_DISABLE Disables the read-while-write feature.
 *
 * @remark In an interrupt or multithreaded environment, this function cannot be called in a re-entrant context.
 * @remark The status of background read-while-write (RWW) is available in the register #MEMCTRL_NVM_OP_STS.
 * @remark The result of background read-while-write (RWW) is available in the register #MEMCTRL_NVM_OP_RESULT.
 *
 * @return Function execution status.
 * @retval #ERR_LOG_SUCCESS
 * @retval #NVM_OP_STS_FLASH_0_BUSY RWW operation on FLASH0 is triggered successfully. FLASH0 will be busy until the background RWW operation is complete.
 * @retval #NVM_OP_STS_FLASH_1_BUSY RWW operation on FLASH1 is triggered successfully. FLASH1 will be busy until the background RWW operation is complete.
 * @retval #ERR_LOG_CODE_MEM_ADDR_RANGE_INVALID
 * @retval #ERR_LOG_CODE_SEGMENT_PROTECTED
 * @retval #ERR_LOG_CODE_SEMAPHORE_RESERVED
 * @retval #ERR_LOG_CODE_MAPRAM_INIT_FAIL
 * @retval #ERR_LOG_CODE_ACCESS_AB_MODE_ERROR
 */
#define user_nvm_sector_erase                ( (int32_t(*)(uint32_t, uint32_t))                               addr_user_nvm_sector_erase               )

/**
 * @brief This user API function writes a number of bytes from the source to the specified flash address \a page_address.
 *
 * @param page_address The address of the NVM page to which to write the data.
 * @param params NVM write parameters. For further information, refer to @ref user_nvm_page_write_t.
 * Supported \a params->options:
 * - #NVM_OPTIONS_NONE  The default setting: corrective action disabled, RWW enabled, failpage erase enabled.
 * - #NVM_OPTIONS_CORR_ACT Enables retrying the write operation if the first write operation verification failed.
 * For EEPROM specific, it enables disturb handling, which refreshes other pages on the background for around every 1K write.
 * - #NVM_OPTIONS_NO_FAILPAGE_ERASE This option applies only to mapped sectors.
 * If it is specified, the failed written page remains.
 * If it is not specified, the failed written page gets erased.
 * - #NVM_OPTIONS_RWW_DISABLE Disables the read-while-write feature.
 *
 * @remark The status of background read-while-write (RWW) is available in the register #MEMCTRL_NVM_OP_STS.
 * @remark The result of background read-while-write (RWW) is available in the register #MEMCTRL_NVM_OP_RESULT.
 * @remark In an interrupt or multithreaded environment, this function cannot be called in a re-entrant context.
 *
 * @return Function execution status.
 * @retval #ERR_LOG_SUCCESS
 * @retval #NVM_OP_STS_FLASH_0_BUSY RWW operation on FLASH0 is triggered successfully. FLASH0 will be busy until the background RWW operation is complete.
 * @retval #NVM_OP_STS_FLASH_1_BUSY RWW operation on FLASH1 is triggered successfully. FLASH1 will be busy until the background RWW is operation complete.
 * @retval #ERR_LOG_CODE_PARAM_INVALID
 * @retval #ERR_LOG_CODE_USER_POINTER_RAM_RANGE_INVALID
 * @retval #ERR_LOG_CODE_ADDRESS_RANGE_CROSSING_PAGE_BOUNDARY
 * @retval #ERR_LOG_CODE_MEM_ADDR_RANGE_INVALID
 * @retval #ERR_LOG_CODE_SEMAPHORE_RESERVED
 * @retval #ERR_LOG_CODE_ACCESS_AB_MODE_ERROR
 * @retval #ERR_LOG_CODE_NVM_SPARE_PAGE_NOT_AVAILABLE
 * @retval #ERR_LOG_CODE_NVM_ECC2_MAPBLOCK_ERROR
 * @retval #ERR_LOG_CODE_NVM_ECC2_DATA_ERROR
 * @retval #ERR_LOG_CODE_NVM_ECC2_MAPRAM_ERROR
 * @retval #ERR_LOG_CODE_NVM_VER_ERROR
 * @retval #ERR_LOG_CODE_MAPRAM_INIT_FAIL
 * @retval #ERR_LOG_CODE_VERIFY_AND_MAPRAM_INIT_FAIL
 */
#define user_nvm_page_write                  ( (int32_t(*)(uint32_t, user_nvm_page_write_t *))                addr_user_nvm_page_write                 )
#define user_nvm_write user_nvm_page_write
                   
/**
 * @brief This user API function triggers the map RAM initialization on the target mapped sector.
 *
 * @param sector_address Sector address to perform operation.
 *
 * @remark In an interrupt or multithreaded environment, this function cannot be called in a re-entrant context.
 *
 * @return Function execution status.
 * @retval #ERR_LOG_SUCCESS
 * @retval #ERR_LOG_CODE_SEMAPHORE_RESERVED
 * @retval #ERR_LOG_CODE_MEM_ADDR_RANGE_INVALID
 * @retval #ERR_LOG_CODE_MAPRAM_INIT_PAGE_FAIL
 * @retval #ERR_LOG_CODE_MAPRAM_INIT_DM_PAGE_FAIL
 */
#define user_nvm_mapram_init                 ( (int32_t(*)(uint32_t))                                         addr_user_nvm_mapram_init                )

/**
 * @brief This user API function attempts to reconstruct map RAM by extracting mapping information from good pages.
 *
 * It can be called if the NVM Service Algorithm (SA) fails to repair a corrupted data map sector. Requests to initialize the
 * map RAM for an unavailable sector or for a linearly mapped sector are ignored.
 * Pages that are mapped two or more times are counted as faulty pages.
 *
 * @param sector_address Address of the sector from which to recover mapping information.
 *
 * @remark In an interrupt or multithreaded environment, this function cannot be called in a re-entrant context.
 *
 * @return Function execution status.
 * @retval Non-Negative successful execution, indicating the amount of good mapped pages that were found.
 * @retval #ERR_LOG_CODE_MEM_ADDR_RANGE_INVALID
 * @retval #ERR_LOG_CODE_NVM_ECC2_MAPRAM_ERROR
 * @retval #ERR_LOG_CODE_SEMAPHORE_RESERVED
 */
#define user_nvm_mapram_recover              ( (int32_t(*)(uint32_t))                                         addr_user_nvm_mapram_recover             )

/**
 * @brief This user API function runs the service algorithm on a mapped sector, attempting to repair faulty pages or double mappings.
 *
 * @param sector_address Address of the sector on which to run the service algorithm (SA).
 *
 * @remark In an interrupt or multithreaded environment, this function cannot be called in a re-entrant context.
 *
 * @return Function execution status.
 * @retval #ERR_LOG_SUCCESS
 * @retval #ERR_LOG_CODE_SEMAPHORE_RESERVED
 * @retval #ERR_LOG_CODE_SEGMENT_PROTECTED
 * @retval #ERR_LOG_CODE_MEM_ADDR_RANGE_INVALID
 * @retval #ERR_LOG_CODE_SA_UNRECOVERABLE
 */
#define user_nvm_service_algorithm           ( (int32_t(*)(uint32_t))                                         addr_user_nvm_service_algorithm          )

/**
 * @brief This user API function performs a write access to NVM SFRs.
 *
 * @param sfr_address NVM SFR address to which to write.
 * @param value Value to write into the specified SFR.
 *
 * @remark Register access is only allowed when the keylock passphrase is not installed.
 * @remark It is an internal API for test purpose, shall not disclose it to customer.
 *
 * @return Function execution status.
 * @retval #ERR_LOG_SUCCESS
 * @retval #ERR_LOG_CODE_PARAM_INVALID
 * @retval #ERR_LOG_CODE_SEGMENT_PROTECTED
 */
#define user_nvm_reg_write                   ( (int32_t(*)(uint32_t, uint32_t ))                              addr_user_nvm_reg_write                  )

/**
 * @brief This user API function performs a read access to NVM SFRs.
 *
 * @param sfr_address NVM SFR address to read from.
 * @param value Pointer to a word from which to read the SFR value.
 *
 * @remark Register access is only allowed when the keylock passphrase is not installed.
 * @remark It is an internal API for test purpose, shall not disclose it to customer.
 *
 * @return Function execution status.
 * @retval #ERR_LOG_SUCCESS
 * @retval #ERR_LOG_CODE_USER_POINTER_RAM_RANGE_INVALID
 * @retval #ERR_LOG_CODE_PARAM_INVALID
 * @retval #ERR_LOG_CODE_SEGMENT_PROTECTED
 */
#define user_nvm_reg_read                    ( (int32_t(*)(uint32_t, uint32_t *))                             addr_user_nvm_reg_read                   )

/**
 * @brief This user API function initiates the secure container and starts the secure download process.
 *
 * The function tries to decrypt the first [0th:31th] bytes of the input streaming data.
 * Upon successful start of secure download operation, the next call of @ref user_secure_download_update routine expects [32th:159th] byte of input streaming data.
 *
 * @param key_id The ID of the key for decryption, key ID range is 0 to 12.
 * @param n_sectors Size in sectors, of the new secure container.
 * @param data Address of the input buffer.
 *
 * @remark In an interrupt or multithreaded environment, this function cannot be called in a re-entrant context.
 *
 * @return Function execution status.
 * @retval #ERR_LOG_SUCCESS
 * @retval #ERR_LOG_CODE_SEMAPHORE_RESERVED
 * @retval #ERR_LOG_CODE_USER_POINTER_RAM_RANGE_INVALID
 * @retval #ERR_LOG_CODE_SIZE_INVALID
 * @retval #ERR_LOG_CODE_SEGMENT_PROTECTED
 * @retval #ERR_LOG_CODE_ACCESS_AB_MODE_ERROR
 * @retval #ERR_LOG_CODE_PARAM_INVALID
 * @retval #ERR_LOG_CODE_AES_UNSUPPORTED_ERROR
 * @retval #ERR_LOG_CODE_AES_BUFFER_SMALL_ERROR
 * @retval #ERR_LOG_CODE_AES_UNAVAILABLE_ERROR
 * @retval #ERR_LOG_CODE_AES_ERROR
 */
#define user_secure_download_start           ( (int32_t(*)(uint8_t, uint8_t, uint8_t *))                      addr_user_secure_download_start          )

/**
 * @brief This user API function continues the secure download process.
 *
 * Call the @ref user_secure_download_start routine before the first update operation.
 * The function can be called multiple times.
 * Each call decrypts 128 bytes of input streaming data and writes the decrypted data (128 bytes) into the target page.
 * The user shall feed in new data with each call.
 *
 * @param page_index The index of the page to which to write, starting from a secure container start address.
 * @param data Address of the input buffer.
 *
 * @remark In an interrupt or multithreaded environment, this function cannot be called in a re-entrant context.
 *
 * @return Function execution status.
 * @retval #ERR_LOG_SUCCESS
 * @retval #ERR_LOG_CODE_SEMAPHORE_RESERVED
 * @retval #ERR_LOG_CODE_USER_POINTER_RAM_RANGE_INVALID
 * @retval #ERR_LOG_CODE_PARAM_INVALID
 * @retval #ERR_LOG_CODE_AES_UNSUPPORTED_ERROR
 * @retval #ERR_LOG_CODE_AES_BUFFER_SMALL_ERROR
 * @retval #ERR_LOG_CODE_AES_UNAVAILABLE_ERROR
 * @retval #ERR_LOG_CODE_AES_ERROR
 * @retval #ERR_LOG_CODE_NVM_VER_ERROR
 */
#define user_secure_download_update          ( (int32_t(*)(uint32_t, uint8_t *))                              addr_user_secure_download_update         )

/**
 * @brief This user API function finalizes the secure download process.
 *
 * The function concludes the entire secure download process and clears the cryptographic context.
 *
 * @remark In an interrupt or multithreaded environment, this function cannot be called in a re-entrant context.
 *
 * @return Function execution status.
 * @retval #ERR_LOG_SUCCESS
 * @retval #ERR_LOG_CODE_SEMAPHORE_RESERVED
 * @retval #ERR_LOG_CODE_AES_UNSUPPORTED_ERROR
 * @retval #ERR_LOG_CODE_AES_BUFFER_SMALL_ERROR
 * @retval #ERR_LOG_CODE_AES_UNAVAILABLE_ERROR
 * @retval #ERR_LOG_CODE_AES_ERROR
 */
#define user_secure_download_finish          ( (int32_t(*)(void))                                             addr_user_secure_download_finish         )

/**
 * @brief This user API function provides an alternative to writing to cache registers in addition to direct register access.
 *
 * @param op The code for the cache operation to perform. For more information, refer to @ref user_cache_op_t.
 * @param address The memory address, namely the FLASH1 access.
 *
 * @return Function execution status.
 * @retval #ERR_LOG_SUCCESS
 * @retval #ERR_LOG_CODE_PARAM_INVALID
 */
#define user_cache_operation                 ( (int32_t(*)(user_cache_op_t, uint32_t))                        addr_user_cache_operation                )

/**
 * @brief This user API function is used to restore the UBSL size in case of a Stop mode exit w/o reset.
 *
 * @remark If user has an UBSL size configuration different than the default setting,
 * in case of stop mode exit w/o reset, this function must be called after exit from the Stop mode.
 */
#define user_ubsl_size_restore               ( (void(*)(void))                                                addr_user_ubsl_size_restore              )

/**
 * @brief This user API function initializes a CMAC generation.
 *
 * @param key_id key ID used for CMAC generation. Key ID range is 1 to 12.
 *
 * @remark In an interrupt or multithreaded environment, this function cannot be called in a re-entrant context.

 * @return Function execution status.
 * @retval #ERR_LOG_SUCCESS
 * @retval #ERR_LOG_CODE_SEMAPHORE_RESERVED
 * @retval #ERR_LOG_CODE_PARAM_INVALID
 * @retval #ERR_LOG_CODE_KEY_SLOT_CORRUPTED
 * @retval #ERR_LOG_CODE_AES_UNSUPPORTED_ERROR
 * @retval #ERR_LOG_CODE_AES_BUFFER_SMALL_ERROR
 * @retval #ERR_LOG_CODE_AES_UNAVAILABLE_ERROR
 * @retval #ERR_LOG_CODE_AES_ERROR
 */
#define user_crypto_aes_cmac_generate_start  ( (int32_t(*)(uint32_t))                                         addr_user_crypto_aes_cmac_generate_start )

/**
 * @brief This user API function updates the ongoing CMAC generation.
 *
 * Call @ref user_crypto_aes_cmac_generate_start routine before the first update operation.
 * The function can be called multiple times.
 *
 * @param buf Buffer for crypto operation. For more information, refer to @ref user_crypto_inp_buf_t.
 *
 * @remark In an interrupt or multithreaded environment, this function cannot be called in a re-entrant context.
 *
 * @return Function execution status.
 * @retval #ERR_LOG_SUCCESS
 * @retval #ERR_LOG_CODE_USER_POINTER_RAM_RANGE_INVALID
 * @retval #ERR_LOG_CODE_SEMAPHORE_RESERVED
 * @retval #ERR_LOG_CODE_AES_UNSUPPORTED_ERROR
 * @retval #ERR_LOG_CODE_AES_BUFFER_SMALL_ERROR
 * @retval #ERR_LOG_CODE_AES_UNAVAILABLE_ERROR
 * @retval #ERR_LOG_CODE_AES_ERROR
 */
#define user_crypto_aes_cmac_generate_update ( (int32_t(*)(user_crypto_inp_buf_t *))                          addr_user_crypto_aes_cmac_generate_update)

/**
 * @brief This user API function finalizes the ongoing CMAC generation.
 *
 * It concludes the entire CMAC generation operation and clears the cryptographic context.
 *
 * @param buf Buffer for crypto operation. For more information, refer to @ref user_crypto_io_buf_t.
 * @param truncation_allowed Whether the function may output a partial MAC.
 *
 * @remark In an interrupt or multithreaded environment, this function cannot be called in a re-entrant context.
 *
 * @return Function execution status.
 * @retval #ERR_LOG_SUCCESS
 * @retval #ERR_LOG_CODE_USER_POINTER_RAM_RANGE_INVALID
 * @retval #ERR_LOG_CODE_SEMAPHORE_RESERVED
 * @retval #ERR_LOG_CODE_AES_UNSUPPORTED_ERROR
 * @retval #ERR_LOG_CODE_AES_BUFFER_SMALL_ERROR
 * @retval #ERR_LOG_CODE_AES_UNAVAILABLE_ERROR
 * @retval #ERR_LOG_CODE_AES_ERROR
 */
#define user_crypto_aes_cmac_generate_finish ( (int32_t(*)(user_crypto_io_buf_t *, bool))                     addr_user_crypto_aes_cmac_generate_finish)

/**
 * @brief This user API function initializes a CMAC verification operation.
 *
 * @param key_id key ID used for CMAC verification operation. Key ID range is 1 to 12.
 *
 * @remark In an interrupt or multithreaded environment, this function cannot be called in a re-entrant context.
 *
 * @return Function execution status.
 * @retval #ERR_LOG_SUCCESS
 * @retval #ERR_LOG_CODE_SEMAPHORE_RESERVED
 * @retval #ERR_LOG_CODE_PARAM_INVALID
 * @retval #ERR_LOG_CODE_KEY_SLOT_CORRUPTED
 * @retval #ERR_LOG_CODE_AES_UNSUPPORTED_ERROR
 * @retval #ERR_LOG_CODE_AES_BUFFER_SMALL_ERROR
 * @retval #ERR_LOG_CODE_AES_UNAVAILABLE_ERROR
 * @retval #ERR_LOG_CODE_AES_ERROR
 */
#define user_crypto_aes_cmac_verify_start    ( (int32_t(*)(uint32_t))                                         addr_user_crypto_aes_cmac_verify_start   )

/**
 * @brief This user API function updates the ongoing CMAC verification.
 *
 * Call @ref user_crypto_aes_cmac_verify_start routine before the first update operation.
 * The function can be called multiple times.
 *
 * @remark In an interrupt or multithreaded environment, this function cannot be called  in a re-entrant context.
 *
 * @param buf Buffer for crypto operation. For more information, refer to @ref user_crypto_inp_buf_t.
 *
 * @return Function execution status.
 * @retval #ERR_LOG_SUCCESS
 * @retval #ERR_LOG_CODE_USER_POINTER_RAM_RANGE_INVALID
 * @retval #ERR_LOG_CODE_SEMAPHORE_RESERVED
 * @retval #ERR_LOG_CODE_AES_UNSUPPORTED_ERROR
 * @retval #ERR_LOG_CODE_AES_BUFFER_SMALL_ERROR
 * @retval #ERR_LOG_CODE_AES_UNAVAILABLE_ERROR
 * @retval #ERR_LOG_CODE_AES_ERROR
 */
#define user_crypto_aes_cmac_verify_update   ( (int32_t(*)(user_crypto_inp_buf_t *))                          addr_user_crypto_aes_cmac_verify_update  )

/**
 * @brief This user API function finalizes the ongoing CMAC verification.
 *
 * The function concludes the entire CMAC verification operation and clears the cryptographic context.
 *
 * @param mac Buffer for crypto operation. For more information, refer to @ref user_crypto_cmac_t.
 *
 * @remark In an interrupt or multithreaded environment, this function cannot be called in a re-entrant context.
 *
 * @return Function execution status.
 * @retval #ERR_LOG_SUCCESS
 * @retval #ERR_LOG_CODE_USER_POINTER_RAM_RANGE_INVALID
 * @retval #ERR_LOG_CODE_SEMAPHORE_RESERVED
 * @retval #ERR_LOG_CODE_AES_UNSUPPORTED_ERROR
 * @retval #ERR_LOG_CODE_AES_BUFFER_SMALL_ERROR
 * @retval #ERR_LOG_CODE_AES_UNAVAILABLE_ERROR
 * @retval #ERR_LOG_CODE_AES_ERROR
 * @retval #ERR_LOG_CODE_CMAC_VERIFY_FAIL
 */
#define user_crypto_aes_cmac_verify_finish   ( (int32_t(*)(user_crypto_cmac_t *))                             addr_user_crypto_aes_cmac_verify_finish  )

/**
 * @brief This user API function initializes an AES operation.
 *
 * @param fid The ID of the desired operation. Refer to @ref user_crypto_fid_t.
 * @param key_id The key ID used for AES operation. Key ID range is 1 to 12.
 * @param cbc_ctx Initial vector for the CBC encryption operation. For other operations (CBC decryption or ECB operation), set this to NULL.
 *
 * @remark In an interrupt or multithreaded environment, this function cannot be called in a re-entrant context.
 *
 * @return Function execution status.
 * @retval #ERR_LOG_SUCCESS
 * @retval #ERR_LOG_CODE_USER_POINTER_RAM_RANGE_INVALID
 * @retval #ERR_LOG_CODE_SEMAPHORE_RESERVED
 * @retval #ERR_LOG_CODE_PARAM_INVALID
 * @retval #ERR_LOG_CODE_KEY_SLOT_CORRUPTED
 * @retval #ERR_LOG_CODE_AES_UNSUPPORTED_ERROR
 * @retval #ERR_LOG_CODE_AES_BUFFER_SMALL_ERROR
 * @retval #ERR_LOG_CODE_AES_UNAVAILABLE_ERROR
 * @retval #ERR_LOG_CODE_AES_ERROR
 */
#define user_crypto_aes_start                ( (int32_t(*)(user_crypto_fid_t, uint32_t, user_crypto_cbc_t *)) addr_user_crypto_aes_start               )

/**
 * @brief This user API function updates the ongoing AES operation.
 *
 * Call @ref user_crypto_aes_start routine before the first update operation.
 * The function can be called multiple times.
 *
 * @param buf Buffer for crypto operation. For more information, refer to @ref user_crypto_io_buf_t.
 *
 * @remark In an interrupt or multithreaded environment, this function cannot be called in a re-entrant context.
 *
 * @return Function execution status.
 * @retval #ERR_LOG_SUCCESS
 * @retval #ERR_LOG_CODE_USER_POINTER_RAM_RANGE_INVALID
 * @retval #ERR_LOG_CODE_SEMAPHORE_RESERVED
 * @retval #ERR_LOG_CODE_PARAM_INVALID
 * @retval #ERR_LOG_CODE_AES_UNSUPPORTED_ERROR
 * @retval #ERR_LOG_CODE_AES_BUFFER_SMALL_ERROR
 * @retval #ERR_LOG_CODE_AES_UNAVAILABLE_ERROR
 * @retval #ERR_LOG_CODE_AES_ERROR
 */
#define user_crypto_aes_update               ( (int32_t(*)(user_crypto_io_buf_t *))                           addr_user_crypto_aes_update              )

/**
 * @brief This user API function finalizes the ongoing AES operation.
 *
 * The function concludes the entire AES operation and clears the cryptographic context.
 *
 * @param buf Buffer for crypto operation. For more information, refer to @ref user_crypto_io_buf_t.
 *
 * @remark In an interrupt or multithreaded environment, this function cannot be called in a re-entrant context.
 *
 * @return Function execution status.
 * @retval #ERR_LOG_SUCCESS
 * @retval #ERR_LOG_CODE_USER_POINTER_RAM_RANGE_INVALID
 * @retval #ERR_LOG_CODE_SEMAPHORE_RESERVED
 * @retval #ERR_LOG_CODE_PARAM_INVALID
 * @retval #ERR_LOG_CODE_AES_UNSUPPORTED_ERROR
 * @retval #ERR_LOG_CODE_AES_BUFFER_SMALL_ERROR
 * @retval #ERR_LOG_CODE_AES_UNAVAILABLE_ERROR
 * @retval #ERR_LOG_CODE_AES_ERROR
 */
#define user_crypto_aes_finish               ( (int32_t(*)(user_crypto_io_buf_t *))                           addr_user_crypto_aes_finish              )

/**
 * @brief This user API function writes a cryptographic key to the target key slot.
 *
 * @param key_write_params Key write parameters. For more information, refer to @ref user_key_write_t.
 *
 * @remark In an interrupt or multithreaded environment, this function cannot be called in a re-entrant context.
 *
 * @return Function execution status.
 * @retval #ERR_LOG_SUCCESS
 * @retval #ERR_LOG_CODE_USER_POINTER_RAM_RANGE_INVALID
 * @retval #ERR_LOG_CODE_SEMAPHORE_RESERVED
 * @retval #ERR_LOG_CODE_PARAM_INVALID
 * @retval #ERR_LOG_CODE_AES_UNSUPPORTED_ERROR
 * @retval #ERR_LOG_CODE_AES_BUFFER_SMALL_ERROR
 * @retval #ERR_LOG_CODE_AES_UNAVAILABLE_ERROR
 * @retval #ERR_LOG_CODE_AES_ERROR
 * @retval #ERR_LOG_CODE_CMAC_VERIFY_FAIL
 * @retval #ERR_LOG_CODE_KEY_SLOT_CORRUPTED
 * @retval #ERR_LOG_CODE_KEY_PROTECTED
 * @retval #ERR_LOG_CODE_KEY_VERSION
 * @retval #ERR_LOG_CODE_KEY_SIZE
 * @retval #ERR_LOG_CODE_ACCESS_AB_MODE_ERROR
 * @retval #ERR_LOG_CODE_NVM_VER_ERROR
 */
#define user_crypto_key_write                ( (int32_t(*)(user_key_write_t *))                               addr_user_crypto_key_write               )

/**
 * @brief This user API function erases a cryptographic key.
 *
 * @param key_erase_params Key erase parameters. For more information, refer to @ref user_key_erase_t.
 *
 * @remark In an interrupt or multithreaded environment, this function cannot be called in a re-entrant context.
 *
 * @return Function execution status.
 * @retval #ERR_LOG_SUCCESS
 * @retval #ERR_LOG_CODE_USER_POINTER_RAM_RANGE_INVALID
 * @retval #ERR_LOG_CODE_SEMAPHORE_RESERVED
 * @retval #ERR_LOG_CODE_PARAM_INVALID
 * @retval #ERR_LOG_CODE_AES_UNSUPPORTED_ERROR
 * @retval #ERR_LOG_CODE_AES_BUFFER_SMALL_ERROR
 * @retval #ERR_LOG_CODE_AES_UNAVAILABLE_ERROR
 * @retval #ERR_LOG_CODE_AES_ERROR
 * @retval #ERR_LOG_CODE_CMAC_VERIFY_FAIL
 * @retval #ERR_LOG_CODE_KEY_SLOT_CORRUPTED
 * @retval #ERR_LOG_CODE_KEY_PROTECTED
 * @retval #ERR_LOG_CODE_KEY_VERSION
 * @retval #ERR_LOG_CODE_KEY_SIZE
 * @retval #ERR_LOG_CODE_KEY_ERASE_FAIL
 */
#define user_crypto_key_erase                ( (int32_t(*)(user_key_erase_t *))                               addr_user_crypto_key_erase               )

/**
 * @brief This user API function verifies an existing cryptographic key. An additional key repair operation can be enabled by setting \a do_repair.
 *
 * @param key_id ID of the key to verify. Key ID range is 1 to 12.
 * @param do_repair The repair option.
 * - false: Performs a verification operation only.
 * - true:  Performs a verification operation. Additionally, in case of a verification failure. Attempts to repair the key slot using redundancy.
 *
 * @remark In an interrupt or multithreaded environment, this function cannot be called in a re-entrant context.
 *
 * @return Function execution status.
 * @retval #ERR_LOG_SUCCESS
 * @retval #ERR_LOG_CODE_SEMAPHORE_RESERVED
 * @retval #ERR_LOG_CODE_AES_UNAVAILABLE_ERROR
 * @retval #ERR_LOG_CODE_PARAM_INVALID
 * @retval #ERR_LOG_CODE_ACCESS_AB_MODE_ERROR
 * @retval #ERR_LOG_CODE_KEY_SLOT_MISMATCH
 * @retval #ERR_LOG_CODE_KEY_SLOT_CORRUPTED
 * @retval #ERR_LOG_CODE_KEY_VERIFY_FAIL
 * @retval #ERR_LOG_CODE_NVM_VER_ERROR
 */
#define user_crypto_key_verify               ( (int32_t(*)(uint8_t, bool))                                    addr_user_crypto_key_verify              )

/* User API extension, callable from UBSL segment only */
/**
 * @brief This user API function temporarily clears the write protection of the UBSL segment.
 *
 * @param passphrase The passphrase must be #NVM_SEG_PROT_UBSL_NO_ERASE.
 *
 * @remark In an interrupt or multithreaded environment, this function cannot be called in a re-entrant context.
 *
 * @return Function execution status.
 * @retval #ERR_LOG_SUCCESS
 * @retval #ERR_LOG_CODE_USER_PROTECT_WRONG_PASSWORD
 * @retval #ERR_LOG_CODE_SEMAPHORE_RESERVED
 */
#define user_nvm_ubsl_temp_protect_clear     ( (int32_t(*)(uint32_t))                                         addr_user_nvm_ubsl_temp_protect_clear    )

/**
 * @brief This user API function temporarily sets the write protection of the UBSL segment.
 *
 * @param passphrase The passphrase must be #NVM_SEG_PROT_UBSL_NO_ERASE.
 *
 * @remark In an interrupt or multithreaded environment, this function cannot be called in a re-entrant context.
 *
 * @return Function execution status.
 * @retval #ERR_LOG_SUCCESS
 * @retval #ERR_LOG_CODE_USER_PROTECT_WRONG_PASSWORD
 * @retval #ERR_LOG_CODE_SEMAPHORE_RESERVED
 */
#define user_nvm_ubsl_temp_protect_set       ( (int32_t(*)(uint32_t))                                         addr_user_nvm_ubsl_temp_protect_set      )

/**
 * @brief This user API function configures and enables the secondary UBSL image.
 *
 * @param image_offset New image address offset (the offset of startup page address), starting from the UBSL segment start address.
 *
 * @remark In an interrupt or multithreaded environment, this function cannot be called in a re-entrant context.
 *
 * @return Function execution status.
 * @retval #ERR_LOG_SUCCESS
 * @retval #ERR_LOG_CODE_MEM_ADDR_RANGE_INVALID
 * @retval #ERR_LOG_CODE_SEMAPHORE_RESERVED
 * @retval #ERR_LOG_CODE_ACCESS_AB_MODE_ERROR
 * @retval #ERR_LOG_CODE_NVM_VER_ERROR
 */
#define user_secure_dualboot                 ( (int32_t(*)(uint32_t))                                         addr_user_secure_dualboot                )

/*******************************************************************************
**                     Global Inline Function Definitions                     **
*******************************************************************************/

/** @}*/

#endif /* _BOOTROM_H */
