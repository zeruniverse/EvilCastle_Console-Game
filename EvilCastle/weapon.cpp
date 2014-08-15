#include<iostream>
#include "weapon.h"
weapon::weapon()
	{
		this->num=0;
	}
bool weapon::get()
	{
		int i=(num++) % 10;
		switch (i)
		{
		case 0:cout<<"获得青钢剑，攻击力增强\n";return true;
		case 5:cout<<"获得AK47，攻击力增强\n";return true;
		case 9:cout<<"获得春哥的力量，攻击力增强\n";return true;
		}
		return false;
	}
weapon::~weapon()
	{
	}