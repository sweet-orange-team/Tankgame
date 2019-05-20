#include<iostream>	
using namespace std;
#include"Control.h"
#include"Map.h"
#include"Console.h"
#include"Tank.h"
#include"Prop.h"
#include<time.h>
#include<conio.h>


Control::Control(int _flag)
{
	Console console;
	console.setCursorPosition(1, 20);
}

Control::~Control()
{
}

int Control::menu()
{
    char* n = u8"��";
    Console::setCursorPosition(3,51);
    Console::setColor(red);
    cout << "̹  ��  ��  ս";
    Console::setColor(gray);
    Console::setCursorPosition(7, 0);
    for (int i = 1; i < 60; i++)
    {
        cout << Console::U2G(n);
    }
    Console::setCursorPosition(8, 49);
    Console::setColor(white);
    cout << "a��d�ƶ���꣬yȷ��";
    Console::setCursorPosition(9, 0);
    Console::setColor(gray);
    for (int i = 1; i < 60; i++)
    {
        cout << Console::U2G(n);
    }
    Console::setCursorPosition(16, 45);
    Console::setColor(white);
    cout << ">>��ʼ��Ϸ";
    int j = 1;
    Console::setCursorPosition(16, 63);
    Console::setColor(gray);
    cout << "�˳���Ϸ";
    Console::setColor(white);
    Console::setCursorPosition(24, 0);
    Console::setColor(gray);
    for (int i = 1; i < 60; i++)
    {
        cout << Console::U2G(n);
    }
    Console::setCursorPosition(25, 46);
    Console::setColor(white);
    cout << "Made";
    Console::setColor(gray);
    cout << " by ";
    Console::setColor(yellow);
    cout<<"Sweet-Orange-Team";
    Console::setColor(white);
    Console::setCursorPosition(26, 0);
    for (int i = 1; i < 60; i++)
    {
        cout << Console::U2G(n);
    }
    while (1)
    {
        char op=_getch();
        switch(op)
        {
            case 'a':
            {
                if (j == 0)
                {
                    Console::setCursorPosition(16, 45);
                    Console::setColor(white);
                    cout << ">>��ʼ��Ϸ";
                    Console::setCursorPosition(16, 61);
                    Console::setColor(gray);
                    cout << "  �˳���Ϸ";
                    Console::setColor(white);
                    j = 1;
                }
                break;
            }
            case 'd':
            {
                if (j == 1)
                {
                    Console::setCursorPosition(16, 45); 
                    Console::setColor(gray);
                    cout << "  ��ʼ��Ϸ";
                    Console::setColor(white);
                    Console::setCursorPosition(16, 61);
                    cout << ">>�˳���Ϸ";
                    j = 0;
                }
                break;
            }
            case 'y':
            {
                if (j == 0) return -1;
                else return 1;
                break;
            }
            default:
                break;
        }
    }
}

int Control::start() {				//������ʼ
	Console console;				//��ʼ������̨
	Map map;						//��ʼ����ͼ
	map.show();
	TankUser mytank = TankUser();
	TankEnemies enemies = TankEnemies();
    props p = props();
	mytank.show();
    int count=0;
    int num=0;
    while (true)
    {
        console.checkKey(mytank);
        mytank.bulletMove();
        enemies.allEnemyMove();
        map.refresh();

        //prop.refresh
        {
        if (count% 125==0)
        {
            p.initProp(mytank);
            count = 0;
        }
        if (count == 0)
        {
            if (p.prop1->IsGet(mytank))
            {
                p.prop1->isGet(mytank);
                num = 1;
            }
            else if (p.prop2->IsGet(mytank))
            {
                p.prop2->isGet(mytank);
                num = 2;
            }
        }
        if (count == 125)
        {
            switch (num)
            {
            case 1:
            {
                p.prop1->Recover(mytank);
                p.prop1->clearProp();
                delete p.prop1;
                break;
            }
            case 2:
            {
                p.prop2->Recover(mytank);
                p.prop2->clearProp();
                delete p.prop2;
                break;
            }
            }
        }
    }

		if (!mytank.isAlive())break;
		Sleep(80);
        count++;
	}

	system("pause");
	system("cls");
	system("pause");
	return 0;
}

