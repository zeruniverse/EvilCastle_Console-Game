#include<iostream>
#include"shield.h"
	
shield::shield()
	{
		this->num=0;
	}
bool shield::get()
	{
		int i=(num++) % 7;
		switch (i)
		{
		case 0:cout<<"��ò��£���������ǿ\n";return true;
		case 2:cout<<"��ÿ��ף���������ǿ\n";return true;
		case 5:cout<<"��ö��ƣ���������ǿ\n";return true;
		}
		return false;
	}
shield::~shield()
	{
	}

