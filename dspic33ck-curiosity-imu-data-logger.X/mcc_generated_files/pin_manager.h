/**
  PIN MANAGER Generated Driver File

  @Company:
    Microchip Technology Inc.

  @File Name:
    pin_manager.h

  @Summary:
    This is the generated manager file for the PIC24 / dsPIC33 / PIC32MM MCUs device.  This manager
    configures the pins direction, initial state, analog setting.
    The peripheral pin select, PPS, configuration is also handled by this manager.

  @Description:
    This source file provides implementations for PIN MANAGER.
    Generation Information :
        Product Revision  :  PIC24 / dsPIC33 / PIC32MM MCUs - 1.169.0
        Device            :  dsPIC33CK256MP508
    The generated drivers are tested against the following:
        Compiler          :  XC16 v1.50
        MPLAB 	          :  MPLAB X v5.40
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

#ifndef _PIN_MANAGER_H
#define _PIN_MANAGER_H
/**
    Section: Includes
*/
#include <xc.h>

/**
    Section: Device Pin Macros
*/
/**
  @Summary
    Sets the GPIO pin, RD2, high using LATD2.

  @Description
    Sets the GPIO pin, RD2, high using LATD2.

  @Preconditions
    The RD2 must be set to an output.

  @Returns
    None.

  @Param
    None.

  @Example
    <code>
    // Set RD2 high (1)
    MIKROA_CS_SetHigh();
    </code>

*/
#define MIKROA_CS_SetHigh()          (_LATD2 = 1)
/**
  @Summary
    Sets the GPIO pin, RD2, low using LATD2.

  @Description
    Sets the GPIO pin, RD2, low using LATD2.

  @Preconditions
    The RD2 must be set to an output.

  @Returns
    None.

  @Param
    None.

  @Example
    <code>
    // Set RD2 low (0)
    MIKROA_CS_SetLow();
    </code>

*/
#define MIKROA_CS_SetLow()           (_LATD2 = 0)
/**
  @Summary
    Toggles the GPIO pin, RD2, using LATD2.

  @Description
    Toggles the GPIO pin, RD2, using LATD2.

  @Preconditions
    The RD2 must be set to an output.

  @Returns
    None.

  @Param
    None.

  @Example
    <code>
    // Toggle RD2
    MIKROA_CS_Toggle();
    </code>

*/
#define MIKROA_CS_Toggle()           (_LATD2 ^= 1)
/**
  @Summary
    Reads the value of the GPIO pin, RD2.

  @Description
    Reads the value of the GPIO pin, RD2.

  @Preconditions
    None.

  @Returns
    None.

  @Param
    None.

  @Example
    <code>
    uint16_t portValue;

    // Read RD2
    postValue = MIKROA_CS_GetValue();
    </code>

*/
#define MIKROA_CS_GetValue()         _RD2
/**
  @Summary
    Configures the GPIO pin, RD2, as an input.

  @Description
    Configures the GPIO pin, RD2, as an input.

  @Preconditions
    None.

  @Returns
    None.

  @Param
    None.

  @Example
    <code>
    // Sets the RD2 as an input
    MIKROA_CS_SetDigitalInput();
    </code>

*/
#define MIKROA_CS_SetDigitalInput()  (_TRISD2 = 1)
/**
  @Summary
    Configures the GPIO pin, RD2, as an output.

  @Description
    Configures the GPIO pin, RD2, as an output.

  @Preconditions
    None.

  @Returns
    None.

  @Param
    None.

  @Example
    <code>
    // Sets the RD2 as an output
    MIKROA_CS_SetDigitalOutput();
    </code>

*/
#define MIKROA_CS_SetDigitalOutput() (_TRISD2 = 0)
/**
  @Summary
    Sets the GPIO pin, RD6, high using LATD6.

  @Description
    Sets the GPIO pin, RD6, high using LATD6.

  @Preconditions
    The RD6 must be set to an output.

  @Returns
    None.

  @Param
    None.

  @Example
    <code>
    // Set RD6 high (1)
    SDO1_SetHigh();
    </code>

*/
#define SDO1_SetHigh()          (_LATD6 = 1)
/**
  @Summary
    Sets the GPIO pin, RD6, low using LATD6.

  @Description
    Sets the GPIO pin, RD6, low using LATD6.

  @Preconditions
    The RD6 must be set to an output.

  @Returns
    None.

  @Param
    None.

  @Example
    <code>
    // Set RD6 low (0)
    SDO1_SetLow();
    </code>

*/
#define SDO1_SetLow()           (_LATD6 = 0)
/**
  @Summary
    Toggles the GPIO pin, RD6, using LATD6.

  @Description
    Toggles the GPIO pin, RD6, using LATD6.

  @Preconditions
    The RD6 must be set to an output.

  @Returns
    None.

  @Param
    None.

  @Example
    <code>
    // Toggle RD6
    SDO1_Toggle();
    </code>

*/
#define SDO1_Toggle()           (_LATD6 ^= 1)
/**
  @Summary
    Reads the value of the GPIO pin, RD6.

  @Description
    Reads the value of the GPIO pin, RD6.

  @Preconditions
    None.

  @Returns
    None.

  @Param
    None.

  @Example
    <code>
    uint16_t portValue;

    // Read RD6
    postValue = SDO1_GetValue();
    </code>

*/
#define SDO1_GetValue()         _RD6
/**
  @Summary
    Configures the GPIO pin, RD6, as an input.

  @Description
    Configures the GPIO pin, RD6, as an input.

  @Preconditions
    None.

  @Returns
    None.

  @Param
    None.

  @Example
    <code>
    // Sets the RD6 as an input
    SDO1_SetDigitalInput();
    </code>

*/
#define SDO1_SetDigitalInput()  (_TRISD6 = 1)
/**
  @Summary
    Configures the GPIO pin, RD6, as an output.

  @Description
    Configures the GPIO pin, RD6, as an output.

  @Preconditions
    None.

  @Returns
    None.

  @Param
    None.

  @Example
    <code>
    // Sets the RD6 as an output
    SDO1_SetDigitalOutput();
    </code>

*/
#define SDO1_SetDigitalOutput() (_TRISD6 = 0)
/**
  @Summary
    Sets the GPIO pin, RD7, high using LATD7.

  @Description
    Sets the GPIO pin, RD7, high using LATD7.

  @Preconditions
    The RD7 must be set to an output.

  @Returns
    None.

  @Param
    None.

  @Example
    <code>
    // Set RD7 high (1)
    SDI1_SetHigh();
    </code>

*/
#define SDI1_SetHigh()          (_LATD7 = 1)
/**
  @Summary
    Sets the GPIO pin, RD7, low using LATD7.

  @Description
    Sets the GPIO pin, RD7, low using LATD7.

  @Preconditions
    The RD7 must be set to an output.

  @Returns
    None.

  @Param
    None.

  @Example
    <code>
    // Set RD7 low (0)
    SDI1_SetLow();
    </code>

*/
#define SDI1_SetLow()           (_LATD7 = 0)
/**
  @Summary
    Toggles the GPIO pin, RD7, using LATD7.

  @Description
    Toggles the GPIO pin, RD7, using LATD7.

  @Preconditions
    The RD7 must be set to an output.

  @Returns
    None.

  @Param
    None.

  @Example
    <code>
    // Toggle RD7
    SDI1_Toggle();
    </code>

*/
#define SDI1_Toggle()           (_LATD7 ^= 1)
/**
  @Summary
    Reads the value of the GPIO pin, RD7.

  @Description
    Reads the value of the GPIO pin, RD7.

  @Preconditions
    None.

  @Returns
    None.

  @Param
    None.

  @Example
    <code>
    uint16_t portValue;

    // Read RD7
    postValue = SDI1_GetValue();
    </code>

*/
#define SDI1_GetValue()         _RD7
/**
  @Summary
    Configures the GPIO pin, RD7, as an input.

  @Description
    Configures the GPIO pin, RD7, as an input.

  @Preconditions
    None.

  @Returns
    None.

  @Param
    None.

  @Example
    <code>
    // Sets the RD7 as an input
    SDI1_SetDigitalInput();
    </code>

*/
#define SDI1_SetDigitalInput()  (_TRISD7 = 1)
/**
  @Summary
    Configures the GPIO pin, RD7, as an output.

  @Description
    Configures the GPIO pin, RD7, as an output.

  @Preconditions
    None.

  @Returns
    None.

  @Param
    None.

  @Example
    <code>
    // Sets the RD7 as an output
    SDI1_SetDigitalOutput();
    </code>

*/
#define SDI1_SetDigitalOutput() (_TRISD7 = 0)
/**
  @Summary
    Sets the GPIO pin, RD8, high using LATD8.

  @Description
    Sets the GPIO pin, RD8, high using LATD8.

  @Preconditions
    The RD8 must be set to an output.

  @Returns
    None.

  @Param
    None.

  @Example
    <code>
    // Set RD8 high (1)
    SCK1OUT_SetHigh();
    </code>

*/
#define SCK1OUT_SetHigh()          (_LATD8 = 1)
/**
  @Summary
    Sets the GPIO pin, RD8, low using LATD8.

  @Description
    Sets the GPIO pin, RD8, low using LATD8.

  @Preconditions
    The RD8 must be set to an output.

  @Returns
    None.

  @Param
    None.

  @Example
    <code>
    // Set RD8 low (0)
    SCK1OUT_SetLow();
    </code>

*/
#define SCK1OUT_SetLow()           (_LATD8 = 0)
/**
  @Summary
    Toggles the GPIO pin, RD8, using LATD8.

  @Description
    Toggles the GPIO pin, RD8, using LATD8.

  @Preconditions
    The RD8 must be set to an output.

  @Returns
    None.

  @Param
    None.

  @Example
    <code>
    // Toggle RD8
    SCK1OUT_Toggle();
    </code>

*/
#define SCK1OUT_Toggle()           (_LATD8 ^= 1)
/**
  @Summary
    Reads the value of the GPIO pin, RD8.

  @Description
    Reads the value of the GPIO pin, RD8.

  @Preconditions
    None.

  @Returns
    None.

  @Param
    None.

  @Example
    <code>
    uint16_t portValue;

    // Read RD8
    postValue = SCK1OUT_GetValue();
    </code>

*/
#define SCK1OUT_GetValue()         _RD8
/**
  @Summary
    Configures the GPIO pin, RD8, as an input.

  @Description
    Configures the GPIO pin, RD8, as an input.

  @Preconditions
    None.

  @Returns
    None.

  @Param
    None.

  @Example
    <code>
    // Sets the RD8 as an input
    SCK1OUT_SetDigitalInput();
    </code>

*/
#define SCK1OUT_SetDigitalInput()  (_TRISD8 = 1)
/**
  @Summary
    Configures the GPIO pin, RD8, as an output.

  @Description
    Configures the GPIO pin, RD8, as an output.

  @Preconditions
    None.

  @Returns
    None.

  @Param
    None.

  @Example
    <code>
    // Sets the RD8 as an output
    SCK1OUT_SetDigitalOutput();
    </code>

*/
#define SCK1OUT_SetDigitalOutput() (_TRISD8 = 0)
/**
  @Summary
    Sets the GPIO pin, RE10, high using LATE10.

  @Description
    Sets the GPIO pin, RE10, high using LATE10.

  @Preconditions
    The RE10 must be set to an output.

  @Returns
    None.

  @Param
    None.

  @Example
    <code>
    // Set RE10 high (1)
    MIKROB_CS_SetHigh();
    </code>

*/
#define MIKROB_CS_SetHigh()          (_LATE10 = 1)
/**
  @Summary
    Sets the GPIO pin, RE10, low using LATE10.

  @Description
    Sets the GPIO pin, RE10, low using LATE10.

  @Preconditions
    The RE10 must be set to an output.

  @Returns
    None.

  @Param
    None.

  @Example
    <code>
    // Set RE10 low (0)
    MIKROB_CS_SetLow();
    </code>

*/
#define MIKROB_CS_SetLow()           (_LATE10 = 0)
/**
  @Summary
    Toggles the GPIO pin, RE10, using LATE10.

  @Description
    Toggles the GPIO pin, RE10, using LATE10.

  @Preconditions
    The RE10 must be set to an output.

  @Returns
    None.

  @Param
    None.

  @Example
    <code>
    // Toggle RE10
    MIKROB_CS_Toggle();
    </code>

*/
#define MIKROB_CS_Toggle()           (_LATE10 ^= 1)
/**
  @Summary
    Reads the value of the GPIO pin, RE10.

  @Description
    Reads the value of the GPIO pin, RE10.

  @Preconditions
    None.

  @Returns
    None.

  @Param
    None.

  @Example
    <code>
    uint16_t portValue;

    // Read RE10
    postValue = MIKROB_CS_GetValue();
    </code>

*/
#define MIKROB_CS_GetValue()         _RE10
/**
  @Summary
    Configures the GPIO pin, RE10, as an input.

  @Description
    Configures the GPIO pin, RE10, as an input.

  @Preconditions
    None.

  @Returns
    None.

  @Param
    None.

  @Example
    <code>
    // Sets the RE10 as an input
    MIKROB_CS_SetDigitalInput();
    </code>

*/
#define MIKROB_CS_SetDigitalInput()  (_TRISE10 = 1)
/**
  @Summary
    Configures the GPIO pin, RE10, as an output.

  @Description
    Configures the GPIO pin, RE10, as an output.

  @Preconditions
    None.

  @Returns
    None.

  @Param
    None.

  @Example
    <code>
    // Sets the RE10 as an output
    MIKROB_CS_SetDigitalOutput();
    </code>

*/
#define MIKROB_CS_SetDigitalOutput() (_TRISE10 = 0)
/**
  @Summary
    Sets the GPIO pin, RE11, high using LATE11.

  @Description
    Sets the GPIO pin, RE11, high using LATE11.

  @Preconditions
    The RE11 must be set to an output.

  @Returns
    None.

  @Param
    None.

  @Example
    <code>
    // Set RE11 high (1)
    MIKROA_INT_SetHigh();
    </code>

*/
#define MIKROA_INT_SetHigh()          (_LATE11 = 1)
/**
  @Summary
    Sets the GPIO pin, RE11, low using LATE11.

  @Description
    Sets the GPIO pin, RE11, low using LATE11.

  @Preconditions
    The RE11 must be set to an output.

  @Returns
    None.

  @Param
    None.

  @Example
    <code>
    // Set RE11 low (0)
    MIKROA_INT_SetLow();
    </code>

*/
#define MIKROA_INT_SetLow()           (_LATE11 = 0)
/**
  @Summary
    Toggles the GPIO pin, RE11, using LATE11.

  @Description
    Toggles the GPIO pin, RE11, using LATE11.

  @Preconditions
    The RE11 must be set to an output.

  @Returns
    None.

  @Param
    None.

  @Example
    <code>
    // Toggle RE11
    MIKROA_INT_Toggle();
    </code>

*/
#define MIKROA_INT_Toggle()           (_LATE11 ^= 1)
/**
  @Summary
    Reads the value of the GPIO pin, RE11.

  @Description
    Reads the value of the GPIO pin, RE11.

  @Preconditions
    None.

  @Returns
    None.

  @Param
    None.

  @Example
    <code>
    uint16_t portValue;

    // Read RE11
    postValue = MIKROA_INT_GetValue();
    </code>

*/
#define MIKROA_INT_GetValue()         _RE11
/**
  @Summary
    Configures the GPIO pin, RE11, as an input.

  @Description
    Configures the GPIO pin, RE11, as an input.

  @Preconditions
    None.

  @Returns
    None.

  @Param
    None.

  @Example
    <code>
    // Sets the RE11 as an input
    MIKROA_INT_SetDigitalInput();
    </code>

*/
#define MIKROA_INT_SetDigitalInput()  (_TRISE11 = 1)
/**
  @Summary
    Configures the GPIO pin, RE11, as an output.

  @Description
    Configures the GPIO pin, RE11, as an output.

  @Preconditions
    None.

  @Returns
    None.

  @Param
    None.

  @Example
    <code>
    // Sets the RE11 as an output
    MIKROA_INT_SetDigitalOutput();
    </code>

*/
#define MIKROA_INT_SetDigitalOutput() (_TRISE11 = 0)
/**
  @Summary
    Sets the GPIO pin, RE12, high using LATE12.

  @Description
    Sets the GPIO pin, RE12, high using LATE12.

  @Preconditions
    The RE12 must be set to an output.

  @Returns
    None.

  @Param
    None.

  @Example
    <code>
    // Set RE12 high (1)
    MIKROB_INT_SetHigh();
    </code>

*/
#define MIKROB_INT_SetHigh()          (_LATE12 = 1)
/**
  @Summary
    Sets the GPIO pin, RE12, low using LATE12.

  @Description
    Sets the GPIO pin, RE12, low using LATE12.

  @Preconditions
    The RE12 must be set to an output.

  @Returns
    None.

  @Param
    None.

  @Example
    <code>
    // Set RE12 low (0)
    MIKROB_INT_SetLow();
    </code>

*/
#define MIKROB_INT_SetLow()           (_LATE12 = 0)
/**
  @Summary
    Toggles the GPIO pin, RE12, using LATE12.

  @Description
    Toggles the GPIO pin, RE12, using LATE12.

  @Preconditions
    The RE12 must be set to an output.

  @Returns
    None.

  @Param
    None.

  @Example
    <code>
    // Toggle RE12
    MIKROB_INT_Toggle();
    </code>

*/
#define MIKROB_INT_Toggle()           (_LATE12 ^= 1)
/**
  @Summary
    Reads the value of the GPIO pin, RE12.

  @Description
    Reads the value of the GPIO pin, RE12.

  @Preconditions
    None.

  @Returns
    None.

  @Param
    None.

  @Example
    <code>
    uint16_t portValue;

    // Read RE12
    postValue = MIKROB_INT_GetValue();
    </code>

*/
#define MIKROB_INT_GetValue()         _RE12
/**
  @Summary
    Configures the GPIO pin, RE12, as an input.

  @Description
    Configures the GPIO pin, RE12, as an input.

  @Preconditions
    None.

  @Returns
    None.

  @Param
    None.

  @Example
    <code>
    // Sets the RE12 as an input
    MIKROB_INT_SetDigitalInput();
    </code>

*/
#define MIKROB_INT_SetDigitalInput()  (_TRISE12 = 1)
/**
  @Summary
    Configures the GPIO pin, RE12, as an output.

  @Description
    Configures the GPIO pin, RE12, as an output.

  @Preconditions
    None.

  @Returns
    None.

  @Param
    None.

  @Example
    <code>
    // Sets the RE12 as an output
    MIKROB_INT_SetDigitalOutput();
    </code>

*/
#define MIKROB_INT_SetDigitalOutput() (_TRISE12 = 0)
/**
  @Summary
    Sets the GPIO pin, RE13, high using LATE13.

  @Description
    Sets the GPIO pin, RE13, high using LATE13.

  @Preconditions
    The RE13 must be set to an output.

  @Returns
    None.

  @Param
    None.

  @Example
    <code>
    // Set RE13 high (1)
    LED_BLUE_SetHigh();
    </code>

*/
#define LED_BLUE_SetHigh()          (_LATE13 = 1)
/**
  @Summary
    Sets the GPIO pin, RE13, low using LATE13.

  @Description
    Sets the GPIO pin, RE13, low using LATE13.

  @Preconditions
    The RE13 must be set to an output.

  @Returns
    None.

  @Param
    None.

  @Example
    <code>
    // Set RE13 low (0)
    LED_BLUE_SetLow();
    </code>

*/
#define LED_BLUE_SetLow()           (_LATE13 = 0)
/**
  @Summary
    Toggles the GPIO pin, RE13, using LATE13.

  @Description
    Toggles the GPIO pin, RE13, using LATE13.

  @Preconditions
    The RE13 must be set to an output.

  @Returns
    None.

  @Param
    None.

  @Example
    <code>
    // Toggle RE13
    LED_BLUE_Toggle();
    </code>

*/
#define LED_BLUE_Toggle()           (_LATE13 ^= 1)
/**
  @Summary
    Reads the value of the GPIO pin, RE13.

  @Description
    Reads the value of the GPIO pin, RE13.

  @Preconditions
    None.

  @Returns
    None.

  @Param
    None.

  @Example
    <code>
    uint16_t portValue;

    // Read RE13
    postValue = LED_BLUE_GetValue();
    </code>

*/
#define LED_BLUE_GetValue()         _RE13
/**
  @Summary
    Configures the GPIO pin, RE13, as an input.

  @Description
    Configures the GPIO pin, RE13, as an input.

  @Preconditions
    None.

  @Returns
    None.

  @Param
    None.

  @Example
    <code>
    // Sets the RE13 as an input
    LED_BLUE_SetDigitalInput();
    </code>

*/
#define LED_BLUE_SetDigitalInput()  (_TRISE13 = 1)
/**
  @Summary
    Configures the GPIO pin, RE13, as an output.

  @Description
    Configures the GPIO pin, RE13, as an output.

  @Preconditions
    None.

  @Returns
    None.

  @Param
    None.

  @Example
    <code>
    // Sets the RE13 as an output
    LED_BLUE_SetDigitalOutput();
    </code>

*/
#define LED_BLUE_SetDigitalOutput() (_TRISE13 = 0)
/**
  @Summary
    Sets the GPIO pin, RE14, high using LATE14.

  @Description
    Sets the GPIO pin, RE14, high using LATE14.

  @Preconditions
    The RE14 must be set to an output.

  @Returns
    None.

  @Param
    None.

  @Example
    <code>
    // Set RE14 high (1)
    LED_GREEN_SetHigh();
    </code>

*/
#define LED_GREEN_SetHigh()          (_LATE14 = 1)
/**
  @Summary
    Sets the GPIO pin, RE14, low using LATE14.

  @Description
    Sets the GPIO pin, RE14, low using LATE14.

  @Preconditions
    The RE14 must be set to an output.

  @Returns
    None.

  @Param
    None.

  @Example
    <code>
    // Set RE14 low (0)
    LED_GREEN_SetLow();
    </code>

*/
#define LED_GREEN_SetLow()           (_LATE14 = 0)
/**
  @Summary
    Toggles the GPIO pin, RE14, using LATE14.

  @Description
    Toggles the GPIO pin, RE14, using LATE14.

  @Preconditions
    The RE14 must be set to an output.

  @Returns
    None.

  @Param
    None.

  @Example
    <code>
    // Toggle RE14
    LED_GREEN_Toggle();
    </code>

*/
#define LED_GREEN_Toggle()           (_LATE14 ^= 1)
/**
  @Summary
    Reads the value of the GPIO pin, RE14.

  @Description
    Reads the value of the GPIO pin, RE14.

  @Preconditions
    None.

  @Returns
    None.

  @Param
    None.

  @Example
    <code>
    uint16_t portValue;

    // Read RE14
    postValue = LED_GREEN_GetValue();
    </code>

*/
#define LED_GREEN_GetValue()         _RE14
/**
  @Summary
    Configures the GPIO pin, RE14, as an input.

  @Description
    Configures the GPIO pin, RE14, as an input.

  @Preconditions
    None.

  @Returns
    None.

  @Param
    None.

  @Example
    <code>
    // Sets the RE14 as an input
    LED_GREEN_SetDigitalInput();
    </code>

*/
#define LED_GREEN_SetDigitalInput()  (_TRISE14 = 1)
/**
  @Summary
    Configures the GPIO pin, RE14, as an output.

  @Description
    Configures the GPIO pin, RE14, as an output.

  @Preconditions
    None.

  @Returns
    None.

  @Param
    None.

  @Example
    <code>
    // Sets the RE14 as an output
    LED_GREEN_SetDigitalOutput();
    </code>

*/
#define LED_GREEN_SetDigitalOutput() (_TRISE14 = 0)
/**
  @Summary
    Sets the GPIO pin, RE15, high using LATE15.

  @Description
    Sets the GPIO pin, RE15, high using LATE15.

  @Preconditions
    The RE15 must be set to an output.

  @Returns
    None.

  @Param
    None.

  @Example
    <code>
    // Set RE15 high (1)
    LED_RED_SetHigh();
    </code>

*/
#define LED_RED_SetHigh()          (_LATE15 = 1)
/**
  @Summary
    Sets the GPIO pin, RE15, low using LATE15.

  @Description
    Sets the GPIO pin, RE15, low using LATE15.

  @Preconditions
    The RE15 must be set to an output.

  @Returns
    None.

  @Param
    None.

  @Example
    <code>
    // Set RE15 low (0)
    LED_RED_SetLow();
    </code>

*/
#define LED_RED_SetLow()           (_LATE15 = 0)
/**
  @Summary
    Toggles the GPIO pin, RE15, using LATE15.

  @Description
    Toggles the GPIO pin, RE15, using LATE15.

  @Preconditions
    The RE15 must be set to an output.

  @Returns
    None.

  @Param
    None.

  @Example
    <code>
    // Toggle RE15
    LED_RED_Toggle();
    </code>

*/
#define LED_RED_Toggle()           (_LATE15 ^= 1)
/**
  @Summary
    Reads the value of the GPIO pin, RE15.

  @Description
    Reads the value of the GPIO pin, RE15.

  @Preconditions
    None.

  @Returns
    None.

  @Param
    None.

  @Example
    <code>
    uint16_t portValue;

    // Read RE15
    postValue = LED_RED_GetValue();
    </code>

*/
#define LED_RED_GetValue()         _RE15
/**
  @Summary
    Configures the GPIO pin, RE15, as an input.

  @Description
    Configures the GPIO pin, RE15, as an input.

  @Preconditions
    None.

  @Returns
    None.

  @Param
    None.

  @Example
    <code>
    // Sets the RE15 as an input
    LED_RED_SetDigitalInput();
    </code>

*/
#define LED_RED_SetDigitalInput()  (_TRISE15 = 1)
/**
  @Summary
    Configures the GPIO pin, RE15, as an output.

  @Description
    Configures the GPIO pin, RE15, as an output.

  @Preconditions
    None.

  @Returns
    None.

  @Param
    None.

  @Example
    <code>
    // Sets the RE15 as an output
    LED_RED_SetDigitalOutput();
    </code>

*/
#define LED_RED_SetDigitalOutput() (_TRISE15 = 0)
/**
  @Summary
    Sets the GPIO pin, RE7, high using LATE7.

  @Description
    Sets the GPIO pin, RE7, high using LATE7.

  @Preconditions
    The RE7 must be set to an output.

  @Returns
    None.

  @Param
    None.

  @Example
    <code>
    // Set RE7 high (1)
    BUTTON_S1_SetHigh();
    </code>

*/
#define BUTTON_S1_SetHigh()          (_LATE7 = 1)
/**
  @Summary
    Sets the GPIO pin, RE7, low using LATE7.

  @Description
    Sets the GPIO pin, RE7, low using LATE7.

  @Preconditions
    The RE7 must be set to an output.

  @Returns
    None.

  @Param
    None.

  @Example
    <code>
    // Set RE7 low (0)
    BUTTON_S1_SetLow();
    </code>

*/
#define BUTTON_S1_SetLow()           (_LATE7 = 0)
/**
  @Summary
    Toggles the GPIO pin, RE7, using LATE7.

  @Description
    Toggles the GPIO pin, RE7, using LATE7.

  @Preconditions
    The RE7 must be set to an output.

  @Returns
    None.

  @Param
    None.

  @Example
    <code>
    // Toggle RE7
    BUTTON_S1_Toggle();
    </code>

*/
#define BUTTON_S1_Toggle()           (_LATE7 ^= 1)
/**
  @Summary
    Reads the value of the GPIO pin, RE7.

  @Description
    Reads the value of the GPIO pin, RE7.

  @Preconditions
    None.

  @Returns
    None.

  @Param
    None.

  @Example
    <code>
    uint16_t portValue;

    // Read RE7
    postValue = BUTTON_S1_GetValue();
    </code>

*/
#define BUTTON_S1_GetValue()         _RE7
/**
  @Summary
    Configures the GPIO pin, RE7, as an input.

  @Description
    Configures the GPIO pin, RE7, as an input.

  @Preconditions
    None.

  @Returns
    None.

  @Param
    None.

  @Example
    <code>
    // Sets the RE7 as an input
    BUTTON_S1_SetDigitalInput();
    </code>

*/
#define BUTTON_S1_SetDigitalInput()  (_TRISE7 = 1)
/**
  @Summary
    Configures the GPIO pin, RE7, as an output.

  @Description
    Configures the GPIO pin, RE7, as an output.

  @Preconditions
    None.

  @Returns
    None.

  @Param
    None.

  @Example
    <code>
    // Sets the RE7 as an output
    BUTTON_S1_SetDigitalOutput();
    </code>

*/
#define BUTTON_S1_SetDigitalOutput() (_TRISE7 = 0)

