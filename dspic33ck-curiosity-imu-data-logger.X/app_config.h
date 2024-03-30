/* Microchip Technology Inc. and its subsidiaries.  You may use this software 
 * and any derivatives exclusively with Microchip products. 
 * 
 * THIS SOFTWARE IS SUPPLIED BY MICROCHIP "AS IS".  NO WARRANTIES, WHETHER 
 * EXPRESS, IMPLIED OR STATUTORY, APPLY TO THIS SOFTWARE, INCLUDING ANY IMPLIED 
 * WARRANTIES OF NON-INFRINGEMENT, MERCHANTABILITY, AND FITNESS FOR A 
 * PARTICULAR PURPOSE, OR ITS INTERACTION WITH MICROCHIP PRODUCTS, COMBINATION 
 * WITH ANY OTHER PRODUCTS, OR USE IN ANY APPLICATION. 
 *
 * IN NO EVENT WILL MICROCHIP BE LIABLE FOR ANY INDIRECT, SPECIAL, PUNITIVE, 
 * INCIDENTAL OR CONSEQUENTIAL LOSS, DAMAGE, COST OR EXPENSE OF ANY KIND 
 * WHATSOEVER RELATED TO THE SOFTWARE, HOWEVER CAUSED, EVEN IF MICROCHIP HAS 
 * BEEN ADVISED OF THE POSSIBILITY OR THE DAMAGES ARE FORESEEABLE.  TO THE 
 * FULLEST EXTENT ALLOWED BY LAW, MICROCHIP'S TOTAL LIABILITY ON ALL CLAIMS 
 * IN ANY WAY RELATED TO THIS SOFTWARE WILL NOT EXCEED THE AMOUNT OF FEES, IF 
 * ANY, THAT YOU HAVE PAID DIRECTLY TO MICROCHIP FOR THIS SOFTWARE.
 *
 * MICROCHIP PROVIDES THIS SOFTWARE CONDITIONALLY UPON YOUR ACCEPTANCE OF THESE 
 * TERMS. 
 */

/* 
 * File:   
 * Author: 
 * Comments:
 * Revision history: 
 */

// This is a guard condition so that contents of this file are not included
// more than once.  
#ifndef APP_CONFIG_H
#define	APP_CONFIG_H

// *****************************************************************************
// *****************************************************************************
// Section: User configurable application level parameters
// *****************************************************************************
// *****************************************************************************




// Set to true to have firmware dump data to uart in form suitable for MPLAB DV plugin
#define DATA_VISUALIZER_BUILD  true

#define MPDV_START_OF_FRAME     0xA5U   // Frame header byte for MPLAB DV

// IMU sampling rate in Hz
// For BMI160:
//  Use one of 25, 50, 100, 200, 400, 800, or 1600
// For ICM42688:
//  Use one of 25, 50, 100, 200, 500
// !NB! Increasing the sample rate above 200Hz with all 6 axes may cause buffer overruns
// Change at your own risk!
#define SNSR_SAMPLE_RATE        100

#define SNSR_BUF_LEN            256

// For data visualizer, stream sensor data type natively
#if DATA_VISUALIZER_BUILD
#define SNSR_DATA_TYPE          int16_t

#endif

// Define which axes from the IMU to use
#define SNSR_USE_ACCEL_X        true
#define SNSR_USE_ACCEL_Y        true
#define SNSR_USE_ACCEL_Z        true
#define SNSR_USE_GYRO_X         false
#define SNSR_USE_GYRO_Y         false
#define SNSR_USE_GYRO_Z         false


#define RING_BUF_LEN            SNSR_BUF_LEN


// LED tick rate parameters
#define TICK_RATE_FAST          100
#define TICK_RATE_SLOW          500

// *****************************************************************************
// *****************************************************************************
// Section: Defines derived from user config parameters
// *****************************************************************************
// *****************************************************************************
#define SNSR_NUM_AXES   (SNSR_USE_ACCEL_X + SNSR_USE_ACCEL_Y + SNSR_USE_ACCEL_Z \
                            + SNSR_USE_GYRO_X + SNSR_USE_GYRO_Y + SNSR_USE_GYRO_Z)

/* Define whether multiple sensors types are being used */
#define SNSR_USE_GYRO   (SNSR_USE_GYRO_X || SNSR_USE_GYRO_Y || SNSR_USE_GYRO_Z)
#define SNSR_USE_ACCEL  (SNSR_USE_ACCEL_X || SNSR_USE_ACCEL_Y || SNSR_USE_ACCEL_Z)
#if (SNSR_USE_ACCEL && SNSR_USE_GYRO)
    #define MULTI_SENSOR 1
#else
    #define MULTI_SENSOR 0
#endif



#if SNSR_TYPE_BMI160
#define MIKRO_INT_SetInterruptHandler   MIKROA_INT_SetInterruptHandler
#elif SNSR_TYPE_ICM42688
#define MIKRO_INT_SetInterruptHandler   MIKROB_INT_SetInterruptHandler
#endif

// Provide the functions needed by sensor module
#define snsr_read_timer_us read_timer_us
#define snsr_read_timer_ms read_timer_ms
#define snsr_sleep_ms      sleep_ms
#define snsr_sleep_us      sleep_us

// Some convenience macros
#define BUTTON_S1_IsPressed() (BUTTON_S1_GetValue() == 0)

#define LED_BLUE_On     LED_BLUE_SetHigh
#define LED_BLUE_Off    LED_BLUE_SetLow
#define LED_GREEN_On    LED_GREEN_SetHigh
#define LED_GREEN_Off   LED_GREEN_SetLow
#define LED_RED_On      LED_RED_SetHigh
#define LED_RED_Off     LED_RED_SetLow

#ifdef	__cplusplus
extern "C" {
#endif /* __cplusplus */
    
#ifdef	__cplusplus
}
#endif /* __cplusplus */

#endif	/* APP_CONFIG_H */

