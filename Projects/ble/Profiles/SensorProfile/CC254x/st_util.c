/******************************************************************************

 @file  st_util.c

 @brief Utilties for Sensor Tag services

 Group: WCS, BTS
 Target Device: CC2540, CC2541

 ******************************************************************************
 
 Copyright (c) 2012-2020, Texas Instruments Incorporated
 All rights reserved.

 IMPORTANT: Your use of this Software is limited to those specific rights
 granted under the terms of a software license agreement between the user
 who downloaded the software, his/her employer (which must be your employer)
 and Texas Instruments Incorporated (the "License"). You may not use this
 Software unless you agree to abide by the terms of the License. The License
 limits your use, and you acknowledge, that the Software may not be modified,
 copied or distributed unless embedded on a Texas Instruments microcontroller
 or used solely and exclusively in conjunction with a Texas Instruments radio
 frequency transceiver, which is integrated into your product. Other than for
 the foregoing purpose, you may not use, reproduce, copy, prepare derivative
 works of, modify, distribute, perform, display or sell this Software and/or
 its documentation for any purpose.

 YOU FURTHER ACKNOWLEDGE AND AGREE THAT THE SOFTWARE AND DOCUMENTATION ARE
 PROVIDED �AS IS� WITHOUT WARRANTY OF ANY KIND, EITHER EXPRESS OR IMPLIED,
 INCLUDING WITHOUT LIMITATION, ANY WARRANTY OF MERCHANTABILITY, TITLE,
 NON-INFRINGEMENT AND FITNESS FOR A PARTICULAR PURPOSE. IN NO EVENT SHALL
 TEXAS INSTRUMENTS OR ITS LICENSORS BE LIABLE OR OBLIGATED UNDER CONTRACT,
 NEGLIGENCE, STRICT LIABILITY, CONTRIBUTION, BREACH OF WARRANTY, OR OTHER
 LEGAL EQUITABLE THEORY ANY DIRECT OR INDIRECT DAMAGES OR EXPENSES
 INCLUDING BUT NOT LIMITED TO ANY INCIDENTAL, SPECIAL, INDIRECT, PUNITIVE
 OR CONSEQUENTIAL DAMAGES, LOST PROFITS OR LOST DATA, COST OF PROCUREMENT
 OF SUBSTITUTE GOODS, TECHNOLOGY, SERVICES, OR ANY CLAIMS BY THIRD PARTIES
 (INCLUDING BUT NOT LIMITED TO ANY DEFENSE THEREOF), OR OTHER SIMILAR COSTS.

 Should you have any questions regarding your right to use this Software,
 contact Texas Instruments Incorporated at www.TI.com.

 ******************************************************************************
 Release Name: ble_sdk_1.5.1.1
 Release Date: 2020-01-30 19:28:56
 *****************************************************************************/

/*-------------------------------------------------------------------
 * INCLUDES
 */
#include "bcomdef.h"
#include "gatt.h"
#include "st_util.h"
#include "linkdb.h"

/*-------------------------------------------------------------------
 * FUNCTIONS
 */

/*********************************************************************
 * @fn      utilExtractUuid16
 *
 * @brief   Extracts a 16-bit UUID from a GATT attribute
 *
 * @param   pAttr - pointer to attribute
 *
 * @param   pUuid - pointer to UUID to be extracted
 *
 * @return  Success or Failure
 */
bStatus_t utilExtractUuid16(gattAttribute_t *pAttr, uint16 *pUuid)
{
  bStatus_t status = SUCCESS;

  if ( pAttr->type.len == ATT_BT_UUID_SIZE )
  {
    // 16-bit UUID direct
    *pUuid = BUILD_UINT16( pAttr->type.uuid[0], pAttr->type.uuid[1]);
#ifdef GATT_TI_UUID_128_BIT
  }
  else if (pAttr->type.len == ATT_UUID_SIZE)
  {
    // 16-bit UUID extracted bytes 12 and 13
    *pUuid = BUILD_UINT16( pAttr->type.uuid[12], pAttr->type.uuid[13]);
#endif
  } else {
    *pUuid = 0xFFFF;
    status = FAILURE;
  }

  return status;
}

/*********************************************************************
 * @fn      util_initCharacteristicConfig
 *
 * @brief   Initialise a characteristics configuration
 *
 * @param   pDataConfig - pointer to characteristics configuration
 *
 * @return  Success or bleMemAllocError
 */
bStatus_t util_initCharacteristicConfig( gattCharCfg_t **pDataConfig )
{
  // Allocate Client Characteristic Configuration table
  *pDataConfig = (gattCharCfg_t *)osal_mem_alloc(sizeof(gattCharCfg_t) *
                                                    linkDBNumConns);
  if (*pDataConfig == NULL)
  {
    return (bleMemAllocError);
  }
  
  // Register with Link DB to receive link status change callback
  GATTServApp_InitCharCfg(INVALID_CONNHANDLE, *pDataConfig);
  
  return SUCCESS;
}

/*********************************************************************
*********************************************************************/

