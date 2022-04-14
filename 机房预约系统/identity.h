#pragma once
#include<iostream>
#include<string>
using namespace std;

//身份抽象类
class Identity
{
public:
	//操作菜单
	virtual void openMenu() = 0;

	//用户名
	string m_Name;
	//密码
	string m_Password;
};