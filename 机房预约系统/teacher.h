#pragma once
#include<iostream>
#include"identity.h"
using namespace std;

class Teacher : public Identity
{
public:
	//Ĭ�Ϲ���
	Teacher();
	//�вι���
	Teacher(int empId, string name, string password);
	//�˵�����
	void openMenu();
	//�鿴����ԤԼ
	void showAllOrder();
	//���ԤԼ
	void validOrder();
	//ְ����
	int m_EmpId;
};