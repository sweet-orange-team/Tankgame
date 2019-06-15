#include<iostream>	
using namespace std;
#include"Control.h"
#include"Map.h"
#include"Console.h"
#include"Tank.h"
#include"Prop.h"
#include"Barrier.h"
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

void Control::tankl(int x, int y)       //左边坦克
{
	Console::setColor(yellow);
	Console::setCursorPosition(x, y);
	cout << "■■";
	Console::setCursorPosition(x - 1, y);
	cout << "  ■■";
	Console::setCursorPosition(x - 2, y);
	cout << "■■";
	Console::setColor(white);
}

void Control::tankr(int x, int y)        //右边坦克
{
	Console::setColor(red);
	Console::setCursorPosition(x, y);
	cout << "  ■■";
	Console::setCursorPosition(x - 1, y);
	cout << "■■";
	Console::setCursorPosition(x - 2, y);
	cout << "  ■■";
	Console::setColor(white);
}

void Control::clear(int x, int y)        //清除
{
	Console::setCursorPosition(x, y);
	cout << "      ";
	Console::setCursorPosition(x - 1, y);
	cout << "      ";
	Console::setCursorPosition(x - 2, y);
	cout << "      ";
}

void Control::animation()                
{
    //撞击后清除
	int x1 = 15, y1 = 26, x2 = 15, y2 = 86;
	while (y1 + 6 <= y2)
	{
		tankl(x1, y1);
		tankr(x2, y2);
		Sleep(100);
		clear(x1, y1);
		clear(x2, y2);
		y1 += 2;
		y2 -= 2;
	}
	clear(x1, y1);
	clear(x2, y2);


	//坦克大战
	//                                                                                                                          
	//    ■                      //          ■            //            ■              //    ■         ■   ■
	//    ■      ■■■■■■■  //■■■■■■■■■■■  //            ■              //    ■         ■    ■
	//    ■      ■          ■  //          ■            //■■■■■■■■■■■■■  //    ■■■■   ■■■■■
	// ■■■■   ■          ■  //   ■■■■■■■■     //            ■              //    ■     ■■■
	//    ■      ■■■■■■■  //   ■            ■     //           ■■             //    ■         ■  ■
	//    ■      ■          ■  //   ■            ■     //           ■  ■           //■■■■■■    ■ ■
	//    ■      ■          ■  //    ■■■■■■■      //         ■     ■          //■        ■    ■■
	//    ■      ■          ■  //       ■    ■         //       ■         ■        //■        ■    ■      ■
	//    ■■■   ■■■■■■   //      ■     ■       ■//     ■             ■      //■■■■■■   ■ ■    ■
	//■■■                      //    ■       ■       ■//   ■                 ■■■//■           ■     ■  ■
	//  ■     ■■■■■■■■■ //■■           ■■■■ // ■                     ■  //           ■         ■■
	//                                                                                                              ■ 

	Console::setColor(9);
	Console::setCursorPosition(9, 3);
	cout << "    ■                      ";
	Console::setCursorPosition(10, 3);
	cout << "    ■      ■■■■■■■  ";
	Console::setCursorPosition(11, 3);
	cout << "    ■      ■          ■  ";
	Console::setCursorPosition(12, 3);
	cout << " ■■■■   ■          ■  ";
	Console::setCursorPosition(13, 3);
	cout << "    ■      ■■■■■■■  ";
	Console::setCursorPosition(14, 3);
	cout << "    ■      ■          ■  ";
	Console::setCursorPosition(15, 3);
	cout << "    ■      ■          ■  ";
	Console::setCursorPosition(16, 3);
	cout << "    ■      ■          ■  ";
	Console::setCursorPosition(17, 3);
	cout << "    ■■■   ■■■■■■   ";
	Console::setCursorPosition(18, 3);
	cout << "■■■                      ";
	Console::setCursorPosition(19, 3);
	cout << "  ■     ■■■■■■■■■ ";
	Sleep(300);

	Console::setColor(14);
	Console::setCursorPosition(9, 3);
	cout << "    ■                                  ■              ";
	Console::setCursorPosition(10, 3);
	cout << "    ■      ■■■■■■■    ■■■■■■■■■■■    ";
	Console::setCursorPosition(11, 3);
	cout << "    ■      ■          ■              ■              ";
	Console::setCursorPosition(12, 3);
	cout << " ■■■■   ■          ■       ■■■■■■■■       ";
	Console::setCursorPosition(13, 3);
	cout << "    ■      ■■■■■■■       ■            ■       ";
	Console::setCursorPosition(14, 3);
	cout << "    ■      ■          ■       ■            ■       ";
	Console::setCursorPosition(15, 3);
	cout << "    ■      ■          ■        ■■■■■■■        ";
	Console::setCursorPosition(16, 3);
	cout << "    ■      ■          ■           ■    ■           ";
	Console::setCursorPosition(17, 3);
	cout << "    ■■■   ■■■■■■           ■     ■       ■  ";
	Console::setCursorPosition(18, 3);
	cout << "■■■                            ■       ■       ■  ";
	Console::setCursorPosition(19, 3);
	cout << "  ■     ■■■■■■■■■   ■■           ■■■■   ";
	Sleep(300);

	Console::setColor(11);
	Console::setCursorPosition(9, 3);
	cout << "    ■                                  ■                          ■                ";
	Console::setCursorPosition(10, 3);
	cout << "    ■      ■■■■■■■    ■■■■■■■■■■■                ■                ";
	Console::setCursorPosition(11, 3);
	cout << "    ■      ■          ■              ■              ■■■■■■■■■■■■■■  ";
	Console::setCursorPosition(12, 3);
	cout << " ■■■■   ■          ■       ■■■■■■■■                   ■                ";
	Console::setCursorPosition(13, 3);
	cout << "    ■      ■■■■■■■       ■            ■                  ■■               ";
	Console::setCursorPosition(14, 3);
	cout << "    ■      ■          ■       ■            ■                  ■  ■             ";
	Console::setCursorPosition(15, 3);
	cout << "    ■      ■          ■        ■■■■■■■                 ■     ■            ";
	Console::setCursorPosition(16, 3);
	cout << "    ■      ■          ■           ■    ■                  ■         ■          ";
	Console::setCursorPosition(17, 3);
	cout << "    ■■■   ■■■■■■           ■     ■       ■       ■             ■        ";
	Console::setCursorPosition(18, 3);
	cout << "■■■                            ■       ■       ■     ■                 ■■■  ";
	Console::setCursorPosition(19, 3);
	cout << "  ■     ■■■■■■■■■   ■■           ■■■■    ■                     ■    ";
	Sleep(300);

	Console::setColor(4);
	Console::setCursorPosition(9, 3);
	cout << "    ■                                  ■                          ■                    ■         ■   ■";
	Console::setCursorPosition(10, 3);
	cout << "    ■      ■■■■■■■    ■■■■■■■■■■■                ■                    ■         ■    ■";
	Console::setCursorPosition(11, 3);
	cout << "    ■      ■          ■              ■              ■■■■■■■■■■■■■■      ■■■■   ■■■■■";
	Console::setCursorPosition(12, 3);
	cout << " ■■■■   ■          ■       ■■■■■■■■                   ■                    ■     ■■■";
	Console::setCursorPosition(13, 3);
	cout << "    ■      ■■■■■■■       ■            ■                  ■■                   ■         ■  ■";
	Console::setCursorPosition(14, 3);
	cout << "    ■      ■          ■       ■            ■                  ■  ■             ■■■■■■    ■ ■";
	Console::setCursorPosition(15, 3);
	cout << "    ■      ■          ■        ■■■■■■■                 ■     ■            ■        ■    ■■";
	Console::setCursorPosition(16, 3);
	cout << "    ■      ■          ■           ■    ■                  ■         ■          ■        ■    ■      ■";
	Console::setCursorPosition(17, 3);
	cout << "    ■■■   ■■■■■■           ■     ■       ■       ■             ■        ■■■■■■   ■ ■    ■";
	Console::setCursorPosition(18, 3);
	cout << "■■■                            ■       ■       ■     ■                 ■■■  ■           ■     ■  ■";
	Console::setCursorPosition(19, 3);
	cout << "  ■     ■■■■■■■■■   ■■           ■■■■    ■                     ■               ■         ■■";
	Console::setCursorPosition(20, 3);
	cout << "                                                                                                              ■";
	Sleep(500);
	system("cls");
	Console::setColor(white);
}

