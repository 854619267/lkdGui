

/* ϵͳͷ�ļ� */
#include "stm32f10x.h"
#include "systemconfig.h"

/* lkdGui��������ļ� */
#include "UC1698Driver.h"

/* lkdGui���ļ� */
#include "lkdGui.h"
#include "menutest.h"
#include "keyDriver.h"
#include "zikuSpi.h"

extern void defaultFontInit(void);

int main(void)
{
	SystemconfigInit();
	
	ZiKuInit();
	LcdInit();/* lcd��ʼ�� */
	defaultFontInit();/* �ֿ��ʼ�� */
	GuiUpdateDisplayAll();/* ������Ļ-���� */
	userAppInit();
	KeyDriverInit();
	
	//GuiRowText(15, 20,150, FONT_MID,"abcdefghijklmn");
	//GuiRowText(15, 30,150, FONT_MID,"opqrstuvwxyz");
	//GuiRowText(15, 40,150, FONT_MID,"~!@#$%^&*()_+-=");
	//GuiRowText(15, 50,150, FONT_MID,"{}[]|\\<>,.:;""'/");
	//GuiRowText(15, 50,150, FONT_MID,"ABCDEFGHIJKLMN");
	//GuiRowText(15, 60,150, FONT_MID,"OPQRSTUVWXYZ");
	GuiRowText(15, 70,150, FONT_MID,"�����˽���");
	char stris[8] = {11,'\0'};
	//GuiRowText(15, 20,150, FONT_MID,stris);
	GuiUpdateDisplayAll();
	while(1)
	{
		userAppMain();
		ScanKeyStatus();
	}
}


/* END */
