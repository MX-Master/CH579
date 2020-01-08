


#ifndef __CH57x_FLASH_H__
#define __CH57x_FLASH_H__

#ifdef __cplusplus
 extern "C" {
#endif

#include "CH579SFR.h"
#include "core_cm0.h"
     
#define ROM_UUID_ADDR        0x40608         // chip UID address ( ID-48bit + CKS-16bit )
#define ROM_MAC_ADDR         0x40608         // NET MAC address 48bit

// ��ȡΨһID
void GetUniqueID(PUINT8 buf);                                           /* ��ȡоƬΨһID��С��ģʽ��6B-ID�� 2B-CKS */    
     
// ��ȡ����MAC
void GetMACAddress(PUINT8 buf);                                         /* ��ȡ����MAC��С��ģʽ��6B-MAC */    
	 

void EnableCodeFlash(void);                                             /* ���� CodeFlash �����дȨ�� */
void EnableDataFlash(void);                                             /* ���� DataFlash �����дȨ�� */
void LockFlashALL(void);                                                /* ���� CodeFlash/DataFlash ȫ������ */
UINT8 Flash_BlockErase(UINT32 addr);                                    /* �������һ�β���512B��ʹ��ʱ����Ҫ�� EnableFlashCode()/EnableDataFlash() + LockFlashALL() ���ʹ�� */
UINT8 Flash_WriteDW(UINT32 addr, UINT32 dat);	                        /* ˫��д����ַ��4�ֽڶ��롣ʹ��ʱ����Ҫ�� EnableFlashCode()/EnableDataFlash() + LockFlashALL() ���ʹ�� */
	 
	 
#ifdef __cplusplus
}
#endif

#endif  // __CH57x_FLASH_H__	