int Control::menu()                       //菜单
{
	char* n = u8"■";
	Console::setCursorPosition(3, 51);
	Console::setColor(red);
	cout << "坦  克  大  战";
	Console::setColor(gray);
	Console::setCursorPosition(7, 0);
	for (int i = 1; i < 60; i++)
	{
		cout << Console::U2G(n);
	}
	Console::setCursorPosition(8, 49);
	Console::setColor(3);
	cout << "a、d移动光标，y确定";
	Console::setCursorPosition(9, 0);
	Console::setColor(gray);
	for (int i = 1; i < 60; i++)
	{
		cout << Console::U2G(n);
	}
	Console::setCursorPosition(16, 34);
	Console::setColor(white);
	cout << ">>开始游戏";
	Console::setCursorPosition(16, 54);
	Console::setColor(gray);
	cout << "退出游戏";
	Console::setCursorPosition(16, 72);
	cout << "操作指南";
	Console::setColor(white);
	Console::setCursorPosition(24, 0);
	Console::setColor(gray);
	for (int i = 1; i < 60; i++)
	{
		cout << Console::U2G(n);
	}
	Console::setCursorPosition(25, 46);
	Console::setColor(14);
	cout << "Made by ";
	Console::setColor(yellow);
	cout << "Sweet-Orange-Team";
	Console::setColor(white);
	Console::setCursorPosition(26, 0);
	for (int i = 1; i < 60; i++)
	{
		cout << Console::U2G(n);
	}
	int j = 1;
	while (1)                  //判断光标移动
	{
		char op = _getch();
		switch (op)
		{
		case 'a':
		{
			if (j == 0)
			{
				Console::setCursorPosition(16, 34);
				Console::setColor(white);
				cout << ">>开始游戏";
				Console::setCursorPosition(16, 52);
				Console::setColor(gray);
				cout << "  退出游戏";
				Console::setCursorPosition(16, 70);
				cout << "  操作指南";
				Console::setColor(white);
				j = 1;
			}
			else if (j == 2)
			{
				Console::setCursorPosition(16, 34);
				Console::setColor(gray);
				cout << "  开始游戏";
				Console::setCursorPosition(16, 70);
				cout << "  操作指南";
				Console::setCursorPosition(16, 52);
				Console::setColor(white);
				cout << ">>退出游戏";
				j = 0;
			}
			break;
		}
		case 'd':
		{
			if (j == 1)
			{
				Console::setCursorPosition(16, 34);
				Console::setColor(gray);
				cout << "  开始游戏";
				Console::setCursorPosition(16, 70);
				cout << "  操作指南";
				Console::setColor(white);
				Console::setCursorPosition(16, 52);
				cout << ">>退出游戏";
				j = 0;
			}

			else if (j == 0)
			{
				Console::setCursorPosition(16, 34);
				Console::setColor(gray);
				cout << "  开始游戏";
				Console::setCursorPosition(16, 52);
				cout << "  退出游戏";
				Console::setColor(white);
				Console::setCursorPosition(16, 70);
				cout << ">>操作指南";
				j = 2;
			}
			break;
		}
		case 'y':                     //判断选择
		{
			if (j == 0) return 0;
			else if (j == 2)
			{
				system("cls");
				Console::setColor(3);
				Console::setCursorPosition(1, 3);
				cout << "b键开始游戏...";
				Console::setCursorPosition(6, 5);
				Console::setColor(3);
				cout << "移动";
				Console::setCursorPosition(6, 12);
				Console::setColor(white);
				cout << "w 向上移动   s 向下移动";
				Console::setCursorPosition(7, 12);
				cout << "a 向左移动   d 向右移动";
				Console::setCursorPosition(8, 12);
				cout << "p 暂停       空格 发射子弹";
				Console::setCursorPosition(10, 5);
				Console::setColor(3);
				cout << "道具";
				Console::setCursorPosition(10, 12);
				Console::setColor(14);
				cout << "● ";
				Console::setColor(white);
				cout << "高级子弹:增加伤害";
				Console::setCursorPosition(11, 12);
				Console::setColor(14);
				cout << "★ ";
				Console::setColor(white);
				cout << "无敌:接触到子弹和敌方坦克不受到伤害";
				Console::setCursorPosition(12, 12);
				Console::setColor(14);
				cout << "▲ ";
				Console::setColor(white);
				cout << "回血 : 血量 + 1";
				Console::setCursorPosition(14, 5);
				Console::setColor(3);
				cout << "障碍物";
				Console::setCursorPosition(14, 12);
				Console::setColor(9);
				cout << "■";
				Console::setColor(white);
				cout << "  河流:子弹可穿过,但坦克无法跨越";
				Console::setCursorPosition(15, 12);
				Console::setColor(12);
				cout << "■";
				Console::setColor(white);
				cout << "  砖块:子弹不可穿过,坦克无法跨越，但可击碎";
				Console::setCursorPosition(16, 12);
				cout << "■";
				cout << "  墙体:子弹不可穿过,坦克无法跨越，不可击碎";
				j = 3;
				break;
			}
			else return 1;
			break;
		}
		case'b':
		{
			if (j == 3)
				return 1;
		}
		default:
			break;
		}
	}
}

