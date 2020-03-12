

/* ϵͳͷ�ļ� */
#include "stm32f10x.h"
#include "systemconfig.h"

/* lkdGui��������ļ� */
#include "lkdGui.h"


int main(void)
{
	SystemconfigInit();
	
	LcdInit();/* lcd��ʼ�� */
	defaultFontInit();/* �ֿ��ʼ�� */
	GuiUpdateDisplayAll();/* ������Ļ-���� */
	
	/* ���� */
	GuiPoint(10, 10, forecolor);
	GuiPoint(15, 15, forecolor);
	/* ��б�� */
	GuiBiasLine(20, 0,40, 20,forecolor);
	GuiBiasLine(30, 0,60, 20,forecolor);
	GuiBiasLine(40, 0,100, 20,forecolor);
	GuiBiasLine(50, 0,159, 20,forecolor);
	/* ��ˮƽ���� */
	GuiHPointLine(0, 22,160, 2, forecolor);
	GuiHPointLine(0, 32,160, 3, forecolor);
	GuiHPointLine(0, 42,160, 4, forecolor);
	GuiHPointLine(0, 52,160, 5, forecolor);
	/* ��ˮƽ�� */
	GuiHLine(0, 62, 160, forecolor);
	/* ����ֱ���� */
	GuiRPointLine(10, 63,100,2, forecolor);
	GuiRPointLine(20, 63,100,3, forecolor);
	GuiRPointLine(30, 63,100,4, forecolor);
	GuiRPointLine(40, 63,100,5, forecolor);
	/* ����ֱ�� */
	GuiRLine(50, 63,100, forecolor);
	/* ������ */
	GuiRect(0, 101, 159,159, forecolor);
	/* �������� */
	GuiFillRect(10, 110, 150,150, forecolor);
	/* �������� */
	GuiFillRect(30, 120, 130,140, backcolor);
	/* ���� */
	GuiUpdateDisplayAll();
	while(1)
	{
		
	}
}
