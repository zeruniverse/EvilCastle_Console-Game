#include <iostream>
#include<string.h>
#include<stdio.h>
#include<conio.h>
#include "message.h"
#include <stdlib.h>
using namespace std;
void message::print(char *a) const
{
	int i,len;
	len=strlen(a);
	for(i=0;i<len;i++){printf("%c",a[i]);_sleep(60);}
}
void message::hint() const
{
	system("cls");
	cout<<"************************************************************************\n"
		<<"                           ��ӭ����EvilCastle V1.6  \n"
		<<"                          PROGRAMMED BY ZEYU, ZHAO  \n\n\n"
		<<"                         ������Ϸ�Ѷȣ�0-6����ʼ��Ϸ\n"
		<<"�Ѷ�:  0--��ѧ�ߣ�1--�򵥣�2--�еȣ�3--���ѣ�4--���֣�5--ר�ң�6--��ս��\n"
		<<"                           ��������'h'-��ʾ��Ϸ����\n"
		<<"                            ��������'q'-�˳���Ϸ \n"
		<<"                          (��Ϸ������������ִ�Сд)\n"
		<<"************************************************************************\n";

}
void message::welcome() const
{
	system("cls");
	print("�ܾ���ǰ����һλ������һȺMonster����ˡ�\nMonster�ľۼ������������ס����Զ��EvilCastle��\n");
	print("������ļ�˺ܶ���ʿȥEvilCastle���ȹ�������û��һ�����ܹ�������\n�ͽ�Խ��Խ�ߣ�����Ը��ȥEvilCastle����Խ��Խ�١�\n");
	print("......\n��ʱ����һλ��ʿ�����ˡ�\n");
	print("������һ��ȥ��EvilCastle��\n���¾ʹ����￪ʼ��......\n");
	cout<<"�����������\n";
	while(kbhit())getch();
	getch();
}
void message::help() const
{
	system("cls");
    cout<<"��Ϸ��Ӣ�۽�̽��EvilCastle�ķ��䡣ÿ����һ��������ж�Ӧ��ʾ��\n"
		<<"���ݷ���ӵ�еĳ��ڿ���ѡ��һ��ͨ���������䡣\n"
		<<"��̽���У���Ļ�Ϸ�����ʾӢ�۵���Ϣ��\n"
		<<"�벻Ҫ������¥��¥��Խ�߹���ȼ�Խ�ߡ�\n"
		<<"��ɱ���������Ի�þ��鲢��һ�����ʻ����Ϣ����ߡ�\n"
		<<"��Ϸ�����л����������óɾ�Ŷ�������õ����гɾͰɡ�\n"
		<<"��ʾ����Ϸ�е�������ִ�Сд\n"
		<<"����̽����^_^\n"
		<<"*************************\n�����������\n";
	getch();
}