#include <ctime>
#include<iostream>
#include"room.h"
room::room(int up_room)//��һ������
	{
		this->level=-1;
		status=0;
		id=1;
		this->east=0;
		this->west=0;
		this->up=up_room;
		this->down=0;
		this->south=0;
		this->north=0;
	}
room::room(int id,int level)
	{
		this->level=level;
		if(rand() % 2){status=1;mons=new monster(this->level);} else status=0;//1--�й֣�0--û��
		this->id=id;
		this->east=0;
		this->west=0;
		this->up=0;
		this->down=0;
		this->south=0;
		this->north=0;
	}
void room::deletemonster()
{
	if(status) delete(mons);
	if(status==2) status=3;else status=0;
}
void room::changeroom(int boss_level)//�����ķ��䣬���������մ�BOSS����
	{
		if(status) delete(mons);
		status=2;
		mons=new monster(boss_level);
	}
void room::route(char direct,int go)
	{
		switch (direct)
		{
		case 'e':this->east=go;break;
		case 'n':this->north=go;break;
		case 'w':this->west=go;break;
		case 's':this->south=go;break;
		case 'u':this->up=go;break;
		case 'd':this->down=go;break;
		}
	}

int room::getroute(char direct) const
	{
		switch (direct)
		{
		case 'e':return this->east;
		case 'n':return this->north;
		case 'w':return this->west;
		case 's':return this->south;
		case 'u':return this->up;
		case 'd':return this->down;
		}
	}
int room::check() const
	{
		return status;
	}
void room::info()
	{ 
		if(id!=1){
		cout<<"���ǵ�"<<this->id<<"�ŷ��䡣\n"
			<<"�����������³���:\n";
		if(east) cout<<"�������(E)ͨ���"<<east<<"�ŷ��䡣\n";
		if(west) cout<<"�������(W)ͨ���"<<west<<"�ŷ��䡣\n";
		if(north) cout<<"�������(N)ͨ���"<<north<<"�ŷ��䡣\n";
		if(south) cout<<"�������(S)ͨ���"<<south<<"�ŷ��䡣\n";
		if(up) cout<<"��¥������(U)���Ե����"<<up<<"�ŷ��䡣\n";
		if(down) cout<<"��¥������(D)���Ե����"<<down<<"�ŷ��䡣\n";
		}
		else {
			cout<<"�����ǵ�1�ŷ��䡣����EvilCastle���ó̴����￪ʼ��\n"
				<<"��EvilCastle�У��ȼ�Խ�ߵĹ���ֲ���Խ�ߵ�¥�㡣\n"
				<<"����ڳ��׼��֮ǰ�벻Ҫ���ϣ�U�������ߡ�\n"
				<<"������Ϊ�˱����Լ��İ�ȫ�����ٽ���¥�ݡ�\n"
				<<"����ÿһ�㶼������һ��������ͨ���һ���¥�ݡ�\n"
				<<"����EvilCastle�ĵײ㣬��¥������(U)����ͨ��"<<up<<"�ŷ���\n"
				<<"����̽����^_^\n";
		}
}
monster *room::getmons()
{
	if(this->status) return mons;
	else return NULL;
}
void room::_makestatus0()
{
	this->status=0;
}
room::~room()
{
	if(status) delete(mons);
}	