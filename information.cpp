#include<iostream>
#include"information.h"
information::information()
{
    this->info.clear();
}
void information::listall()
{
    for(vector<string>::iterator ite=this->info.begin(); ite!=this->info.end();ite++)//Ñ­»·Êä³öËùÓÐ¼ÇÂ¼
    {
        cout<<*ite<<"\n";
    }
}
void information::add(string info)
{
    if(info!="") this->info.push_back(info);
}
information::~information()
{
    this->info.clear();
    vector<string>().swap(this->info);
}