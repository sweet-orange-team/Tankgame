#include<iostream>
#include <stdio.h> 
#include <windows.h>
using namespace std;
#include"Console.h"


int main() {
	Console console;				//��ʼ������̨
	cout << "hello-------------------------------------------------------------------------------\n";	//����
	while (1) {
		if (console.check('Q')) {
			cout << "��ð���" << endl;
		};
		Sleep(20);//ѭ��ʱ��������ֹ̫ռ�ڴ�
		//system("cls");//���� 
	}
	

	system("pause");
	return 0;
}