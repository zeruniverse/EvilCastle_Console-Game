#ifndef _ROOM_H_
#define _ROOM_H_
#include"monster.h"
using namespace std;
class room{
public:
	room(int up_room);//��һ������
	room(int id,int level);
	void changeroom(int boss_level);//�����ķ��䣬���������մ�BOSS����
	void route(char direct,int go);
	void deletemonster();
	int check() const;
	void info();
	monster *getmons();
	int getroute(char direct) const;
	void _makestatus0();
	~room();
private:
	int id;
	int level;
	int east;
	int west;
	int south;
	int north;
	int up;
	int down;
	int status;
	monster *mons;
	
};
#endif _ROOM_H_