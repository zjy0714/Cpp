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
	//Ĭ�Ϲ���
	Manager();
	//�вι���
	Manager(string name, string password);
	//�˵�����
	void openMenu();
	//����˺�
	void addPerson();
	//�鿴�˺�
	void showPerson();
	//�鿴������Ϣ
	void showComputer();
	//���ԤԼ��¼
	void clearFile();
	//��ʼ������
	void initVector();
	//����ظ� ����:(����id������)����ֵ:(true�������ظ���false�������ظ�)
	bool checkRepeat(int id, int type);
	//ѧ������
	vector<Student> vStu;
	//��ʦ����
	vector<Teacher> vTea;
	//������Ϣ����
	vector<ComputerRoom> vCom;
};