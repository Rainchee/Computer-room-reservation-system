#pragma once
#include<iostream>
#include"identity.h"
#include<string>
#include<vector>
#include"computerRoom.h"
#include<fstream>
#include"globalFile.h"
#include"orderFile.h"
using namespace std;
//ѧ����
class Student  :  public Identity
{
public:
	//Ĭ�Ϲ���
	Student();	
	//�вι���
	Student(int id, string name, string pwd);
	//�˵�����
     virtual void operMenu();
	//����ԤԼ
	void applyOrder();
	//�鿴����ԤԼ
	void showOrder();
	//�鿴����ԤԼ
	void showAllOrder();
	//ȡ��ԤԼ
	void cancelOrder();
	//ѧ��ѧ��
	int m_id;
	vector<ComputerRoom> vCom;
};
