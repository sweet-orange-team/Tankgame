#include"Console.h"
#include"Control.h"
#include"Map.h"
#include"Tank.h"

int main() {
	Console console;				//��ʼ������̨
	Map map;						//��ʼ����ͼ
    Tank tank;
	map.show();						//�����ͼ	Tank tank(100, 0, 1, yellow);	//�½�һ������̹��
	tank.append(map);				//���̹�˽���ͼ--����ֱ�����
	map.show();

	system("pause");
	return 0;
}