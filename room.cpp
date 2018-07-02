#include <ctime>
#include<iostream>
#include"room.h"
#include <stdlib.h>
room::room(int up_room)//第一个房间
{
    this->level=-1;
    status=0;
    id=1;
    this->east=0;
    this->west=0;
    this->up=up_room;
    this->down=0;
    this->south=0;
    this->north=0;
}
room::room(int id,int level)
{
    this->level=level;
        if(rand() % 2){status=1;mons=new monster(this->level);} else status=0;//1--有怪，0--没怪
        this->id=id;
        this->east=0;
        this->west=0;
        this->up=0;
        this->down=0;
        this->south=0;
        this->north=0;
    }
    void room::deletemonster()
    {
        if(status) delete(mons);
        if(status==2) status=3;else status=0;
    }
void room::changeroom(int boss_level)//公主的房间，公主由最终大BOSS看守
{
    if(status) delete(mons);
    status=2;
    mons=new monster(boss_level);
}
void room::route(char direct,int go)
{
    switch (direct)
    {
        case 'e':this->east=go;break;
        case 'n':this->north=go;break;
        case 'w':this->west=go;break;
        case 's':this->south=go;break;
        case 'u':this->up=go;break;
        case 'd':this->down=go;break;
    }
}

int room::getroute(char direct) const
{
    switch (direct)
    {
        case 'e':return this->east;
        case 'n':return this->north;
        case 'w':return this->west;
        case 's':return this->south;
        case 'u':return this->up;
        case 'd':return this->down;
    }
}
int room::check() const
{
    return status;
}
void room::info()
{
    if(id!=1){
        cout<<"这是第"<<this->id<<"号房间。\n"
        <<"本房间有以下出口:\n";
        if(east) cout<<"东面出口(E)通向第"<<east<<"号房间。\n";
        if(west) cout<<"西面出口(W)通向第"<<west<<"号房间。\n";
        if(north) cout<<"北面出口(N)通向第"<<north<<"号房间。\n";
        if(south) cout<<"南面出口(S)通向第"<<south<<"号房间。\n";
        if(up) cout<<"沿楼梯向上(U)可以到达第"<<up<<"号房间。\n";
        if(down) cout<<"沿楼梯向下(D)可以到达第"<<down<<"号房间。\n";
    }
    else {
        cout<<"这里是第1号房间。您在EvilCastle的旅程从这里开始。\n"
        <<"在EvilCastle中，等级越高的怪物分布在越高的楼层。\n"
        <<"因此在充分准备之前请不要往上（U）方向走。\n"
        <<"怪物们为了保护自己的安全，很少建设楼梯。\n"
        <<"但是每一层都至少有一个房间有通向高一层的楼梯。\n"
        <<"这是EvilCastle的底层，沿楼梯向上(U)可以通向"<<up<<"号房间\n"
        <<"尽情探索吧^_^\n";
    }
}
monster *room::getmons()
{
    if(this->status) return mons;
    else return NULL;
}
void room::_makestatus0()
{
    this->status=0;
}
room::~room()
{
    if(status) delete(mons);
}