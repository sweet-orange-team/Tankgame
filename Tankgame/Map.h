#pragma once
#ifndef _MAP_H
#define _MAP_H
class Map
{
public:							//30*106
	Map();						//map[][][]˵����
	~Map();						//ǰ����ά�ȶ����꣬������ά�ȶ���ɫ
	void show();				//0:�ո�,1:ǽ��     2:̹��,
	void refresh();				//3:�ӵ�,4:�з�̹��,5:����
	static int map[30][106][2];
private:
	int privateMap[30][106][2];	//�����鿴��ͼ��Ϣ
};

#endif // !_MAP_H