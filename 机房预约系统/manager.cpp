#include"manager.h"

//默认构造
Manager::Manager()
{

}
//有参构造
Manager::Manager(string name, string password)
{
	//初始化管理员信息
	this->m_Name = name;
	this->m_Password = password;
	//初始化容器 获取到文件中学生和教师信息
	this->initVector();
	//初始化机房信息
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
//菜单界面
void Manager::openMenu()
{
	cout << "欢迎管理员:  " << this->m_Name << "登录" << endl;
	cout << "---1、添加账号---" << endl;
	cout << "---2、查看账号---" << endl;
	cout << "---3、查看机房---" << endl;
	cout << "---4、清空预约---" << endl;
	cout << "---0、注销登录---" << endl;
	cout << "请选择您的操作:  " << endl;
}
//添加账号
void Manager::addPerson()
{
	cout << "请输入添加账号的类型: " << endl;
	cout << "1、添加学生" << endl;
	cout << "2、添加教师" << endl;
	string filename;
	string tip;//提示id号
	string errorTip;//重复错误提示
	ofstream ofs;
	int select = 0;
	cin >> select;
	if (select == 1)//添加学生
	{
		filename = STUDENT_FILE;
		tip = "请输入学号: ";
		errorTip = "学号重复,请重新输入";
	}
	else//添加老师
	{
		filename = TEACHER_FILE;
		tip = "请输入职工号: ";
		errorTip = "职工号重复,请重新输入";
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
		if (ret)//有重复
		{
			cout << errorTip << endl;
		}
		else
		{
			break;
		}
	}
	cout << "请输入姓名：" << endl;
	cin >> name;
	cout << "请输入密码：" << endl;
	cin >> password;
	//向文件中添加数据
	ofs << id << " " << name << " " << password << " " << endl;
	cout << "添加成功" << endl;
	system("pause");
	system("cls");
	ofs.close();
	//调用初始化容器接口，重新获取文件中的数据
	this->initVector();
}
void printStudent(Student& s)
{
	cout << "学号:  " << s.m_Id << "姓名:  " << s.m_Name << "密码:  " << s.m_Password << endl;
}
void printTeacher(Teacher& t)
{
	cout << "职工号:  " << t.m_EmpId << "姓名:  " << t.m_Name << "密码:  " << t.m_Password << endl;
}
//查看账号
void Manager::showPerson()
{
	cout << "请选择查看内容:  " << endl;
	cout << "1、查看所有学生" << endl;
	cout << "2、查看所有老师" << endl;
	int select = 0;//接收用户选择
	cin >> select;
	if (select == 1)
	{
		//查看学生
		cout << "所有学生信息如下:  " << endl;
		for_each(vStu.begin(), vStu.end(), printStudent);
	}
	else
	{
		//查看老师
		cout << "所有老师信息如下:  " << endl;
		for_each(vTea.begin(), vTea.end(), printTeacher);
	}
	system("pause");
	system("cls");
}
//查看机房信息
void Manager::showComputer()
{
	cout << "机房的信息如下" << endl;
	for (vector<ComputerRoom>::iterator it = vCom.begin(); it != vCom.end(); it++)
	{
		cout << "机房编号: " << it->m_ComId << "机房最大容量: " << it->m_MaxNum << endl;
	}
	system("pause");
	system("cls");
}
//清空预约记录
void Manager::clearFile()
{
	ofstream ofs;
	ofs.open(ORDER_FILE, ios::trunc);
	ofs.close();
	cout << "清空成功" << endl;
	system("pause");
	system("cls");
}
//初始化容器
void Manager::initVector()
{
	//确保容器清空
	vStu.clear();
	vTea.clear();
	//读取信息
	ifstream ifs;
	//学生
	ifs.open(STUDENT_FILE, ios::in);
	if (!ifs.is_open())
	{
		cout << "文件读取失败" << endl;
		return;
	}
	Student s;
	while (ifs >> s.m_Id && ifs >> s.m_Name && ifs >> s.m_Password)
	{
		vStu.push_back(s);
	}
	//cout << "当前学生数量为:  " << vStu.size() << endl;
	ifs.close();
	//教师
	ifs.open(TEACHER_FILE, ios::in);
	if (!ifs.is_open())
	{
		cout << "文件读取失败" << endl;
		return;
	}
	Teacher t;
	while (ifs >> t.m_EmpId && ifs >> t.m_Name && ifs >> t.m_Password)
	{
		vTea.push_back(t);
	}
	//cout << "当前教师数量为:  " << vTea.size() << endl;
	ifs.close();
}
//检测重复 参数:(传入id，类型)返回值:(true代表有重复，false代表无重复)
bool Manager::checkRepeat(int id, int type)
{
	if (type == 1)
	{
		//检测学生
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
		//检测教师
		for (vector<Teacher>::iterator it = vTea.begin(); it != vTea.end(); it++)
		{
			if (id == it->m_EmpId)
			{
				return true;
			}
		}
	}
}