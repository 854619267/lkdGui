/**
  * @file   userFontPort.c
  * @author  guoweilkd
  * @version V0.0.0
  * @date    2018/04/18
  * @brief  lkdGui���������ӿڣ�����ֲ����亯���ľ������ݡ�
  */

/* ��ģ����:���ú��� */

#include <stdint.h>
#include "lkdGui.h"
#include "GT21L16S2W.h"

extern const unsigned char gb2312_12_12[8178][24];
extern const unsigned char ASCII_6_12[128][12];
extern const unsigned char ASCII_64_64[128][64*8];
extern unsigned char ASCII_8_16[96][16];
/* �������ʵ�� */
static lkdFont defaultFont;

/**
  *@brief ��ȡ������ģ
  *@param  code1, ���� 
  *@param  pBuff ��ģbuff,������ѭ�������ģ����
  *@retval 0
  */
static uint8_t GetDfontData(uint8_t code1, uint8_t code2,uint8_t *pBuff)
{
    /* ����û����� */
//	uint16_t offset;
//	
//	offset = ((code1 - 0xA1)*94 + (code2 - 0xA1));
//	for(uint8_t i = 0; i < 24; i++){
//		pBuff[i] = gb2312_12_12[offset][i];
//	}
extern uint8_t GetFontGb2312_12_12(uint8_t codeH, uint8_t codeL, uint8_t *pBuff);
GetFontGb2312_12_12(code1,code2,pBuff);
	//gt_12_GetData(code1,code2,pBuff);
    return 0;
}


/**
  *@brief ��ȡASCII��ģ
  *@param  code1, ���� 
  *@param  pBuff ��ģbuff,������ѭ�������ģ����
  *@retval 0
  */
static uint8_t GetSfontData(uint8_t code1, uint8_t *pBuff)
{
	uint16_t offset = code1 - 32; 
    /* ����û����� */
//	for(uint8_t i = 0; i < 16; i++){
//		pBuff[i] = ASCII_8_16[offset][i];
//	}
//	for(uint16_t i = 0; i < 512; i++){
//		pBuff[i] = ASCII_64_64[code1][i];
//	}
//extern uint8_t GetFontASCII_8_16(uint8_t code1, uint8_t *pBuff);
	//GetFontASCII_8_16(code1,pBuff);
	ASCII_GetData(code1,ASCII_6X12,pBuff);
    return 0;
}

/**
  *@brief �����ʼ��
  *@param  None
  *@retval None
  */
void defaultFontInit(void)
{
    /* ��������Ҫ������Ӧ���޸� */

    /* ��buff�Ĵ�С�������ģ��С���� */
	static uint8_t dataBuff[64*8];

	defaultFont.name = "������ģΪ12*12��GB2312,ASCII��ģΪ5*7";
	defaultFont.dhigh = 12;
	defaultFont.dwide = 12;
	defaultFont.shigh = 16;
	defaultFont.swide = 8;
	defaultFont.pZmBuff = dataBuff;
	defaultFont.getDfont = GetDfontData;
	defaultFont.getSfont = GetSfontData;

    /* ����ΪϵͳĬ������ */
	GuiFontSet(&defaultFont);
}

/* END */
