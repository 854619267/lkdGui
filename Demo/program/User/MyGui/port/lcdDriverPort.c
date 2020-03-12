/**
  * @file   lcdDriverPort.c
  * @author  guoweilkd
  * @version V0.0.0
  * @date    2018/04/18
  * @brief  lkdGuiҺ����ʾ�������ӿڣ�����ֲ����亯���ľ������ݡ�
  */

#include <stdint.h>
#include "lkdGui.h"
#include "UC1698Driver.h"

/* Gui��ʾ������ */
static uint8_t  lkdGuiBuff[GUIYMAX][GUIXMAX/8 + GUIXMAX%8];
/* ��λ��ȡ���� */
const static uint8_t colBit[] = {0x80, 0x40, 0x20, 0x10, 0x08, 0x04, 0x02, 0x01};

/**
  *@brief ��Gui������������ʾ��lcd��
  *@param  None
  *@retval None
  */
void GuiUpdateDisplayAll(void)
{
	uint32_t x,y;
	LCD_CS_LOW();
	SetLcdCol(0x25);
	SetLcdRow(0);
	LCD_RS_HIGH();
	LCD_RD_HIGH();
	for(y = 0; y < GUIYMAX; y++){
		for(x = 0;x < 20; x++){
			Write8DotsUC1698U(lkdGuiBuff[y][x]);
		}
		WriteLcdData(0x00);
	}
	LCD_CS_HIGH();
}

/**
  *@brief ��Guiָ��������������ʾ��lcd��
  *@param  beginx,beginy,endx,endy ����
  *@retval None
  */
void GuiRangeUpdateDisplay(lkdCoord beginx, lkdCoord beginy,lkdCoord endx, lkdCoord endy)
{
	
}

/**
  *@brief �򻺳�������
  *@param  x,y ����
  *@param  color ��ɫ <Ŀǰֻ�к�:CBLACK ��:CWHITLE>
  *@retval None
  */
void GuiDrawPoint(lkdCoord x, lkdCoord y, lkdColour color)
{
	if(color == CWHITLE){//��ɫ
		lkdGuiBuff[y][x >> 3] &= ~colBit[x & 0x07];
	}
	else{//��ɫ
		lkdGuiBuff[y][x >> 3] |= colBit[x & 0x07];
	}
}

/**
  *@brief ��ȡ��ǰ��ʾ�ĵ�
  *@param  x,y ����
  *@param  color ��ɫ <Ŀǰֻ�к�:CBLACK ��:CWHITLE>
  *@retval None
  */
void  GuiReadPoint(lkdCoord x, lkdCoord y, lkdColour *pColor)
{
	
}

/**
  *@brief ����ʾ
  *@param  None
  *@retval None
  */
void CloseLcdDisplay(void)
{
	Uc1698CloseLcdDisplay();
}

/**
  *@brief ����ʾ
  *@param  None
  *@retval None
  */
void OpenLcdDisplay(void)
{
	Uc1698CloseLcdDisplay();
}

/* END */
