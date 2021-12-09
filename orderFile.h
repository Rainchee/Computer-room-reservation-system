#pragma once
#include<iostream>
using namespace std;
#include"globalFile.h"
#include<fstream>
#include<map>
class OrderFile
{
public:
	//构造函数
	OrderFile();
	//更新预约
	void updateOrder();
	//记录预约
	int m_Size;
	//记录所以预约信息的容器
	map<int, map<string, string>>m_orderData;
};