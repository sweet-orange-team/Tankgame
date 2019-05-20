#pragma once
#ifndef _PROP_H

#include<iostream>
#include"Map.h"

class Prop                                           //���߻���
{
public:
    Prop(int x, int y, char*body);
    ~Prop();
    int IsGet(TankUser&Tank);                        //�ж��Ƿ񱻼�
    virtual void isGet(TankUser&Tank) = 0;
    virtual void Recover(TankUser&Tank) = 0;
	void showProp();
	void clearProp();
	void append();
	char* getBody();
protected:
    int x, y;
    char*body;
    //char*body   �߼��ӵ�����     �޵У���
};

class BulletProp :public Prop                         //�߼��ӵ�
{
public:
    BulletProp(int x, int y, char*body = u8"��");
    ~BulletProp();
    void isGet();
    void Recover();
	//�麯�����붨��....
	void isGet(TankUser&Tank) {};
	void Recover(TankUser&Tank) {}; 
	static char* body;
	static int attack;
};

class InvincibleProp :public Prop                     //�޵�
{
public:
    InvincibleProp(int x, int y, char*body = u8"��");
    ~InvincibleProp();
    void isGet(TankUser&Tank);
    void Recover(TankUser&Tank);
};


class props 
{
public:
    props();
    ~props();
    static int propNum;
    void initProp(TankUser&Tank);
    BulletProp*prop1;
    InvincibleProp*prop2;
};

#endif // !_PROP_H

