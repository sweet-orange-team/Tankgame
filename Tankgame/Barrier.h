#pragma once
#ifndef _BARRIER_H

#include<iostream>
#include"Map.h"

class Barrier
{
public:
    Barrier();
    ~Barrier();
    virtual void append()=0;
    virtual void show()=0;
protected:
    int x, y;
    int color;
    int xlen, ylen;
    int id;
};

class River :public Barrier      //无法跨越，子弹可穿过 Map::map[x][y][0]=6
{
public:
    River();
    ~River();
    static int a;
    void append();
    void show();
    char body[3][8];
    char Body[3][3][8]=
    {
        {
            { 0,0,0,0,1,1,0,0 },
            { 0,0,1,1,1,1,1,1 },
            { 1,1,1,1,0,0,0,0 }
        },
        {
            { 0,0,1,1,0,0,0,0 },
            { 1,1,1,1,1,1,0,0 },
            { 0,0,0,0,1,1,1,1 }
           
        },
        {
            { 0,0,1,1,0,0,0,0 },
            { 1,1,1,1,0,0,0,0 },
            { 1,1,1,1,1,1,1,1 }
}
        };
};

class Wall :public Barrier       //无法跨越，子弹不可穿过不可击碎 Map::map[x][y][0]=1
{
public:
    Wall();
    Wall(int x, int y);
    ~Wall();
    void show();
    void append();
    char body[2][6] =
    {
        { 1,1,1,1,1,1 },
        { 1,1,1,1,0,0 }
    };
};

class Brick :public Barrier      //无法跨越，子弹可击碎 Map::map[x][y][0]=7
{
public:
    Brick();
    ~Brick();
    static int a;
    void show();
    void append();
    void iShot();
    int body[8][22]=
    {   
        { 0,0,0,0,0,0,0,0,1,1,0,0,1,1,0,0,0,0,0,0,0,0 },           
        { 0,0,0,0,0,0,0,0,1,1,0,0,1,1,0,0,0,0,0,0,0,0 },             
        { 1,1,0,0,0,0,1,1,1,1,1,1,1,1,1,1,0,0,0,0,1,1 },     
        { 1,1,1,1,1,1,1,1,0,0,1,1,0,0,1,1,1,1,1,1,1,1 },     
        { 0,0,0,0,0,0,1,1,1,1,1,1,1,1,1,1,0,0,0,0,0,0 },           
        { 0,0,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,0,0 },       
        { 1,1,1,1,1,1,0,0,1,1,1,1,1,1,0,0,1,1,1,1,1,1 },     
        { 1,1,1,1,0,0,0,0,0,0,1,1,0,0,0,0,0,0,1,1,1,1 }   
    };
};

class barries
{
public:
    barries();
    ~barries();
    void initBarries();
    void refresh();
    River * r1,*r2;
    Wall*w1, *w2, *w3;
    Brick*b1;
};
#endif // !_BARRIER_H

//        ■        ■              ■
//River ■■■ or ■■■     or   ■■         3*8
//    ■■            ■■        ■■■■
// { 0,0,0,0,1,1,0,0 },{ 0,0,1,1,1,1,1,1 },{ 1,1,1,1,0,0,0,0 }
// { 0,0,1,1,0,0,0,0 },{ 1,1,1,1,1,1,0,0 },{ 0,0,0,0,1,1,1,1 }
// { 0,0,1,1,0,0,0,0 },{ 1,1,1,1,0,0,0,0 },{ 1,1,1,1,1,1,1,1 }

//Wall ■■■ *2                     2*6
//     ■■
//  {1,1,1,1,1,1}
   


//{ 0,0,0,0,0,0,0,0,1,1,0,0,1,1,0,0,0,0,0,0,0,0 }             ■  ■
//{ 0,0,0,0,0,0,0,0,1,1,0,0,1,1,0,0,0,0,0,0,0,0 }             ■  ■
//{ 1,1,0,0,0,0,1,1,1,1,1,1,1,1,1,1,0,0,0,0,1,1 }     ■    ■■■■■    ■
//{ 1,1,1,1,1,1,1,1,0,0,1,1,0,0,1,1,1,1,1,1,1,1 }     ■■■■  ■  ■■■■
//{ 0,0,0,0,0,0,1,1,1,1,1,1,1,1,1,1,0,0,0,0,0,0 }           ■■■■■
//{ 0,0,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,0,0 }       ■■■■■■■■■
//{ 1,1,1,1,1,1,0,0,1,1,1,1,1,1,0,0,1,1,1,1,1,1 }     ■■■  ■■■  ■■■
//{ 1,1,1,1,0,0,0,0,0,0,1,1,0,0,0,0,0,0,1,1,1,1 }     ■■      ■      ■■