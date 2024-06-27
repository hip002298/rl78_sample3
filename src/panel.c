/*******************************************************************************
* DISCLAIMER
* This software is supplied by Renesas Electronics Corporation and is only
* intended for use with Renesas products. No other uses are authorized. This
* software is owned by Renesas Electronics Corporation and is protected under
* all applicable laws, including copyright laws.
* THIS SOFTWARE IS PROVIDED "AS IS" AND RENESAS MAKES NO WARRANTIES REGARDING
* THIS SOFTWARE, WHETHER EXPRESS, IMPLIED OR STATUTORY, INCLUDING BUT NOT
* LIMITED TO WARRANTIES OF MERCHANTABILITY, FITNESS FOR A PARTICULAR PURPOSE
* AND NON-INFRINGEMENT. ALL SUCH WARRANTIES ARE EXPRESSLY DISCLAIMED.
* TO THE MAXIMUM EXTENT PERMITTED NOT PROHIBITED BY LAW, NEITHER RENESAS
* ELECTRONICS CORPORATION NOR ANY OF ITS AFFILIATED COMPANIES SHALL BE LIABLE
* FOR ANY DIRECT, INDIRECT, SPECIAL, INCIDENTAL OR CONSEQUENTIAL DAMAGES FOR
* ANY REASON RELATED TO THIS SOFTWARE, EVEN IF RENESAS OR ITS AFFILIATES HAVE
* BEEN ADVISED OF THE POSSIBILITY OF SUCH DAMAGES.
* Renesas reserves the right, without notice, to make changes to this software
* and to discontinue the availability of this software. By using this software,
* you agree to the additional terms and conditions found by accessing the
* following link:
* http://www.renesas.com/disclaimer
*
* Copyright (C) 2016 Renesas Electronics Corporation. All rights reserved.
*******************************************************************************/

/*******************************************************************************
* File Name    : panel.c
* Version      : Applilet EZ PL for RL78
* Device(s)    : R5F1056A,R5F1057A,R5F1058A
* Tool-Chain   : CC-RL
* Description  : This file implements main function.
* Creation Date: 2016/09/14
*******************************************************************************/

/*******************************************************************************
Includes <System Includes> , "Project Includes"
*******************************************************************************/
#include "sfr.h"
#include "common.h"
#include "config.h"
#include "panel.h"

/*******************************************************************************
Exported global variables and functions (to be accessed by other files)
*******************************************************************************/
#if defined DTC_USED || defined STANDBY_USED
#pragma address dtc_vectortable = VECTOR_ADDRESS
UCHAR __near dtc_vectortable[40];
#pragma address dtc_controldata = CONTROLDATA_ADDRESS
ST_DTC_DATA __near dtc_controldata[24];
#endif /*DTC_USED || STANDBY_USED*/
/*--- Variable declaration ---*/
	UCHAR I_07;
	UCHAR I_09;
	UCHAR I_11;
	UCHAR I_13;
	UCHAR I_15;
	UCHAR I_17;
	UCHAR I_19;
	UCHAR I_21;
	UCHAR F1407 = 0;
	UCHAR F1409 = 0;
	UCHAR F1411 = 0;
	UCHAR flag_left;
	UCHAR flag_central;
	UCHAR flag_right;
	UCHAR a;
/*----------------------------*/
UCHAR panel_num_insert(void)
{
	if(I_07 == LOW){
		return 0;
	}else if(I_09 == LOW){
		return 1;
	}else if(I_11 == LOW){
		return 2;
	}else if(I_13 == LOW){
		return 3;
	}else if(I_15 == LOW){
		return 4;
	}else if(I_17 == LOW){
		return 5;
	}else if(I_19 == LOW){
		return 6;
	}else if(I_21 == LOW){
		return 7;
	}else{
		return 0;
	}
}

UCHAR LED_left(void)
{
                 a = panel_num_insert();    
		 if(a % 4 == 1){
			return fON;
		 }else{
			return fOFF;
		 }
		
}
UCHAR LED_central(void)
{
                a = panel_num_insert();       
		if(a % 4 == 2){
			return fON;
		}else{
			return fOFF;
		}
			
}
UCHAR LED_right(void)
{
                a = panel_num_insert();  
		if(a % 4 == 3){
			return fON;
		}else{
			return fOFF;
		}
	
}

void panel_init0(void)
{

	DGIN_INIT0(0);
	DGIN_INIT0(0);
	DGIN_INIT0(0);
	DGIN_INIT0(0);
	DGIN_INIT0(0);
	DGIN_INIT0(0);
	DGIN_INIT0(0);
	DGIN_INIT0(0);
}

void panel(void)
{
	DGIN_INIT;
	flag_left = LED_left();
	flag_central = LED_central();
	flag_right = LED_right();

	DGIN_PROC( I_07,20, LOW,10,fTrg10ms); 
	DGIN_PROC( I_09,21, LOW,10,fTrg10ms);
	DGIN_PROC( I_11,22, LOW,10,fTrg10ms);
	DGIN_PROC( I_13,51, LOW,10,fTrg10ms); 
	DGIN_PROC( I_15,52, LOW,10,fTrg10ms); 
	DGIN_PROC( I_17,53, LOW,10,fTrg10ms); 
	DGIN_PROC( I_19,54, LOW,10,fTrg10ms); 
	DGIN_PROC( I_21,55, LOW,10,fTrg10ms); 
	DGOUT_PROC( 30, flag_left, LOW );
	DGOUT_PROC( 31, flag_central, LOW );
	DGOUT_PROC( 32, flag_right, LOW );
}
