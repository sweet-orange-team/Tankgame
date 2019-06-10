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

void Control::tankl(int x, int y)       //���̹��
{
	Console::setColor(yellow);
	Console::setCursorPosition(x, y);
	cout << "����";
	Console::setCursorPosition(x - 1, y);
	cout << "  ����";
	Console::setCursorPosition(x - 2, y);
	cout << "����";
	Console::setColor(white);
}

void Control::tankr(int x, int y)        //�ұ�̹��
{
	Console::setColor(red);
	Console::setCursorPosition(x, y);
	cout << "  ����";
	Console::setCursorPosition(x - 1, y);
	cout << "����";
	Console::setCursorPosition(x - 2, y);
	cout << "  ����";
	Console::setColor(white);
}

void Control::clear(int x, int y)        //���
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
    //ײ�������
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


	//̹�˴�ս
	//                                                                                                                          
	//    ��                      //          ��            //            ��              //    ��         ��   ��
	//    ��      ��������������  //����������������������  //            ��              //    ��         ��    ��
	//    ��      ��          ��  //          ��            //��������������������������  //    ��������   ����������
	// ��������   ��          ��  //   ����������������     //            ��              //    ��     ������
	//    ��      ��������������  //   ��            ��     //           ����             //    ��         ��  ��
	//    ��      ��          ��  //   ��            ��     //           ��  ��           //������������    �� ��
	//    ��      ��          ��  //    ��������������      //         ��     ��          //��        ��    ����
	//    ��      ��          ��  //       ��    ��         //       ��         ��        //��        ��    ��      ��
	//    ������   ������������   //      ��     ��       ��//     ��             ��      //������������   �� ��    ��
	//������                      //    ��       ��       ��//   ��                 ������//��           ��     ��  ��
	//  ��     ������������������ //����           �������� // ��                     ��  //           ��         ����
	//                                                                                                              �� 

	Console::setColor(9);
	Console::setCursorPosition(9, 3);
	cout << "    ��                      ";
	Console::setCursorPosition(10, 3);
	cout << "    ��      ��������������  ";
	Console::setCursorPosition(11, 3);
	cout << "    ��      ��          ��  ";
	Console::setCursorPosition(12, 3);
	cout << " ��������   ��          ��  ";
	Console::setCursorPosition(13, 3);
	cout << "    ��      ��������������  ";
	Console::setCursorPosition(14, 3);
	cout << "    ��      ��          ��  ";
	Console::setCursorPosition(15, 3);
	cout << "    ��      ��          ��  ";
	Console::setCursorPosition(16, 3);
	cout << "    ��      ��          ��  ";
	Console::setCursorPosition(17, 3);
	cout << "    ������   ������������   ";
	Console::setCursorPosition(18, 3);
	cout << "������                      ";
	Console::setCursorPosition(19, 3);
	cout << "  ��     ������������������ ";
	Sleep(300);

	Console::setColor(14);
	Console::setCursorPosition(9, 3);
	cout << "    ��                                  ��              ";
	Console::setCursorPosition(10, 3);
	cout << "    ��      ��������������    ����������������������    ";
	Console::setCursorPosition(11, 3);
	cout << "    ��      ��          ��              ��              ";
	Console::setCursorPosition(12, 3);
	cout << " ��������   ��          ��       ����������������       ";
	Console::setCursorPosition(13, 3);
	cout << "    ��      ��������������       ��            ��       ";
	Console::setCursorPosition(14, 3);
	cout << "    ��      ��          ��       ��            ��       ";
	Console::setCursorPosition(15, 3);
	cout << "    ��      ��          ��        ��������������        ";
	Console::setCursorPosition(16, 3);
	cout << "    ��      ��          ��           ��    ��           ";
	Console::setCursorPosition(17, 3);
	cout << "    ������   ������������           ��     ��       ��  ";
	Console::setCursorPosition(18, 3);
	cout << "������                            ��       ��       ��  ";
	Console::setCursorPosition(19, 3);
	cout << "  ��     ������������������   ����           ��������   ";
	Sleep(300);

	Console::setColor(11);
	Console::setCursorPosition(9, 3);
	cout << "    ��                                  ��                          ��                ";
	Console::setCursorPosition(10, 3);
	cout << "    ��      ��������������    ����������������������                ��                ";
	Console::setCursorPosition(11, 3);
	cout << "    ��      ��          ��              ��              ����������������������������  ";
	Console::setCursorPosition(12, 3);
	cout << " ��������   ��          ��       ����������������                   ��                ";
	Console::setCursorPosition(13, 3);
	cout << "    ��      ��������������       ��            ��                  ����               ";
	Console::setCursorPosition(14, 3);
	cout << "    ��      ��          ��       ��            ��                  ��  ��             ";
	Console::setCursorPosition(15, 3);
	cout << "    ��      ��          ��        ��������������                 ��     ��            ";
	Console::setCursorPosition(16, 3);
	cout << "    ��      ��          ��           ��    ��                  ��         ��          ";
	Console::setCursorPosition(17, 3);
	cout << "    ������   ������������           ��     ��       ��       ��             ��        ";
	Console::setCursorPosition(18, 3);
	cout << "������                            ��       ��       ��     ��                 ������  ";
	Console::setCursorPosition(19, 3);
	cout << "  ��     ������������������   ����           ��������    ��                     ��    ";
	Sleep(300);

	Console::setColor(4);
	Console::setCursorPosition(9, 3);
	cout << "    ��                                  ��                          ��                    ��         ��   ��";
	Console::setCursorPosition(10, 3);
	cout << "    ��      ��������������    ����������������������                ��                    ��         ��    ��";
	Console::setCursorPosition(11, 3);
	cout << "    ��      ��          ��              ��              ����������������������������      ��������   ����������";
	Console::setCursorPosition(12, 3);
	cout << " ��������   ��          ��       ����������������                   ��                    ��     ������";
	Console::setCursorPosition(13, 3);
	cout << "    ��      ��������������       ��            ��                  ����                   ��         ��  ��";
	Console::setCursorPosition(14, 3);
	cout << "    ��      ��          ��       ��            ��                  ��  ��             ������������    �� ��";
	Console::setCursorPosition(15, 3);
	cout << "    ��      ��          ��        ��������������                 ��     ��            ��        ��    ����";
	Console::setCursorPosition(16, 3);
	cout << "    ��      ��          ��           ��    ��                  ��         ��          ��        ��    ��      ��";
	Console::setCursorPosition(17, 3);
	cout << "    ������   ������������           ��     ��       ��       ��             ��        ������������   �� ��    ��";
	Console::setCursorPosition(18, 3);
	cout << "������                            ��       ��       ��     ��                 ������  ��           ��     ��  ��";
	Console::setCursorPosition(19, 3);
	cout << "  ��     ������������������   ����           ��������    ��                     ��               ��         ����";
	Console::setCursorPosition(20, 3);
	cout << "                                                                                                              ��";
	Sleep(500);
	system("cls");
	Console::setColor(white);
}

