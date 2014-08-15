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
		case 0:cout<<"获得布衣，防御力增强\n";return true;
		case 2:cout<<"获得盔甲，防御力增强\n";return true;
		case 5:cout<<"获得盾牌，防御力增强\n";return true;
		}
		return false;
	}
shield::~shield()
	{
	}