int Control::start() {				//主程序开始
	while (true)
	{
		int bre;
		Console console;				//初始化控制台
		Map map;						//初始化地图
		map.show();
		TankUser mytank = TankUser();    //初始化用户坦克
		TankEnemies enemies = TankEnemies();//初始化敌方坦克
		props p = props();           //初始化道具群
		barries b = barries();       //初始化障碍物群
		b.initBarries();
		mytank.show(); 
		while (true)                 //计时循环！
		{
			console.checkKey(mytank);
			mytank.bulletMove();
			enemies.allEnemyMove();
			p.UseProp(mytank);
			map.refresh(b);
			if (!mytank.isAlive()) {
				if (restart() == 0) {
					bre = 1;
					break;
				}
				else
				{
					TankUser::blood = 5;
					bre = 0;
					break;
				}
			}
			Sleep(40);
		}
		if (bre)
		{
			break;
		}
	}
	return 0;
}

int Control::restart()                 //重新开始
{
	system("cls");
    Console::setCursorPosition(9, 52);
    Console::setColor(red);
    cout << "Good Game!";
	Console::setCursorPosition(10, 45);
    Console::setColor(white);
	cout << Console::U2G(u8"■■■■■■■■■■■■") << "\n";
	Console::setCursorPosition(11, 51);
	cout <</* Console::U2G(u8"■") <<*/ "总分：";
	Console::setColor(14);
	cout << TankUser::score << "      \n";
	Console::setCursorPosition(12, 45);
	Console::setColor(white);
	cout << Console::U2G(u8"■■■■■■■■■■■■") << "\n";
	Console::setCursorPosition(13, 45);
	cout << "按 y 重新开始，按 n 退出\n";
	while (true)
	{
		char cha = _getch();
		if (cha == 'y') {
            TankUser::score = 0;
			return 1;
		}
		if (cha=='n')
		{
			return 0;
		}
	}
}
