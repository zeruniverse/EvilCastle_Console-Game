#include<iostream>
#include "shoe.h"
shoe::shoe()
	{
		this->num=0;
	}
bool shoe::get()
	{
		int i=(num++) % 10;
		switch (i)
		{
		case 0:cout<<"��ò�Ьһ˫���ٶ�����\n";return true;
		case 5:cout<<"���nikeһ˫���ٶ�����\n";return true;
		case 9:cout<<"���adidasһ˫���ٶ�����\n";return true;
		}
		return false;
	}
shoe::~shoe()
	{
	}
