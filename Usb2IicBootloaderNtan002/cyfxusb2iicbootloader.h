/*
 ## Cypress USB 3.0 Platform header file (cyfxusb2iicbootloader.h)
 ## ===========================
 ##
 ##  Copyright Cypress Semiconductor Corporation, 2010-2011,
 ##  All Rights Reserved
 ##  UNPUBLISHED, LICENSED SOFTWARE.
 ##
 ##  CONFIDENTIAL AND PROPRIETARY INFORMATION
 ##  WHICH IS THE PROPERTY OF CYPRESS.
 ##
 ##  Use of this file is governed
 ##  by the license agreement included in the file
 ##
 ##     <install>/license/license.txt
 ##
 ##  where <install> is the Cypress software
 ##  installation root directory path.
 ##
 ## ===========================
*/

/* This file contains the constants used by the USB2IIC application example */

#ifndef _INCLUDED_CYFXUSB2IICBOOTLOADER_H_
#define _INCLUDED_CYFXUSB2IICBOOTLOADER_H_

#include "cyu3types.h"
#include "cyu3usbconst.h"
#include "cyu3externcstart.h"

/* Endpoint and socket definitions for the USB2IIC application */

/* To change the producer and consumer EP enter the appropriate EP numbers for the #defines.
 * In the case of IN endpoints enter EP number along with the direction bit.
 * For eg. EP 6 IN endpoint is 0x86
 *     and EP 6 OUT endpoint is 0x06.
 * To change sockets mention the appropriate socket number in the #defines. */

/* Note: For USB 2.0 the endpoints and corresponding sockets are one-to-one mapped
         i.e. EP 1 is mapped to UIB socket 1 and EP 2 to socket 2 so on */

#define CY_FX_EP_PRODUCER               0x01    /* EP 1 OUT */
#define CY_FX_EP_CONSUMER               0x81    /* EP 1 IN */

#define CY_FX_EP_PRODUCER_SOCKET        CY_U3P_UIB_SOCKET_PROD_1    /* Socket 1 is producer */
#define CY_FX_EP_CONSUMER_SOCKET        CY_U3P_UIB_SOCKET_CONS_1    /* Socket 1 is consumer */

#define CY_FX_EP_PACKET_SIZE            (64)                    // Max packet size
#define CY_FX_I2C_PAYLOAD_SIZE          (CY_FX_EP_PACKET_SIZE-3)    // Max payload for I2C


#define CY_FX_BULKLP_DMA_BUF_COUNT      (8)                       /* Bulk loop channel buffer count */
#define CY_FX_BULKLP_DMA_TX_SIZE        (0)                       /* DMA transfer size is set to infinite */
#define CY_FX_BULKLP_THREAD_STACK       (0x1000)                  /* Bulk loop application thread stack size */
#define CY_FX_BULKLP_THREAD_PRIORITY    (8)                       /* Bulk loop application thread priority */

/* Burst mode definitions: Only for super speed operation. The maximum burst mode 
 * supported is limited by the USB hosts available. The maximum value for this is 16
 * and the minimum (no-burst) is 1. */

#ifdef CYMEM_256K

/*
   As we have only 32 KB total DMA buffers available on the CYUSB3011/CYUSB3012 parts, the buffering
   needs to be reduced.
 */

/* Burst length in 1 KB packets. Only applicable to USB 3.0. */
#define CY_FX_EP_BURST_LENGTH                   (1)

/* Multiplication factor used when allocating DMA buffers to reduce DMA callback frequency. */
#define CY_FX_DMA_SIZE_MULTIPLIER               (1)

/* Number of DMA buffers to be used. More buffers can give better throughput. */
#define CY_FX_BULKSRCSINK_DMA_BUF_COUNT         (2)

#else

/* Burst length in 1 KB packets. Only applicable to USB 3.0. */
#define CY_FX_EP_BURST_LENGTH                   (1)

/* Multiplication factor used when allocating DMA buffers to reduce DMA callback frequency. */
#define CY_FX_DMA_SIZE_MULTIPLIER               (1)

/* Number of DMA buffers to be used. More buffers can give better throughput. */
#define CY_FX_BULKSRCSINK_DMA_BUF_COUNT         (2)

#endif

/* Byte value that is filled into the source buffers that FX3 sends out. */
#define CY_FX_BULKSRCSINK_PATTERN            (0xAA)

//******************************************************
// Command format declaration
//
//  outBuf[0] : Control bits
//    7 6 5 4 3 2 1 0
//    | | | | | | | +-- R/W
//    | | | | | | +---- START
//    | | | | +-------- STOP
//    | | +------------ CONFIG
//
#define     CTRL_RW             (0x01u)
#define     CTRL_START          (0x02u)
#define     CTRL_STOP           (0x08u)
#define     CTRL_CONFIG         (0x20u)

//  CONFIGURATION COMMAND
//
//  outBuf[0] : Configuration code
//    7 6 5 4 3 2 1 0
//    0 0 1   | |
//            +-+------ SPEED
//
//  SPEED
//    00 : 100kHz
//    01 : 400kHz
//    10 : 50kHz
//
#define     CONFIG_SPEED        (0x0cu)
#define     CONFIG_100K         (0x00u)
#define     CONFIG_400K         (0x04u)
#define     CONFIG_50K          (0x08u)

//  Length field for generic commands
//
//  outBuf[1] : Long

//  Command code/Slave address field
//
//  dataOut[2] : Command
//    7 6 5 4 3 2 1 0
//    | +-+-+-+-+-+-+-- Command code/Slave address
//    +---------------- Internal command
//
#define     COM_INTERNAL        (0x80u)
#define     COM_STATUS          (0x80u)
#define     COM_VERSION         (0x81u)

//  Status code
//
//  inBuf[0] : Status
//    7 6 5 4 3 2 1 0
//    | | | | | | | +-- ACK
//    | | | | | +------ VTARG
//
#define     STAT_ACK            (0x01u)
#define     STAT_VTARG          (0x04u)

//  Power code
#define     POWER_NONE          (0x00u)
#define     POWER_5p0V          (0x01u)
#define     POWER_3p3V          (0x02u)

//******************************************************


/* Extern definitions for the USB Descriptors */
extern const uint8_t CyFxUSB20DeviceDscr[];
extern const uint8_t CyFxUSB30DeviceDscr[];
extern const uint8_t CyFxUSBDeviceQualDscr[];
extern const uint8_t CyFxUSBFSConfigDscr[];
extern const uint8_t CyFxUSBHSConfigDscr[];
extern const uint8_t CyFxUSBBOSDscr[];
extern const uint8_t CyFxUSBSSConfigDscr[];
extern const uint8_t CyFxUSBReportDscr[];
extern const uint8_t CyFxUSBStringLangIDDscr[];
extern const uint8_t CyFxUSBManufactureDscr[];
extern const uint8_t CyFxUSBProductDscr[];
extern const uint8_t CyFxUSBStringConfigDscr[];
extern const uint8_t CyFxUSBStringInterfDscr[];

#include <cyu3externcend.h>

#endif /* _INCLUDED_CYFXUSB2IICBOOTLOADER_H_ */

/*[]*/
