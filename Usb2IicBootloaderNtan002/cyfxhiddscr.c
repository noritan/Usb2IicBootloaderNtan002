/*
 ## Cypress USB 3.0 Platform header file (cyfxhiddscr.c)
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

/* This file contains the USB enumeration descriptors for the USB2IIC application example.
 * The descriptor arrays must be 32 byte aligned and multiple of 32 bytes if the D-cache is
 * turned on. If the linker used is not capable of supporting the aligned feature for this,
 * either the descriptors must be placed in a different section and the section should be 
 * 32 byte aligned and 32 byte multiple; or dynamically allocated buffer allocated using
 * CyU3PDmaBufferAlloc must be used, and the descriptor must be loaded into it. The example
 * assumes that the aligned attribute for 32 bytes is supported by the linker. Do not add
 * any other variables to this file other than USB descriptors. This is not the only
 * pre-requisite to enabling the D-cache. Refer to the documentation for
 * CyU3PDeviceCacheControl for more information.
 */

#include "cyfxusb2iicbootloader.h"

/* Standard device descriptor for USB 3.0 */
const uint8_t CyFxUSB30DeviceDscr[] __attribute__ ((aligned (32))) =
{
    0x12,                           /* Descriptor size */
    CY_U3P_USB_DEVICE_DESCR,        /* Device descriptor type */
    0x00,0x03,                      /* USB 3.0 */
    0x00,                           /* Device class */
    0x00,                           /* Device sub-class */
    0x00,                           /* Device protocol */
    0x09,                           /* Maxpacket size for EP0 : 2^9 */
    0xB4,0x04,                      /* Vendor ID */
    0x32,0xF2,                      /* Product ID */
    0x00,0x00,                      /* Device release number */
    0x01,                           /* Manufacture string index */
    0x02,                           /* Product string index */
    0x03,                           /* Serial number string index */
    0x01                            /* Number of configurations */
};

/* Standard device descriptor for USB 2.0 */
const uint8_t CyFxUSB20DeviceDscr[] __attribute__ ((aligned (32))) =
{
    0x12,                           /* Descriptor size */
    CY_U3P_USB_DEVICE_DESCR,        /* Device descriptor type */
    0x10,0x02,                      /* USB 2.10 */
    0x00,                           /* Device class */
    0x00,                           /* Device sub-class */
    0x00,                           /* Device protocol */
    0x40,                           /* Maxpacket size for EP0 : 64 bytes */
    0xB4,0x04,                      /* Vendor ID */
    0x32,0xF2,                      /* Product ID */
    0x00,0x00,                      /* Device release number */
    0x01,                           /* Manufacture string index */
    0x02,                           /* Product string index */
    0x03,                           /* Serial number string index */
    0x01                            /* Number of configurations */
};

/* Binary device object store descriptor */
const uint8_t CyFxUSBBOSDscr[] __attribute__ ((aligned (32))) =
{
    0x05,                           /* Descriptor size */
    CY_U3P_BOS_DESCR,               /* Device descriptor type */
    0x16,0x00,                      /* Length of this descriptor and all sub descriptors */
    0x02,                           /* Number of device capability descriptors */

    /* USB 2.0 extension */
    0x07,                           /* Descriptor size */
    CY_U3P_DEVICE_CAPB_DESCR,       /* Device capability type descriptor */
    CY_U3P_USB2_EXTN_CAPB_TYPE,     /* USB 2.0 extension capability type */
    0x02,0x00,0x00,0x00,            /* Supported device level features: LPM support  */

    /* SuperSpeed device capability */
    0x0A,                           /* Descriptor size */
    CY_U3P_DEVICE_CAPB_DESCR,       /* Device capability type descriptor */
    CY_U3P_SS_USB_CAPB_TYPE,        /* SuperSpeed device capability type */
    0x00,                           /* Supported device level features  */
    0x06,0x00,                      /* Speeds supported by the device : HS and FS */
    0x03,                           /* Functionality support */
    0x0A,                           /* U1 Device Exit latency */
    0xFF,0x07                       /* U2 Device Exit latency */
};

/* Standard device qualifier descriptor */
const uint8_t CyFxUSBDeviceQualDscr[] __attribute__ ((aligned (32))) =
{
    0x0A,                           /* Descriptor size */
    CY_U3P_USB_DEVQUAL_DESCR,       /* Device qualifier descriptor type */
    0x00,0x02,                      /* USB 2.0 */
    0x00,                           /* Device class */
    0x00,                           /* Device sub-class */
    0x00,                           /* Device protocol */
    0x40,                           /* Maxpacket size for EP0 : 64 bytes */
    0x01,                           /* Number of configurations */
    0x00                            /* Reserved */
};

