/** @file sys_main.c 
*   @brief Application main file
*   @date 11-Dec-2018
*   @version 04.07.01
*
*   This file contains an empty main function,
*   which can be used for the application.
*/

/* 
* Copyright (C) 2009-2018 Texas Instruments Incorporated - www.ti.com 
* 
* 
*  Redistribution and use in source and binary forms, with or without 
*  modification, are permitted provided that the following conditions 
*  are met:
*
*    Redistributions of source code must retain the above copyright 
*    notice, this list of conditions and the following disclaimer.
*
*    Redistributions in binary form must reproduce the above copyright
*    notice, this list of conditions and the following disclaimer in the 
*    documentation and/or other materials provided with the   
*    distribution.
*
*    Neither the name of Texas Instruments Incorporated nor the names of
*    its contributors may be used to endorse or promote products derived
*    from this software without specific prior written permission.
*
*  THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS 
*  "AS IS" AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT 
*  LIMITED TO, THE IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR
*  A PARTICULAR PURPOSE ARE DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT 
*  OWNER OR CONTRIBUTORS BE LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL, 
*  SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT 
*  LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES; LOSS OF USE,
*  DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND ON ANY
*  THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT 
*  (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE 
*  OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.
*
*/


/* USER CODE BEGIN (0) */
/* USER CODE END */

/* Include Files */
#include "sci.h"
#include "sys_common.h"


/* USER CODE BEGIN (1) */

/*SLIP Protocol Variables*/
#define END     0xC0
#define ESC     0xDB
#define ESC_END 0xDC
#define ESC_ESC 0xDD


#define BUFFER_SIZE 256
unsigned char data;
unsigned char Buff[BUFFER_SIZE];
bool escapeFlag;

uint8_t index = 0,size = 0;

/* USER CODE END */

/** @fn void main(void)
*   @brief Application main function
*   @note This function is empty by default.
*
*   This function is called after startup.
*   The user can use this function to implement the application.
*/

/* USER CODE BEGIN (2) */
/* USER CODE END */

void main(void)
{
/* USER CODE BEGIN (3) */
    _enable_IRQ();
    sciInit();
    sciSend(scilinREG,14,(unsigned char *)"SLIP Echo Test");
    sciReceive(scilinREG, 1, (unsigned char *)&data);

    while(1);
/* USER CODE END */

}


/* USER CODE BEGIN (4) */

uint8_t SLIP_Read(sciBASE_t *sci,unsigned char * buffer){

     uint8_t packetSize = 0;
     sciReceive(sci,1,(unsigned char *)&data);

     if(data == END){
      packetSize = index;
      index = 0;
      }
     else if(data == ESC){
      escapeFlag = true;
     }
     else if (escapeFlag){
       switch(data){
       case ESC_END:
            buffer[index++] = END;
            break;
       case ESC_ESC:
            buffer[index++] = ESC;
            break;
       default:
            buffer[index++] = data;

        }
        escapeFlag = false;
      }
     else{
      buffer[index++] = data;
     }

   return packetSize;
}


void SLIP_Write(sciBASE_t *sci,unsigned char * buffer, uint8_t packetSize ){
    unsigned char data;
    uint8 cmd;
    int i;
    // Begin Packet
    cmd = END;
    sciSend(sci, 1, &cmd);


    //Write Back Data
    for( i = 0; i< packetSize ; i++){
    data = buffer[i];
    switch(data){

       case END:
            cmd = ESC;
            sciSend(sci, 1, &cmd);
            cmd = ESC_END;
            sciSend(sci, 1, &cmd);
            break;
        case ESC:
            cmd = ESC;
            sciSend(sci, 1, &cmd);
            cmd = ESC_ESC;
            sciSend(sci, 1, &cmd);

            break;
        default:
            sciSend(sci, 1, (unsigned char*)&data);
        }

    }

    // End Packet
    cmd = END;
    sciSend(sci, 1, &cmd);


}

void sciNotification(sciBASE_t *sci, unsigned flags) {

   size = SLIP_Read(sci,Buff);
   if(size >0){
       SLIP_Write(sci,Buff,size);
   }

}

void esmGroup1Notification(int bit)
{
    return;
}

void esmGroup2Notification(int bit)
{
    return;
}


/* USER CODE END */
