//难度0--初学者；1--简单；2--中等；3--困难；4--高手；5--专家；6--挑战者；

#include <iostream>
#include <string>
#include <ctime>
#include <conio.h>
#include "message.h"
#include "achievement.h"
#include "hero.h"
#include "information.h"
#include "mymap.h"
#include "shield.h"
#include "shoe.h"
#include "weapon.h"
#include <sstream>
void win(message &msg,achievement &ach)
{
	int cmd;
	system("cls");
	msg.print("勇士与公主来到了EvilCastle门口。\n数天后，勇士带着公主回到了王国的城门口。\n公主：谢谢你。\n勇士：没事。\n公主拿出一个礼盒。\n公主：这是我父亲送给我的，就当是一点心意吧。\n");
	cout<<"*************************\n"
		<<"是否接受公主的奖赏？\n"
		<<"Y:那我就收下吧。\n"
		<<"N:我做好事从不求回报。\n"
		<<"*************************\n";
	while(kbhit())getch();
	while(true)
	{
		cmd=getch();
		if(cmd=='y'||cmd=='Y')
		{
			system("cls");
			cout<<"勇士与公主来到了EvilCastle门口。\n数天后，勇士带着公主回到了王国的城门口。\n公主：谢谢你。\n勇士：没事。\n公主拿出一个礼盒。\n公主：这是我父亲送给我的，就当是一点心意吧。\n";
			msg.print("勇士：那我就收下吧。\n");
			cout<<"\n\n获得iPhone 5S 土豪金24K定制版一台\n";
			ach.getachv(19);
			break;
		}
		if(cmd=='n'||cmd=='N')
		{
			system("cls");
			cout<<"勇士与公主来到了EvilCastle门口。\n数天后，勇士带着公主回到了王国的城门口。\n公主：谢谢你。\n勇士：没事。\n公主拿出一个礼盒。\n公主：这是我父亲送给我的，就当是一点心意吧。\n";
			msg.print("勇士：江湖之人，本当见义勇为，礼品还是您留下吧。\n说完，勇士就消失了。\n公主再也没有见到过勇士，只在自己口袋里发现了他的QQ号\n......\n");
			ach.getachv(18);
			break;
		}
	}
	cout<<"游戏结束。\n按任意键查看游戏成就。";
    while(kbhit())getch();
	getch();
}

