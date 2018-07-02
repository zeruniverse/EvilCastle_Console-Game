#ifndef _WEAP_H_
#define _WEAP_H_
#include<string>
#include<iostream>
#include <vector>
using namespace std;
class weapon{
public:
    weapon();
    bool get();
    ~weapon();

private:
    int num;
};
#endif