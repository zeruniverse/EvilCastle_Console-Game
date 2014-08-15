#include <ctime>
#include<iostream>
#include<sstream>
#include"mymap.h"
mymap::mymap(int difficult)
{
	int i,j,k,l,g,_1mymap;
	int tmp[8];
	bool mark;
	tmp[0]=1;
	princes=0;
	stair_num=0;
	stair.clear();
	rooms.clear();
	srand((unsigned)time(0)); 
	_1mymap=rand() % 21 + 2;
	rooms.push_back(new room(_1mymap));
	for(i=0;i<=difficult;i++)
	{
		for(j=tmp[i];j<=tmp[i]+20+i*10;j++)
		{
			rooms.push_back(new room(j+1,i));
		}
		tmp[i+1]=j;
	}
	this->room_num=tmp[difficult+1];
	rooms[_1mymap-1]->route('d',1);
	for(i=0;i<=difficult;i++) //构建路径
	{
		j=0;//东西方向上一次的开始
		l=tmp[i];//东西方向本次开始
		mark=false;
		while(true)//东西方向分层
		{
			k=rand() %8+5;//东西方向房间数
			for(g=l;g<l+k-1;g++)
			{
				if(g>tmp[i+1]-1){mark=true;break;}
				if(g==tmp[i+1]-1){
					mark=true; 
					if(j&&((j+g-l)<l))
					{
					rooms[g]->route('s',j+g-l+1);
					rooms[j+g-l]->route('n',g+1);
					}break;
					}
				rooms[g]->route('e',g+2);
				rooms[g+1]->route('w',g+1);
				if(j&&((j+g-l)<l))
				{
					rooms[g]->route('s',j+g-l+1);
					rooms[j+g-l]->route('n',g+1);
				}
			}
			if(mark) break;
			j=l;
			l=g+1;
		}
		if(!princes&&(i>difficult-2))//可以出现BOSS
		{
			k=rand()%(room_num-tmp[i])+tmp[i];
			princes=k;
			j=difficult+1;
			if(j>2) j+=1;
			rooms[k]->changeroom(j);
		}
		if(i)//上下楼梯
		{
			k=rand()%3+1;//楼梯个数
			for(j=0;j<k;j++)
			{
				l=rand()%(tmp[i]-tmp[i-1])+tmp[i-1];//上一层
				g=rand()%(tmp[i+1]-tmp[i])+tmp[i];//本层
				while(l==princes||g==princes||rooms[l]->getroute('u')||rooms[g]->getroute('d'))//公主房间不在楼梯上
				{
					l=rand()%(tmp[i]-tmp[i-1])+tmp[i-1];//上一层
					g=rand()%(tmp[i+1]-tmp[i])+tmp[i];//本层
				}
				rooms[l]->route('u',g+1);
				rooms[g]->route('d',l+1);
				stair_num++;
				stair.push_back(l);
			}
		}
	}
}
	void mymap::roominfo(int roomnum)
	{
		this->rooms[roomnum-1]->info();
	}
	int mymap::check_mon(int roomnum)
	{
		if(!this->rooms[roomnum-1]->check()) return -1;
		return this->rooms[roomnum-1]->getmons()->info();
	}
	int mymap::check_room_status(int roomnum)
	{
		return this->rooms[roomnum-1]->check();
	}
	int mymap::roomnumber() const
	{
		return this->room_num;
	}
	string mymap::getstair()
	{
		ostringstream oss;
		if(stair_num<0) return "";
		oss.clear();
	    oss.str("");
		oss<<"第"<<this->stair[--stair_num]<<"号房间有楼梯。";
	    return oss.str();
	}

	int mymap::getprinroom() const
	{
		return this->princes+1;
	}
	void mymap::findp()
	{
		this->rooms[princes]->_makestatus0();
	}
	room* mymap::getroom(int roomnum) const
	{
		return this->rooms[roomnum-1];
	}
mymap::~mymap()
{
	for(vector<room *>::iterator ite=this->rooms.begin(); ite!=this->rooms.end();ite++)//循环删除
	{
		delete(*ite);
	}
	rooms.clear();
	stair.clear();
	vector<room *>().swap(this->rooms);
	vector<int>().swap(this->stair);
}
