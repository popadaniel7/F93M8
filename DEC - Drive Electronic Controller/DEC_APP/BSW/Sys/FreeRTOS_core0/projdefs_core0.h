/*
 * FreeRTOS_core0 Kernel V10.5.1
 * Copyright (C) 2021 Amazon.com, Inc. or its affiliates.  All Rights Reserved.
 *
 * SPDX-License-Identifier: MIT
 *
 * Permission is hereby granted, free of charge, to any person obtaining a copy of
 * this software and associated documentation files (the "Software"), to deal in
 * the Software without restriction, including without limitation the rights to
 * use, copy, modify, merge, publish, distribute, sublicense, and/or sell copies of
 * the Software, and to permit persons to whom the Software is furnished to do so,
 * subject to the following conditions:
 *
 * The above copyright notice and this permission notice shall be included in all
 * copies or substantial portions of the Software.
 *
 * THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
 * IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY, FITNESS
 * FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE AUTHORS OR
 * COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER LIABILITY, WHETHER
 * IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM, OUT OF OR IN
 * CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE SOFTWARE.
 *
 * https://www.FreeRTOS_core0.org
 * https://github.com/FreeRTOS_core0
 *
 */

#ifndef PROJDEFS_CORE0_H
#define PROJDEFS_CORE0_H

/*
 * Defines the prototype to which task_core0 functions must conform.  Defined in this
 * file to ensure the type is known before portable.h is included.
 */
typedef void (* TaskFunction_t_core0)( void * );

/* Converts a time in milliseconds to a time in ticks.  This macro can be
 * overridden by a macro of the same name defined in FreeRTOSConfig.h in case the
 * definition here is not suitable for your application. */
#ifndef pdMS_TO_TICKS_core0
    #define pdMS_TO_TICKS_core0( xTimeInMs_core0 )    ( ( TickType_t_core0 ) ( ( ( TickType_t_core0 ) ( xTimeInMs_core0 ) * ( TickType_t_core0 ) configTICK_RATE_HZ_core0 ) / ( TickType_t_core0 ) 1000U ) )
#endif

#define pdFALSE_core0                                  ( ( BaseType_t_core0 ) 0 )
#define pdTRUE_core0                                   ( ( BaseType_t_core0 ) 1 )

#define pdPASS_core0                                   ( pdTRUE_core0 )
#define pdFAIL_core0                                   ( pdFALSE_core0 )
#define errQUEUE_EMPTY_core0                           ( ( BaseType_t_core0 ) 0 )
#define errQUEUE_FULL_core0                            ( ( BaseType_t_core0 ) 0 )

/* FreeRTOS_core0 error definitions. */
#define errCOULD_NOT_ALLOCATE_REQUIRED_MEMORY_core0    ( -1 )
#define errQUEUE_BLOCKED_core0                         ( -4 )
#define errQUEUE_YIELD_core0                           ( -5 )

/* Macros used for basic data corruption checks. */
#ifndef configUSE_LIST_DATA_INTEGRITY_CHECK_BYTES_core0
    #define configUSE_LIST_DATA_INTEGRITY_CHECK_BYTES_core0    0
#endif

#if ( configUSE_16_BIT_TICKS_core0 == 1 )
    #define pdINTEGRITY_CHECK_VALUE_core0    0x5a5a
#else
    #define pdINTEGRITY_CHECK_VALUE_core0    0x5a5a5a5aUL
#endif

/* The following errno values are used by FreeRTOS_core0+ components, not FreeRTOS_core0
 * itself. */