/* Standard super speed configuration descriptor */
const uint8_t CyFxUSBSSConfigDscr[] __attribute__ ((aligned (32))) =
{
    /* Configuration descriptor */
    0x09,                           /* Descriptor size */
    CY_U3P_USB_CONFIG_DESCR,        /* Configuration descriptor type */
    0x35,0x00,                      /* Length of this descriptor and all sub descriptors */
    0x01,                           /* Number of interfaces */
    0x01,                           /* Configuration number */
    0x04,                           /* Configuration string index */
    0x80,                           /* Config characteristics - Bus powered */
    0x0C,                           /* Max power consumption of device (in 8mA unit) : 96mA */

    /* Interface descriptor */
    0x09,                           /* Descriptor size */
    CY_U3P_USB_INTRFC_DESCR,        /* Interface Descriptor type */
    0x00,                           /* Interface number */
    0x00,                           /* Alternate setting number */
    0x02,                           /* Number of endpoints */
    0x03,                           /* Interface class HID */
    0x00,                           /* Interface sub class */
    0x00,                           /* Interface protocol code */
    0x05,                           /* Interface descriptor string index */

    /* HID Class Descriptor */
    0x09,                           /* HID Class Descriptor Length */
    CY_U3P_USB_HID_DESCR,           /* DescriptorType: HID_CLASS */
    0x11, 0x01,                     /* bcdHID */
    0x21,                           /* bCountryCode */
    0x01,                           /* bNumDescriptors */
    CY_U3P_USB_REPORT_DESCR,        /* bDescriptorType */
    0x2B, 0x00,                     /* wDescriptorLength */

    /* Endpoint descriptor for producer EP */
    0x07,                           /* Descriptor size */
    CY_U3P_USB_ENDPNT_DESCR,        /* Endpoint descriptor type */
    CY_FX_EP_PRODUCER,              /* Endpoint address and description */
    CY_U3P_USB_EP_INTR,             /* Interrupt endpoint type */
    CY_FX_EP_PACKET_SIZE,0x00,      /* Max packet size = 64 bytes */
    0x01,                           /* Servicing interval for data transfers : 1ms */

    /* Super speed endpoint companion descriptor for producer EP */
    0x06,                           /* Descriptor size */
    CY_U3P_SS_EP_COMPN_DESCR,       /* SS endpoint companion descriptor type */
    (CY_FX_EP_BURST_LENGTH - 1),    /* Max no. of packets in a burst(0-15) - 0: burst 1 packet at a time */
    0x00,                           /* Max streams for bulk EP = 0 (No streams) */
    0x40,0x00,                      /* Service interval for the EP : 0 for bulk */

    /* Endpoint descriptor for consumer EP */
    0x07,                           /* Descriptor size */
    CY_U3P_USB_ENDPNT_DESCR,        /* Endpoint descriptor type */
    CY_FX_EP_CONSUMER,              /* Endpoint address and description */
    CY_U3P_USB_EP_INTR,             /* Interrupt endpoint type */
    CY_FX_EP_PACKET_SIZE,0x00,      /* Max packet size = 64 bytes */
    0x01,                           /* Servicing interval for data transfers : 1ms */

    /* Super speed endpoint companion descriptor for consumer EP */
    0x06,                           /* Descriptor size */
    CY_U3P_SS_EP_COMPN_DESCR,       /* SS endpoint companion descriptor type */
    (CY_FX_EP_BURST_LENGTH - 1),    /* Max no. of packets in a burst(0-15) - 0: burst 1 packet at a time */
    0x00,                           /* Max streams for bulk EP = 0 (No streams) */
    0x40,0x00                       /* Service interval for the EP : 0 for bulk */
};

