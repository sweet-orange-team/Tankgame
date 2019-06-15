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
    virtual void isGet()=0;                          //���񵽺�Ĳ���
    virtual void Recover() = 0;                      //Ч���ָ�
	virtual void showProp();                         //��ʾ
	void clearProp();                                //���
	void append();                                   //��ӽ���ͼ
	char* getBody();                                 //��ȡ��״
protected:
    int x, y;
    char*body;
    //char*body   �߼��ӵ�����     �޵У���     ��Ѫ����
};

class BulletProp :public Prop                         //�߼��ӵ�
{
public:
    BulletProp(int x, int y, char*body = u8"��");
    ~BulletProp() ;
    void isGet() ;
    void Recover();
    void showProp();
	static char* body;
	static int attack;
};

class InvincibleProp :public Prop                     //�޵�
{
public:
    InvincibleProp(int x, int y, char*body = u8"��");
    ~InvincibleProp();
    void isGet() ;
    void Recover() ;
    static int selfboom;
};

class BloodProp :public Prop                          //��Ѫ
{
    public:
        BloodProp(int x, int y, char*body = u8"��");
        ~BloodProp();
        void isGet() ;
        void Recover() ;
};


class props               //����Ⱥ��
{
public:
    props();
    ~props();
    static int count;      //����
    static int num;        //�жϵ�������
    static int isget;      //�Ƿ񱻼�
    static int judge;      //�ж�״̬
    static int timercount; //��ʱ
    static void timer();   //��ʱ��
    void initProp();       //��ʼ��
    void UseProp(TankUser&Tank);
    BulletProp*prop1;
    InvincibleProp*prop2;
    BloodProp*prop3;
};

#endif // !_PROP_H

