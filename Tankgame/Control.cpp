#include<iostream>	
using namespace std;
#include"Control.h"
#include"Map.h"
#include"Console.h"
#include"Tank.h"


Control::Control(int _flag)
{
	flag = _flag;
}

Control::~Control()
{
}


int Control::start() {				//������ʼ
	Console console;				//��ʼ������̨
	Map map;						//��ʼ����ͼ
	Tank tank(100,0,1,yellow,0);
	//map.show();						//�����ͼ	Tank tank(100, 0, 1, yellow);	//�½�һ������̹��
	tank.append(map);				//���̹�˽���ͼ--����ֱ�����
	while (true)
	{
		map.show();
	}
	

	system("pause");
	return 0;
}
