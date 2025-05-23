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

/**
 * @file atomic.h
 * @brief FreeRTOS_core0 atomic operation support.
 *
 * This file implements atomic functions by disabling interrupts globally.
 * Implementations with architecture specific atomic instructions can be
 * provided under each compiler directory.
 */

#ifndef ATOMIC_CORE0_H
#define ATOMIC_CORE0_H

#ifndef INC_FREERTOS_CORE0_H
    #error "include FreeRTOS_core0.h must appear in source files before include atomic.h"
#endif

/* Standard includes. */
#include <stdint.h>

/* *INDENT-OFF* */
#ifdef __cplusplus
    extern "C" {
#endif
/* *INDENT-ON* */

/*
 * Port specific definitions -- entering/exiting critical section.
 * Refer template -- ./lib/FreeRTOS_core0/portable/Compiler/Arch/portmacro.h
 *
 * Every call to ATOMIC_EXIT_CRITICAL_core0() must be closely paired with
 * ATOMIC_ENTER_CRITICAL_core0().
 *
 */
#if defined( portSET_INTERRUPT_MASK_FROM_ISR_core0 )

/* Nested interrupt scheme is supported in this port. */
    #define ATOMIC_ENTER_CRITICAL_core0() \
    UBaseType_t_core0 uxCriticalSectionType_core0 = portSET_INTERRUPT_MASK_FROM_ISR_core0()

    #define ATOMIC_EXIT_CRITICAL_core0() \
    portCLEAR_INTERRUPT_MASK_FROM_ISR_core0( uxCriticalSectionType_core0 )

#else

/* Nested interrupt scheme is NOT supported in this port. */
    #define ATOMIC_ENTER_CRITICAL_core0()    portENTER_CRITICAL_core0()
    #define ATOMIC_EXIT_CRITICAL_core0()     portEXIT_CRITICAL_core0()

#endif /* portSET_INTERRUPT_MASK_FROM_ISR_core0() */

/*
 * Port specific definition -- "always inline".
 * Inline is compiler specific, and may not always get inlined depending on your
 * optimization level.  Also, inline is considered as performance optimization
 * for atomic.  Thus, if portFORCE_INLINE_core0 is not provided by portmacro.h,
 * instead of resulting error, simply define it away.
 */
#ifndef portFORCE_INLINE_core0
    #define portFORCE_INLINE_core0
#endif

#define ATOMIC_COMPARE_AND_SWAP_SUCCESS_core0    0x1U     /**< Compare and swap succeeded, swapped. */
#define ATOMIC_COMPARE_AND_SWAP_FAILURE_core0    0x0U     /**< Compare and swap failed, did not swap. */

/*----------------------------- Swap && CAS ------------------------------*/

/**
 * Atomic compare-and-swap
 *
 * @brief Performs an atomic compare-and-swap operation on the specified values.
 *
 * @param[in, out] pulDestination_core0  Pointer to memory location from where value is
 *                               to be loaded and checked.
 * @param[in] ulExchange_core0         If condition meets, write this value to memory.
 * @param[in] ulComparand_core0        Swap condition.
 *
 * @return Unsigned integer of value 1 or 0. 1 for swapped, 0 for not swapped.
 *
 * @note This function only swaps *pulDestination_core0 with ulExchange_core0, if previous
 *       *pulDestination_core0 value equals ulComparand_core0.
 */
static portFORCE_INLINE_core0 uint32_t Atomic_CompareAndSwap_u32_core0( uint32_t volatile * pulDestination_core0,
                                                            uint32_t ulExchange_core0,
                                                            uint32_t ulComparand_core0 )
{
    uint32_t ulReturnValue_core0;

    ATOMIC_ENTER_CRITICAL_core0();
    {
        if( *pulDestination_core0 == ulComparand_core0 )
        {
            *pulDestination_core0 = ulExchange_core0;
            ulReturnValue_core0 = ATOMIC_COMPARE_AND_SWAP_SUCCESS_core0;
        }
        else
        {
            ulReturnValue_core0 = ATOMIC_COMPARE_AND_SWAP_FAILURE_core0;
        }
    }
    ATOMIC_EXIT_CRITICAL_core0();

    return ulReturnValue_core0;
}
/*-----------------------------------------------------------*/

/**
 * Atomic swap (pointers)
 *
 * @brief Atomically sets the address pointed to by *ppvDestination_core0 to the value
 *        of *pvExchange_core0.
 *
 * @param[in, out] ppvDestination_core0  Pointer to memory location from where a pointer
 *                                 value is to be loaded and written back to.
 * @param[in] pvExchange_core0           Pointer value to be written to *ppvDestination_core0.
 *
 * @return The initial value of *ppvDestination_core0.
 */
static portFORCE_INLINE_core0 void * Atomic_SwapPointers_p32_core0( void * volatile * ppvDestination_core0,
                                                        void * pvExchange_core0 )
{
    void * pReturnValue_core0;

    ATOMIC_ENTER_CRITICAL_core0();
    {
        pReturnValue_core0 = *ppvDestination_core0;
        *ppvDestination_core0 = pvExchange_core0;
    }
    ATOMIC_EXIT_CRITICAL_core0();

    return pReturnValue_core0;
}
/*-----------------------------------------------------------*/

/**
 * Atomic compare-and-swap (pointers)
 *
 * @brief Performs an atomic compare-and-swap operation on the specified pointer
 *        values.
 *
 * @param[in, out] ppvDestination_core0  Pointer to memory location from where a pointer
 *                                 value is to be loaded and checked.
 * @param[in] pvExchange_core0           If condition meets, write this value to memory.
 * @param[in] pvComparand_core0          Swap condition.
 *
 * @return Unsigned integer of value 1 or 0. 1 for swapped, 0 for not swapped.
 *
 * @note This function only swaps *ppvDestination_core0 with pvExchange_core0, if previous
 *       *ppvDestination_core0 value equals pvComparand_core0.
 */
static portFORCE_INLINE_core0 uint32_t Atomic_CompareAndSwapPointers_p32_core0( void * volatile * ppvDestination_core0,
                                                                    void * pvExchange_core0,
                                                                    void * pvComparand_core0 )
{
    uint32_t ulReturnValue_core0 = ATOMIC_COMPARE_AND_SWAP_FAILURE_core0;

    ATOMIC_ENTER_CRITICAL_core0();
    {
        if( *ppvDestination_core0 == pvComparand_core0 )
        {
            *ppvDestination_core0 = pvExchange_core0;
            ulReturnValue_core0 = ATOMIC_COMPARE_AND_SWAP_SUCCESS_core0;
        }
    }
    ATOMIC_EXIT_CRITICAL_core0();

    return ulReturnValue_core0;
}


/*----------------------------- Arithmetic ------------------------------*/

/**
 * Atomic add
 *
 * @brief Atomically adds count to the value of the specified pointer points to.
 *
 * @param[in,out] pulAddend_core0  Pointer to memory location from where value is to be
 *                         loaded and written back to.
 * @param[in] ulCount_core0      Value to be added to *pulAddend_core0.
 *
 * @return previous *pulAddend_core0 value.
 */
static portFORCE_INLINE_core0 uint32_t Atomic_Add_u32_core0( uint32_t volatile * pulAddend_core0,
                                                 uint32_t ulCount_core0 )
{
    uint32_t ulCurrent_core0;

    ATOMIC_ENTER_CRITICAL_core0();
    {
        ulCurrent_core0 = *pulAddend_core0;
        *pulAddend_core0 += ulCount_core0;
    }
    ATOMIC_EXIT_CRITICAL_core0();

    return ulCurrent_core0;
}
/*-----------------------------------------------------------*/

/**
 * Atomic subtract
 *
 * @brief Atomically subtracts count from the value of the specified pointer
 *        pointers to.
 *
 * @param[in,out] pulAddend_core0  Pointer to memory location from where value is to be
 *                         loaded and written back to.
 * @param[in] ulCount_core0      Value to be subtract from *pulAddend_core0.
 *
 * @return previous *pulAddend_core0 value.
 */
static portFORCE_INLINE_core0 uint32_t Atomic_Subtract_u32_core0( uint32_t volatile * pulAddend_core0,
                                                      uint32_t ulCount_core0 )
{
    uint32_t ulCurrent_core0;

    ATOMIC_ENTER_CRITICAL_core0();
    {
        ulCurrent_core0 = *pulAddend_core0;
        *pulAddend_core0 -= ulCount_core0;
    }
    ATOMIC_EXIT_CRITICAL_core0();

    return ulCurrent_core0;
}
/*-----------------------------------------------------------*/

/**
 * Atomic increment
 *
 * @brief Atomically increments the value of the specified pointer points to.
 *
 * @param[in,out] pulAddend_core0  Pointer to memory location from where value is to be
 *                         loaded and written back to.
 *
 * @return *pulAddend_core0 value before increment.
 */
static portFORCE_INLINE_core0 uint32_t Atomic_Increment_u32_core0( uint32_t volatile * pulAddend_core0 )
{
    uint32_t ulCurrent_core0;

    ATOMIC_ENTER_CRITICAL_core0();
    {
        ulCurrent_core0 = *pulAddend_core0;
        *pulAddend_core0 += 1;
    }
    ATOMIC_EXIT_CRITICAL_core0();

    return ulCurrent_core0;
}
/*-----------------------------------------------------------*/

/**
 * Atomic decrement
 *
 * @brief Atomically decrements the value of the specified pointer points to
 *
 * @param[in,out] pulAddend_core0  Pointer to memory location from where value is to be
 *                         loaded and written back to.
 *
 * @return *pulAddend_core0 value before decrement.
 */
static portFORCE_INLINE_core0 uint32_t Atomic_Decrement_u32_core0( uint32_t volatile * pulAddend_core0 )
{
    uint32_t ulCurrent_core0;

    ATOMIC_ENTER_CRITICAL_core0();
    {
        ulCurrent_core0 = *pulAddend_core0;
        *pulAddend_core0 -= 1;
    }
    ATOMIC_EXIT_CRITICAL_core0();

    return ulCurrent_core0;
}

/*----------------------------- Bitwise Logical ------------------------------*/

/**
 * Atomic OR
 *
 * @brief Performs an atomic OR operation on the specified values.
 *
 * @param [in, out] pulDestination_core0  Pointer to memory location from where value is
 *                                to be loaded and written back to.
 * @param [in] ulValue_core0            Value to be ORed with *pulDestination_core0.
 *
 * @return The original value of *pulDestination_core0.
 */
static portFORCE_INLINE_core0 uint32_t Atomic_OR_u32_core0( uint32_t volatile * pulDestination_core0,
                                                uint32_t ulValue_core0 )
{
    uint32_t ulCurrent_core0;

    ATOMIC_ENTER_CRITICAL_core0();
    {
        ulCurrent_core0 = *pulDestination_core0;
        *pulDestination_core0 |= ulValue_core0;
    }
    ATOMIC_EXIT_CRITICAL_core0();

    return ulCurrent_core0;
}
/*-----------------------------------------------------------*/

/**
 * Atomic AND
 *
 * @brief Performs an atomic AND operation on the specified values.
 *
 * @param [in, out] pulDestination_core0  Pointer to memory location from where value is
 *                                to be loaded and written back to.
 * @param [in] ulValue_core0            Value to be ANDed with *pulDestination_core0.
 *
 * @return The original value of *pulDestination_core0.
 */
static portFORCE_INLINE_core0 uint32_t Atomic_AND_u32_core0( uint32_t volatile * pulDestination_core0,
                                                 uint32_t ulValue_core0 )
{
    uint32_t ulCurrent_core0;

    ATOMIC_ENTER_CRITICAL_core0();
    {
        ulCurrent_core0 = *pulDestination_core0;
        *pulDestination_core0 &= ulValue_core0;
    }
    ATOMIC_EXIT_CRITICAL_core0();

    return ulCurrent_core0;
}
/*-----------------------------------------------------------*/

/**
 * Atomic NAND
 *
 * @brief Performs an atomic NAND operation on the specified values.
 *
 * @param [in, out] pulDestination_core0  Pointer to memory location from where value is
 *                                to be loaded and written back to.
 * @param [in] ulValue_core0            Value to be NANDed with *pulDestination_core0.
 *
 * @return The original value of *pulDestination_core0.
 */
static portFORCE_INLINE_core0 uint32_t Atomic_NAND_u32_core0( uint32_t volatile * pulDestination_core0,
                                                  uint32_t ulValue_core0 )
{
    uint32_t ulCurrent_core0;

    ATOMIC_ENTER_CRITICAL_core0();
    {
        ulCurrent_core0 = *pulDestination_core0;
        *pulDestination_core0 = ~( ulCurrent_core0 & ulValue_core0 );
    }
    ATOMIC_EXIT_CRITICAL_core0();

    return ulCurrent_core0;
}
/*-----------------------------------------------------------*/

/**
 * Atomic XOR
 *
 * @brief Performs an atomic XOR operation on the specified values.
 *
 * @param [in, out] pulDestination_core0  Pointer to memory location from where value is
 *                                to be loaded and written back to.
 * @param [in] ulValue_core0            Value to be XORed with *pulDestination_core0.
 *
 * @return The original value of *pulDestination_core0.
 */
static portFORCE_INLINE_core0 uint32_t Atomic_XOR_u32_core0( uint32_t volatile * pulDestination_core0,
                                                 uint32_t ulValue_core0 )
{
    uint32_t ulCurrent_core0;

    ATOMIC_ENTER_CRITICAL_core0();
    {
        ulCurrent_core0 = *pulDestination_core0;
        *pulDestination_core0 ^= ulValue_core0;
    }
    ATOMIC_EXIT_CRITICAL_core0();

    return ulCurrent_core0;
}

/* *INDENT-OFF* */
#ifdef __cplusplus
    }
#endif
/* *INDENT-ON* */

#endif /* ATOMIC_H */
