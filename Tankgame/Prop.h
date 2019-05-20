#pragma once
#ifndef _PROP_H

#include<iostream>
#include"Map.h"

class Prop                                           //道具基类
{
public:
    Prop(int x, int y, char*body);
    ~Prop();
    int IsGet(TankUser&Tank);                        //判断是否被捡到
    virtual void isGet(TankUser&Tank) = 0;
    virtual void Recover(TankUser&Tank) = 0;
	void showProp();
	void clearProp();
	void append();
	char* getBody();
protected:
    int x, y;
    char*body;
    //char*body   高级子弹：▲     无敌：★
};

class BulletProp :public Prop                         //高级子弹
{
public:
    BulletProp(int x, int y, char*body = u8"▲");
    ~BulletProp();
    void isGet();
    void Recover();
	//虚函数必须定义....
	void isGet(TankUser&Tank) {};
	void Recover(TankUser&Tank) {}; 
	static char* body;
	static int attack;
};

class InvincibleProp :public Prop                     //无敌
{
public:
    InvincibleProp(int x, int y, char*body = u8"★");
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

