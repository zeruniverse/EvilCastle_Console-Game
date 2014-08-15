#include <ctime> 
#include <iostream>
#include "monster.h"
monster::monster(int level)
	{
		if(level>1)level++;
		if(level>3)level++;
		if(level>6) level++;
        type=rand() % 6;
		hp=rand() % 3 +1 +level*6;
		dam=rand() %2+1 +level*2;
		speed=rand() %5+ level*2;
	}
int monster::info()
	{
		system("cls");
		cout<<"该处有怪物看守\n怪物信息为：\n";
		switch (type)
		{
		case  0:cout<<"普通怪物\n";break;
		case  1:cout<<"血怪\n";break;
		case  2:cout<<"持有武器的怪物\n";break;
		case  3:cout<<"看守盾牌的怪物\n";break;
		case  4:cout<<"穿鞋子的怪物\n";break;
		case  5:cout<<"怪物通信员\n";break;
		}
		cout<<"血量："<<hp<<"\n";
		cout<<"攻击："<<dam<<"\n";
		cout<<"速度："<<speed<<"\n";
		return type;
	}
int monster::getdam() const
	{return dam;}
int monster::gethp() const {return hp;}
int monster::getspd() const {return speed;}
monster::~monster()
	{
	}