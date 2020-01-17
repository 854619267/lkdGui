/**
  * @file   menutest.h
  * @author  guoweilkd
  * @version V0.0.0
  * @date    2018/06/30
  * @brief  �˵�ʹ��Demo
  */
#include "menutest.h"
#include "keyDriver.h"
#include "lkdGui.h"

/* �˵����� */
enum MenuKeyIs keyStatus;
/* �˵���� */
lkdMenu HmiMenu;
/* �˵�ջ */
#define MENUSTACK_NUM 8
MenuStack userMenuStack[MENUSTACK_NUM];

/* �������� */
static void HomeFun(void *param);
static void MenuFun(void *param);
static void Win0Fun(void *param);
static void Win1Fun(void *param);
static void Win2Fun(void *param);

/* ���ڶ��� */
lkdWin homeWin = {0,0,160,160,NULL,HomeFun,NULL};/* ���洰�� */
lkdWin menuWin = {0,0,160,160,"�˵�����",MenuFun,NULL};/* �˵����� */
lkdWin win0 = {0,0,160,160,"lkdGui����",Win0Fun,NULL};
lkdWin win1 = {0,0,160,160,"���Դ���",Win1Fun,NULL};
lkdWin win2 = {20,20,140,100,"���Դ���",Win2Fun,NULL};

/* �˵��ڵ㶨�� */
lkdMenuNode Node33 = {33,"�����˵�4", NULL,   NULL,NULL};
lkdMenuNode Node32 = {32,"�����˵�3", &Node33,NULL,NULL};
lkdMenuNode Node31 = {31,"�����˵�2", &Node32,NULL,NULL};
lkdMenuNode Node30 = {30,"�����˵�1", &Node31,NULL,&win2};

lkdMenuNode Node29 = {29,"�����˵�17", NULL,    NULL,NULL};
lkdMenuNode Node28 = {28,"�����˵�16", &Node29, NULL,NULL};
lkdMenuNode Node27 = {27,"�����˵�15", &Node28, NULL,NULL};
lkdMenuNode Node26 = {26,"�����˵�14", &Node27, NULL,NULL};
lkdMenuNode Node25 = {25,"�����˵�13", &Node26, NULL,NULL};
lkdMenuNode Node24 = {24,"�����˵�12", &Node25, NULL,NULL};
lkdMenuNode Node23 = {23,"�����˵�11", &Node24, NULL,NULL};
lkdMenuNode Node22 = {22,"�����˵�10", &Node23, NULL,NULL};
lkdMenuNode Node21 = {21,"�����˵�9",  &Node22, NULL,NULL};
lkdMenuNode Node20 = {20,"�����˵�8",  &Node21, NULL,NULL};

lkdMenuNode Node19 = {19,"�����˵�7", NULL,    NULL,NULL};
lkdMenuNode Node18 = {18,"�����˵�6", &Node19, NULL,NULL};
lkdMenuNode Node17 = {17,"�����˵�5", &Node18, NULL,NULL};
lkdMenuNode Node16 = {16,"�����˵�4", &Node17, NULL,NULL};
lkdMenuNode Node15 = {15,"�����˵�3", &Node16, &Node30,NULL};
lkdMenuNode Node14 = {14,"�����˵�2", &Node15, NULL,&win1};
lkdMenuNode Node13 = {13,"�����˵�1", &Node14, NULL,NULL};

lkdMenuNode Node12 = {12,"һ���˵�12",NULL,   NULL,   NULL};
lkdMenuNode Node11 = {11,"һ���˵�11",&Node12,NULL,		NULL};
lkdMenuNode Node10 = {10,"һ���˵�10",&Node11,NULL,		NULL};
lkdMenuNode Node9 = {9,"һ���˵�9",		&Node10,&Node20,NULL};
lkdMenuNode Node8 = {8,"һ���˵�8",		&Node9,	NULL,		NULL};
lkdMenuNode Node7 = {7,"һ���˵�7",		&Node8,	NULL,		NULL};
lkdMenuNode Node6 = {6,"һ���˵�6",		&Node7,	NULL,		NULL};
lkdMenuNode Node5 = {5,"һ���˵�5",		&Node6,	NULL,		NULL};
lkdMenuNode Node4 = {4,"һ���˵�4",		&Node5,	NULL,		NULL};
lkdMenuNode Node3 = {3,"һ���˵�3",		&Node4,	NULL,		NULL};
lkdMenuNode Node2 = {2,"һ���˵�2",		&Node3,	&Node13,NULL};
lkdMenuNode Node1 = {1,"һ���˵�1",		&Node2,	NULL,		&win0};
lkdMenuNode Node0 = {0,"root",				NULL,	  &Node1,		NULL};


/**
  *@brief  �˵����
  *@param  step ���� pNode �˵��ڵ�
  *@retval None
  */
static void MenuItemDealWith(lkdMenuNode *pNode)
{
	if(pNode->pSon != NULL){//չ��ѡ�нڵ�Ĳ˵�
		GuiMenuCurrentNodeSonUnfold(&HmiMenu);
	}
	else if(pNode->user != NULL){//�򿪲˵���Ӧ�Ĵ���
		GuiWinAdd(pNode->user);
	}
}