#define pdFREERTOS_ERRNO_NONE_core0             0   /* No errors */
#define pdFREERTOS_ERRNO_ENOENT_core0           2   /* No such file or directory */
#define pdFREERTOS_ERRNO_EINTR_core0            4   /* Interrupted system call */
#define pdFREERTOS_ERRNO_EIO_core0              5   /* I/O error */
#define pdFREERTOS_ERRNO_ENXIO_core0            6   /* No such device or address */
#define pdFREERTOS_ERRNO_EBADF_core0            9   /* Bad file number */
#define pdFREERTOS_ERRNO_EAGAIN_core0           11  /* No more processes */
#define pdFREERTOS_ERRNO_EWOULDBLOCK_core0      11  /* Operation would block */
#define pdFREERTOS_ERRNO_ENOMEM_core0           12  /* Not enough memory */
#define pdFREERTOS_ERRNO_EACCES_core0           13  /* Permission denied */
#define pdFREERTOS_ERRNO_EFAULT_core0           14  /* Bad address */
#define pdFREERTOS_ERRNO_EBUSY_core0            16  /* Mount device busy */
#define pdFREERTOS_ERRNO_EEXIST_core0           17  /* File exists */
#define pdFREERTOS_ERRNO_EXDEV_core0            18  /* Cross-device link */
#define pdFREERTOS_ERRNO_ENODEV_core0           19  /* No such device */
#define pdFREERTOS_ERRNO_ENOTDIR_core0           20  /* Not a directory */
#define pdFREERTOS_ERRNO_EISDIR_core0            21  /* Is a directory */
#define pdFREERTOS_ERRNO_EINVAL_core0            22  /* Invalid argument */
#define pdFREERTOS_ERRNO_ENOSPC_core0            28  /* No space left on device */
#define pdFREERTOS_ERRNO_ESPIPE_core0            29  /* Illegal seek */
#define pdFREERTOS_ERRNO_EROFS_core0             30  /* Read only file system */
#define pdFREERTOS_ERRNO_EUNATCH_core0           42  /* Protocol driver not attached */
#define pdFREERTOS_ERRNO_EBADE_core0             50  /* Invalid exchange */
#define pdFREERTOS_ERRNO_EFTYPE_core0            79  /* Inappropriate file type or format */
#define pdFREERTOS_ERRNO_ENMFILE_core0           89  /* No more files */
#define pdFREERTOS_ERRNO_ENOTEMPTY_core0         90  /* Directory not empty */
#define pdFREERTOS_ERRNO_ENAMETOOLONG_core0      91  /* File or path name too long */
#define pdFREERTOS_ERRNO_EOPNOTSUPP_core0        95  /* Operation not supported on transport endpoint */
#define pdFREERTOS_ERRNO_ENOBUFS_core0           105 /* No buffer space available */
#define pdFREERTOS_ERRNO_ENOPROTOOPT_core0       109 /* Protocol not available */
#define pdFREERTOS_ERRNO_EADDRINUSE_core0        112 /* Address already in use */
#define pdFREERTOS_ERRNO_ETIMEDOUT_core0         116 /* Connection timed out */
#define pdFREERTOS_ERRNO_EINPROGRESS_core0       119 /* Connection already in progress */
#define pdFREERTOS_ERRNO_EALREADY_core0          120 /* Socket already connected */
#define pdFREERTOS_ERRNO_EADDRNOTAVAIL_core0     125 /* Address not available */
#define pdFREERTOS_ERRNO_EISCONN_core0           127 /* Socket is already connected */
#define pdFREERTOS_ERRNO_ENOTCONN_core0          128 /* Socket is not connected */
#define pdFREERTOS_ERRNO_ENOMEDIUM_core0         135 /* No medium inserted */
#define pdFREERTOS_ERRNO_EILSEQ_core0            138 /* An invalid UTF-16 sequence was encountered. */
#define pdFREERTOS_ERRNO_ECANCELED_core0         140 /* Operation canceled. */

/* The following endian values are used by FreeRTOS_core0+ components, not FreeRTOS_core0
 * itself. */
#define pdFREERTOS_LITTLE_ENDIAN_core0           0
#define pdFREERTOS_BIG_ENDIAN_core0              1

/* Re-defining endian values for generic naming. */
#define pdLITTLE_ENDIAN_core0                    pdFREERTOS_LITTLE_ENDIAN_core0 
#define pdBIG_ENDIAN_core0                       pdFREERTOS_BIG_ENDIAN_core0 


#endif /* PROJDEFS_H */
