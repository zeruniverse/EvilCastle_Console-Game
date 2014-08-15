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
	void getthing(int type);//1--������2--���ߣ�3--Ь��
	hero(int difficult);
	bool die(int pos, class mymap const & mymaps,message & msg);//��BOSS���������������
	void add_hp(int hp);//��Ѫ��0--������
	int battle(int pos, class mymap const & mymaps,bool iscatch,message &msg);//0--���ˣ�1--Ӯ�ˣ�2--����ȫ��;3--���������
	bool move(class mymap const & mymaps,int pos);//true--�ҵ�������false--û�ҵ�
	void info();
	int getpos() const;
	int gethp() const;
	int getlev() const;
	~hero();
private:
	void addexp();
	int difficult;//�������Ѷ�
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