/**
  *@brief  �˵����ƺ���
  *@param  None
  *@retval None
  */
void MenuControlFun(void)
{
	switch(keyStatus){
	case MKEY_UP:GuiMenuItemUpMove(&HmiMenu);break;
	case MKEY_DOWN:GuiMenuItemDownMove(&HmiMenu);break;
	case MKEY_LEFT:
	case MKEY_CANCEL:
		GuiMenuCurrentNodeHide(&HmiMenu);
		if(HmiMenu.count == 0){//��⵽�˵��˳��ź�
			GuiWinDeleteTop();
		}break;
	case MKEY_RIGHT:
	case MKEY_OK:
		MenuItemDealWith(GuiMenuGetCurrentpNode(&HmiMenu));
		break;
	}
}
	
/**
  *@brief  �˵���ʼ��
  *@param  None
  *@retval None
  */
void UserMenuInit(void)
{
	HmiMenu.x = 1;
	HmiMenu.y = 16;
	HmiMenu.wide = 158;
	HmiMenu.hight = 142;
	HmiMenu.Itemshigh = 15;
	HmiMenu.ItemsWide = 70;
	HmiMenu.stack = userMenuStack;
	HmiMenu.stackNum = 8;
	HmiMenu.Root = &Node0;/* �˵�������˵��ڵ�󶨵�һ�� */
	HmiMenu.MenuDealWithFun = MenuControlFun;/* �˵����ƻص����� */
	GuiMenuInit(&HmiMenu);
}

/**
  *@brief  ���洰��ʵ��
  *@param  None
  *@retval None
  */
static void HomeFun(void *param)
{
	//�û�Ӧ�ô���:��ͼ��
	static uint8_t step;
	lkdColour forecolor = GuiGetForecolor();
	
	if(step == 0){
		GuiRect(homeWin.x + 10,homeWin.y + 10,homeWin.x + 40,homeWin.y + 40,forecolor);
		step = 1;
	}
	/* ����״̬���� */
	switch(keyStatus){
	case MKEY_UP:break;
	case MKEY_DOWN:break;
	case MKEY_LEFT:break;
	case MKEY_RIGHT:break;
	case MKEY_CANCEL:step = 0;break;
	case MKEY_OK:
		step = 0;
		GuiWinAdd(&menuWin);
		break;
	}
}

/**
  *@brief  �˵�����ʵ��
  *@param  None
  *@retval None
  */
static void MenuFun(void *param)
{
	if(HmiMenu.count == 0){
		GuiMenuCurrentNodeSonUnfold(&HmiMenu);
	}
	HmiMenu.MenuDealWithFun();
}

/**
  *@brief  ����0ʵ�庯��
  *@param  None
  *@retval None
  */
static void Win0Fun(void *param)
{
	//�û�Ӧ�ô���:��ͼ��
	/* ����״̬���� */
	switch(keyStatus){
	case MKEY_UP:break;
	case MKEY_DOWN:break;
	case MKEY_LEFT:break;
	case MKEY_RIGHT:break;
	case MKEY_CANCEL:
		GuiWinDeleteTop();
		GuiMenuRedrawMenu(&HmiMenu);
		break;
	case MKEY_OK:break;
	}
}
/**
  *@brief  ����1ʵ�庯��
  *@param  None
  *@retval None
  */
static void Win1Fun(void *param)
{
	//�û�Ӧ�ô���:��ͼ��
	/* ����״̬���� */
	switch(keyStatus){
	case MKEY_UP:break;
	case MKEY_DOWN:break;
	case MKEY_LEFT:break;
	case MKEY_RIGHT:break;
	case MKEY_CANCEL:
		GuiWinDeleteTop();
		GuiMenuRedrawMenu(&HmiMenu);
		break;
	case MKEY_OK:break;
	}
}
/**
  *@brief  ����2ʵ�庯��
  *@param  None
  *@retval None
  */
static void Win2Fun(void *param)
{
	//�û�Ӧ�ô���:��ͼ��
	
	/* ����״̬���� */
	switch(keyStatus){
	case MKEY_UP:break;
	case MKEY_DOWN:break;
	case MKEY_LEFT:break;
	case MKEY_RIGHT:break;
	case MKEY_CANCEL:
		GuiWinDeleteTop();
		GuiMenuRedrawMenu(&HmiMenu);
		break;
	case MKEY_OK:break;
	}
}

/**
  *@brief  �û��˵�������
  *@param  None
  *@retval None
  */
void userAppMain(void)
{
	keyStatus = GetMenuKeyState();
	SetMenuKeyIsNoKey();
	GuiWinDisplay();
}

/**
  *@brief  �û�Ӧ�ó�ʼ��
  *@param  None
  *@retval None
  */
void userAppInit(void)
{
	UserMenuInit();
	GuiSetForecolor(1);
	GuiSetbackcolor(0);
	GuiWinAdd(&homeWin);
}

/* END */
