//�Ѷ�0--��ѧ�ߣ�1--�򵥣�2--�еȣ�3--���ѣ�4--���֣�5--ר�ң�6--��ս�ߣ�

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
	msg.print("��ʿ�빫��������EvilCastle�ſڡ�\n�������ʿ���Ź����ص��������ĳ��ſڡ�\n������лл�㡣\n��ʿ��û�¡�\n�����ó�һ����С�\n�����������Ҹ����͸��ҵģ��͵���һ������ɡ�\n");
	cout<<"*************************\n"
		<<"�Ƿ���ܹ����Ľ��ͣ�\n"
		<<"Y:���Ҿ����°ɡ�\n"
		<<"N:�������´Ӳ���ر���\n"
		<<"*************************\n";
	while(kbhit())getch();
	while(true)
	{
		cmd=getch();
		if(cmd=='y'||cmd=='Y')
		{
			system("cls");
			cout<<"��ʿ�빫��������EvilCastle�ſڡ�\n�������ʿ���Ź����ص��������ĳ��ſڡ�\n������лл�㡣\n��ʿ��û�¡�\n�����ó�һ����С�\n�����������Ҹ����͸��ҵģ��͵���һ������ɡ�\n";
			msg.print("��ʿ�����Ҿ����°ɡ�\n");
			cout<<"\n\n���iPhone 5S ������24K���ư�һ̨\n";
			ach.getachv(19);
			break;
		}
		if(cmd=='n'||cmd=='N')
		{
			system("cls");
			cout<<"��ʿ�빫��������EvilCastle�ſڡ�\n�������ʿ���Ź����ص��������ĳ��ſڡ�\n������лл�㡣\n��ʿ��û�¡�\n�����ó�һ����С�\n�����������Ҹ����͸��ҵģ��͵���һ������ɡ�\n";
			msg.print("��ʿ������֮�ˣ�����������Ϊ����Ʒ���������°ɡ�\n˵�꣬��ʿ����ʧ�ˡ�\n������Ҳû�м�������ʿ��ֻ���Լ��ڴ��﷢��������QQ��\n......\n");
			ach.getachv(18);
			break;
		}
	}
	cout<<"��Ϸ������\n��������鿴��Ϸ�ɾ͡�";
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
		if(cmd>='0'&&cmd<='6')//��ʼ��Ϸ
		{
			find=false;
			die=false;
			getprin=false;
			getpringo=false;
			succ=false;
			isbreak=false;
			cmd=cmd-'0';
			system("cls");
			cout<<"����Ϸ�з�����Ϣ��ʾҳ�水��Q����ֱ���˳���Ϸ�������˵�!\n";
			cout<<"���ڹ�����ͼ�����Ժ�......\n";
			myhero=new hero(cmd);
			castle=new mymap(cmd);
			myshoe=new shoe();
			myshel=new shield();
			myweap=new weapon();
			info=new information();
			achi=new achievement();
			oss.clear();
			oss.str("");
			oss<<"EvilCastle��"<<castle->roomnumber()<<"�����䡣��"<<cmd+2<<"�㣨��1�ŷ������ڲ����ǵ�һ�㣩��";
			info->add(oss.str());
			cout<<"******\n��Ϸ������ɣ��������������Ϸ��\n";
			while(kbhit())getch();getch();
			system("cls");
			cout<<"Ӣ����Ϣ��\n";
			myhero->info();
			cout<<"**********************\n������Ϣ��\n";
			castle->roominfo(1);
			pos=1;
			cout<<"**********************\n�밴�¼����ϵ���ĸ������Ҫ̽���ķ���(E,W,N,S,U,D)\n";
			while(true)//��ʼ̽��
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
					if(!pos_next){cout<<"���ϣ�ײǽ�ˡ���������������\n����������ԡ�";while(kbhit())getch();getch();break;}
					achi->getachv(0);
					if(!castle->check_room_status(pos_next)) {pos=pos_next; myhero->move(*castle,pos);break;}
					i=castle->check_mon(pos_next);
					cout<<"����Y�μ�ս��������������\n";
					while(kbhit())getch();j=getch();
					iscatch=false;
					if(j!='Y'&&j!='y')
					{//����
                    k=rand() % 6;
					if(k>1) {achi->getachv(10);break;}
					achi->getachv(11);
					iscatch=true;
					}
					//ս��
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
					//��Ѫ
					    k=rand() % 6;
						if(k) k+=myhero->getlev();
						cout<<"��ü�Ѫ\n";
						_sleep(1500);
						myhero->add_hp(k);
					}
					if(i==2)
					{
						//����
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
						cout<<"������Ѱ����������ȡ����Ϣ��\n";
						_sleep(1500);
						achi->getachv(5);
						if(!getprin)
						{
							achi->getachv(13);
							oss.clear();
						    oss.str("");
	                     	oss<<"�����ڵ�"<<castle->getprinroom()<<"�ŷ��䡣";
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
	                     	oss<<"��"<<k<<"�ŷ������ͨ�����ķ��䡣";
							info->add(oss.str());
							getpringo=true;
						}else
						{//¥��
							info->add(castle->getstair());
						}
					}
					myhero->move(*castle,pos_next);
					if(castle->check_room_status(pos_next)){find=true;achi->getachv(15);castle->findp();}
					pos=pos_next;
					break;
				case 'w':case'W':
					pos_next=castle->getroom(pos)->getroute('w');
					if(!pos_next){cout<<"���ϣ�ײǽ�ˡ���������������\n����������ԡ�";while(kbhit())getch();getch();break;}
					achi->getachv(0);
					if(!castle->check_room_status(pos_next)) {pos=pos_next; myhero->move(*castle,pos);break;}
					i=castle->check_mon(pos_next);
					cout<<"����Y�μ�ս��������������\n";
					while(kbhit())getch();j=getch();
					iscatch=false;
					if(j!='Y'&&j!='y')
					{ //����
                    k=rand() % 6;
					if(k>1) {achi->getachv(10);break;}
					achi->getachv(11);
					iscatch=true;
					}
					//ս��
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
					//��Ѫ
					    k=rand() % 6;
						if(k) k+=myhero->getlev();
						cout<<"��ü�Ѫ\n";
						_sleep(1500);
						myhero->add_hp(k);
					}
					if(i==2)
					{
						//����
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
						cout<<"������Ѱ����������ȡ����Ϣ��\n";
						_sleep(1500);
						achi->getachv(5);
						if(!getprin)
						{
							achi->getachv(13);
							oss.clear();
						    oss.str("");
	                     	oss<<"�����ڵ�"<<castle->getprinroom()<<"�ŷ��䡣";
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
	                     	oss<<"��"<<k<<"�ŷ������ͨ�����ķ��䡣";
							info->add(oss.str());
							getpringo=true;
						}else
						{//¥��
							info->add(castle->getstair());
						}
					}
					myhero->move(*castle,pos_next);
					if(castle->check_room_status(pos_next)){find=true;achi->getachv(15);castle->findp();}
					pos=pos_next;
					break;
				case 'n':case'N':
					pos_next=castle->getroom(pos)->getroute('n');
					if(!pos_next){cout<<"���ϣ�ײǽ�ˡ���������������\n����������ԡ�";while(kbhit())getch();getch();break;}
					achi->getachv(0);
					if(!castle->check_room_status(pos_next)) {pos=pos_next; myhero->move(*castle,pos);break;}
					i=castle->check_mon(pos_next);
					cout<<"����Y�μ�ս��������������\n";
					while(kbhit())getch();j=getch();
					iscatch=false;
					if(j!='Y'&&j!='y')
					{//����
                    k=rand() % 6;
					if(k>2) {achi->getachv(10);break;}
					achi->getachv(11);
					iscatch=true;
					}
					//ս��
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
					//��Ѫ
					    k=rand() % 6;
						if(k) k+=myhero->getlev();
						cout<<"��ü�Ѫ\n";
						_sleep(1500);
						myhero->add_hp(k);
					}
					if(i==2)
					{
						//����
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
						cout<<"������Ѱ����������ȡ����Ϣ��\n";
						_sleep(1500);
						achi->getachv(5);
						if(!getprin)
						{
							achi->getachv(13);
							oss.clear();
						    oss.str("");
	                     	oss<<"�����ڵ�"<<castle->getprinroom()<<"�ŷ��䡣";
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
	                     	oss<<"��"<<k<<"�ŷ������ͨ�����ķ��䡣";
							info->add(oss.str());
							getpringo=true;
						}else
						{//¥��
							info->add(castle->getstair());
						}
					}
					myhero->move(*castle,pos_next);
					if(castle->check_room_status(pos_next)){find=true;achi->getachv(15);castle->findp();}
					pos=pos_next;
					break;
				case 's':case 'S':
					pos_next=castle->getroom(pos)->getroute('s');
					if(!pos_next){cout<<"���ϣ�ײǽ�ˡ���������������\n����������ԡ�";while(kbhit())getch();getch();break;}
					achi->getachv(0);
					if(!castle->check_room_status(pos_next)) {pos=pos_next; myhero->move(*castle,pos);break;}
					i=castle->check_mon(pos_next);
					cout<<"����Y�μ�ս��������������\n";
					while(kbhit())getch();j=getch();
					iscatch=false;
					if(j!='Y'&&j!='y')
					{
						//����
                    k=rand() % 6;
					if(k>1) {achi->getachv(10);break;}
					achi->getachv(11);
					iscatch=true;
					}
					//ս��
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
					//��Ѫ
					    k=rand() % 6;
						if(k) k+=myhero->getlev();
						cout<<"��ü�Ѫ\n";
						_sleep(1500);
						myhero->add_hp(k);
					}
					if(i==2)
					{
						//����
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
						cout<<"������Ѱ����������ȡ����Ϣ��\n";
						_sleep(1500);
						achi->getachv(5);
						if(!getprin)
						{
							achi->getachv(13);
							oss.clear();
						    oss.str("");
	                     	oss<<"�����ڵ�"<<castle->getprinroom()<<"�ŷ��䡣";
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
	                     	oss<<"��"<<k<<"�ŷ������ͨ�����ķ��䡣";
							info->add(oss.str());
							getpringo=true;
						}else
						{//¥��
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
					if(!pos_next){cout<<"���ϣ�ײǽ�ˡ���������������\n����������ԡ�";while(kbhit())getch();getch();break;}
					achi->getachv(0);
					if(!castle->check_room_status(pos_next)) {pos=pos_next; myhero->move(*castle,pos);break;}
					i=castle->check_mon(pos_next);
					cout<<"����Y�μ�ս��������������\n";
					while(kbhit())getch();j=getch();
					iscatch=false;
					if(j!='Y'&&j!='y')
					{//����
                    k=rand() % 6;
					if(k>1) {achi->getachv(10);break;}
					achi->getachv(11);
					iscatch=true;
					}
					//ս��
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
					//��Ѫ
					    k=rand() % 6;
						if(k) k+=myhero->getlev();
						cout<<"��ü�Ѫ\n";
						_sleep(1500);
						myhero->add_hp(k);
					}
					if(i==2)
					{
						//����
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
						cout<<"������Ѱ����������ȡ����Ϣ��\n";
						_sleep(1500);
						achi->getachv(5);
						if(!getprin)
						{
							achi->getachv(13);
							oss.clear();
						    oss.str("");
	                     	oss<<"�����ڵ�"<<castle->getprinroom()<<"�ŷ��䡣";
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
	                     	oss<<"��"<<k<<"�ŷ������ͨ�����ķ��䡣";
							info->add(oss.str());
							getpringo=true;
						}else
						{//¥��
							info->add(castle->getstair());
						}
					}
					myhero->move(*castle,pos_next);
					if(castle->check_room_status(pos_next)){find=true;achi->getachv(15);castle->findp();}
					pos=pos_next;
					break;
				case 'u':case'U':
					pos_next=castle->getroom(pos)->getroute('u');
					if(!pos_next){cout<<"���ϣ�ײǽ�ˡ���������������\n����������ԡ�";while(kbhit())getch();getch();break;}
					if(pos!=1) achi->getachv(16);
					achi->getachv(0);
					if(!castle->check_room_status(pos_next)) {pos=pos_next; myhero->move(*castle,pos);break;}
					i=castle->check_mon(pos_next);
					cout<<"����Y�μ�ս��������������\n";
					while(kbhit())getch();j=getch();
					iscatch=false;
					if(j!='Y'&&j!='y')
					{ //����
                    k=rand() % 6;
					if(k>1) {achi->getachv(10);break;}
					achi->getachv(11);
					iscatch=true;
					}
					//ս��
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
					//��Ѫ
					    k=rand() % 6;
						if(k) k+=myhero->getlev();
						cout<<"��ü�Ѫ\n";
						_sleep(1500);
						myhero->add_hp(k);
					}
					if(i==2)
					{
						//����
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
						cout<<"������Ѱ����������ȡ����Ϣ��\n";
						_sleep(1500);
						achi->getachv(5);
						if(!getprin)
						{
							achi->getachv(13);
							oss.clear();
						    oss.str("");
	                     	oss<<"�����ڵ�"<<castle->getprinroom()<<"�ŷ��䡣";
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
	                     	oss<<"��"<<k<<"�ŷ������ͨ�����ķ��䡣";
							info->add(oss.str());
							getpringo=true;
						}else
						{//¥��
							info->add(castle->getstair());
						}
					}
					myhero->move(*castle,pos_next);
					if(castle->check_room_status(pos_next)){find=true;achi->getachv(15);castle->findp();}
					pos=pos_next;
					break;
					}
					if(isbreak)//����ǿ��
					{cout<<"�ȴ�ϵͳ���õ�ͼ...���Ժ�";break;}
					if(succ)//����ʤ��
					{
						win(Msg,*achi);
						system("cls");
						cout<<"***********************\n"
							<<"��Ϸ�ɾ�ҳ��\n"
							<<"***********************\n";
						achi->listall();
						while(kbhit())getch();
						cout<<"***********************\n"
							<<"�������������Ϸ���˵���\n";
						getch();
						cout<<"�ȴ�ϵͳ���õ�ͼ...���Ժ�";
						break;
					}
					if(die)//��������
					{
						system("cls");
						cout<<"Ӣ����������Ϸʧ��\n��������鿴������Ϸ����ɾ͡�\n";
						while(kbhit())getch();getch();
						cout<<"***********************\n"
							<<"��Ϸ�ɾ�ҳ��\n"
							<<"***********************\n";
						achi->listall();
						while(kbhit())getch();
						cout<<"***********************\n"
							<<"�������������Ϸ���˵���\n";
						getch();
						cout<<"�ȴ�ϵͳ���õ�ͼ...���Ժ�";
						break;
					}
					system("cls");
					cout<<"Ӣ����Ϣ��\n";
					myhero->info();
					cout<<"**********************\nĿǰ���յ�EvilCastle��Ϣ��\n";
					info->listall();
					cout<<"**********************\n������Ϣ��\n";
					castle->roominfo(pos);
					cout<<"**********************\n�밴�¼����ϵ���ĸ������Ҫ̽���ķ���(E,W,N,S,U,D)\n";
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