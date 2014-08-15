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
	if(findprin) {cout<<"Ӣ�����ҵ�����������칫����EvilCastle���ڣ�����1�����䣩��\n";}
	else cout<<"����̽��EvilCastle���ҵ�����\n";
	cout<<"��ѪHP��"<<hp<<"/"<<hp_lim<<"\n"
		<<"ɱ������"<<dam<<"/"<<dam_lim<<"\n"
		<<"��������"<<shel<<"/"<<shel_lim<<"\n"
		<<"�ٶ�:   "<<speed<<"/"<<speed_lim<<"\n"
		<<"���飺  "<<exp<<"/5\n"
		<<"�ȼ���  "<<level<<"\n";
}
int hero::getpos() const
{
	return position;
}
bool hero::die(int pos,mymap const &now,message & msg)
{
		int i;
		cout<<"Ӣ�۲���������\n������ؼ���ʱ�̣����������\n";
		if(now.rooms[pos-1]->check()==2) {cout<<"����һ����Ȼ�ǿ��ع������ռ���BOSS������ORZ......";return false;}
			msg.print("���磺����������ң��ҿ������㸴�\n");
			msg.print("Ӣ�ۣ��Ŵ��磬��������\n");
			msg.print("���磺��Ҫ�������Ƿ��ϣ�����������һ��0��");
			cout<<2+difficult;
			msg.print("����(0,...,");
			cout<<2+difficult;
			msg.print(")����һ�°ɣ�\n");
			cout<<"��������²������>>";
		cin>>i;
		if(i==rand() % (3+difficult)||i==8200)//i=8200����ģʽ
		{
			cout<<"��ϲ��Ѫ���\n�����ѱ�������ߣ�\n";
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
	if(iscatch)cout<<"�����﷢���ˣ�ǿ�Ʋμ�ս����\n";
	cout<<"��ʼս��\n";
	cout<<"***********\n���������������ս������\n"
		<<"***********\n";
	if(mymaps.rooms[pos-1]->getmons()->getspd()>this->speed)
		{
			hp=hp-mondam;
			if(hp<=0) hp=0;
			cout<<"����غϣ������Ӣ�����"<<mondam<<"���˺���Ӣ��ʣ��HP��"<<hp<<"\n";
			if(hp==0) if(die(pos,mymaps,msg))
			{
				cout<<"ս�������������������\n";
				while(kbhit())getch();
				getch();
				return 3;
			} else
			{
				cout<<"δ���ս��������Ӣ�������������������\n";
				while(kbhit())getch();
				getch();
				return 0;
			}
	}
	while(!kbhit())//û�а��¼�
	{
		_sleep(1500);
		monhp=monhp-dam<0?0:monhp-dam;
		cout<<"Ӣ�ۻغϣ�Ӣ�۶Թ������"<<dam<<"���˺�������ʣ��HP��"<<monhp<<"\n";
		if(monhp==0) break;
		_sleep(1500);
		if(kbhit()) {key=true;break;}
		hp=hp-mondam;
		if(hp<=0) hp=0;
		cout<<"����غϣ������Ӣ�����"<<mondam<<"���˺���Ӣ��ʣ��HP��"<<hp<<"\n";
		if(hp==0) if(die(pos,mymaps,msg))
		{
				cout<<"ս�������������������\n";
				while(kbhit())getch();
				getch();
				return 3;
		} else
		{
				cout<<"δ���ս��������Ӣ�������������������\n";
				while(kbhit())getch();
				getch();
				return 0;
		}
	}
	if(monhp==0){mymaps.rooms[pos-1]->deletemonster();addexp();cout<<"ս��������Ӣ�ۻ��ʤ�������1�㾭��\n�����������\n";while(kbhit())getch();getch();return 2;}
	cout<<"...\n";
	if(key)//����غ�
	{
			hp=hp-mondam;
			if(hp<=0) hp=0;
			if(hp==0) if(die(pos,mymaps,msg))
			{
				cout<<"ս�������������������\n";
				while(kbhit())getch();
				getch();
				return 3;
			} else
			{
				cout<<"δ���ս��������Ӣ�������������������\n";
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
				cout<<"ս�������������������\n";
				while(kbhit())getch();
				getch();
				return 3;
		} else
		{
				cout<<"δ���ս��������Ӣ�������������������\n";
				while(kbhit())getch();
				getch();
				return 0;
		}
	}
	mymaps.rooms[pos-1]->deletemonster();addexp();cout<<"ս��������Ӣ�ۻ��ʤ�������1�㾭��\n�����������\n";while(kbhit())getch();getch();return 1;
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