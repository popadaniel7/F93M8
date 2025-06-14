#include "ColDet.h"
#include "Ain.h"
#include "Dem.h"
#include "EncCal.h"
#include <time.h>
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <math.h>
#include "Can.h"

uint32 ColDet_MainCounter = 0u;
uint8 ColDet_CanTx_BrakeLevel = 0u;  
uint8 ColDet_CanTx_IrSenStat = 0u;
uint8 ColDet_CanRx_CalculatedSpeed = 0u;
CollisionState ColDet_CanTx_CollisionState = COLLISION_SAFE;

void ColDet_MainFunction(void);

void ColDet_MainFunction(void)
{
    static float convStableDistanceCm = 0.0f;
    static float convTtcWarn = 0.0f;
    static float convTtcBrake = 0.0f;
    static double speed = 0.0f;
    static double ttc = 0.0f;
    uint32 distanceCm = EncCal_Calibration_ColDet_InvalidDist;
    uint32 lastDistanceCm = EncCal_Calibration_ColDet_InvalidDist;
    static uint16 localCounter = 0u;
    static bool objectDetected = 0u;
    static uint32 cycleTimeTtcWarn = 0u;
    static uint32 cycleTimeTtcBrake = 0u;
    static uint8 debflag = 0u;

    if(600u > ColDet_MainCounter)
    {
        debflag = 1u;
    }
    else
    {
        /* Do nothing. */
    }

    convStableDistanceCm = (float)EncCal_Calibration_ColDet_StableDistanceCm / 100.0f;
    convTtcWarn = (float)EncCal_Calibration_ColDet_TtcWarn / 100.0f;
    convTtcBrake  = (float)EncCal_Calibration_ColDet_TtcBrake / 100.0f;
    speed = ColDet_CanRx_CalculatedSpeed;        
    distanceCm = Ain_IRSensorValue;
    cycleTimeTtcWarn = (EncCal_Calibration_ColDet_TtcWarn * 10u) / 5u;
    cycleTimeTtcBrake = (EncCal_Calibration_ColDet_TtcBrake * 10u) / 5u;

    if(abs(distanceCm - lastDistanceCm) <= convStableDistanceCm)
    {
        distanceCm = lastDistanceCm;
    }
    else
    {
        /* Do nothing. */
    }

    lastDistanceCm = distanceCm;
    objectDetected = (distanceCm < EncCal_Calibration_ColDet_InvalidDist);

    if((objectDetected && speed) > 0.0f)
    {
        ttc = distanceCm / speed;
    }
    else
    {
        ttc = 9999u; 
    }
    
    switch(ColDet_CanTx_CollisionState)
    {
        default:

            break;

        case COLLISION_ERROR:

            ColDet_CanTx_BrakeLevel = 0u;

            break;

        case COLLISION_SAFE:

            if((0u != objectDetected) && (ttc <= convTtcBrake))
            {                
                ColDet_CanTx_CollisionState = COLLISION_BRAKE;

                if((ColDet_MainCounter % cycleTimeTtcBrake == 0u) && (0u != ColDet_MainCounter))
                {
                    if(100u > ColDet_CanTx_BrakeLevel)
                    {
                        ColDet_CanTx_BrakeLevel += 10u;
                    }
                    else
                    {
                        /* Do nothing. */
                    }
                }
                else
                {
                    /* Do nothing. */
                }
            }
            else if((0u != objectDetected) && (ttc <= convTtcWarn))
            {                
                ColDet_CanTx_CollisionState = COLLISION_WARNING;

                if((ColDet_MainCounter % cycleTimeTtcWarn == 0u) && (0u != ColDet_MainCounter))
                {
                    if(50u < ColDet_CanTx_BrakeLevel)
                    {
                        ColDet_CanTx_BrakeLevel -= 10u;
                    }
                    else
                    {
                        /* Do nothing. */
                    }
                }
                else
                {
                    /* Do nothing. */
                }
            }
            else
            {
                ColDet_CanTx_CollisionState = COLLISION_SAFE;

                if((ColDet_MainCounter % cycleTimeTtcWarn == 0u) && (0u != ColDet_MainCounter))
                {
                    if(0u < ColDet_CanTx_BrakeLevel)
                    {
                        ColDet_CanTx_BrakeLevel -= 10u;
                    }
                    else
                    {
                        /* Do nothing. */
                    }
                }
                else
                {
                    /* Do nothing. */
                }
            }

            break;

        case COLLISION_WARNING:

            if((0u == objectDetected) || (ttc > convTtcWarn))
            {
                ColDet_CanTx_CollisionState = COLLISION_SAFE;

                if((ColDet_MainCounter % cycleTimeTtcWarn == 0u) && (0u != ColDet_MainCounter))
                {
                    if(0u < ColDet_CanTx_BrakeLevel)
                    {
                        ColDet_CanTx_BrakeLevel -= 10u;
                    }
                    else
                    {
                        /* Do nothing. */
                    }
                }
                else
                {
                    /* Do nothing. */
                }
            }
            else if (ttc <= convTtcBrake)
            {
                ColDet_CanTx_CollisionState = COLLISION_BRAKE;

                if((ColDet_MainCounter % cycleTimeTtcBrake == 0u) && (0u != ColDet_MainCounter))
                {
                    if (100u > ColDet_CanTx_BrakeLevel)
                    {
                        ColDet_CanTx_BrakeLevel += 10u;
                    }
                    else
                    {
                        /* Do nothing. */
                    }
                }
                else
                {
                    /* Do nothing. */
                }
            }
            else
            {
                if((ColDet_MainCounter % cycleTimeTtcWarn == 0u) && (0u != ColDet_MainCounter))
                {
                    if(50u > ColDet_CanTx_BrakeLevel)
                    {
                        ColDet_CanTx_BrakeLevel += 10u;
                    }
                    else
                    {
                        /* Do nothing. */
                    }
                }
                else
                {
                    /* Do nothing. */
                }
            }

            break;

        case COLLISION_BRAKE:

            if((0u == objectDetected) || (ttc > convTtcWarn))
            {
                ColDet_CanTx_CollisionState = COLLISION_SAFE;

                if((ColDet_MainCounter % cycleTimeTtcWarn == 0u) && (0u != ColDet_MainCounter))
                {
                    if(0u < ColDet_CanTx_BrakeLevel)
                    {
                        ColDet_CanTx_BrakeLevel -= 10u;
                    }
                    else
                    {
                        /* Do nothing. */
                    }
                }
                else
                {
                    /* Do nothing. */
                }
            }
            else if((ttc > convTtcBrake) && (ttc <= convTtcWarn))
            {
                ColDet_CanTx_CollisionState = COLLISION_WARNING;

                if((ColDet_MainCounter % cycleTimeTtcBrake == 0u) && (0u != ColDet_MainCounter))
                {
                    if (50u > ColDet_CanTx_BrakeLevel)
                    {
                        ColDet_CanTx_BrakeLevel += 10u;
                    }
                    else if(50u < ColDet_CanTx_BrakeLevel)
                    {
                        ColDet_CanTx_BrakeLevel -= 10u;
                    }
                    else
                    {
                        /* Do nothing. */
                    }
                }
                else
                {
                    /* Do nothing. */
                }
            }
            else
            {
                ColDet_CanTx_CollisionState = COLLISION_BRAKE;

                if((ColDet_MainCounter % cycleTimeTtcBrake == 0u) && (0u != ColDet_MainCounter))
                {
                    if (100u > ColDet_CanTx_BrakeLevel)
                    {
                        ColDet_CanTx_BrakeLevel += 10u;
                    }
                    else
                    {
                        /* Do nothing. */
                    }
                }
                else
                {
                    /* Do nothing. */
                }
            }

            break;
    }

    if(Ain_IRSensorValue == ((EncCal_Calibration_ColDet_InvalidDist << 8u) | 0xFFU) && 1u == debflag)
    {
        localCounter++;

        if(2000u < localCounter)
        {
            Dem_SetDtc(COLDET_DTC_ID_IR_SENSOR_MALFUNCTION, 1u, 0u);
            ColDet_CanTx_CollisionState = COLLISION_ERROR;
            ColDet_CanTx_BrakeLevel = 0u;
            localCounter = 0u;
        }
        else
        {
            /* Do nothing. */
        }
    }
    else
    {
        Dem_SetDtc(COLDET_DTC_ID_IR_SENSOR_MALFUNCTION, 0u, 0u);

        if(COLLISION_ERROR == ColDet_CanTx_CollisionState)
        {
            ColDet_CanTx_CollisionState = COLLISION_SAFE;
        }
        else
        {
            /* Do nothing. */
        }

        localCounter = 0u;
    }

    ColDet_CanTx_IrSenStat = ColDet_CanTx_CollisionState;
    ColDet_MainCounter++;
}
