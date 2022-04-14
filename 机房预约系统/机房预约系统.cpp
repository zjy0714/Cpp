#include<iostream>
#include<fstream>
#include<string>
#include"globalFile.h"
#include"identity.h"
#include"student.h"
#include"teacher.h"
#include"manager.h"
using namespace std;

//进入学生子菜单界面
void studentMenu(Identity*& student)
{
	while (true)
	{
		Student* stu = (Student*)student;
		//调用子菜单
		stu->openMenu();
		int select = 0;
		cin >> select;//接收用户选择
		if (select == 1)//申请预约
		{
			stu->applyOrder();
		}
		else if (select == 2)//查看自身预约
		{
			stu->showMyOrder();
		}
		else if (select == 3)//查看所有预约
		{
			stu->showAllOrder();
		}
		else if (select == 4)//取消预约
		{
			stu->cancelOrder();
		}
		else//注销登录
		{
			delete student;
			cout << "注销成功" << endl;
			system("pause");
			system("cls");
			return;
		}
	}
}
//进入管理员子菜单界面
void managerMenu(Identity*& manager)
{
	while (true)
	{
		//将Identity类型转为manager类型
		Manager* man = (Manager*)manager;
		//调用子菜单界面
		man->openMenu();
		int select = 0;
		//接收用户选择
		cin >> select;
		if (select == 1)//添加账号
		{
			man->addPerson();
		}
		else if (select == 2)//查看账号
		{
			man->showPerson();
		}
		else if (select == 3)//查看机房
		{
			man->showComputer();
		}
		else if (select == 4)//清空预约
		{
			man->clearFile();
		}
		else
		{
			delete manager;//释放堆区对象
			cout << "注销成功" << endl;
			system("pause");
			system("cls");
			return;
		}
	}
}
//登录功能
void LoginIn(string filename, int type)
{
	Identity* person = NULL;//指向子类对象
	//读文件
	ifstream ifs;
	ifs.open(filename, ios::in);
	//判断文件是否存在
	if (!ifs.is_open())
	{
		cout << "文件不存在" << endl;
		ifs.close();
		return;
	}
	//准备接收用户的信息
	int id = 0;
	string name;
	string password;
	//判断身份
	if (type == 1)//学生
	{
		cout << "请输入您的学号:  " << endl;
		cin >> id;
	}
	else if (type == 2)//老师
	{
		cout << "请输入您的职工号" << endl;
		cin >> id;
	}
	cout << "请输入用户名:  " << endl;
	cin >> name;
	cout << "请输入密码:  " << endl;
	cin >> password;
	if (type == 1)
	{
		//学生身份验证
		int fId;//从文件中获取的id
		string fName;//从文件中获取的姓名
		string fPassword;//从文件中获取的密码
		while (ifs >> fId && ifs >> fName && ifs >> fPassword)
		{
			if (fId == id && fName == name && fPassword == password)
			{
				cout << "学生验证登录成功" << endl;
				system("pause");
				system("cls");
				person = new Student(id, name, password);
				//进入学生身份子菜单
				studentMenu(person);
				return;
			}
		}
	}
	else if (type == 2)
	{
		//教师身份验证
		int fId;//从文件中获取的id
		string fName;//从文件中获取的姓名
		string fPassword;//从文件中获取的密码
		while (ifs >> fId && ifs >> fName && ifs >> fPassword)
		{
			if (fId == id && fName == name && fPassword == password)
			{
				cout << "教师验证登录成功" << endl;
				system("pause");
				system("cls");
				person = new Teacher(id, name, password);
				//进入教师身份子菜单

				return;
			}
		}
	}
	else if (type == 3)
	{
		//管理员身份验证
		string fName;//从文件中获取的姓名
		string fPassword;//从文件中获取的密码
		while (ifs >> fName && ifs >> fPassword)
		{
			if (fName == name && fPassword == password)
			{
				cout << "管理员验证登录成功" << endl;
				system("pause");
				system("cls");
				person = new Manager(name, password);
				//进入管理员身份子菜单
				managerMenu(person);
				return;
			}
		}
	}
		cout << "验证登录失败" << endl;
		system("pause");
		system("cls");
}
int main()
{
	int select;//接收用户的选择
	while (true)
	{
		cout << "---------欢迎使用机房预约系统-----------" << endl;
		cout << endl << "请输入您的身份:  " << endl;
		cout << "------1、学生代表--------" << endl;
		cout << "------2、  老师  --------" << endl;
		cout << "------3、 管理员 --------" << endl;
		cout << "------0、  退出  --------" << endl;
		cout << "请输入您的选择:  " << endl;
		cin >> select;//用户选择
		switch (select)
		{
		case 1: //学生
			LoginIn(STUDENT_FILE, 1);
			break;
		case 2: //老师
			LoginIn(TEACHER_FILE, 2);
			break;
		case 3: //管理员
			LoginIn(ADMIN_FILE, 3);
			break;
		case 0: //退出系统
			cout << "欢迎下次使用" << endl;
			system("pause");
			return 0;
			break;
		default:
			cout << "输入错误，请重新选择" << endl;
			system("pause");
			system("cls");
			break;
		}
	}

	system("pause");
	return 0;
}