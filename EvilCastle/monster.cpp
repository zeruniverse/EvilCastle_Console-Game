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
		cout<<"�ô��й��￴��\n������ϢΪ��\n";
		switch (type)
		{
		case  0:cout<<"��ͨ����\n";break;
		case  1:cout<<"Ѫ��\n";break;
		case  2:cout<<"���������Ĺ���\n";break;
		case  3:cout<<"���ض��ƵĹ���\n";break;
		case  4:cout<<"��Ь�ӵĹ���\n";break;
		case  5:cout<<"����ͨ��Ա\n";break;
		}
		cout<<"Ѫ����"<<hp<<"\n";
		cout<<"������"<<dam<<"\n";
		cout<<"�ٶȣ�"<<speed<<"\n";
		return type;
	}
int monster::getdam() const
	{return dam;}
int monster::gethp() const {return hp;}
int monster::getspd() const {return speed;}
monster::~monster()
	{
	}