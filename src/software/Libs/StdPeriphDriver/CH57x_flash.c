/********************************** (C) COPYRIGHT *******************************
* File Name          : CH57x_flash.c
* Author             : WCH
* Version            : V1.0
* Date               : 2018/12/15
* Description 
*******************************************************************************/

#include "CH57x_common.h"


/*******************************************************************************
* Function Name  : GetUniqueID
* Description    : ��ȡоƬΨһID��С��ģʽ��6B-ID�� 2B-CKS
* Input          : buf: �洢8�ֽڣ�ǰ6�ֽڣ�С�ˣ�ID����2�ֽڣ�С�ˣ�У���
* Return         : None
*******************************************************************************/
void GetUniqueID(PUINT8 buf)
{
    PUINT8  pID;
    UINT8   i;
    
    pID = (PUINT8)ROM_UUID_ADDR;
    for(i=0; i<8; i++)
    {
        *buf++ = *pID++;
    }    
}

/*******************************************************************************
* Function Name  : GetMACAddress
* Description    : ��ȡ����MAC��С��ģʽ��6B-MAC
* Input          : buf: �洢6�ֽڣ�6�ֽڣ�С�ˣ����� MAC
* Return         : None
*******************************************************************************/
void GetMACAddress(PUINT8 buf)
{
    PUINT8  pMAC;
    UINT8   i;
    
    pMAC = (PUINT8)ROM_MAC_ADDR;
    for(i=0; i<6; i++)
    {
        *buf++ = *pMAC++;
    }    
}

/*******************************************************************************
* Function Name  : EnableCodeFlash
* Description    : ���� CodeFlash �����дȨ��
* Input          : None
* Return         : None
*******************************************************************************/
void EnableCodeFlash(void)
{
    R8_FLASH_PROTECT = RB_ROM_WE_MUST_10|RB_ROM_CODE_WE;
}

/*******************************************************************************
* Function Name  : EnableDataFlash
* Description    : ���� DataFlash �����дȨ��
* Input          : None
* Return         : None
*******************************************************************************/
void EnableDataFlash(void)
{
    R8_FLASH_PROTECT = RB_ROM_WE_MUST_10|RB_ROM_DATA_WE;
}

/*******************************************************************************
* Function Name  : LockFlashALL
* Description    : ���� CodeFlash/DataFlash ȫ������
* Input          : None
* Return         : None
*******************************************************************************/
void LockFlashALL(void)
{
    R8_FLASH_PROTECT = RB_ROM_WE_MUST_10;
}


/*******************************************************************************
* Function Name  : Flash_BlockErase
* Description    : CodeFlash �������һ�β���512B��ʹ��ʱ����Ҫ�� EnableFlashCode()/EnableDataFlash() + LockFlashALL() ���ʹ��
* Input          : addr: 32λ��ַ����Ҫ512����,�˵�ַΪ���Ե�ַ
				   	CodeFlash����0 -
				   	DataFlash����0x3e800 -		   				
* Return         : FAILED  - ����
                   status  - ����������
				   SUCCESS - �ɹ�
*******************************************************************************/
UINT8 Flash_BlockErase(UINT32 addr)
{
    UINT8  status = 0;

    if( addr & (0x200-1) )          return FAILED;

    R32_FLASH_ADDR = addr;
    R8_FLASH_COMMAND = ROM_CMD_ERASE;
    status = R8_FLASH_STATUS;
    if( status == RB_ROM_ADDR_OK )  return SUCCESS;
    else                            return status;
}

/*******************************************************************************
* Function Name  : Flash_WriteDW
* Description    : DataFlash ˫��д����ַ��4�ֽڶ��롣ʹ��ʱ����Ҫ�� EnableFlashCode()/EnableDataFlash() + LockFlashALL() ���ʹ��
* Input          : addr: 32λ��ַ����Ҫ512����,�˵�ַΪ���Ե�ַ
				   	CodeFlash����0 -
				   	DataFlash����0x3e800 -
				   dat: 32λд������
* Return         : FAILED  - ����
                   status  - д������
				   SUCCESS - �ɹ�
*******************************************************************************/
UINT8 Flash_WriteDW(UINT32 addr, UINT32 dat)
{
    UINT8  status = 0;

    if( addr & (4-1) )                  return FAILED;

    R32_FLASH_ADDR = addr;
    R32_FLASH_DATA = dat;	
    R8_FLASH_COMMAND = ROM_CMD_PROG;		
    status = R8_FLASH_STATUS;
    if( status == RB_ROM_ADDR_OK )  return SUCCESS;
    else                            return status;
}

