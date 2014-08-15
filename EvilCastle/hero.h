#ifndef _HERO_H_
#define _HERO_H_
#include<string>
#include <vector>
#include <iostream>
#include<ctime>
#include "mymap.h"
#include "message.h"
using namespace std;
class hero{
public:
	void getthing(int type);//1--武器，2--防具，3--鞋子
	hero(int difficult);
	bool die(int pos, class mymap const & mymaps,message & msg);//非BOSS致死获得重生机会
	void add_hp(int hp);//加血。0--加满；
	int battle(int pos, class mymap const & mymaps,bool iscatch,message &msg);//0--死了；1--赢了；2--看完全程;3--春哥的拯救
	bool move(class mymap const & mymaps,int pos);//true--找到公主；false--没找到
	void info();
	int getpos() const;
	int gethp() const;
	int getlev() const;
	~hero();
private:
	void addexp();
	int difficult;//猜数字难度
	int position;
	int hp;
	bool findprin;
	int hp_lim;
	int dam;
	int dam_lim;
	int shel;
	int shel_lim;
	int speed;
	int speed_lim;
	int exp;
	int level;
};
#endif _HERO_H_