/********************************** (C) COPYRIGHT *******************************
* File Name          : CONFIG.h
* Author             : WCH
* Version            : V1.10
* Date               : 2019/11/05
* Description        : ����˵����Ĭ��ֵ���ڹ������������õ�ǰֵ
*******************************************************************************/

/******************************************************************************/
#ifndef __CONFIG_H
#define __CONFIG_H

#define	ID_CH577							0x77
#define	ID_CH578							0x78
#define	ID_CH579							0x79

#define CHIP_ID								ID_CH579

#ifdef CH57xBLE_ROM
#include "CH57xBLE_ROM.H"
#else
#include "CH57xBLE_LIB.H"
#endif
/*********************************************************************
��MAC��
	BLE_MAC												- �Ƿ��Զ�������Mac��ַ ( Ĭ��:FALSE )����Ҫ��main.c�޸�Mac��ַ����

��SLEEP��
	HAL_SLEEP   									- �Ƿ���˯�߹��� ( Ĭ��:FALSE )
	WAKE_UP_RTC_MAX_TIME					- ˯�߻�������ʱ�䣬���ݲ�ͬ˯������ȡֵ�ɷ�Ϊ��˯��ģʽ/�µ�ģʽ -	80
																																								��ͣģʽ					-	60
																																								����ģʽ					-	10
														
��SNV��
	BLE_SNV    				            - �Ƿ���SNV���ܣ����ڴ������Ϣ( Ĭ��:TRUE )
	BLE_SNV_ADDR    					    - SNV��Ϣ�����ַ��ʹ��code flash���һ��( Ĭ��:0x3E600 )
	BLE_SNV_NUM    					    	- SNV��Ϣ�����������ÿ����Ա�����������( Ĭ��:1 )

��RTC��
	CLK_OSC32K_RC									- �Ƿ�ʹ���ڲ�32K��ʹ��������������������������ر�( Ĭ��:TRUE )	

��MEMORY��
	BLE_MEMHEAP_SIZE  						- ����Э��ջʹ�õ�RAM��С��( Ĭ��:(1024*8) )               

��DATA��
	BLE_BUFF_MAX_LEN							- ����������������( Ĭ��:27 (ATT_MTU=23)��ȡֵ��Χ[27~251] )
	BLE_BUFF_NUM									- ����������İ�����( Ĭ��:10 )
	BLE_TX_NUM_EVENT							- ���������¼������Է����ٸ����ݰ�( Ĭ��:1 )
	BLE_TX_POWER									- ���书��( Ĭ��:LL_TX_POWEER_0_DBM (0dBm) )

��TEST��
	BLE_DIRECT_TEST								- �Ƿ�����ֱ�Ӳ���ģʽ( Ĭ��:FALSE )
	
��MULTICONN��
	PERIPHERAL_MAX_CONNECTION			- ����ͬʱ�����ٴӻ���ɫ( Ĭ��:1 )
	CENTRAL_MAX_CONNECTION				- ����ͬʱ������������ɫ( Ĭ��:3 )
**********************************************************************/

/*********************************************************************
 * Ĭ������ֵ
 */
#ifndef BLE_MAC
#define BLE_MAC											FALSE
#endif
#ifndef HAL_SLEEP
#define HAL_SLEEP										FALSE
#define WAKE_UP_RTC_MAX_TIME				0
#endif
#ifndef HAL_KEY
#define HAL_KEY											FALSE
#endif
#ifndef HAL_LED
#define HAL_LED											FALSE	
#endif
#ifndef BLE_SNV
#define BLE_SNV											TRUE
#define BLE_SNV_ADDR								0x3E600
#define BLE_SNV_NUM									1
#endif
#ifndef CLK_OSC32K_RC
#define CLK_OSC32K_RC								TRUE
#endif
#ifndef BLE_MEMHEAP_SIZE
#define BLE_MEMHEAP_SIZE						(1024*8)
#endif
#ifndef BLE_BUFF_MAX_LEN
#define BLE_BUFF_MAX_LEN						27
#endif
#ifndef BLE_BUFF_NUM
#define BLE_BUFF_NUM								10
#endif
#ifndef BLE_TX_NUM_EVENT
#define BLE_TX_NUM_EVENT						1
#endif
#ifndef BLE_TX_POWER
#define BLE_TX_POWER								LL_TX_POWEER_0_DBM
#endif
#ifndef BLE_DIRECT_TEST
#define BLE_DIRECT_TEST							FALSE
#endif
#ifndef PERIPHERAL_MAX_CONNECTION
#define PERIPHERAL_MAX_CONNECTION		1
#endif
#ifndef CENTRAL_MAX_CONNECTION
#define CENTRAL_MAX_CONNECTION			3
#endif

extern u32 MEM_BUF[BLE_MEMHEAP_SIZE/4];
extern u8C MacAddr[6];

#endif

/******************************* endfile @ config ******************************/
