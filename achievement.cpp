#include<iostream>
#include <unistd.h>
#include"achievement.h"
achievement::achievement()
{
    this->achieve.clear();
    for(int i=0; i<20;i++) goten[i]=false;
}
void achievement::listall()
{
    cout<<"本局游戏所获成就（按获得时间排序）：\n";
    for(vector<string>::iterator ite=this->achieve.begin(); ite!=this->achieve.end();ite++)//循环输出所有记录
    {
        cout<<*ite<<"\n";
    }

}
void achievement::getachv(int type)
{
    if(goten[type]) return ;
    goten[type]=true;
    switch (type)
    {
       case 0: this->achieve.push_back("迈出第一步——开始游戏并探索一个房间"); cout<<"获得成就：迈出第一步\n";sleep(1);return ;
       case 1: this->achieve.push_back("打败怪物——打败第一个怪物");cout<<"获得成就：打败怪物\n";sleep(1); return;
       case 2: this->achieve.push_back("获得武器——获得第一件武器"); cout<<"获得成就：获得武器\n";sleep(1);return;
       case 3: this->achieve.push_back("获得防具——获得第一件防具"); cout<<"获得成就：获得防具\n";sleep(1);return;
       case 4: this->achieve.push_back("获得鞋子——获得第一件鞋子");cout<<"获得成就：获得鞋子\n";sleep(1); return;
       case 5: this->achieve.push_back("取得信息——取得第一条信息"); cout<<"获得成就：取得信息\n";sleep(1);return;
       case 6: this->achieve.push_back("有耐心是一种美德——观看完一次战斗并取得胜利");cout<<"获得成就：有耐心是一种美德\n";sleep(1); return ;
       case 7: this->achieve.push_back("升级——获得第一次升级");cout<< "获得成就：升级\n";sleep(1); return;
       case 8: this->achieve.push_back("大难不死——赢得战斗时HP<=2");cout<< "获得成就：大难不死\n";sleep(1); return;
       case 9: this->achieve.push_back("命不该绝——成功获得春哥帮助"); cout<<"获得成就：命不该绝\n";sleep(1); return;
       case 10: this->achieve.push_back("溜得快——成功逃跑"); cout<< "获得成就：溜得快\n";sleep(1);return;
       case 11: this->achieve.push_back("惨遭毒手——逃跑失败，被迫战斗");cout<< "获得成就：惨遭毒手\n";sleep(1); return;
       case 12: this->achieve.push_back("迷途知返——未找到公主返回第一层（开始的地方）"); cout<<"获得成就：迷途知返\n";sleep(1); return;
       case 13: this->achieve.push_back("公主在那里——得知公主的位置"); cout<<"获得成就：公主在那里\n";sleep(1);return ;
       case 14: this->achieve.push_back("小菜一碟——不损失HP打败怪物");cout<<"获得成就：小菜一碟\n";sleep(1); return ;
       case 15: this->achieve.push_back("功成名就——找到公主");cout<< "获得成就：功成名就（在房间内发现公主！）\n";sleep(1); return;
       case 16: this->achieve.push_back("勇气——第一次上二楼以上");cout<< "获得成就：勇气\n";sleep(1); return;
       case 17: this->achieve.push_back("一线光明——获得通向公主所在地的信息");cout<<"获得成就：一线光明\n"; sleep(1);return ;
       case 18: this->achieve.push_back("雷锋——拒绝公主的奖赏"); cout<<"获得成就：雷锋\n";sleep(1);return ;
       case 19: this->achieve.push_back("取得回报——接受公主的奖赏");cout<< "获得成就：取得回报\n";sleep(1); return;
       default: return;
   }
}
achievement::~achievement()
{
    this->achieve.clear();
    vector<string>().swap(this->achieve);
}