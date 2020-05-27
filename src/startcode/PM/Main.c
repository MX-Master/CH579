/********************************** (C) COPYRIGHT *******************************
* File Name          : Main.c
* Author             : WCH
* Version            : V1.1
* Date               : 2020/03/18
* Description 		 : ϵͳ˯��ģʽ��������ʾ��GPIOA_6��GPIOA_5��Ϊ����Դ����6��˯�ߵȼ�
*******************************************************************************/

/* ע�⣺ʹ�õ͹��ģ�Idleģʽ���⣩˯�߻��Ѻ���Ҫ��������ϵͳʱ�ӣ�����ʹ�õ���32Mʱ�ӷ�Ƶ��4M��Ƶ */

#include "CH57x_common.h"

void DebugInit(void)		
{
    GPIOA_SetBits(GPIO_Pin_9);
    GPIOA_ModeCfg(GPIO_Pin_9, GPIO_ModeOut_PP_5mA);
    UART1_DefInit();
}

int main()
{
    SetSysClock( CLK_SOURCE_HSE_32MHz );        // �����ⲿ32M����Ƶ
    GPIOA_ModeCfg( GPIO_Pin_All, GPIO_ModeIN_PU );
    GPIOB_ModeCfg( GPIO_Pin_All, GPIO_ModeIN_PU );
    
    
/* ���ô��ڵ��� */   
    DebugInit();
    PRINT( "Start @ChipID=%02x\n", R8_CHIP_ID );
    DelayMs(200); 

#if 1    
    /* ���û���ԴΪ GPIO - PA6&PA5 */
    GPIOA_ModeCfg( GPIO_Pin_6|GPIO_Pin_5, GPIO_ModeIN_PU );
    GPIOA_ITModeCfg( GPIO_Pin_6|GPIO_Pin_5, GPIO_ITMode_FallEdge );        // �½��ػ���
    NVIC_EnableIRQ( GPIO_IRQn );
    PWR_PeriphWakeUpCfg( ENABLE, RB_SLP_GPIO_WAKE );
#endif    
    
#if 1
    PRINT( "IDLE mode sleep \n");   
    DelayMs(1);
    LowPower_Idle();
    PRINT( "wake.. \n"); 
    DelayMs(500);
#endif    
    
#if 1
    PRINT( "Halt_1 mode sleep \n");   
    DelayMs(1);
    LowPower_Halt_1();
    SetSysClock( CLK_SOURCE_HSE_32MHz );  // �л���ԭʼʱ��
    PRINT( "wake.. \n"); 
    DelayMs(500);    
#endif    
    
#if 1
    PRINT( "Halt_2 mode sleep \n");   
    DelayMs(1);
    LowPower_Halt_2();
    SetSysClock( CLK_SOURCE_HSE_32MHz );  // �л���ԭʼʱ��
    PRINT( "wake.. \n"); 
    DelayMs(500);    
#endif    

#if 1
    PRINT( "sleep mode sleep \n");   
    DelayMs(1);
    LowPower_Sleep( RB_PWR_RAM14K|RB_PWR_RAM2K );       //ֻ����14+2K SRAM ����
    SetSysClock( CLK_SOURCE_HSE_32MHz );  // �л���ԭʼʱ��
    PRINT( "wake.. \n");      
    DelayMs(500);
#endif

#if 1
    PRINT( "shut down mode sleep \n");   
    DelayMs(1);
    LowPower_Shutdown( NULL );                          //ȫ���ϵ磬���Ѻ�λ
/* ��ģʽ���Ѻ��ִ�и�λ������������벻������ */
    SetSysClock( CLK_SOURCE_HSE_32MHz );  // �л���ԭʼʱ��
    PRINT( "wake.. \n");
    DelayMs(500);
#endif

    while(1);    
}


void GPIO_IRQHandler(void)
{
    GPIOA_ClearITFlagBit( GPIO_Pin_6|GPIO_Pin_5 );
}