/**
    Section: Function Prototypes
*/
/**
  @Summary
    Configures the pin settings of the dsPIC33CK256MP508
    The peripheral pin select, PPS, configuration is also handled by this manager.

  @Description
    This is the generated manager file for the PIC24 / dsPIC33 / PIC32MM MCUs device.  This manager
    configures the pins direction, initial state, analog setting.
    The peripheral pin select, PPS, configuration is also handled by this manager.

  @Preconditions
    None.

  @Returns
    None.

  @Param
    None.

  @Example
    <code>
    void SYSTEM_Initialize(void)
    {
        // Other initializers are called from this function
        PIN_MANAGER_Initialize();
    }
    </code>

*/
void PIN_MANAGER_Initialize (void);

/**
  @Summary
    Callback for MIKROA_INT Pin.

  @Description
    This routine is callback for MIKROA_INT Pin

  @Param
    None.

  @Returns
    None
 
 
  @Example 
    <code>
        MIKROA_INT_SetInterruptHandler(&MIKROA_INT_CallBack);
    </code>
*/
void MIKROA_INT_CallBack(void);

/**
  @Summary
    Callback for MIKROB_INT Pin.

  @Description
    This routine is callback for MIKROB_INT Pin

  @Param
    None.

  @Returns
    None
 
 
  @Example 
    <code>
        MIKROB_INT_SetInterruptHandler(&MIKROB_INT_CallBack);
    </code>
*/
void MIKROB_INT_CallBack(void);


