#pragma once
#ifndef _PROP_H

#include<iostream>
#include"Map.h"

class Prop                                           //���߻���
{
public:
    Prop(int x, int y, char*body, int isSee=1);
    ~Prop();
   virtual void showProp();
   virtual void clearProp();
   virtual void append();
   virtual char* getBody();
protected:
    int x, y;
    int isSee;
    char*body;
    //char*body   �߼��ӵ�����     �޵У���
};

class BulletProp :public Prop                         //�߼��ӵ�
{
public:
    BulletProp(int x, int y, char*body = u8"��", int isSee =1);
    ~BulletProp();
    void isGet(TankUser&Tank);
};

class InvincibleProp :public Prop                     //�޵�
{
public:
    InvincibleProp(int x, int y, char*body = u8"��", int isSee=1);
    ~InvincibleProp();
    void isGet(TankUser&Tank,TankEnemy&tank);
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

