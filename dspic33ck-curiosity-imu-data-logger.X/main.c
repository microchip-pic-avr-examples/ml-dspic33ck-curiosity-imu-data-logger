/**
  Generated main.c file from MPLAB Code Configurator

  @Company
    Microchip Technology Inc.

  @File Name
    main.c

  @Summary
    This is the generated main.c using PIC24 / dsPIC33 / PIC32MM MCUs.

  @Description
    This source file provides main entry point for system initialization and application code development.
    Generation Information :
        Product Revision  :  PIC24 / dsPIC33 / PIC32MM MCUs - 1.169.0
        Device            :  dsPIC33CK256MP508
    The generated drivers are tested against the following:
        Compiler          :  XC16 v2.10
        MPLAB 	          :  MPLAB X v6.20
*/

/*
    (c) 2020 Microchip Technology Inc. and its subsidiaries. You may use this
    software and any derivatives exclusively with Microchip products.

    THIS SOFTWARE IS SUPPLIED BY MICROCHIP "AS IS". NO WARRANTIES, WHETHER
    EXPRESS, IMPLIED OR STATUTORY, APPLY TO THIS SOFTWARE, INCLUDING ANY IMPLIED
    WARRANTIES OF NON-INFRINGEMENT, MERCHANTABILITY, AND FITNESS FOR A
    PARTICULAR PURPOSE, OR ITS INTERACTION WITH MICROCHIP PRODUCTS, COMBINATION
    WITH ANY OTHER PRODUCTS, OR USE IN ANY APPLICATION.

    IN NO EVENT WILL MICROCHIP BE LIABLE FOR ANY INDIRECT, SPECIAL, PUNITIVE,
    INCIDENTAL OR CONSEQUENTIAL LOSS, DAMAGE, COST OR EXPENSE OF ANY KIND
    WHATSOEVER RELATED TO THE SOFTWARE, HOWEVER CAUSED, EVEN IF MICROCHIP HAS
    BEEN ADVISED OF THE POSSIBILITY OR THE DAMAGES ARE FORESEEABLE. TO THE
    FULLEST EXTENT ALLOWED BY LAW, MICROCHIP'S TOTAL LIABILITY ON ALL CLAIMS IN
    ANY WAY RELATED TO THIS SOFTWARE WILL NOT EXCEED THE AMOUNT OF FEES, IF ANY,
    THAT YOU HAVE PAID DIRECTLY TO MICROCHIP FOR THIS SOFTWARE.

    MICROCHIP PROVIDES THIS SOFTWARE CONDITIONALLY UPON YOUR ACCEPTANCE OF THESE
    TERMS.
*/

/**
  Section: Included Files
*/
#include <stdio.h>
#include <stdlib.h>
#include "mcc_generated_files/system.h"
#include "mcc_generated_files/tmr1.h"
#include "mcc_generated_files/uart1.h"
#include "mcc_generated_files/pin_manager.h"
#include "app_config.h"
#include "sensor.h"


static int tickrate = 0;
static volatile uint32_t tickcounter = 0;

static struct sensor_device_t sensor;
static struct sensor_buffer_t snsr_buffer;

buffer_data_t ring_buffer[SNSR_BUF_LEN][SNSR_NUM_AXES]; // buffer_data_t neai_buffer[SNSR_BUF_LEN][SNSR_NUM_AXES];

uint64_t read_timer_ms(void) {
    return tickcounter;
}

uint64_t read_timer_us(void) {
    return tickcounter * 1000 + TMR1_Counter16BitGet();
}

void sleep_ms(uint32_t ms) {
    TMR1_Stop();
    TMR1_Counter16BitSet(0);
    tickcounter = 0;
    TMR1_Start();
    while (read_timer_ms() < ms) {};
}

void sleep_us(uint32_t us) {
    TMR1_Stop();
    TMR1_Counter16BitSet(0);
    tickcounter = 0;
    TMR1_Start();
    while (read_timer_us() < us) {};
}

void MSTick_Callback(void) {
    static int mstick = 0;
    
    ++tickcounter;
    if (tickrate == 0) {
        mstick = 0;
    }
    else if (++mstick == tickrate) {
        LED_GREEN_Toggle();
        mstick = 0;
    }
}

// For handling read of the sensor data
void SNSR_ISR_HANDLER(void) {    
    /* Check if any errors we've flagged have been acknowledged */
    if (sensor.status != SNSR_STATUS_OK) {
        return;
    }
    
    sensor.status = sensor_read(&sensor, &snsr_buffer);
}

/*
                         Main application
 */
int main(void)
{
     int ringIdx = 0;

    
    // initialize the device
    SYSTEM_Initialize();
    
    /* Register and start the LED ticker */
    tickrate = 0;
    tickcounter = 0;
    TMR1_SetInterruptHandler(MSTick_Callback);
    TMR1_Start();
    
    /* Register IO Interrupt callback for sensor capture from MikroBus*/
    MIKRO_INT_SetInterruptHandler(SNSR_ISR_HANDLER);
    
    /* Initialize our data buffer */
    buffer_init(&snsr_buffer);

    printf("\r\n");
    
    while (1)
    {    
        if (sensor_init(&sensor) != SNSR_STATUS_OK) {
            printf("sensor init result = %d\r\n", sensor.status);
            break;
        }
        
        if (sensor_set_config(&sensor) != SNSR_STATUS_OK) {
            printf("sensor configuration result = %d\r\n", sensor.status);
            break;
        }
        
        printf("sensor sample rate set at %dHz\r\n", SNSR_SAMPLE_RATE);
        


        break;
    }
    
    tickrate = TICK_RATE_SLOW;
    while (1)
    {
        if (sensor.status != SNSR_STATUS_OK) {
            printf("Got a bad sensor status: %d\r\n", sensor.status);
            break;
        }
        else if (snsr_buffer.overrun == true) {
            printf("\r\n\r\n\r\nOverrun!\r\n\r\n\r\n");
            
            // Light the LEDs to indicate overflow
            tickrate = 0;
            { LED_GREEN_On(); LED_RED_On(); }  // Indicate OVERFLOW
            sleep_ms(5000U);
            { LED_GREEN_Off(); LED_RED_Off(); } // Clear OVERFLOW
            tickrate = TICK_RATE_SLOW;
            
            ringIdx = 0;
            buffer_reset(&snsr_buffer);
            continue;
        }
       
        else {
            // Feed ring buffer
            int rdcnt = buffer_read(&snsr_buffer, &ring_buffer[ringIdx], RING_BUF_LEN - ringIdx);
#if DATA_VISUALIZER_BUILD
            // Send out data as its read
            uint8_t headerbyte = MPDV_START_OF_FRAME;
            uint8_t *ptr = (uint8_t *) &ring_buffer[ringIdx][0];
            for (int i=0; i < rdcnt ; i++) {
                UART1_Write(headerbyte);
                
                for (int j=0; j < sizeof(buffer_frame_t) ; j++) {
                    UART1_Write(*ptr++);
                }
                
                headerbyte = ~headerbyte;
                UART1_Write(headerbyte);
                headerbyte = ~headerbyte;
            }
#endif
            ringIdx += rdcnt; // Update ring  buffer write index
        }
        
        if (ringIdx < RING_BUF_LEN) {
            // Not enough data, keep buffering
            continue;
        }

        
        // Reset the ring buffer
        ringIdx = 0;
    }
    
    tickrate = 0;
    LED_GREEN_Off();
    LED_RED_On();    
    
    while (1) {};
    
    return EXIT_FAILURE;
}
/**
 End of File
*/