/* Standard high speed configuration descriptor */
const uint8_t CyFxUSBHSConfigDscr[] __attribute__ ((aligned (32))) =
{
    /* Configuration descriptor */
    0x09,                           /* Descriptor size */
    CY_U3P_USB_CONFIG_DESCR,        /* Configuration descriptor type */
    0x29,0x00,                      /* Length of this descriptor and all sub descriptors */
    0x01,                           /* Number of interfaces */
    0x01,                           /* Configuration number */
    0x04,                           /* Configuration string index */
    0x80,                           /* Config characteristics - bus powered */
    0x32,                           /* Max power consumption of device (in 2mA unit) : 100mA */

    /* Interface descriptor */
    0x09,                           /* Descriptor size */
    CY_U3P_USB_INTRFC_DESCR,        /* Interface Descriptor type */
    0x00,                           /* Interface number */
    0x00,                           /* Alternate setting number */
    0x02,                           /* Number of endpoints */
    0x03,                           /* Interface class HID */
    0x00,                           /* Interface sub class */
    0x00,                           /* Interface protocol code */
    0x05,                           /* Interface descriptor string index */

    /* HID Class Descriptor */
    0x09,                           /* HID Class Descriptor Length */
    CY_U3P_USB_HID_DESCR,           /* DescriptorType: HID_CLASS */
    0x11, 0x01,                     /* bcdHID */
    0x21,                           /* bCountryCode */
    0x01,                           /* bNumDescriptors */
    CY_U3P_USB_REPORT_DESCR,        /* bDescriptorType */
    0x2B, 0x00,                     /* wDescriptorLength */

    /* Endpoint descriptor for producer EP */
    0x07,                           /* Descriptor size */
    CY_U3P_USB_ENDPNT_DESCR,        /* Endpoint descriptor type */
    CY_FX_EP_PRODUCER,              /* Endpoint address and description */
    CY_U3P_USB_EP_INTR,             /* Interrupt endpoint type */
    CY_FX_EP_PACKET_SIZE,0x00,      /* Max packet size = 64 bytes */
    0x01,                           /* Servicing interval for data transfers : 1ms */

    /* Endpoint descriptor for consumer EP */
    0x07,                           /* Descriptor size */
    CY_U3P_USB_ENDPNT_DESCR,        /* Endpoint descriptor type */
    CY_FX_EP_CONSUMER,              /* Endpoint address and description */
    CY_U3P_USB_EP_INTR,             /* Interrupt endpoint type */
    CY_FX_EP_PACKET_SIZE,0x00,      /* Max packet size = 64 bytes */
    0x01                            /* Servicing interval for data transfers : 1ms */
};

/* Standard full speed configuration descriptor */
const uint8_t CyFxUSBFSConfigDscr[] __attribute__ ((aligned (32))) =
{
    /* Configuration descriptor */
    0x09,                           /* Descriptor size */
    CY_U3P_USB_CONFIG_DESCR,        /* Configuration descriptor type */
    0x29,0x00,                      /* Length of this descriptor and all sub descriptors */
    0x01,                           /* Number of interfaces */
    0x01,                           /* Configuration number */
    0x04,                           /* Configuration string index */
    0x80,                           /* Config characteristics - bus powered */
    0x32,                           /* Max power consumption of device (in 2mA unit) : 100mA */

    /* Interface descriptor */
    0x09,                           /* Descriptor size */
    CY_U3P_USB_INTRFC_DESCR,        /* Interface descriptor type */
    0x00,                           /* Interface number */
    0x00,                           /* Alternate setting number */
    0x02,                           /* Number of endpoints */
    0x03,                           /* Interface class HID */
    0x00,                           /* Interface sub class */
    0x00,                           /* Interface protocol code */
    0x05,                           /* Interface descriptor string index */

    /* HID Class Descriptor */
    0x09,                           /* HID Class Descriptor Length */
    CY_U3P_USB_HID_DESCR,           /* DescriptorType: HID_CLASS */
    0x11, 0x01,                     /* bcdHID */
    0x21,                           /* bCountryCode */
    0x01,                           /* bNumDescriptors */
    CY_U3P_USB_REPORT_DESCR,        /* bDescriptorType */
    0x2B, 0x00,                     /* wDescriptorLength */

    /* Endpoint descriptor for producer EP */
    0x07,                           /* Descriptor size */
    CY_U3P_USB_ENDPNT_DESCR,        /* Endpoint descriptor type */
    CY_FX_EP_PRODUCER,              /* Endpoint address and description */
    CY_U3P_USB_EP_INTR,             /* Interrupt endpoint type */
    CY_FX_EP_PACKET_SIZE,0x00,      /* Max packet size = 64 bytes */
    0x01,                           /* Servicing interval for data transfers : 1ms */

    /* Endpoint descriptor for consumer EP */
    0x07,                           /* Descriptor size */
    CY_U3P_USB_ENDPNT_DESCR,        /* Endpoint descriptor type */
    CY_FX_EP_CONSUMER,              /* Endpoint address and description */
    CY_U3P_USB_EP_INTR,             /* Interrupt endpoint type */
    CY_FX_EP_PACKET_SIZE,0x00,      /* Max packet size = 64 bytes */
    0x01                            /* Servicing interval for data transfers : 1ms */
};

