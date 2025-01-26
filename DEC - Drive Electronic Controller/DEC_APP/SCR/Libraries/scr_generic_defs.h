#ifndef SCR_GENERICDEFS_H
#define SCR_GENERICDEFS_H

#include "registers.h"

typedef unsigned char uint8;

#define SCR_ISR __isr;
#define SFR(X) (*(__near volatile uint8*)(X))

#endif
