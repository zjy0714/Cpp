#pragma once
#include<iostream>
#include<fstream>
#include<vector>
#include<algorithm>
#include"globalFile.h"
#include"identity.h"
#include"student.h"
#include"teacher.h"
#include"computerRoom.h"
using namespace std;

class Manager : public Identity
{
public:
	//默认构造
	Manager();
	//有参构造
	Manager(string name, string password);
	//菜单界面
	void openMenu();
	//添加账号
	void addPerson();
	//查看账号
	void showPerson();
	//查看机房信息
	void showComputer();
	//清空预约记录
	void clearFile();
	//初始化容器
	void initVector();
	//检测重复 参数:(传入id，类型)返回值:(true代表有重复，false代表无重复)
	bool checkRepeat(int id, int type);
	//学生容器
	vector<Student> vStu;
	//教师容器
	vector<Teacher> vTea;
	//机房信息容器
	vector<ComputerRoom> vCom;
};