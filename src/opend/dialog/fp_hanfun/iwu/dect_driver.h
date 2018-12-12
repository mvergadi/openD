/*
 * Copyright (C) 2018 by Dialog Semiconductor. All rights reserved.
 *
 * Redistribution and use in source and binary forms, with or without
 * modification, are permitted provided that the following conditions
 * are met:
 * 1. Redistributions of source code must retain the above copyright
 *    notice, this list of conditions and the following disclaimer.
 * 2. Redistributions in binary form must reproduce the above copyright
 *    notice, this list of conditions and the following disclaimer in the
 *    documentation and/or other materials provided with the distribution.
 * 3. Neither the name of Dialog Semiconductor nor the names of its Affiliates
 *    may be used to endorse or promote products derived from this software
 *    without specific prior written permission.
 *
 * THIS SOFTWARE IS PROVIDED BY THE REGENTS AND CONTRIBUTORS ``AS IS'' AND
 * ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE
 * IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE
 * ARE DISCLAIMED.  IN NO EVENT SHALL THE REGENTS OR CONTRIBUTORS BE LIABLE
 * FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL
 * DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS
 * OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION)
 * HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT
 * LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY
 * OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF
 * SUCH DAMAGE.
 *
 */#ifndef DECT_DRV_H
#define DECT_DRV_H
/*========================== Include files ==================================*/

char ULE_mail_switch(unsigned short Length, unsigned char *MailPtr);
void Dect_bridge_main();
/******************************************************************************
 *                                 ULE		                                  *
 ******************************************************************************/
/******************************************************************************
 *                                 Additional defines                         *
 ******************************************************************************/
#define ULP_DLC_CTRL_UNACKNOWLEDGED  0x01
#define ULP_DLC_CTRL_ACKNOWLEDGED    0x02


// This should be in a lib header
typedef struct ApiProdTestCfmType
{
  RosPrimitiveType Primitive;            /*!< API_PROD_TEST_CFM = 0x4FFF */
  rsuint16 Opcode;                      /*!< Op-code identifying the HW test command. */
  rsuint16 ParameterLength;             /*!< The total length in bytes of the
                                           parameters. */
  rsuint8 Parameters [1];               /*!< Optional parameters. */
} ApiProdTestCfmType;

void TxBuff_Send( void );

#endif //__DECT_DRV_H__