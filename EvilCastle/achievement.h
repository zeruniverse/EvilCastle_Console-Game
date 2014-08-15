#ifndef _ACHIV_H_
#define _ACHIV_H_
#include<string>
#include <vector>
using namespace std;
class achievement{
public:
	achievement();
	void listall();
	void getachv(int type);
	~achievement();



private:
	vector<string> achieve;
	bool goten[20];
};
#endif _ACHIV_H_