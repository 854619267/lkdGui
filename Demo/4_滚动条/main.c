

/* ϵͳͷ�ļ� */
#include "stm32f10x.h"
#include "systemconfig.h"

/* lkdGui��������ļ� */
#include "UC1698Driver.h"
#include "lkdGui.h"

int main(void)
{
	SystemconfigInit();
	
	LcdInit();/* lcd��ʼ�� */
	defaultFontInit();/* �ֿ��ʼ�� */
	GuiUpdateDisplayAll();/* ������Ļ-���� */
	
	lkdScroll tScroll;
	tScroll.x = 0;
	tScroll.y = 0;
	tScroll.hight = 160;
	while(1)
	{
		for(uint8_t tMax = 1; tMax < 10; tMax ++){
			tScroll.max = tMax;	
			for(uint8_t i = 0; i < tScroll.max; i ++){
				tScroll.lump = i;/* ���ȿ���� */
				GuiVScroll(&tScroll);/* ˮƽ������ */
				GuiHScroll(&tScroll);/* ��ֱ������ */
				GuiUpdateDisplayAll();/* ���� */
				Delay_ms(500);
			}
		}
	}
}

/* END */
