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
    //char*body   �߼��ӵ�����     �޵У���
};

class BulletProp :public Prop                         //�߼��ӵ�
{
public:
    void isGet(Tank&Tank);
protected:
    char*body = u8"��";
};

class InvincibleProp :public Prop                     //�޵�
{
public:
    void isGet(Tank&Tank);
protected:
    char*body = u8"��";
};

#endif // !_PROP_H