/**
  @Summary
    Assigns a function pointer with a callback address.

  @Description
    This routine assigns a function pointer with a callback address.

  @Param
    Address of the callback routine.

  @Returns
    None
 
  @Example 
    <code>
        MIKROA_INT_SetInterruptHandler(&MIKROA_INT_CallBack);
    </code>
*/
void MIKROA_INT_SetInterruptHandler(void (* InterruptHandler)(void));

/**
  @Summary
    Assigns a function pointer with a callback address.

  @Description
    This routine assigns a function pointer with a callback address.

  @Param
    Address of the callback routine.

  @Returns
    None
 
  @Example 
    <code>
        MIKROA_INT_SetIOCInterruptHandler(&MIKROA_INT_CallBack);
    </code>
*/
void __attribute__((deprecated("\nThis will be removed in future MCC releases. \nUse MIKROA_INT_SetInterruptHandler instead."))) MIKROA_INT_SetIOCInterruptHandler(void *handler);

/**
  @Summary
    Assigns a function pointer with a callback address.

  @Description
    This routine assigns a function pointer with a callback address.

  @Param
    Address of the callback routine.

  @Returns
    None
 
  @Example 
    <code>
        MIKROB_INT_SetInterruptHandler(&MIKROB_INT_CallBack);
    </code>
*/
void MIKROB_INT_SetInterruptHandler(void (* InterruptHandler)(void));

/**
  @Summary
    Assigns a function pointer with a callback address.

  @Description
    This routine assigns a function pointer with a callback address.

  @Param
    Address of the callback routine.

  @Returns
    None
 
  @Example 
    <code>
        MIKROB_INT_SetIOCInterruptHandler(&MIKROB_INT_CallBack);
    </code>
*/
void __attribute__((deprecated("\nThis will be removed in future MCC releases. \nUse MIKROB_INT_SetInterruptHandler instead."))) MIKROB_INT_SetIOCInterruptHandler(void *handler);


#endif
