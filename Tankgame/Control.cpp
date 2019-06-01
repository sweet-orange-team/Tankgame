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

void Control::tankl(int x, int y)
{
    Console::setColor(yellow);
    Console::setCursorPosition(x, y);
    cout << "■■";
    Console::setCursorPosition(x-1, y);
    cout << "  ■■";
    Console::setCursorPosition(x-2, y);
    cout << "■■";
    Console::setColor(white);
}

void Control::tankr(int x, int y)
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

void Control::clear(int x, int y)
{
    Console::setCursorPosition(x, y);
    cout << "      ";
    Console::setCursorPosition(x - 1, y);
    cout << "      ";
    Console::setCursorPosition(x - 2, y);
    cout << "      ";
}

int Control::menu()
{
    char* n = u8"■";
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
    for (int i = 9; i < 21; i++)
    {
        Console::setCursorPosition(i, 3);
        cout << "                                                                                                                ";
    }
    Console::setColor(white);

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
    Console::setColor(3);
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
    Console::setColor(14);
    cout << "Made by ";
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
                    Console::setColor(white);
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
    barries b = barries();
    b.initBarries();
	mytank.show();
    while (true)
    {
        console.checkKey(mytank);
        mytank.bulletMove();
        enemies.allEnemyMove();
        p.UseProp(mytank);
        map.refresh(b);
		if (!mytank.isAlive())break;
		Sleep(40);
	}
	system("pause");
	system("cls");
	system("pause");
	return 0;
}
