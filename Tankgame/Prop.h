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
    virtual void isGet()=0;
    virtual void Recover() = 0;
	virtual void showProp();
	void clearProp();
	void append();
	char* getBody();
protected:
    int x, y;
    char*body;
    //char*body   高级子弹：▲     无敌：★     回血：●
};

class BulletProp :public Prop                         //高级子弹
{
public:
    BulletProp(int x, int y, char*body = u8"▲");
    ~BulletProp() ;
    void isGet() ;
    void Recover();
    void showProp();
	static char* body;
	static int attack;
};

class InvincibleProp :public Prop                     //无敌
{
public:
    InvincibleProp(int x, int y, char*body = u8"★");
    ~InvincibleProp();
    void isGet() ;
    void Recover() ;
    static int selfboom;
};

class BloodProp :public Prop                          //回血
{
    public:
        BloodProp(int x, int y, char*body = u8"●");
        ~BloodProp();
        void isGet() ;
        void Recover() ;
};


class props 
{
public:
    props();
    ~props();
    static int count;
    static int num;
    static int isget;
    static int judge;
    static int timercount;
    static void timer();
    void initProp();
    void UseProp(TankUser&Tank);
    BulletProp*prop1;
    InvincibleProp*prop2;
    BloodProp*prop3;
};

#endif // !_PROP_H

