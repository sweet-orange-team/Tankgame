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
    char body[2][2][6]=
    {
        {
            { 0,0,1,1,1,1 },//x
            { 1,1,1,1,0,0 }
        },
        {
            { 1,1,1,1,1,1 },
            { 0,0,0,0,1,1 }
        }
    };
};

class Wall :public Barrier       //无法跨越，子弹不可穿过不可击碎 Map::map[x][y][0]=1
{
public:
    Wall();
    ~Wall();
    void show();
    void append();
    char body[1][4] = { 1,1,1,1 };
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
    char body[2][5][10]=
    {   
        {//y
             { 0,0,0,0,1,1,1,1,0,0 }, //x
             { 0,0,0,0,1,1,0,0,0,0 }, //x+1
             { 1,1,1,1,1,1,0,0,0,0 }, //x+2
             { 0,0,1,1,1,1,1,1,0,0 }, //x+3
             { 1,1,1,1,1,1,0,0,1,1 }  //x+4
        },
        {//y
             { 0,0,1,1,1,1,0,0,0,0 }, //x
             { 1,1,1,1,1,1,1,1,1,1 }, //x+1
             { 1,1,1,1,0,0,1,1,0,0 }, //x+2
             { 1,1,0,0,0,0,1,1,1,1 }, //x+3
             { 0,0,0,0,1,1,1,1,1,1 }  //x+4
         }
    };
};

class barries
{
public:
    barries();
    ~barries();
    void initBarries();
    River * r1;
    Wall*w1, *w2;
    Brick*b1;
};
#endif // !_BARRIER_H


//River ■■ or ■■■ *1          2*6
//    ■■          ■


//Wall ■■  *2                    1*4

   
//       ■■                              ■■
//Brick  ■        *1      5*10          ■■■■■
//   ■■■                              ■■  ■
//     ■■■                            ■    ■■
//   ■■■  ■                              ■■■