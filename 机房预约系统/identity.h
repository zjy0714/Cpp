#pragma once
#include<iostream>
#include<string>
using namespace std;

//��ݳ�����
class Identity
{
public:
	//�����˵�
	virtual void openMenu() = 0;

	//�û���
	string m_Name;
	//����
	string m_Password;
};