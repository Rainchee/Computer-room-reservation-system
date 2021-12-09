#pragma once
#include<iostream>
using namespace std;
#include"identity.h"
#include"globalFile.h"
#include<string>
#include<fstream>
#include<vector>
#include"student.h"
#include"teacher.h"
#include<algorithm>
#include"computerRoom.h"
class Manager :public Identity
{
public:
	//Ĭ�Ϲ���
	Manager();
	//�вι���
	Manager(string name, string pwd);
	//�˵�����
	virtual void operMenu();
    //�����˺�
	void addPerson();
	//�鿴�˺�
	void showPerson();
	//�鿴������Ϣ
	void showComputer();
	//���ԤԼ��¼
	void cleanFile();
	//��ʼ������
	void initVector();
	//ѧ������
	vector<Student>vStu;
	//��ʦ����
	vector<Teacher>vTea;
	//����ظ�
	bool checkRepeat(int id, int type);
	//������Ϣ
	vector<ComputerRoom>vCom;
};