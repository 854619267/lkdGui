/**
  * @file   lcdDriverPort.c
  * @author  guoweilkd
  * @version V0.0.0
  * @date    2018/04/18
  * @brief  lkdGuiҺ����ʾ�������ӿڣ�����ֲ����亯���ľ������ݡ�
  */

#include <stdint.h>
#include "lkdGui.h"

/**
  *@brief ��Gui������������ʾ��lcd��
  *@param  None
  *@retval None
  */
void GuiUpdateDisplayAll(void)
{

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

}

/**
  *@brief ����ʾ
  *@param  None
  *@retval None
  */
void OpenLcdDisplay(void)
{

}