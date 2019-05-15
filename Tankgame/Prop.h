#pragma once
#ifndef _PROP_H

class Prop 
{
public:
    Prop(int x, int y, int isSee=0);
    ~Prop();
   virtual void showProp();
   virtual void clearProp();
   virtual void append();
   virtual char* getBody();
   virtual void isGet(Tank&Tank);
protected:
    int x, y;
    int isSee;
    char*body;
    //char*body   高级子弹：▲     无敌：★
};

class BulletProp :public Prop                         //高级子弹
{
public:
    void isGet(Tank&Tank);
protected:
    char*body = u8"▲";
};

class InvincibleProp :public Prop                     //无敌
{
public:
    void isGet(Tank&Tank);
protected:
    char*body = u8"★";
};

#endif // !_PROP_H

