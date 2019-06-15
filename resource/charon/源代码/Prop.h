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
    virtual void isGet()=0;                          //被捡到后的操作
    virtual void Recover() = 0;                      //效果恢复
	virtual void showProp();                         //显示
	void clearProp();                                //清除
	void append();                                   //添加进地图
	char* getBody();                                 //获取形状
protected:
    int x, y;
    char*body;
    //char*body   高级子弹：●     无敌：★     回血：▲
};

class BulletProp :public Prop                         //高级子弹
{
public:
    BulletProp(int x, int y, char*body = u8"●");
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
        BloodProp(int x, int y, char*body = u8"▲");
        ~BloodProp();
        void isGet() ;
        void Recover() ;
};


class props               //道具群类
{
public:
    props();
    ~props();
    static int count;      //计数
    static int num;        //判断道具种类
    static int isget;      //是否被捡到
    static int judge;      //判断状态
    static int timercount; //计时
    static void timer();   //计时器
    void initProp();       //初始化
    void UseProp(TankUser&Tank);
    BulletProp*prop1;
    InvincibleProp*prop2;
    BloodProp*prop3;
};

#endif // !_PROP_H

