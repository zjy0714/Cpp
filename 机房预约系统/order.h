#pragma once
#include<iostream>
#include<map>
#include<fstream>
#include"globalFile.h"
using namespace std;

class OrderFile
{
public:
	//���캯��
	OrderFile();
	//����ԤԼ��¼
	void updateOrder();
	//��¼ԤԼ����
	int m_Size;
	//��¼����ԤԼ��Ϣ������
	map<int, map<string, string>> m_OrderData;
};