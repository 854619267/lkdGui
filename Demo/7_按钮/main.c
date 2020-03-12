

/* ϵͳͷ�ļ� */
#include "stm32f10x.h"
#include "systemconfig.h"
#include "stdio.h"

/* lkdGui��������ļ� */
#include "UC1698Driver.h"
#include "lkdGui.h"

int main(void)
{
	SystemconfigInit();
	
	LcdInit();/* lcd��ʼ�� */
	defaultFontInit();/* �ֿ��ʼ�� */
	GuiUpdateDisplayAll();/* ������Ļ-���� */
	
	lkdButton tButton;
	
	tButton.x = 20;
	tButton.y = 50;
	tButton.wide = thisFont->dwide * 2 + 15;
	tButton.high = thisFont->dhigh + 5;
	tButton.name = "ȷ��";
	tButton.flag = 0;/* ̧��״̬ */
	
	GuiButton(&tButton);
	tButton.x = 80;
	tButton.y = 50;
	tButton.wide = thisFont->dwide * 2 + 15;
	tButton.high = thisFont->dhigh + 5;
	tButton.name = "ȡ��";
	tButton.flag = 1;/* ����״̬ */
	GuiButton(&tButton);
	
	tButton.x = 10;
	tButton.y = 80;
	tButton.wide = thisFont->dwide * 4 + 15;
	tButton.high = thisFont->dhigh + 5;
	tButton.name = "ȷ��ִ��";
	tButton.flag = 0;/* ̧��״̬ */
	
	GuiButton(&tButton);
	tButton.x = 80;
	tButton.y = 80;
	tButton.wide = thisFont->dwide * 4 + 15;
	tButton.high = thisFont->dhigh + 5;
	tButton.name = "ȷ��ִ��";
	tButton.flag = 1;/* ����״̬ */
	GuiButton(&tButton);
	
	tButton.x = 10;
	tButton.y = 110;
	tButton.wide = thisFont->dwide * 4 + 15;
	tButton.high = thisFont->dhigh * 2 + 5;
	tButton.name = "ȷ��ִ��";
	tButton.flag = 0;/* ̧��״̬ */
	
	GuiButton(&tButton);
	tButton.x = 80;
	tButton.y = 110;
	tButton.wide = thisFont->dwide * 4 + 15;
	tButton.high = thisFont->dhigh * 2 + 5;
	tButton.name = "ȷ��ִ��";
	tButton.flag = 1;/* ����״̬ */
	GuiButton(&tButton);
	
	GuiUpdateDisplayAll();/* ���� */
	while(1)
	{
	}
}

/* END */
