#pragma once
#ifndef _PROP_H

#include<iostream>
#include"Map.h"

class Prop                                           //道具基类
{
public:
    Prop(int x, int y, int isSee=0);
    ~Prop();
   virtual void showProp();
   virtual void clearProp();
   virtual void append();
   virtual char* getBody();
protected:
    int x, y;
    int isSee;
    char*body;
    //char*body   高级子弹：▲     无敌：★
};

class BulletProp :public Prop                         //高级子弹
{
public:
    BulletProp(int x, int y, int isSee);
    ~BulletProp();
    void isGet(TankUser&Tank);
protected:
    char*body = u8"▲";
};

class InvincibleProp :public Prop                     //无敌
{
public:
    InvincibleProp(int x, int y, int isSee);
    ~InvincibleProp();
    void isGet(TankUser&Tank,TankEnemy&tank);
protected:
    char*body = u8"★";
};


class prop {
public:
    prop();
    ~prop();
    static int propNum;
    void del();
    void add(int x, int y);
private:
    BulletProp*prop1;
    InvincibleProp*prop2;
};

#endif // !_PROP_H

