#include<iostream>
#include<fstream>
#include<string>
#include"globalFile.h"
#include"identity.h"
#include"student.h"
#include"teacher.h"
#include"manager.h"
using namespace std;

//����ѧ���Ӳ˵�����
void studentMenu(Identity*& student)
{
	while (true)
	{
		Student* stu = (Student*)student;
		//�����Ӳ˵�
		stu->openMenu();
		int select = 0;
		cin >> select;//�����û�ѡ��
		if (select == 1)//����ԤԼ
		{
			stu->applyOrder();
		}
		else if (select == 2)//�鿴����ԤԼ
		{
			stu->showMyOrder();
		}
		else if (select == 3)//�鿴����ԤԼ
		{
			stu->showAllOrder();
		}
		else if (select == 4)//ȡ��ԤԼ
		{
			stu->cancelOrder();
		}
		else//ע����¼
		{
			delete student;
			cout << "ע���ɹ�" << endl;
			system("pause");
			system("cls");
			return;
		}
	}
}
//�������Ա�Ӳ˵�����
void managerMenu(Identity*& manager)
{
	while (true)
	{
		//��Identity����תΪmanager����
		Manager* man = (Manager*)manager;
		//�����Ӳ˵�����
		man->openMenu();
		int select = 0;
		//�����û�ѡ��
		cin >> select;
		if (select == 1)//����˺�
		{
			man->addPerson();
		}
		else if (select == 2)//�鿴�˺�
		{
			man->showPerson();
		}
		else if (select == 3)//�鿴����
		{
			man->showComputer();
		}
		else if (select == 4)//���ԤԼ
		{
			man->clearFile();
		}
		else
		{
			delete manager;//�ͷŶ�������
			cout << "ע���ɹ�" << endl;
			system("pause");
			system("cls");
			return;
		}
	}
}
//��¼����
void LoginIn(string filename, int type)
{
	Identity* person = NULL;//ָ���������
	//���ļ�
	ifstream ifs;
	ifs.open(filename, ios::in);
	//�ж��ļ��Ƿ����
	if (!ifs.is_open())
	{
		cout << "�ļ�������" << endl;
		ifs.close();
		return;
	}
	//׼�������û�����Ϣ
	int id = 0;
	string name;
	string password;
	//�ж����
	if (type == 1)//ѧ��
	{
		cout << "����������ѧ��:  " << endl;
		cin >> id;
	}
	else if (type == 2)//��ʦ
	{
		cout << "����������ְ����" << endl;
		cin >> id;
	}
	cout << "�������û���:  " << endl;
	cin >> name;
	cout << "����������:  " << endl;
	cin >> password;
	if (type == 1)
	{
		//ѧ�������֤
		int fId;//���ļ��л�ȡ��id
		string fName;//���ļ��л�ȡ������
		string fPassword;//���ļ��л�ȡ������
		while (ifs >> fId && ifs >> fName && ifs >> fPassword)
		{
			if (fId == id && fName == name && fPassword == password)
			{
				cout << "ѧ����֤��¼�ɹ�" << endl;
				system("pause");
				system("cls");
				person = new Student(id, name, password);
				//����ѧ������Ӳ˵�
				studentMenu(person);
				return;
			}
		}
	}
	else if (type == 2)
	{
		//��ʦ�����֤
		int fId;//���ļ��л�ȡ��id
		string fName;//���ļ��л�ȡ������
		string fPassword;//���ļ��л�ȡ������
		while (ifs >> fId && ifs >> fName && ifs >> fPassword)
		{
			if (fId == id && fName == name && fPassword == password)
			{
				cout << "��ʦ��֤��¼�ɹ�" << endl;
				system("pause");
				system("cls");
				person = new Teacher(id, name, password);
				//�����ʦ����Ӳ˵�

				return;
			}
		}
	}
	else if (type == 3)
	{
		//����Ա�����֤
		string fName;//���ļ��л�ȡ������
		string fPassword;//���ļ��л�ȡ������
		while (ifs >> fName && ifs >> fPassword)
		{
			if (fName == name && fPassword == password)
			{
				cout << "����Ա��֤��¼�ɹ�" << endl;
				system("pause");
				system("cls");
				person = new Manager(name, password);
				//�������Ա����Ӳ˵�
				managerMenu(person);
				return;
			}
		}
	}
		cout << "��֤��¼ʧ��" << endl;
		system("pause");
		system("cls");
}
int main()
{
	int select;//�����û���ѡ��
	while (true)
	{
		cout << "---------��ӭʹ�û���ԤԼϵͳ-----------" << endl;
		cout << endl << "�������������:  " << endl;
		cout << "------1��ѧ������--------" << endl;
		cout << "------2��  ��ʦ  --------" << endl;
		cout << "------3�� ����Ա --------" << endl;
		cout << "------0��  �˳�  --------" << endl;
		cout << "����������ѡ��:  " << endl;
		cin >> select;//�û�ѡ��
		switch (select)
		{
		case 1: //ѧ��
			LoginIn(STUDENT_FILE, 1);
			break;
		case 2: //��ʦ
			LoginIn(TEACHER_FILE, 2);
			break;
		case 3: //����Ա
			LoginIn(ADMIN_FILE, 3);
			break;
		case 0: //�˳�ϵͳ
			cout << "��ӭ�´�ʹ��" << endl;
			system("pause");
			return 0;
			break;
		default:
			cout << "�������������ѡ��" << endl;
			system("pause");
			system("cls");
			break;
		}
	}

	system("pause");
	return 0;
}