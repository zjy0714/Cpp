#pragma once
#include<iostream>
#include<vector>
#include<fstream>
#include"identity.h"
#include"computerRoom.h"
#include"globalFile.h"
#include"order.h"
using namespace std;

//ѧ����
class Student : public Identity
{
public:
	//Ĭ�Ϲ���
	Student();
	//�вι���
	Student(int id, string name, string password);
	//�˵�����
	void openMenu();
	//����ԤԼ
	void applyOrder();
	// �鿴����ԤԼ
	void showMyOrder();
	// �鿴����ԤԼ
	void showAllOrder();
	// ȡ��ԤԼ
	void cancelOrder();
	//ѧ��ѧ��
	int m_Id;
	//��������
	vector<ComputerRoom> vCom;
};