int Control::menu()                       //�˵�
{
	char* n = u8"��";
	Console::setCursorPosition(3, 51);
	Console::setColor(red);
	cout << "̹  ��  ��  ս";
	Console::setColor(gray);
	Console::setCursorPosition(7, 0);
	for (int i = 1; i < 60; i++)
	{
		cout << Console::U2G(n);
	}
	Console::setCursorPosition(8, 49);
	Console::setColor(3);
	cout << "a��d�ƶ���꣬yȷ��";
	Console::setCursorPosition(9, 0);
	Console::setColor(gray);
	for (int i = 1; i < 60; i++)
	{
		cout << Console::U2G(n);
	}
	Console::setCursorPosition(16, 34);
	Console::setColor(white);
	cout << ">>��ʼ��Ϸ";
	Console::setCursorPosition(16, 54);
	Console::setColor(gray);
	cout << "�˳���Ϸ";
	Console::setCursorPosition(16, 72);
	cout << "����ָ��";
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
	while (1)                  //�жϹ���ƶ�
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
				cout << ">>��ʼ��Ϸ";
				Console::setCursorPosition(16, 52);
				Console::setColor(gray);
				cout << "  �˳���Ϸ";
				Console::setCursorPosition(16, 70);
				cout << "  ����ָ��";
				Console::setColor(white);
				j = 1;
			}
			else if (j == 2)
			{
				Console::setCursorPosition(16, 34);
				Console::setColor(gray);
				cout << "  ��ʼ��Ϸ";
				Console::setCursorPosition(16, 70);
				cout << "  ����ָ��";
				Console::setCursorPosition(16, 52);
				Console::setColor(white);
				cout << ">>�˳���Ϸ";
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
				cout << "  ��ʼ��Ϸ";
				Console::setCursorPosition(16, 70);
				cout << "  ����ָ��";
				Console::setColor(white);
				Console::setCursorPosition(16, 52);
				cout << ">>�˳���Ϸ";
				j = 0;
			}

			else if (j == 0)
			{
				Console::setCursorPosition(16, 34);
				Console::setColor(gray);
				cout << "  ��ʼ��Ϸ";
				Console::setCursorPosition(16, 52);
				cout << "  �˳���Ϸ";
				Console::setColor(white);
				Console::setCursorPosition(16, 70);
				cout << ">>����ָ��";
				j = 2;
			}
			break;
		}
		case 'y':                     //�ж�ѡ��
		{
			if (j == 0) return 0;
			else if (j == 2)
			{
				system("cls");
				Console::setColor(3);
				Console::setCursorPosition(1, 3);
				cout << "b����ʼ��Ϸ...";
				Console::setCursorPosition(6, 5);
				Console::setColor(3);
				cout << "�ƶ�";
				Console::setCursorPosition(6, 12);
				Console::setColor(white);
				cout << "w �����ƶ�   s �����ƶ�";
				Console::setCursorPosition(7, 12);
				cout << "a �����ƶ�   d �����ƶ�";
				Console::setCursorPosition(8, 12);
				cout << "p ��ͣ       �ո� �����ӵ�";
				Console::setCursorPosition(10, 5);
				Console::setColor(3);
				cout << "����";
				Console::setCursorPosition(10, 12);
				Console::setColor(14);
				cout << "�� ";
				Console::setColor(white);
				cout << "�߼��ӵ�:�����˺�";
				Console::setCursorPosition(11, 12);
				Console::setColor(14);
				cout << "�� ";
				Console::setColor(white);
				cout << "�޵�:�Ӵ����ӵ��͵з�̹�˲��ܵ��˺�";
				Console::setCursorPosition(12, 12);
				Console::setColor(14);
				cout << "�� ";
				Console::setColor(white);
				cout << "��Ѫ : Ѫ�� + 1";
				Console::setCursorPosition(14, 5);
				Console::setColor(3);
				cout << "�ϰ���";
				Console::setCursorPosition(14, 12);
				Console::setColor(9);
				cout << "��";
				Console::setColor(white);
				cout << "  ����:�ӵ��ɴ���,��̹���޷���Խ";
				Console::setCursorPosition(15, 12);
				Console::setColor(12);
				cout << "��";
				Console::setColor(white);
				cout << "  ש��:�ӵ����ɴ���,̹���޷���Խ�����ɻ���";
				Console::setCursorPosition(16, 12);
				cout << "��";
				cout << "  ǽ��:�ӵ����ɴ���,̹���޷���Խ�����ɻ���";
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

int Control::start() {				//������ʼ
	while (true)
	{
		int bre;
		Console console;				//��ʼ������̨
		Map map;						//��ʼ����ͼ
		map.show();
		TankUser mytank = TankUser();    //��ʼ���û�̹��
		TankEnemies enemies = TankEnemies();//��ʼ���з�̹��
		props p = props();           //��ʼ������Ⱥ
		barries b = barries();       //��ʼ���ϰ���Ⱥ
		b.initBarries();
		mytank.show(); 
		while (true)                 //��ʱѭ����
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

int Control::restart()                 //���¿�ʼ
{
	system("cls");
    Console::setCursorPosition(9, 52);
    Console::setColor(red);
    cout << "Good Game!";
	Console::setCursorPosition(10, 45);
    Console::setColor(white);
	cout << Console::U2G(u8"������������������������") << "\n";
	Console::setCursorPosition(11, 51);
	cout <</* Console::U2G(u8"��") <<*/ "�ܷ֣�";
	Console::setColor(14);
	cout << TankUser::score << "      \n";
	Console::setCursorPosition(12, 45);
	Console::setColor(white);
	cout << Console::U2G(u8"������������������������") << "\n";
	Console::setCursorPosition(13, 45);
	cout << "�� y ���¿�ʼ���� n �˳�\n";
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
