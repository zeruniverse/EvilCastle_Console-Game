#ifndef _MAP_H_
#define _MAP_H_
#include<string>
#include "room.h"
#include "hero.h"
#include <vector>
using namespace std;
class map{
	friend class hero;
public:
	map(int difficult); 
	~map();
private:
	vector<room *> rooms;
	int room_num;
	int princes;//������princes+1�ŷ���
	vector<int> stair;
	int stair_num;
};
#endif _MAP_H_