/* Standard full speed configuration descriptor */
const uint8_t CyFxUSBReportDscr[] __attribute__ ((aligned (32))) =
{
        /* Descriptor Size (Not part of descriptor)*/ 0x2Bu, 0x00u,
        /* USAGE_PAGE                              */ 0x06u, 0xA0u, 0xFFu,
        /* USAGE                                   */ 0x09u, 0x01u,
        /* COLLECTION                              */ 0xA1u, 0x01u,
        /* USAGE                                   */ 0x09u, 0x02u,
        /* COLLECTION                              */ 0xA1u, 0x00u,
        /* USAGE_MINIMUM                           */ 0x19u, 0x03u,
        /* USAGE_MAXIMUM                           */ 0x29u, 0x42u,
        /* LOGICAL_MINIMUM                         */ 0x15u, 0x00u,
        /* LOGICAL_MAXIMUM                         */ 0x26u, 0xFFu, 0x00u,
        /* REPORT_SIZE                             */ 0x75u, 0x08u,
        /* REPORT_COUNT                            */ 0x95u, 0x40u,
        /* OUTPUT                                  */ 0x91u, 0x02u,
        /* USAGE_MINIMUM                           */ 0x19u, 0x44u,
        /* USAGE_MAXIMUM                           */ 0x29u, 0x83u,
        /* LOGICAL_MINIMUM                         */ 0x15u, 0x00u,
        /* LOGICAL_MAXIMUM                         */ 0x26u, 0xFFu, 0x00u,
        /* REPORT_SIZE                             */ 0x75u, 0x08u,
        /* REPORT_COUNT                            */ 0x95u, 0x40u,
        /* INPUT                                   */ 0x81u, 0x02u,
        /* END_COLLECTION                          */ 0xC0u,
        /* END_COLLECTION                          */ 0xC0u,
};

/* Standard language ID string descriptor */
const uint8_t CyFxUSBStringLangIDDscr[] __attribute__ ((aligned (32))) =
{
    0x04,                           /* Descriptor size */
    CY_U3P_USB_STRING_DESCR,        /* Device descriptor type */
    0x09,0x04                       /* Language ID supported */
};

/* Standard manufacturer string descriptor */
const uint8_t CyFxUSBManufactureDscr[] __attribute__ ((aligned (32))) =
{
    0x1Eu,                          /* Descriptor size */
    CY_U3P_USB_STRING_DESCR,        /* Device descriptor type */
     (uint8_t)'E', 0u,(uint8_t)'n', 0u,(uint8_t)'g', 0u,
     (uint8_t)'i', 0u,(uint8_t)'n', 0u,(uint8_t)'e', 0u,
     (uint8_t)'e', 0u,(uint8_t)'r', 0u,(uint8_t)' ', 0u,
     (uint8_t)'g', 0u,(uint8_t)'r', 0u,(uint8_t)'o', 0u,
     (uint8_t)'u', 0u,(uint8_t)'p', 0u,
};

/* Standard product string descriptor */
const uint8_t CyFxUSBProductDscr[] __attribute__ ((aligned (32))) =
{
    0x32u,                          /* Descriptor size */
    CY_U3P_USB_STRING_DESCR,        /* Device descriptor type */
    (uint8_t)'H', 0u,(uint8_t)'I', 0u,(uint8_t)'D', 0u,
    (uint8_t)' ', 0u,(uint8_t)'U', 0u,(uint8_t)'S', 0u,
    (uint8_t)'B', 0u,(uint8_t)' ', 0u,(uint8_t)'t', 0u,
    (uint8_t)'o', 0u,(uint8_t)' ', 0u,(uint8_t)'I', 0u,
    (uint8_t)'I', 0u,(uint8_t)'C', 0u,(uint8_t)' ', 0u,
    (uint8_t)'c', 0u,(uint8_t)'o', 0u,(uint8_t)'n', 0u,
    (uint8_t)'v', 0u,(uint8_t)'e', 0u,(uint8_t)'r', 0u,
    (uint8_t)'t', 0u,(uint8_t)'e', 0u,(uint8_t)'r', 0u,
};

/* Standard configuration string descriptor */
const uint8_t CyFxUSBStringConfigDscr[] __attribute__ ((aligned (32))) =
{
    0x16u,                          /* Descriptor size */
    CY_U3P_USB_STRING_DESCR,        /* Device descriptor type */
    (uint8_t)'H', 0u,(uint8_t)'I', 0u,(uint8_t)'D', 0u,
    (uint8_t)' ', 0u,(uint8_t)'C', 0u,(uint8_t)'o', 0u,
    (uint8_t)'n', 0u,(uint8_t)'f', 0u,(uint8_t)'i', 0u,
    (uint8_t)'g', 0u,
};

/* Standard interface string descriptor */
const uint8_t CyFxUSBStringInterfDscr[] __attribute__ ((aligned (32))) =
{
    0x12u,                          /* Descriptor size */
    CY_U3P_USB_STRING_DESCR,        /* Device descriptor type */
    (uint8_t)'H', 0u,(uint8_t)'I', 0u,(uint8_t)'D', 0u,
    (uint8_t)' ', 0u,(uint8_t)'R', 0u,(uint8_t)'_', 0u,
    (uint8_t)'W', 0u,(uint8_t)'8', 0u,
};

/* Place this buffer as the last buffer so that no other variable / code shares
 * the same cache line. Do not add any other variables / arrays in this file.
 * This will lead to variables sharing the same cache line. */
const uint8_t CyFxUsbDscrAlignBuffer[32] __attribute__ ((aligned (32)));

/* [ ] */

