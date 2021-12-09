#pragma once
#include<iostream>
using namespace std;
#include"identity.h"
#include<iostream>
#include<string>
#include<vector>
#include"computerRoom.h"
#include<fstream>
#include"globalFile.h"
#include"orderFile.h"
//教师类设计
class Teacher :public Identity
{
public:
	//默认构造
	Teacher();
	//有参构造
	Teacher(int empId, string name, string pwd);
	//菜单界面
	virtual void operMenu();
	//查看所有预约
	void showAllOrder();
	//审核预约
	void validOrder();
	//职工号
	int m_EmpId;
};
