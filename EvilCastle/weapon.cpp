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
		case 0:cout<<"�����ֽ�����������ǿ\n";return true;
		case 5:cout<<"���AK47����������ǿ\n";return true;
		case 9:cout<<"��ô������������������ǿ\n";return true;
		}
		return false;
	}
weapon::~weapon()
	{
	}