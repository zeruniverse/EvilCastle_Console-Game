#include<iostream>
#include"achievement.h"
achievement::achievement()
	{
		this->achieve.clear();
		for(int i=0; i<20;i++) goten[i]=false;
	}
void achievement::listall()
	{
	cout<<"������Ϸ����ɾͣ������ʱ�����򣩣�\n";
	for(vector<string>::iterator ite=this->achieve.begin(); ite!=this->achieve.end();ite++)//ѭ��������м�¼
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
		 case 0: this->achieve.push_back("������һ��������ʼ��Ϸ��̽��һ������"); cout<<"��óɾͣ�������һ��\n";_sleep(1500);return ;
		 case 1: this->achieve.push_back("��ܹ������ܵ�һ������");cout<<"��óɾͣ���ܹ���\n";_sleep(1500); return;
	     case 2: this->achieve.push_back("�������������õ�һ������"); cout<<"��óɾͣ��������\n";_sleep(1500);return;
	     case 3: this->achieve.push_back("��÷��ߡ�����õ�һ������"); cout<<"��óɾͣ���÷���\n";_sleep(1500);return;
	     case 4: this->achieve.push_back("���Ь�ӡ�����õ�һ��Ь��");cout<<"��óɾͣ����Ь��\n";_sleep(1500); return;
	     case 5: this->achieve.push_back("ȡ����Ϣ����ȡ�õ�һ����Ϣ"); cout<<"��óɾͣ�ȡ����Ϣ\n";_sleep(1500);return;
	     case 6: this->achieve.push_back("��������һ�����¡����ۿ���һ��ս����ȡ��ʤ��");cout<<"��óɾͣ���������һ������\n";_sleep(1500); return ;
	     case 7: this->achieve.push_back("����������õ�һ������");cout<< "��óɾͣ�����\n";_sleep(1500); return;
		 case 8: this->achieve.push_back("���Ѳ�������Ӯ��ս��ʱHP<=2");cout<< "��óɾͣ����Ѳ���\n";_sleep(1500); return;
	     case 9: this->achieve.push_back("�����þ������ɹ���ô������"); cout<<"��óɾͣ������þ�\n";_sleep(1500); return;
	     case 10: this->achieve.push_back("��ÿ졪���ɹ�����"); cout<< "��óɾͣ���ÿ�\n";_sleep(1500);return;
	     case 11: this->achieve.push_back("���ⶾ�֡�������ʧ�ܣ�����ս��");cout<< "��óɾͣ����ⶾ��\n";_sleep(1500); return;
	     case 12: this->achieve.push_back("��;֪������δ�ҵ��������ص�һ�㣨��ʼ�ĵط���"); cout<<"��óɾͣ���;֪��\n";_sleep(1500); return;
	     case 13: this->achieve.push_back("�������������֪������λ��"); cout<<"��óɾͣ�����������\n";_sleep(1500);return ;
		 case 14: this->achieve.push_back("С��һ����������ʧHP��ܹ���");cout<<"��óɾͣ�С��һ��\n";_sleep(1500); return ;
		 case 15: this->achieve.push_back("�������͡����ҵ�����");cout<< "��óɾͣ��������ͣ��ڷ����ڷ��ֹ�������\n";_sleep(1500); return;
	     case 16: this->achieve.push_back("����������һ���϶�¥����");cout<< "��óɾͣ�����\n";_sleep(1500); return;
	     case 17: this->achieve.push_back("һ�߹����������ͨ�������ڵص���Ϣ");cout<<"��óɾͣ�һ�߹���\n"; _sleep(1500);return ;
	     case 18: this->achieve.push_back("�׷桪���ܾ������Ľ���"); cout<<"��óɾͣ��׷�\n";_sleep(1500);return ;
	     case 19: this->achieve.push_back("ȡ�ûر��������ܹ����Ľ���");cout<< "��óɾͣ�ȡ�ûر�\n";_sleep(1500); return;
		default: return;
		}
	}
achievement::~achievement()	
	{
		this->achieve.clear();
	    vector<string>().swap(this->achieve);
	}