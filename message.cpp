#include <iostream>
#include<string.h>
#include<stdio.h>
#include <cstdlib>
#include "kbhit.h"
#include "message.h"
#include <stdlib.h>
#include <unistd.h>
#include "getch.h"
using namespace std;
void message::print(char *a) const
{
    int i,len;
    len=strlen(a);
    for(i=0;i<len;i++){printf("%c",a[i]);usleep(6600);}
}
void message::hint() const
{
    system("clear");
    cout<<"************************************************************************\n"
        <<"                           欢迎来到EvilCastle V1.6  \n"
        <<"                          PROGRAMMED BY ZEYU, ZHAO  \n\n\n"
        <<"                         输入游戏难度（0-6）开始游戏\n"
        <<"难度:  0--初学者；1--简单；2--中等；3--困难；4--高手；5--专家；6--挑战者\n"
        <<"                           输入命令'h'-显示游戏帮助\n"
        <<"                            输入命令'q'-退出游戏 \n"
        <<"                          (游戏中命令均不区分大小写)\n"
        <<"************************************************************************\n";

}
void message::welcome() const
{
    system("clear");
    print("很久以前，有一位公主被一群Monster绑架了。\nMonster的聚集地是离人类居住区很远的EvilCastle。\n");
    print("国王招募了很多勇士去EvilCastle拯救公主。但没有一个人能够回来。\n赏金越来越高，但是愿意去EvilCastle的人越来越少。\n");
    print("......\n此时，有一位勇士出现了。\n");
    print("他独自一人去了EvilCastle。\n故事就从这里开始了......\n");
    cout<<"按任意键继续\n";
    while(kbhit())getch();
    getch();
}
void message::help() const
{
    system("clear");
    cout<<"游戏中英雄将探索EvilCastle的房间。每进入一个房间会有对应提示。\n"
        <<"根据房间拥有的出口可以选择一个通向其它房间。\n"
        <<"在探索中，屏幕上方将显示英雄的信息。\n"
        <<"请不要轻易上楼，楼层越高怪物等级越高。\n"
        <<"在杀死怪物后可以获得经验并有一定概率获得信息或道具。\n"
        <<"游戏过程中还可以随机获得成就哦～尝试拿到所有成就吧～\n"
        <<"提示：游戏中的命令不区分大小写\n"
        <<"尽情探索吧^_^\n"
        <<"*************************\n按任意键返回\n";
    getch();
}