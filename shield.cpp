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
        case 0:cout<<"获得草盾，防御提升\n";return true;
        case 2:cout<<"获得铁盾，防御提升\n";return true;
        case 5:cout<<"获得钢盾，防御提升\n";return true;
    }
    return false;
}
shield::~shield()
{
}