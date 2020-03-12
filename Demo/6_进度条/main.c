

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
	
	lkdProgress tProGress;
	uint8_t ratioStr[8];
	tProGress.x = 5;
	tProGress.y = 20;
	tProGress.wide = 130;
	tProGress.high = thisFont->dhigh;
	tProGress.ratio = 0;
	while(1)
	{
		for(uint8_t i = 0; i < 100; i ++){
			tProGress.ratio = i;/* ���ȿ��� */
			GuiProGress(&tProGress);/* �������� */
			sprintf((char *)ratioStr,"%d%%",tProGress.ratio);
			GuiFillRect(137,21,157,33,backcolor);
			GuiRowText(137,21,20,FONT_RIGHT,ratioStr);
			GuiUpdateDisplayAll();/* ���� */
			Delay_ms(500);
		}
	}
}

/* END */
