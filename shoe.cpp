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
        case 0:cout<<"获得草鞋一双，速度提升\n";return true;
        case 5:cout<<"获得nike一双，速度提升\n";return true;
        case 9:cout<<"获得adidas一双，速度提升\n";return true;
    }
    return false;
}
shoe::~shoe()
{
}