int main()
{
	message Msg;
	ostringstream oss;
	bool find,die,iscatch,getprin,getpringo,succ,isbreak;
	int dificult;
	int cmd;
	int pos,pos_next,i,j,k,hp,hp_old,lev,lev_old;
	hero *myhero;
	mymap *castle;
	shield *myshel;
	shoe *myshoe;
	weapon *myweap;
	information *info;
	achievement *achi;
	Msg.welcome();
	srand((unsigned)time(0));
	while(true)
	{
		Msg.hint();
		while(kbhit())getch();
		cmd=getch();
		if(cmd=='q'||cmd=='Q') break;
		if(cmd=='h'||cmd=='H') Msg.help();
		if(cmd>='0'&&cmd<='6')//开始游戏
		{
			find=false;
			die=false;
			getprin=false;
			getpringo=false;
			succ=false;
			isbreak=false;
			cmd=cmd-'0';
			system("cls");
			cout<<"在游戏中房间信息显示页面按下Q键可直接退出游戏返回主菜单!\n";
			cout<<"正在构建地图，请稍候......\n";
			myhero=new hero(cmd);
			castle=new mymap(cmd);
			myshoe=new shoe();
			myshel=new shield();
			myweap=new weapon();
			info=new information();
			achi=new achievement();
			oss.clear();
			oss.str("");
			oss<<"EvilCastle有"<<castle->roomnumber()<<"个房间。共"<<cmd+2<<"层（第1号房间所在层数是第一层）。";
			info->add(oss.str());
			cout<<"******\n游戏载入完成，按任意键进入游戏。\n";
			while(kbhit())getch();getch();
			system("cls");
			cout<<"英雄信息：\n";
			myhero->info();
			cout<<"**********************\n房间信息：\n";
			castle->roominfo(1);
			pos=1;
			cout<<"**********************\n请按下键盘上的字母代表你要探索的方向(E,W,N,S,U,D)\n";
			while(true)//开始探索
			{
				while(kbhit())getch();
				cmd=getch();
				hp_old=myhero->gethp();
				lev_old=myhero->getlev();
				switch (cmd)
				{
				case 'q':case'Q': isbreak=true;break;
				case 'e':case 'E':
					pos_next=castle->getroom(pos)->getroute('e');
					if(!pos_next){cout<<"哎呦，撞墙了。请输入其它方向。\n按任意键重试。";while(kbhit())getch();getch();break;}
					achi->getachv(0);
					if(!castle->check_room_status(pos_next)) {pos=pos_next; myhero->move(*castle,pos);break;}
					i=castle->check_mon(pos_next);
					cout<<"按下Y参加战斗，其它键逃跑\n";
					while(kbhit())getch();j=getch();
					iscatch=false;
					if(j!='Y'&&j!='y')
					{//逃跑
                    k=rand() % 6;
					if(k>1) {achi->getachv(10);break;}
					achi->getachv(11);
					iscatch=true;
					}
					//战斗
					k=myhero->battle(pos_next,*castle,iscatch,Msg);
					if(!k) {die=true;break;}
					if(k==3){pos=pos_next; myhero->move(*castle,pos);achi->getachv(9);break;}
					if(k==2) achi->getachv(6);
					achi->getachv(1);
					hp=myhero->gethp(); 
					if(hp==hp_old) achi->getachv(14);
					if(hp<=2) achi->getachv(8);
					lev=myhero->getlev();
					if(lev>lev_old) achi->getachv(7);
					if(i==1) 
					{
					//加血
					    k=rand() % 6;
						if(k) k+=myhero->getlev();
						cout<<"获得加血\n";
						_sleep(1500);
						myhero->add_hp(k);
					}
					if(i==2)
					{
						//武器
						iscatch=myweap->get();
						if(iscatch) 
							{_sleep(1500);
						myhero->getthing(1);achi->getachv(2);}
					}
					if(i==3)
					{
						
						iscatch=myshel->get();
						if(iscatch) 
							{_sleep(1500);
						myhero->getthing(2);achi->getachv(3);}
					}
					if(i==4)
					{
						
						iscatch=myshoe->get();
						if(iscatch) 
							{_sleep(1500);
						myhero->getthing(3);achi->getachv(4);}
					}
					if(i==5)
					{
						cout<<"正在搜寻怪物遗物以取得信息。\n";
						_sleep(1500);
						achi->getachv(5);
						if(!getprin)
						{
							achi->getachv(13);
							oss.clear();
						    oss.str("");
	                     	oss<<"公主在第"<<castle->getprinroom()<<"号房间。";
							info->add(oss.str());
							getprin=true;
						}else if(!getpringo)
						{
							achi->getachv(17);
							k=castle->getroom(castle->getprinroom())->getroute('e');
							if(!k) k=castle->getroom(castle->getprinroom())->getroute('w');
							if(!k) k=castle->getroom(castle->getprinroom())->getroute('n');
							if(!k) k=castle->getroom(castle->getprinroom())->getroute('s');
							oss.clear();
						    oss.str("");
	                     	oss<<"第"<<k<<"号房间可以通向公主的房间。";
							info->add(oss.str());
							getpringo=true;
						}else
						{//楼梯
							info->add(castle->getstair());
						}
					}
					myhero->move(*castle,pos_next);
					if(castle->check_room_status(pos_next)){find=true;achi->getachv(15);castle->findp();}
					pos=pos_next;
					break;
				case 'w':case'W':
					pos_next=castle->getroom(pos)->getroute('w');
					if(!pos_next){cout<<"哎呦，撞墙了。请输入其它方向。\n按任意键重试。";while(kbhit())getch();getch();break;}
					achi->getachv(0);
					if(!castle->check_room_status(pos_next)) {pos=pos_next; myhero->move(*castle,pos);break;}
					i=castle->check_mon(pos_next);
					cout<<"按下Y参加战斗，其它键逃跑\n";
					while(kbhit())getch();j=getch();
					iscatch=false;
					if(j!='Y'&&j!='y')
					{ //逃跑
                    k=rand() % 6;
					if(k>1) {achi->getachv(10);break;}
					achi->getachv(11);
					iscatch=true;
					}
					//战斗
					k=myhero->battle(pos_next,*castle,iscatch,Msg);
					if(!k) {die=true;break;}
					if(k==3){pos=pos_next; myhero->move(*castle,pos);achi->getachv(9);break;}
					if(k==2) achi->getachv(6);
					achi->getachv(1);
					hp=myhero->gethp(); 
					if(hp==hp_old) achi->getachv(14);
					if(hp<=2) achi->getachv(8);
					lev=myhero->getlev();
					if(lev>lev_old) achi->getachv(7);
					if(i==1) 
					{
					//加血
					    k=rand() % 6;
						if(k) k+=myhero->getlev();
						cout<<"获得加血\n";
						_sleep(1500);
						myhero->add_hp(k);
					}
					if(i==2)
					{
						//武器
						iscatch=myweap->get();
						if(iscatch) 
							{_sleep(1500);
						myhero->getthing(1);achi->getachv(2);}
					}
					if(i==3)
					{
						
						iscatch=myshel->get();
						if(iscatch) 
							{_sleep(1500);
						myhero->getthing(2);achi->getachv(3);}
					}
					if(i==4)
					{
						
						iscatch=myshoe->get();
						if(iscatch) 
							{_sleep(1500);
						myhero->getthing(3);achi->getachv(4);}
					}
					if(i==5)
					{
						cout<<"正在搜寻怪物遗物以取得信息。\n";
						_sleep(1500);
						achi->getachv(5);
						if(!getprin)
						{
							achi->getachv(13);
							oss.clear();
						    oss.str("");
	                     	oss<<"公主在第"<<castle->getprinroom()<<"号房间。";
							info->add(oss.str());
							getprin=true;
						}else if(!getpringo)
						{
							achi->getachv(17);
							k=castle->getroom(castle->getprinroom())->getroute('e');
							if(!k) k=castle->getroom(castle->getprinroom())->getroute('w');
							if(!k) k=castle->getroom(castle->getprinroom())->getroute('n');
							if(!k) k=castle->getroom(castle->getprinroom())->getroute('s');
							oss.clear();
						    oss.str("");
	                     	oss<<"第"<<k<<"号房间可以通向公主的房间。";
							info->add(oss.str());
							getpringo=true;
						}else
						{//楼梯
							info->add(castle->getstair());
						}
					}
					myhero->move(*castle,pos_next);
					if(castle->check_room_status(pos_next)){find=true;achi->getachv(15);castle->findp();}
					pos=pos_next;
					break;
				case 'n':case'N':
					pos_next=castle->getroom(pos)->getroute('n');
					if(!pos_next){cout<<"哎呦，撞墙了。请输入其它方向。\n按任意键重试。";while(kbhit())getch();getch();break;}
					achi->getachv(0);
					if(!castle->check_room_status(pos_next)) {pos=pos_next; myhero->move(*castle,pos);break;}
					i=castle->check_mon(pos_next);
					cout<<"按下Y参加战斗，其它键逃跑\n";
					while(kbhit())getch();j=getch();
					iscatch=false;
					if(j!='Y'&&j!='y')
					{//逃跑
                    k=rand() % 6;
					if(k>2) {achi->getachv(10);break;}
					achi->getachv(11);
					iscatch=true;
					}
					//战斗
					k=myhero->battle(pos_next,*castle,iscatch,Msg);
					if(!k) {die=true;break;}
					if(k==3){pos=pos_next; myhero->move(*castle,pos);achi->getachv(9);break;}
					if(k==2) achi->getachv(6);
					achi->getachv(1);
					hp=myhero->gethp(); 
					if(hp==hp_old) achi->getachv(14);
					if(hp<=2) achi->getachv(8);
					lev=myhero->getlev();
					if(lev>lev_old) achi->getachv(7);
					if(i==1) 
					{
					//加血
					    k=rand() % 6;
						if(k) k+=myhero->getlev();
						cout<<"获得加血\n";
						_sleep(1500);
						myhero->add_hp(k);
					}
					if(i==2)
					{
						//武器
						iscatch=myweap->get();
						if(iscatch) 
							{_sleep(1500);
						myhero->getthing(1);achi->getachv(2);}
					}
					if(i==3)
					{
						
						iscatch=myshel->get();
						if(iscatch) 
							{_sleep(1500);
						myhero->getthing(2);achi->getachv(3);}
					}
					if(i==4)
					{
						
						iscatch=myshoe->get();
						if(iscatch) 
							{_sleep(1500);
						myhero->getthing(3);achi->getachv(4);}
					}
					if(i==5)
					{
						cout<<"正在搜寻怪物遗物以取得信息。\n";
						_sleep(1500);
						achi->getachv(5);
						if(!getprin)
						{
							achi->getachv(13);
							oss.clear();
						    oss.str("");
	                     	oss<<"公主在第"<<castle->getprinroom()<<"号房间。";
							info->add(oss.str());
							getprin=true;
						}else if(!getpringo)
						{
							achi->getachv(17);
							k=castle->getroom(castle->getprinroom())->getroute('e');
							if(!k) k=castle->getroom(castle->getprinroom())->getroute('w');
							if(!k) k=castle->getroom(castle->getprinroom())->getroute('n');
							if(!k) k=castle->getroom(castle->getprinroom())->getroute('s');
							oss.clear();
						    oss.str("");
	                     	oss<<"第"<<k<<"号房间可以通向公主的房间。";
							info->add(oss.str());
							getpringo=true;
						}else
						{//楼梯
							info->add(castle->getstair());
						}
					}
					myhero->move(*castle,pos_next);
					if(castle->check_room_status(pos_next)){find=true;achi->getachv(15);castle->findp();}
					pos=pos_next;
					break;
				case 's':case 'S':
					pos_next=castle->getroom(pos)->getroute('s');
					if(!pos_next){cout<<"哎呦，撞墙了。请输入其它方向。\n按任意键重试。";while(kbhit())getch();getch();break;}
					achi->getachv(0);
					if(!castle->check_room_status(pos_next)) {pos=pos_next; myhero->move(*castle,pos);break;}
					i=castle->check_mon(pos_next);
					cout<<"按下Y参加战斗，其它键逃跑\n";
					while(kbhit())getch();j=getch();
					iscatch=false;
					if(j!='Y'&&j!='y')
					{
						//逃跑
                    k=rand() % 6;
					if(k>1) {achi->getachv(10);break;}
					achi->getachv(11);
					iscatch=true;
					}
					//战斗
					k=myhero->battle(pos_next,*castle,iscatch,Msg);
					if(!k) {die=true;break;}
					if(k==3){pos=pos_next; myhero->move(*castle,pos);achi->getachv(9);break;}
					if(k==2) achi->getachv(6);
					achi->getachv(1);
					hp=myhero->gethp(); 
					if(hp==hp_old) achi->getachv(14);
					if(hp<=2) achi->getachv(8);
					lev=myhero->getlev();
					if(lev>lev_old) achi->getachv(7);
					if(i==1) 
					{
					//加血
					    k=rand() % 6;
						if(k) k+=myhero->getlev();
						cout<<"获得加血\n";
						_sleep(1500);
						myhero->add_hp(k);
					}
					if(i==2)
					{
						//武器
						iscatch=myweap->get();
						if(iscatch) 
							{_sleep(1500);
						myhero->getthing(1);achi->getachv(2);}
					}
					if(i==3)
					{
						
						iscatch=myshel->get();
						if(iscatch) 
							{_sleep(1500);
						myhero->getthing(2);achi->getachv(3);}
					}
					if(i==4)
					{
						
						iscatch=myshoe->get();
						if(iscatch) 
							{_sleep(1500);
						myhero->getthing(3);achi->getachv(4);}
					}
					if(i==5)
					{
						cout<<"正在搜寻怪物遗物以取得信息。\n";
						_sleep(1500);
						achi->getachv(5);
						if(!getprin)
						{
							achi->getachv(13);
							oss.clear();
						    oss.str("");
	                     	oss<<"公主在第"<<castle->getprinroom()<<"号房间。";
							info->add(oss.str());
							getprin=true;
						}else if(!getpringo)
						{
							achi->getachv(17);
							k=castle->getroom(castle->getprinroom())->getroute('e');
							if(!k) k=castle->getroom(castle->getprinroom())->getroute('w');
							if(!k) k=castle->getroom(castle->getprinroom())->getroute('n');
							if(!k) k=castle->getroom(castle->getprinroom())->getroute('s');
							oss.clear();
						    oss.str("");
	                     	oss<<"第"<<k<<"号房间可以通向公主的房间。";
							info->add(oss.str());
							getpringo=true;
						}else
						{//楼梯
							info->add(castle->getstair());
						}
					}
					myhero->move(*castle,pos_next);
					if(castle->check_room_status(pos_next)){find=true;achi->getachv(15);castle->findp();}
					pos=pos_next;
					break;
				case 'd':case'D':
					pos_next=castle->getroom(pos)->getroute('d');
					if(pos_next==1) {if(find){succ=true;break;}else achi->getachv(12);}
					if(!pos_next){cout<<"哎呦，撞墙了。请输入其它方向。\n按任意键重试。";while(kbhit())getch();getch();break;}
					achi->getachv(0);
					if(!castle->check_room_status(pos_next)) {pos=pos_next; myhero->move(*castle,pos);break;}
					i=castle->check_mon(pos_next);
					cout<<"按下Y参加战斗，其它键逃跑\n";
					while(kbhit())getch();j=getch();
					iscatch=false;
					if(j!='Y'&&j!='y')
					{//逃跑
                    k=rand() % 6;
					if(k>1) {achi->getachv(10);break;}
					achi->getachv(11);
					iscatch=true;
					}
					//战斗
					k=myhero->battle(pos_next,*castle,iscatch,Msg);
					if(!k) {die=true;break;}
					if(k==3){pos=pos_next; myhero->move(*castle,pos);achi->getachv(9);break;}
					if(k==2) achi->getachv(6);
					achi->getachv(1);
					hp=myhero->gethp(); 
					if(hp==hp_old) achi->getachv(14);
					if(hp<=2) achi->getachv(8);
					lev=myhero->getlev();
					if(lev>lev_old) achi->getachv(7);
					if(i==1) 
					{
					//加血
					    k=rand() % 6;
						if(k) k+=myhero->getlev();
						cout<<"获得加血\n";
						_sleep(1500);
						myhero->add_hp(k);
					}
					if(i==2)
					{
						//武器
						iscatch=myweap->get();
						if(iscatch) 
							{_sleep(1500);
						myhero->getthing(1);achi->getachv(2);}
					}
					if(i==3)
					{
						
						iscatch=myshel->get();
						if(iscatch) 
							{_sleep(1500);
						myhero->getthing(2);achi->getachv(3);}
					}
					if(i==4)
					{
						
						iscatch=myshoe->get();
						if(iscatch) 
							{_sleep(1500);
						myhero->getthing(3);achi->getachv(4);}
					}
					if(i==5)
					{
						cout<<"正在搜寻怪物遗物以取得信息。\n";
						_sleep(1500);
						achi->getachv(5);
						if(!getprin)
						{
							achi->getachv(13);
							oss.clear();
						    oss.str("");
	                     	oss<<"公主在第"<<castle->getprinroom()<<"号房间。";
							info->add(oss.str());
							getprin=true;
						}else if(!getpringo)
						{
							achi->getachv(17);
							k=castle->getroom(castle->getprinroom())->getroute('e');
							if(!k) k=castle->getroom(castle->getprinroom())->getroute('w');
							if(!k) k=castle->getroom(castle->getprinroom())->getroute('n');
							if(!k) k=castle->getroom(castle->getprinroom())->getroute('s');
							oss.clear();
						    oss.str("");
	                     	oss<<"第"<<k<<"号房间可以通向公主的房间。";
							info->add(oss.str());
							getpringo=true;
						}else
						{//楼梯
							info->add(castle->getstair());
						}
					}
					myhero->move(*castle,pos_next);
					if(castle->check_room_status(pos_next)){find=true;achi->getachv(15);castle->findp();}
					pos=pos_next;
					break;
				case 'u':case'U':
					pos_next=castle->getroom(pos)->getroute('u');
					if(!pos_next){cout<<"哎呦，撞墙了。请输入其它方向。\n按任意键重试。";while(kbhit())getch();getch();break;}
					if(pos!=1) achi->getachv(16);
					achi->getachv(0);
					if(!castle->check_room_status(pos_next)) {pos=pos_next; myhero->move(*castle,pos);break;}
					i=castle->check_mon(pos_next);
					cout<<"按下Y参加战斗，其它键逃跑\n";
					while(kbhit())getch();j=getch();
					iscatch=false;
					if(j!='Y'&&j!='y')
					{ //逃跑
                    k=rand() % 6;
					if(k>1) {achi->getachv(10);break;}
					achi->getachv(11);
					iscatch=true;
					}
					//战斗
					k=myhero->battle(pos_next,*castle,iscatch,Msg);
					if(!k) {die=true;break;}
					if(k==3){pos=pos_next; myhero->move(*castle,pos);achi->getachv(9);break;}
					if(k==2) achi->getachv(6);
					achi->getachv(1);
					hp=myhero->gethp(); 
					if(hp==hp_old) achi->getachv(14);
					if(hp<=2) achi->getachv(8);
					lev=myhero->getlev();
					if(lev>lev_old) achi->getachv(7);
					if(i==1) 
					{
					//加血
					    k=rand() % 6;
						if(k) k+=myhero->getlev();
						cout<<"获得加血\n";
						_sleep(1500);
						myhero->add_hp(k);
					}
					if(i==2)
					{
						//武器
						iscatch=myweap->get();
						if(iscatch) 
							{_sleep(1500);
						myhero->getthing(1);achi->getachv(2);}
					}
					if(i==3)
					{
						
						iscatch=myshel->get();
						if(iscatch) 
							{_sleep(1500);
						myhero->getthing(2);achi->getachv(3);}
					}
					if(i==4)
					{
						
						iscatch=myshoe->get();
						if(iscatch) 
							{_sleep(1500);
						myhero->getthing(3);achi->getachv(4);}
					}
					if(i==5)
					{
						cout<<"正在搜寻怪物遗物以取得信息。\n";
						_sleep(1500);
						achi->getachv(5);
						if(!getprin)
						{
							achi->getachv(13);
							oss.clear();
						    oss.str("");
	                     	oss<<"公主在第"<<castle->getprinroom()<<"号房间。";
							info->add(oss.str());
							getprin=true;
						}else if(!getpringo)
						{
							achi->getachv(17);
							k=castle->getroom(castle->getprinroom())->getroute('e');
							if(!k) k=castle->getroom(castle->getprinroom())->getroute('w');
							if(!k) k=castle->getroom(castle->getprinroom())->getroute('n');
							if(!k) k=castle->getroom(castle->getprinroom())->getroute('s');
							oss.clear();
						    oss.str("");
	                     	oss<<"第"<<k<<"号房间可以通向公主的房间。";
							info->add(oss.str());
							getpringo=true;
						}else
						{//楼梯
							info->add(castle->getstair());
						}
					}
					myhero->move(*castle,pos_next);
					if(castle->check_room_status(pos_next)){find=true;achi->getachv(15);castle->findp();}
					pos=pos_next;
					break;
					}
					if(isbreak)//处理强退
					{cout<<"等待系统重置地图...请稍候";break;}
					if(succ)//处理胜利
					{
						win(Msg,*achi);
						system("cls");
						cout<<"***********************\n"
							<<"游戏成就页面\n"
							<<"***********************\n";
						achi->listall();
						while(kbhit())getch();
						cout<<"***********************\n"
							<<"按任意键返回游戏主菜单。\n";
						getch();
						cout<<"等待系统重置地图...请稍候";
						break;
					}
					if(die)//处理死亡
					{
						system("cls");
						cout<<"英雄阵亡，游戏失败\n按任意键查看本次游戏所获成就。\n";
						while(kbhit())getch();getch();
						cout<<"***********************\n"
							<<"游戏成就页面\n"
							<<"***********************\n";
						achi->listall();
						while(kbhit())getch();
						cout<<"***********************\n"
							<<"按任意键返回游戏主菜单。\n";
						getch();
						cout<<"等待系统重置地图...请稍候";
						break;
					}
					system("cls");
					cout<<"英雄信息：\n";
					myhero->info();
					cout<<"**********************\n目前掌握的EvilCastle信息：\n";
					info->listall();
					cout<<"**********************\n房间信息：\n";
					castle->roominfo(pos);
					cout<<"**********************\n请按下键盘上的字母代表你要探索的方向(E,W,N,S,U,D)\n";
					}
					delete(myhero);
					delete(castle);
					delete(myshoe);
					delete(myshel);
					delete(myweap);
					delete(info);
					delete(achi);
					}
	}
}