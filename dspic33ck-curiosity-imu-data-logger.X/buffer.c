/*******************************************************************************
  Sensor Buffering Interface Source File

  Company:
    Microchip Technology Inc.

  File Name:
    buffer.c

  Summary:
    This file contains the ring buffer API used for buffering sensor data

  Description:
    This file implements a buffering interface for a 2d array of a single data 
    type with statically allocated memory. The buffer has the behavior that on 
    overrun condition, new incoming data will be ignored until the buffer_reset 
    function is called.
 
  Notes:
    - The API provided here is strictly designed for a single reader thread and 
      single writer thread; other uses will cause race conditions.
    - It's further assumed that the reader will *never* interrupt the writer to 
      call buffer_reset
    - This API does not account for the possibility of out of order
      execution - in such a case memory synchronization primitives must be 
      introduced.
 *******************************************************************************/

/*******************************************************************************
* Copyright (C) 2020 Microchip Technology Inc. and its subsidiaries.
*
* Subject to your compliance with these terms, you may use Microchip software
* and any derivatives exclusively with Microchip products. It is your
* responsibility to comply with third party license terms applicable to your
* use of third party software (including open source software) that may
* accompany Microchip software.
*
* THIS SOFTWARE IS SUPPLIED BY MICROCHIP "AS IS". NO WARRANTIES, WHETHER
* EXPRESS, IMPLIED OR STATUTORY, APPLY TO THIS SOFTWARE, INCLUDING ANY IMPLIED
* WARRANTIES OF NON-INFRINGEMENT, MERCHANTABILITY, AND FITNESS FOR A
* PARTICULAR PURPOSE.
*
* IN NO EVENT WILL MICROCHIP BE LIABLE FOR ANY INDIRECT, SPECIAL, PUNITIVE,
* INCIDENTAL OR CONSEQUENTIAL LOSS, DAMAGE, COST OR EXPENSE OF ANY KIND
* WHATSOEVER RELATED TO THE SOFTWARE, HOWEVER CAUSED, EVEN IF MICROCHIP HAS
* BEEN ADVISED OF THE POSSIBILITY OR THE DAMAGES ARE FORESEEABLE. TO THE
* FULLEST EXTENT ALLOWED BY LAW, MICROCHIP'S TOTAL LIABILITY ON ALL CLAIMS IN
* ANY WAY RELATED TO THIS SOFTWARE WILL NOT EXCEED THE AMOUNT OF FEES, IF ANY,
* THAT YOU HAVE PAID DIRECTLY TO MICROCHIP FOR THIS SOFTWARE.
 *******************************************************************************/

#include <stdbool.h>
#include <string.h>
#include "buffer.h"


void buffer_init(struct sensor_buffer_t *buffer) {
    memset(buffer, 0, sizeof(struct sensor_buffer_t));
}

// Only the reader should call this function, and ONLY if overrun has already occurred
// Furthermore, reader should not be able to interrupt writer to call this function
void buffer_reset(struct sensor_buffer_t *buffer) {
    buffer->overrun = true; // Freeze buffering from the writer while we reset things
    buffer->readIdx = 0;
    buffer->writeIdx = 0;
    memset(buffer->data[0], 0, sizeof(buffer_frame_t));
    buffer->overrun = false;
}

size_t buffer_read(struct sensor_buffer_t *buffer, buffer_data_t dst[][SNSR_NUM_AXES], size_t framecount) {
    size_t writeIdx = buffer->writeIdx;
    size_t readIdx = buffer->readIdx;
    size_t toread = framecount;
    size_t rdcnt;
    
    // Handle wrap around reads
    if (writeIdx < readIdx) {
        rdcnt = SNSR_BUF_LEN - readIdx;
        if (rdcnt > toread)
            rdcnt = toread;
        memcpy(dst[framecount-toread], buffer->data[readIdx], rdcnt*sizeof(buffer_frame_t));
        readIdx = (readIdx + rdcnt) % SNSR_BUF_LEN;
        toread -= rdcnt;
    }

    if ((toread > 0) && (writeIdx > readIdx)) {
        rdcnt = writeIdx - readIdx;
        if (rdcnt > toread)
            rdcnt = toread;
        memcpy(dst[framecount-toread], buffer->data[readIdx], rdcnt*sizeof(buffer_frame_t));
        readIdx += rdcnt;
        toread -= rdcnt;
    }

    // NB! Memory operations *must* be completed before updating the index
    
    buffer->readIdx = readIdx;
    
    return framecount - toread;
}

size_t buffer_write(struct sensor_buffer_t *buffer, buffer_data_t data[][SNSR_NUM_AXES], size_t framecount) {   
    size_t readIdx = buffer->readIdx;
    size_t writeIdx = buffer->writeIdx;
    size_t towrite = framecount;
    size_t wrcnt;
    
    // If overrun is already flagged, don't attempt to write any more data
    if (buffer->overrun == true) {
        return 0;
    }
    
    if (towrite == 0) {
        // Return here as this case can falsely trigger an overrun
        return 0;
    }
    
    // Handle wrap around writes
    if (readIdx <= writeIdx) {
        wrcnt = SNSR_BUF_LEN - writeIdx;
        if (wrcnt > towrite)
            wrcnt = towrite;
        memcpy(buffer->data[writeIdx], data[framecount-towrite], wrcnt*sizeof(buffer_frame_t));
        writeIdx = (writeIdx + wrcnt) % SNSR_BUF_LEN;
        towrite -= wrcnt;
    }
    
    if ((towrite > 0) && (readIdx > writeIdx)) {
        wrcnt = readIdx - writeIdx;
        if (wrcnt > towrite)
            wrcnt = towrite;
        memcpy(buffer->data[writeIdx], data[framecount-towrite], wrcnt*sizeof(buffer_frame_t));
        writeIdx += wrcnt;
        towrite -= wrcnt;
    }
        
    /* Flag overrun condition */
    /* (Note for simplicity this declares overrun 1 frame before overrun actually occurs) */
    if (writeIdx == readIdx) {
        buffer->overrun = true;
    }
    
    // NB! Memory operations *must* be completed before updating the index
   
    buffer->writeIdx = writeIdx;
    
    return framecount - towrite;
}
