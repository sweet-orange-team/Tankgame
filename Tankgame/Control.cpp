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
    char* n = u8"■";
    Console::setCursorPosition(3,51);
    Console::setColor(red);
    cout << "坦  克  大  战";
    Console::setColor(gray);
    Console::setCursorPosition(7, 0);
    for (int i = 1; i < 60; i++)
    {
        cout << Console::U2G(n);
    }
    Console::setCursorPosition(8, 49);
    Console::setColor(white);
    cout << "a、d移动光标，y确定";
    Console::setCursorPosition(9, 0);
    Console::setColor(gray);
    for (int i = 1; i < 60; i++)
    {
        cout << Console::U2G(n);
    }
    Console::setCursorPosition(16, 45);
    Console::setColor(white);
    cout << ">>开始游戏";
    int j = 1;
    Console::setCursorPosition(16, 63);
    Console::setColor(gray);
    cout << "退出游戏";
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
                    cout << ">>开始游戏";
                    Console::setCursorPosition(16, 61);
                    Console::setColor(gray);
                    cout << "  退出游戏";
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
                    cout << "  开始游戏";
                    Console::setColor(white);
                    Console::setCursorPosition(16, 61);
                    cout << ">>退出游戏";
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

int Control::start() {				//主程序开始
	Console console;				//初始化控制台
	Map map;						//初始化地图
	map.show();
	TankUser mytank = TankUser();
	TankEnemies enemies = TankEnemies();
    props p = props();
	mytank.show();
    while (true)
    {
        console.checkKey(mytank);
        mytank.bulletMove();
        enemies.allEnemyMove();
        p.UseProp(mytank);
        map.refresh();
		if (!mytank.isAlive())break;
		Sleep(40);
	}
	system("pause");
	system("cls");
	system("pause");
	return 0;
}
