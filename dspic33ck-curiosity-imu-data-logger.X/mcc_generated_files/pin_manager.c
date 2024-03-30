/**
  PIN MANAGER Generated Driver File

  @Company:
    Microchip Technology Inc.

  @File Name:
    pin_manager.c

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


/**
    Section: Includes
*/

#include <xc.h>
#include <stdio.h>
#include "pin_manager.h"

/**
 Section: File specific functions
*/
void (*MIKROA_INT_InterruptHandler)(void) = NULL;
void (*MIKROB_INT_InterruptHandler)(void) = NULL;

/**
 Section: Driver Interface Function Definitions
*/
void PIN_MANAGER_Initialize (void)
{
    /****************************************************************************
     * Setting the Output Latch SFR(s)
     ***************************************************************************/
    LATA = 0x0000;
    LATB = 0x0000;
    LATC = 0x0000;
    LATD = 0x0010;
    LATE = 0x0000;

    /****************************************************************************
     * Setting the GPIO Direction SFR(s)
     ***************************************************************************/
    TRISA = 0x001F;
    TRISB = 0xFFFD;
    TRISC = 0xFFFF;
    TRISD = 0xFFAB;
    TRISE = 0x1BFF;

    /****************************************************************************
     * Setting the Weak Pull Up and Weak Pull Down SFR(s)
     ***************************************************************************/
    CNPDA = 0x0000;
    CNPDB = 0x0000;
    CNPDC = 0x0000;
    CNPDD = 0x0000;
    CNPDE = 0x0000;
    CNPUA = 0x0000;
    CNPUB = 0x0000;
    CNPUC = 0x0000;
    CNPUD = 0x0000;
    CNPUE = 0x0000;

    /****************************************************************************
     * Setting the Open Drain SFR(s)
     ***************************************************************************/
    ODCA = 0x0000;
    ODCB = 0x0000;
    ODCC = 0x0000;
    ODCD = 0x0000;
    ODCE = 0x0000;

    /****************************************************************************
     * Setting the Analog/Digital Configuration SFR(s)
     ***************************************************************************/
    ANSELA = 0x001F;
    ANSELB = 0x039C;
    ANSELC = 0x00CF;
    ANSELD = 0x2C00;
    ANSELE = 0x000F;
    
    /****************************************************************************
     * Set the PPS
     ***************************************************************************/
    __builtin_write_RPCON(0x0000); // unlock PPS

    RPINR20bits.SCK1R = 0x0048;    //RD8->SPI1:SCK1OUT
    RPINR20bits.SDI1R = 0x0047;    //RD7->SPI1:SDI1
    RPINR18bits.U1RXR = 0x0043;    //RD3->UART1:U1RX
    RPOR20bits.RP72R = 0x0006;    //RD8->SPI1:SCK1OUT
    RPOR19bits.RP70R = 0x0005;    //RD6->SPI1:SDO1
    RPOR18bits.RP68R = 0x0001;    //RD4->UART1:U1TX

    __builtin_write_RPCON(0x0800); // lock PPS
    
    /****************************************************************************
     * Interrupt On Change: positive
     ***************************************************************************/
    CNEN0Ebits.CNEN0E11 = 1;    //Pin : RE11
    CNEN0Ebits.CNEN0E12 = 1;    //Pin : RE12
    /****************************************************************************
     * Interrupt On Change: flag
     ***************************************************************************/
    CNFEbits.CNFE11 = 0;    //Pin : RE11
    CNFEbits.CNFE12 = 0;    //Pin : RE12
    /****************************************************************************
     * Interrupt On Change: config
     ***************************************************************************/
    CNCONEbits.CNSTYLE = 1;    //Config for PORTE
    CNCONEbits.ON = 1;    //Config for PORTE
    
    /* Initialize IOC Interrupt Handler*/
    MIKROA_INT_SetInterruptHandler(&MIKROA_INT_CallBack);
    MIKROB_INT_SetInterruptHandler(&MIKROB_INT_CallBack);
    
    /****************************************************************************
     * Interrupt On Change: Interrupt Enable
     ***************************************************************************/
    IFS4bits.CNEIF = 0; //Clear CNEI interrupt flag
    IEC4bits.CNEIE = 1; //Enable CNEI interrupt
}

void __attribute__ ((weak)) MIKROA_INT_CallBack(void)
{

}

void __attribute__ ((weak)) MIKROB_INT_CallBack(void)
{

}

void MIKROA_INT_SetInterruptHandler(void (* InterruptHandler)(void))
{ 
    IEC4bits.CNEIE = 0; //Disable CNEI interrupt
    MIKROA_INT_InterruptHandler = InterruptHandler; 
    IEC4bits.CNEIE = 1; //Enable CNEI interrupt
}

void MIKROA_INT_SetIOCInterruptHandler(void *handler)
{ 
    MIKROA_INT_SetInterruptHandler(handler);
}

void MIKROB_INT_SetInterruptHandler(void (* InterruptHandler)(void))
{ 
    IEC4bits.CNEIE = 0; //Disable CNEI interrupt
    MIKROB_INT_InterruptHandler = InterruptHandler; 
    IEC4bits.CNEIE = 1; //Enable CNEI interrupt
}

void MIKROB_INT_SetIOCInterruptHandler(void *handler)
{ 
    MIKROB_INT_SetInterruptHandler(handler);
}

/* Interrupt service routine for the CNEI interrupt. */
void __attribute__ (( interrupt, no_auto_psv )) _CNEInterrupt ( void )
{
    if(IFS4bits.CNEIF == 1)
    {
        if(CNFEbits.CNFE11 == 1)
        {
            if(MIKROA_INT_InterruptHandler) 
            { 
                MIKROA_INT_InterruptHandler(); 
            }
            
            CNFEbits.CNFE11 = 0;  //Clear flag for Pin - RE11

        }
        
        if(CNFEbits.CNFE12 == 1)
        {
            if(MIKROB_INT_InterruptHandler) 
            { 
                MIKROB_INT_InterruptHandler(); 
            }
            
            CNFEbits.CNFE12 = 0;  //Clear flag for Pin - RE12

        }
        
        
        // Clear the flag
        IFS4bits.CNEIF = 0;
    }
}

