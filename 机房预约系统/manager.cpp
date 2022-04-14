#include"manager.h"

//Ĭ�Ϲ���
Manager::Manager()
{

}
//�вι���
Manager::Manager(string name, string password)
{
	//��ʼ������Ա��Ϣ
	this->m_Name = name;
	this->m_Password = password;
	//��ʼ������ ��ȡ���ļ���ѧ���ͽ�ʦ��Ϣ
	this->initVector();
	//��ʼ��������Ϣ
	vCom.clear();
	ifstream ifs;
	ifs.open(COMPUTER_FILE, ios::in);
	ComputerRoom c;
	while (ifs >> c.m_ComId && ifs >> c.m_MaxNum)
	{
		vCom.push_back(c);
	}
	ifs.close();
}
//�˵�����
void Manager::openMenu()
{
	cout << "��ӭ����Ա:  " << this->m_Name << "��¼" << endl;
	cout << "---1������˺�---" << endl;
	cout << "---2���鿴�˺�---" << endl;
	cout << "---3���鿴����---" << endl;
	cout << "---4�����ԤԼ---" << endl;
	cout << "---0��ע����¼---" << endl;
	cout << "��ѡ�����Ĳ���:  " << endl;
}
//����˺�
void Manager::addPerson()
{
	cout << "����������˺ŵ�����: " << endl;
	cout << "1�����ѧ��" << endl;
	cout << "2����ӽ�ʦ" << endl;
	string filename;
	string tip;//��ʾid��
	string errorTip;//�ظ�������ʾ
	ofstream ofs;
	int select = 0;
	cin >> select;
	if (select == 1)//���ѧ��
	{
		filename = STUDENT_FILE;
		tip = "������ѧ��: ";
		errorTip = "ѧ���ظ�,����������";
	}
	else//�����ʦ
	{
		filename = TEACHER_FILE;
		tip = "������ְ����: ";
		errorTip = "ְ�����ظ�,����������";
	}
	ofs.open(filename, ios::out | ios::app);
	int id;
	string name;
	string password;
	cout << tip << endl;
	while (true)
	{
		cin >> id;
		bool ret = this->checkRepeat(id,select);
		if (ret)//���ظ�
		{
			cout << errorTip << endl;
		}
		else
		{
			break;
		}
	}
	cout << "������������" << endl;
	cin >> name;
	cout << "���������룺" << endl;
	cin >> password;
	//���ļ����������
	ofs << id << " " << name << " " << password << " " << endl;
	cout << "��ӳɹ�" << endl;
	system("pause");
	system("cls");
	ofs.close();
	//���ó�ʼ�������ӿڣ����»�ȡ�ļ��е�����
	this->initVector();
}
void printStudent(Student& s)
{
	cout << "ѧ��:  " << s.m_Id << "����:  " << s.m_Name << "����:  " << s.m_Password << endl;
}
void printTeacher(Teacher& t)
{
	cout << "ְ����:  " << t.m_EmpId << "����:  " << t.m_Name << "����:  " << t.m_Password << endl;
}
//�鿴�˺�
void Manager::showPerson()
{
	cout << "��ѡ��鿴����:  " << endl;
	cout << "1���鿴����ѧ��" << endl;
	cout << "2���鿴������ʦ" << endl;
	int select = 0;//�����û�ѡ��
	cin >> select;
	if (select == 1)
	{
		//�鿴ѧ��
		cout << "����ѧ����Ϣ����:  " << endl;
		for_each(vStu.begin(), vStu.end(), printStudent);
	}
	else
	{
		//�鿴��ʦ
		cout << "������ʦ��Ϣ����:  " << endl;
		for_each(vTea.begin(), vTea.end(), printTeacher);
	}
	system("pause");
	system("cls");
}
//�鿴������Ϣ
void Manager::showComputer()
{
	cout << "��������Ϣ����" << endl;
	for (vector<ComputerRoom>::iterator it = vCom.begin(); it != vCom.end(); it++)
	{
		cout << "�������: " << it->m_ComId << "�����������: " << it->m_MaxNum << endl;
	}
	system("pause");
	system("cls");
}
//���ԤԼ��¼
void Manager::clearFile()
{
	ofstream ofs;
	ofs.open(ORDER_FILE, ios::trunc);
	ofs.close();
	cout << "��ճɹ�" << endl;
	system("pause");
	system("cls");
}
//��ʼ������
void Manager::initVector()
{
	//ȷ���������
	vStu.clear();
	vTea.clear();
	//��ȡ��Ϣ
	ifstream ifs;
	//ѧ��
	ifs.open(STUDENT_FILE, ios::in);
	if (!ifs.is_open())
	{
		cout << "�ļ���ȡʧ��" << endl;
		return;
	}
	Student s;
	while (ifs >> s.m_Id && ifs >> s.m_Name && ifs >> s.m_Password)
	{
		vStu.push_back(s);
	}
	//cout << "��ǰѧ������Ϊ:  " << vStu.size() << endl;
	ifs.close();
	//��ʦ
	ifs.open(TEACHER_FILE, ios::in);
	if (!ifs.is_open())
	{
		cout << "�ļ���ȡʧ��" << endl;
		return;
	}
	Teacher t;
	while (ifs >> t.m_EmpId && ifs >> t.m_Name && ifs >> t.m_Password)
	{
		vTea.push_back(t);
	}
	//cout << "��ǰ��ʦ����Ϊ:  " << vTea.size() << endl;
	ifs.close();
}
//����ظ� ����:(����id������)����ֵ:(true�������ظ���false�������ظ�)
bool Manager::checkRepeat(int id, int type)
{
	if (type == 1)
	{
		//���ѧ��
		for (vector<Student>::iterator it = vStu.begin(); it != vStu.end(); it++)
		{
			if (id == it->m_Id)
			{
				return true;
			}
		}
	}
	else
	{
		//����ʦ
		for (vector<Teacher>::iterator it = vTea.begin(); it != vTea.end(); it++)
		{
			if (id == it->m_EmpId)
			{
				return true;
			}
		}
	}
}