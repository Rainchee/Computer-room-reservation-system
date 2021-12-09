#include<iostream>
using namespace std;
#include "identity.h"
#include<fstream>
#include<string>
#include"globalFile.h"
#include"student.h"
#include"manager.h"
#include"teacher.h"
//进入学生子菜单界面
void studentMenu(Identity*& student)
{
	while (true)
	{
		//调用子菜单
		student->operMenu();
		Student* stu = (Student*)student;
		int select = 0;
		cin >> select;
		if (select == 1)//申请预约
		{
			stu->applyOrder();
		}
		else if (select == 2)//查看自身预约
		{
			stu->showOrder();
		}
		else if (select == 3)//查看所有人预约
		{
			stu->showAllOrder();
		}
		else if (select == 4)//取消预约
		{
			stu->cancelOrder();
		}
		else//注销
		{
			delete student;
			cout << "注销成功" << endl;
			system("pause");
			system("cls");
			return;
		}
	}
}
//进入教师子菜单界面
void teacherMenu(Identity*& teacher)
{
	while (true)
	{
		//调用子菜单界面
		teacher->operMenu();
		Teacher* tea = (Teacher*)teacher;
		int select = 0;//接受用户选择
		cin >> select;
		if (select == 1)//查看所以预约
		{
			tea->showAllOrder();
		}
		else if (select == 2)//审核预约
		{
			tea->validOrder();
		}
		else
		{
			delete teacher;
			cout << "注销成功" << endl;
			system("pause");
			system("cls");
			return;
		}
	}
}
//进入管理员子菜单
void managerMenu(Identity*& manager)
{
	while (true)
	{
		//调用管理员子菜单
		manager->operMenu();
		//将父类指针，转为子类指针，调用子类其他接口
		Manager* man = (Manager*)manager;
		int select = 0;
		//接收用户选项
		cin >> select;
		if (select == 1)//添加账号
		{
			cout << "添加账号" << endl;
			man->addPerson();
		}
		else if (select == 2)//查看账号
		{
			cout << "查看账号" << endl;
			man->showPerson();
		}
		else if (select == 3)//查看机房
		{
			cout << "查看机房" << endl;
			man->showComputer();
		}
		else if (select == 4)//清空预约
		{
			cout << "清空预约" << endl;
			man->cleanFile();
		}
		else
		{
			delete manager;//销毁堆区对象
			cout << "注销成功" << endl;
			system("pause");
			system("cls");
			return;
		}
	}
}
//登录功能 操作文件名  操作身份名类型
void LoginIn(string fileName, int type)
{
	//父类指针，指向子类
	Identity* person = NULL;
	//读文件
	ifstream ifs;
	ifs.open(fileName,ios::in);
	//判断文件是否存在
	if (!ifs.is_open())
	{
		cout << "文件不存在" << endl;
		ifs.close();
		return;
	}

	//准备接受用户信息
	int id = 0;
	string name;
	string pwd;

	//判断身份
	if (type == 1)//学生
	{
		cout << "请输入你的学号：" << endl;
		cin >> id;
	}
	else if (type == 2)//老师
	{
		cout << "请输入您的职工号：" << endl;
		cin >> id;
	}
	cout << "请输入用户名：" << endl;
	cin >> name;
	cout << "请输入密码：" << endl;
	cin >> pwd;
	//身份验证
	if (type == 1)
	{
		int fId;//从文件读取的id号
		string fName;//文件姓名
		string fPwd;//文件中获取密码
		while (ifs >> fId && ifs >> fName && ifs >> fPwd)
		{
			if (fId == id && fName == name && fPwd == pwd)
			{
				cout << "学生验证登录成功！" << endl;
				system("pause");
				system("cls");
				person = new Student(id,name,pwd);
				//进入学生身份子菜单
				studentMenu(person);

				return;
			}
		}
	}
	else if (type == 2)
	{
		int fId;//从文件读取的id号
		string fName;//文件姓名
		string fPwd;//文件中获取密码
		while (ifs >> fId && ifs >> fName && ifs >> fPwd)
		{
			if (fId == id && fName == name && fPwd == pwd)
			{
				cout << "教师验证登录成功！" << endl;
				system("pause");
				system("cls");
				person = new Teacher(id, name, pwd);
				//进入老师身份子菜单
				teacherMenu(person);

				return;
			}
		}
	}
	else if (type == 3)
	{
		string fName;//文件姓名
		string fPwd;//文件中获取密码
		while ( ifs >> fName && ifs >> fPwd)
		{
			if ( fName == name && fPwd == pwd)
			{
				cout << "管理员验证登录成功！" << endl;
				system("pause");
				system("cls");
				person = new Manager(name, pwd);
				//进入管理员身份子菜单
				managerMenu(person);
				return;
			}
		}
	}
	cout << "验证登陆失败！" << endl;
	system("pause");
	system("cls");
	return;
}

int main()
{
	int select = 0;
	while(true)
	{
		cout << "====================欢迎来到传智博客机房预约系统====================" << endl;
		cout << endl << "请输入您的身份" << endl;
		cout << "\t\t--------------------------------------------------\n";
		cout << "\t\t|                                                |\n";
		cout << "\t\t|                  1.学生代表                    |\n";
		cout << "\t\t|                                                |\n";
		cout << "\t\t|                  2.老师                        |\n";
		cout << "\t\t|                                                |\n";
		cout << "\t\t|                  3.管理员                      |\n";
		cout << "\t\t|                                                |\n";
		cout << "\t\t|                  0.退出                        |\n";
		cout << "\t\t|                                                |\n";
		cout << "\t\t--------------------------------------------------\n";
		cout << "请输入您的选择：";
		cin >> select;
		switch (select)
		{
		case 1:
			LoginIn(STUDENT_FILE, 1);
			break;
		case 2:
			LoginIn(TEACHER_FILE, 2);
			break;
		case 3:
			LoginIn(ADMIN_FILE, 3);
			break;
		case 0:
			cout << "欢迎下一次使用：" << endl;
			system("pause");
			return 0;
			break;
		default:
			cout << "输入有误，请重新选择！" << endl;
			system("pause");
			system("cls");
		}
	}
	system("pause");
	return 0;
}