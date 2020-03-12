

/* ϵͳͷ�ļ� */
#include "stm32f10x.h"
#include "systemconfig.h"

/* lkdGui��������ļ� */
#include "UC1698Driver.h"
#include "lkdGui.h"

void TextDisplay1(void);
void TextDisplay2(void);

int main(void)
{
	SystemconfigInit();
	
	LcdInit();/* lcd��ʼ�� */
	defaultFontInit();/* �ֿ��ʼ�� */
	GuiUpdateDisplayAll();/* ������Ļ-���� */
	
	
	while(1)
	{
		TextDisplay1();
		Delay_ms(2000);
		TextDisplay2();
		Delay_ms(2000);
	}
}

void TextDisplay1(void)
{
	uint8_t *textStr = "lkdGui��һ��Ϊ��ɫ��������Gui������ֲ����,ʹ�ü�...��";
	
	fontTextInfo textInfo;/* �����ı���Ϣ�ṹ */
	
	GuiFillRect(0, 0, 159,159, backcolor);/* ���� */
	
	/* -----------1--------------- */
	textInfo.x = 2;/* �ı���ʼ���� */
	textInfo.y = 2;
	textInfo.wide = 156;/* �ı���Χ��С */
	textInfo.high = 42;
	textInfo.wInterval = 0;/* �ַ���� */
	textInfo.hInterval = 2;/* �м�� */
	textInfo.flag = 0;/* ������ */
	textInfo.beginOffset = thisFont->dwide * 2;/* ��ʼƫ��,�������� */
	GuiText(&textInfo, textStr);
	GuiRect(0, 0, 159,44, forecolor);
	
	/* -----------2--------------- */
	GuiFillRect(0, 48, 159,92, forecolor);
	textInfo.x = 2;/* �ı���ʼ���� */
	textInfo.y = 50;
	textInfo.flag = 1;/* ���� */
	textInfo.beginOffset = thisFont->dwide * 2;/* ��ʼƫ��,�������� */
	GuiText(&textInfo, textStr);
	
	/* -----------3---------------- */
	textInfo.x = 2;/* �ı���ʼ���� */
	textInfo.y = 98;
	textInfo.flag = 1;/* ���� */
	textInfo.beginOffset = thisFont->dwide * 2;/* ��ʼƫ��,�������� */
	GuiText(&textInfo, textStr);
	GuiRect(0, 96, 159,140, forecolor);
	
	/* ���� */
	GuiUpdateDisplayAll();
}

void TextDisplay2(void)
{
	uint8_t *textStr;
	
	fontTextInfo textInfo;/* �����ı���Ϣ�ṹ */
	
	GuiFillRect(0, 0, 159,159, backcolor);/* ���� */
	
	/* -----------4--------------- */
	textStr = "lkdGui�ı���ʾ���ԣ���ǰ�ַ����Ϊ0���أ��м��Ϊ0���ء�";
	textInfo.x = 2;/* �ı���ʼ���� */
	textInfo.y = 2;
	textInfo.wide = 156;/* �ı���Χ��С */
	textInfo.high = 42;
	textInfo.wInterval = 0;/* �ַ���� */
	textInfo.hInterval = 0;/* �м�� */
	textInfo.flag = 0;/* ������ */
	textInfo.beginOffset = thisFont->dwide * 2;/* ��ʼƫ��,�������� */
	GuiText(&textInfo, textStr);
	GuiRect(0, 0, 159,44, forecolor);
	
	/* -----------5--------------- */
	textStr = "lkdGui�ı���ʾ���ԣ���ǰ�ַ����Ϊ2���أ��м��Ϊ2���ء�";
	textInfo.x = 2;/* �ı���ʼ���� */
	textInfo.y = 50;
	textInfo.wInterval = 2;/* �ַ���� */
	textInfo.hInterval = 2;/* �м�� */
	textInfo.flag = 0;/* ������ */
	textInfo.beginOffset = thisFont->dwide * 2;/* ��ʼƫ��,�������� */
	GuiText(&textInfo, textStr);
	GuiRect(0, 48, 159,92, forecolor);
	
	/* -----------6--------------- */
	textStr = "lkdGui�ı���ʾ���ԣ���ǰ�ַ����Ϊ4���أ��м��Ϊ3���ء�";
	textInfo.x = 2;/* �ı���ʼ���� */
	textInfo.y = 98;
	textInfo.high = 60;
	textInfo.wInterval = 4;/* �ַ���� */
	textInfo.hInterval = 3;/* �м�� */
	textInfo.flag = 0;/* ������ */
	textInfo.beginOffset = thisFont->dwide * 2;/* ��ʼƫ��,�������� */
	GuiText(&textInfo, textStr);
	GuiRect(0, 96, 159,159, forecolor);
	
	/* ���� */
	GuiUpdateDisplayAll();
}

/* END */
