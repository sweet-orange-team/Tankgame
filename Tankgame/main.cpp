#include"Console.h"
#include"Control.h"
#include"Map.h"
#include"Tank.h"

int main() {
	Console console;				//��ʼ������̨
	Map map;						//��ʼ����ͼ
	map.show();						//�����ͼ
	Tank tank;						//�½�һ������̹��
	tank.append(map);				//���̹�˽���ͼ--����ֱ�����
	map.show();

	system("pause");
	return 0;
}