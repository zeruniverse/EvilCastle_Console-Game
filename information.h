#ifndef _INFO_H_
#define _INFO_H_
#include<string>
#include <vector>
using namespace std;
class information{
public:
    information();
    void listall();
    void add(string info);
    ~information();
private:
    vector<string> info;
};
#endif