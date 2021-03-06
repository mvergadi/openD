/*
 * Copyright (c) by RTX A/S, Denmark
 * All rights reserved.
 *
 * Redistribution and use in source and binary forms, with or without
 * modification, are permitted provided that the following conditions
 * are met:
 * 1. Redistributions of source code must retain the above copyright
 *    notice, this list of conditions and the following disclaimer.
 * 2. Redistributions in binary form must reproduce the above copyright
 *    notice, this list of conditions and the following disclaimer in the
 *    documentation and/or other materials provided with the distribution.
 * 3. Neither the name of RTX A/S nor the names of its contributors
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
 */
#ifndef APICLSSMPS_H
#define APICLSSMPS_H

/****************************************************************************
*                               Include files
****************************************************************************/
#include <Phoenix/Api/Clss/ApiClss.h>

#ifdef __cplusplus
extern "C"
{
#endif

/****************************************************************************
* FUNCTION:      SendApiClssInd
* DESCRIPTION:   MPS function for sending mails with primitive:
*                API_CLSS_IND = 0x5C41
****************************************************************************/
void SendApiClssInd ( RosTaskIdType Dst,
                      ApiClssDeviceIdType DeviceId,          /*!< Id of the source. */
                      rsuint16 InfoElementLength,            /*!< The length of the Data
                                                                Information Element */
                      rsuint8 InfoElement[1]);               /*!< The InfoElementList
                                                                can hold a number Info
                                                                Elements placed in the in
                                                                the format
                                                                
                                                                { Ie, IeLength, IeData[],
                                                                Ie, IeLength, IeData[], ...} 
                                                                
                                                                Each element is packed
                                                                following the ApiInfoElementType.
                                                                
                                                                At reception the receiving
                                                                task should search through
                                                                the info data package to
                                                                search for the requested
                                                                elements and pick out the
                                                                info data.
                                                                
                                                                Possible Info elements:
                                                                API_IE_PROPRIETARY
                                                                API_IE_IWU_TO_IWU */

/****************************************************************************
* FUNCTION:      SendApiClssSetIwuToIwuCfm
* DESCRIPTION:   MPS function for sending mails with primitive:
*                API_CLSS_SET_IWU_TO_IWU_CFM = 0x5C43
****************************************************************************/
void SendApiClssSetIwuToIwuCfm ( RosTaskIdType Dst,
                                 RsStatusType Status);       /*!< Indicates whether the
                                                                API_CLSS_SET_IWU_TO_IWU_REQ
                                                                was executed correctly or not.
                                                                RsStatusType is defined in
                                                                the ROS */

/****************************************************************************
* FUNCTION:      SendApiClssSetFeaturesCfm
* DESCRIPTION:   MPS function for sending mails with primitive:
*                API_CLSS_SET_FEATURES_CFM = 0x5C49
****************************************************************************/
void SendApiClssSetFeaturesCfm ( RosTaskIdType Dst,
                                 RsStatusType Status,        /*!<  */
                                 ApiClssFeatureType ApiClssFeature);
                                                             /*!< Supported features */

/****************************************************************************
* FUNCTION:      SendApiClssGetFeaturesCfm
* DESCRIPTION:   MPS function for sending mails with primitive:
*                API_CLSS_GET_FEATURES_CFM = 0x5C4B
****************************************************************************/
void SendApiClssGetFeaturesCfm ( RosTaskIdType Dst,
                                 ApiClssFeatureType CurrentFeatures,
                                                             /*!< Current feature
                                                                settings */
                                 ApiClssFeatureType AvailableFeatures);
                                                             /*!< Available feature
                                                                settings */

#ifdef __cplusplus
}
#endif
#endif /*APICLSSMPS_H */


