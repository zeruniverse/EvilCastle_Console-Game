#include<string>
#include <iostream>
#include<ctime>
#include<conio.h>
#include "hero.h"
using namespace std;
hero::hero(int difficult)
{
	position=1;
	hp=10;
	hp_lim=10;
	dam=1;
	dam_lim=3;
	shel=0;
	shel_lim=1;
	findprin=false;
	speed=1;
	speed_lim=5;
	exp=0;
	level=0;
	if(difficult>3) this->difficult=1;
	else this->difficult=0;
}
bool hero::move(mymap const& mymaps,int pos)
{
	this->position=pos;
	if(findprin) return true;
	if(mymaps.rooms[pos-1]->check()==3) {findprin=true;return true;}else return false;
}
void hero::getthing(int type)
{
	switch(type)
	{
	case 1:dam++; if(dam>dam_lim)dam=dam_lim;break;
	case 2:shel++; if(shel>shel_lim)shel=shel_lim;break;
	case 3:speed++; if(speed>speed_lim)speed=speed_lim;break;
	}
}

void hero::info()
{
	if(findprin) {cout<<"英雄已找到公主，请带领公主到EvilCastle出口（即第1个房间）！\n";}
	else cout<<"正在探索EvilCastle以找到公主\n";
	cout<<"气血HP："<<hp<<"/"<<hp_lim<<"\n"
		<<"杀伤力："<<dam<<"/"<<dam_lim<<"\n"
		<<"防御力："<<shel<<"/"<<shel_lim<<"\n"
		<<"速度:   "<<speed<<"/"<<speed_lim<<"\n"
		<<"经验：  "<<exp<<"/5\n"
		<<"等级：  "<<level<<"\n";
}
int hero::getpos() const
{
	return position;
}
bool hero::die(int pos,mymap const &now,message & msg)
{
		int i;
		cout<<"英雄不幸阵亡！\n就在这关键的时刻，春哥出现了\n";
		if(now.rooms[pos-1]->check()==2) {cout<<"春哥一看居然是看守公主的终极大BOSS就走了ORZ......";return false;}
			msg.print("春哥：如果你相信我，我可以让你复活！\n");
			msg.print("英雄：信春哥，得永生。\n");
			msg.print("春哥：我要看看你是否虔诚，我现在想了一个0～");
			cout<<2+difficult;
			msg.print("的数(0,...,");
			cout<<2+difficult;
			msg.print(")，猜一猜吧！\n");
			cout<<"请输入你猜测的数字>>";
		cin>>i;
		if(i==rand() % (3+difficult)||i==8200)//i=8200作弊模式
		{
			cout<<"恭喜满血复活！\n怪物已被春哥带走！\n";
			hp=hp_lim;
			now.rooms[pos-1]->deletemonster();
			this->move(now,pos);
			this->difficult++;
			return true;
		}
		return false;
}
int hero::battle(int pos,mymap const& mymaps,bool iscatch,message & msg)
{
	int monhp,mondam;
	bool key=false;
	while(kbhit())getch();
	monhp=mymaps.rooms[pos-1]->getmons()->gethp();
	mondam=mymaps.rooms[pos-1]->getmons()->getdam();
	mondam=mondam-shel;
	if(mondam<0)mondam=0;
	system("cls");
	if(iscatch)cout<<"被怪物发现了，强制参加战斗！\n";
	cout<<"开始战斗\n";
	cout<<"***********\n按任意键可以跳过战斗过程\n"
		<<"***********\n";
	if(mymaps.rooms[pos-1]->getmons()->getspd()>this->speed)
		{
			hp=hp-mondam;
			if(hp<=0) hp=0;
			cout<<"怪物回合：怪物对英雄造成"<<mondam<<"点伤害，英雄剩余HP："<<hp<<"\n";
			if(hp==0) if(die(pos,mymaps,msg))
			{
				cout<<"战斗结束，按任意键继续\n";
				while(kbhit())getch();
				getch();
				return 3;
			} else
			{
				cout<<"未复活，战斗结束，英雄阵亡。按任意键继续\n";
				while(kbhit())getch();
				getch();
				return 0;
			}
	}
	while(!kbhit())//没有按下键
	{
		_sleep(1500);
		monhp=monhp-dam<0?0:monhp-dam;
		cout<<"英雄回合：英雄对怪物造成"<<dam<<"点伤害，怪物剩余HP："<<monhp<<"\n";
		if(monhp==0) break;
		_sleep(1500);
		if(kbhit()) {key=true;break;}
		hp=hp-mondam;
		if(hp<=0) hp=0;
		cout<<"怪物回合：怪物对英雄造成"<<mondam<<"点伤害，英雄剩余HP："<<hp<<"\n";
		if(hp==0) if(die(pos,mymaps,msg))
		{
				cout<<"战斗结束，按任意键继续\n";
				while(kbhit())getch();
				getch();
				return 3;
		} else
		{
				cout<<"未复活，战斗结束，英雄阵亡。按任意键继续\n";
				while(kbhit())getch();
				getch();
				return 0;
		}
	}
	if(monhp==0){mymaps.rooms[pos-1]->deletemonster();addexp();cout<<"战斗结束，英雄获得胜利！获得1点经验\n按任意键继续\n";while(kbhit())getch();getch();return 2;}
	cout<<"...\n";
	if(key)//怪物回合
	{
			hp=hp-mondam;
			if(hp<=0) hp=0;
			if(hp==0) if(die(pos,mymaps,msg))
			{
				cout<<"战斗结束，按任意键继续\n";
				while(kbhit())getch();
				getch();
				return 3;
			} else
			{
				cout<<"未复活，战斗结束，英雄阵亡。按任意键继续\n";
				while(kbhit())getch();
				getch();
				return 0;
			}
	}

	while(true)
	{
		monhp=monhp-dam<0?0:monhp-dam;
		if(monhp==0) break;
		hp=hp-mondam;
		if(hp<=0) hp=0;
		if(hp==0) if(die(pos,mymaps,msg))
		{
				cout<<"战斗结束，按任意键继续\n";
				while(kbhit())getch();
				getch();
				return 3;
		} else
		{
				cout<<"未复活，战斗结束，英雄阵亡。按任意键继续\n";
				while(kbhit())getch();
				getch();
				return 0;
		}
	}
	mymaps.rooms[pos-1]->deletemonster();addexp();cout<<"战斗结束，英雄获得胜利！获得1点经验\n按任意键继续\n";while(kbhit())getch();getch();return 1;
}
void hero::addexp()
	{
		this->exp++;
		if(this->exp>=5)
		{
		level++;
		exp-=5;
		speed++;
		speed_lim+=2;
		dam++;
		dam_lim+=2;
		hp_lim+=2;
		hp=hp_lim;
		shel_lim++;
		if(level %2) shel++;
		
		}
	}
void hero::add_hp(int hp)
{
	if(!hp) this->hp=hp_lim;
	this->hp+=hp;
	if(this->hp>hp_lim) this->hp=hp_lim;
}
int hero::gethp() const
{
	return this->hp;
}
int hero::getlev() const
{
	return this->level;
}

hero::~hero()
{
}