#ifndef _MONS_H_
#define _MONS_H_
#include<string>
using namespace std;
class monster{
public:
	monster(int level);
	int info();
	int getdam() const;
	int gethp() const;
	int getspd() const;
	~monster();


private:
	int type;
	int hp;
	int dam;
	int speed;
};
#endif _MONS_H_