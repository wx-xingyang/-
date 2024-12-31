#include<iostream>
using namespace std;
#define MAX 1000

//联系人结构体
//联系人的信息包括：姓名，性别，年龄，联系电话，家庭住址
struct Person
{
	string m_name;//姓名；
	int m_Sex;//性别：1男2女；
	int m_Age;//年龄
	string m_Phone;//电话；
	string m_Addr;//地址
};

//通讯录结构体
struct Addressbooks
{
	struct Person PersonArray[MAX];
	int m_Size;//通讯录人员个数


};
void showMenu()
{



	cout << "***********************************" << endl;
	cout << "********   1、添加联系人   ********" << endl;
	cout << "********   2、显示联系人   ********" << endl;
	cout << "********   3、删除联系人   ********" << endl;
	cout << "********   4、查找联系人   ********" << endl;
	cout << "********   5、修改联系人   ********" << endl;
	cout << "********   6、清空联系人   ********" << endl;
	cout << "********   0、退出通讯录   ********" << endl;
	cout << "***********************************" << endl;
}
//添加联系人信息
void addPerson(Addressbooks* abs)
{
	//判断电话本是否满了
	if (abs->m_Size == MAX) 
	{
		cout << "通信录已满，无法添加" << endl;
		return;
	}
	else
	{
		string name;//姓名
		cout << "请输入姓名：" << endl;
		cin >> name;
		abs->PersonArray[abs->m_Size].m_name = name;

		cout << "请输入性别;" << endl;
		cout << "1--男" <<endl;
		cout << "2--女" << endl;
		
		int sex = 0;
		while (true)
		{
			cin >> sex;
			if (sex == 1 || sex == 2)
			{
				abs->PersonArray[abs->m_Size].m_Sex = sex;
				break;
			}
			cout << "输出有误，请重新输入";


		}
		//年龄
		cout << "请输入年龄：" << endl;
		int age = 0;
		cin >> age;
		abs->PersonArray[abs->m_Size].m_Age = age;

		//联系电话
		cout << "请输入联系电话：" << endl;
		string phone = "";
		cin >> phone;
		abs->PersonArray[abs->m_Size].m_Phone = phone;

		//家庭住址
		cout << "请输入家庭住址" << endl;
		string address;
		cin >> address;
		abs->PersonArray[abs->m_Size].m_Addr = address;

		//更新通信录人数
		abs->m_Size++;
		cout << "添加成功" << endl;
		system("pause");
		system("cls");

	}


}
//显示联系人

void showPerson(Addressbooks* abs)
{
	if (abs->m_Size == 0)
	{
		cout << "当前记录为空" << endl;
	}
	else
	{
		for (int i = 0; i < abs->m_Size; i++)
		{
			cout << "姓名：" << abs->PersonArray[i].m_name << "\t";
			cout << "性别：" << abs->PersonArray[i].m_Sex << "\t";
			cout << "年龄：" << abs->PersonArray[i].m_Age << "\t";
			cout << "电话：" << abs->PersonArray[i].m_Phone << "\t";
			cout << "住址：" << abs->PersonArray[i].m_Addr << endl;
			
		}
	}
	system("pause");
	system("cls");
}
//删除
//先判断联系人是否存在
int isExist(Addressbooks* abs, string name)
{
	for (int i = 0; i < abs->m_Size;i++)//这里用到了放循环，其实我感觉用其他的循环也可以，关键字不一定非要用姓名，电话是否也是可以的？
	{
		if(abs->PersonArray[i].m_name == name)
			{
				return i;
			}
	}
	return -1;
}
//删除指定联系人信息
void deletePerson(Addressbooks* abs)
{
	cout << "请输入你要删除的联系人名称" << endl;
	string name;
	cin >> name;
	int ret = isExist(abs, name);//先检查名字是否存在
	if (ret != -1)
	{
		for (int i = ret; i < abs->m_Size; i++)
		{
			abs->PersonArray[i] = abs->PersonArray[i + 1];//整体右移；

		}
		abs->m_Size--;//数量-1；
		cout << "删除成功" << endl;

	}
	else
	{
		cout << "查无此人" << endl;

	}

	system("pause");
	system("cls");//清屏
}
//查找指定联系人
void findPerson(Addressbooks* abs)
{
	cout << "请输入你要查找的联系人名称" << endl;
	string name;
	cin >> name;
	int ret = isExist(abs, name);
	if (ret != -1)
	{
		cout << "姓名：" << abs->PersonArray[ret].m_name << "\t";
		cout << "性别：" << abs->PersonArray[ret].m_Sex << "\t";
		cout << "年龄：" << abs->PersonArray[ret].m_Age << "\t";
		cout << "电话：" << abs->PersonArray[ret].m_Phone << "\t";
		cout << "住址：" << abs->PersonArray[ret].m_Addr << endl;
	}
	else
	{
		cout << "查无此人" << endl;

	}
	system("pause");
	system("cls");

}
//修改联系人
void modifyPerson(Addressbooks* abs)
{

	cout << "请输入你要修改的联系人名称" << endl;
	string name;
	cin >> name;
	int ret = isExist(abs, name);
	if (ret != -1)
	{
		string name;//姓名
		cout << "请输入姓名：" << endl;
		cin >> name;
		abs->PersonArray[abs->m_Size].m_name = name;

		cout << "请输入性别;" << endl;
		cout << "1--男" << endl;
		cout << "2--女" << endl;

		int sex = 0;
		while (true)
		{
			cin >> sex;
			if (sex == 1 || sex == 2)
			{
				abs->PersonArray[abs->m_Size].m_Sex = sex;
				break;
			}
			cout << "输出有误，请重新输入";


		}
		//年龄
		cout << "请输入年龄：" << endl;
		int age = 0;
		cin >> age;
		abs->PersonArray[abs->m_Size].m_Age = age;

		//联系电话
		cout << "请输入联系电话：" << endl;
		string phone = "";
		cin >> phone;
		abs->PersonArray[abs->m_Size].m_Phone = phone;

		//家庭住址
		cout << "请输入家庭住址" << endl;
		string address;
		cin >> address;
		abs->PersonArray[abs->m_Size].m_Addr = address;

		cout << "修改成功" << endl;
	}
	else
	{
		cout << "查无此人" << endl;
	}

	system("pause");
	system("cls");


}
//清空联系人
void cleanPerson(Addressbooks* abs)
{
	abs->m_Size = 0;
	cout << "通讯录已经清空" << endl;
	system("pause");
	system("cls");

}
int main()
{
	//创建通讯录
	Addressbooks abs;
	abs.m_Size = 0;//初始化
	int select = 0;
	while (true)
	{
		showMenu();
		cin >> select;
		switch (select)
		{
		case 1://添加联系人
			addPerson(&abs);
			break;
		case 2://显示联系人
			showPerson(&abs);
			break;
		case 3://删除联系人
			deletePerson(&abs);
			break;
		case 4://查找联系人
			findPerson(&abs);
			break;
		case 5://修改联系人
			modifyPerson(&abs);
			break;
		case 6://清空联系人
			cleanPerson(&abs);
			break;
		case 0://退出通讯录
		
			cout << "欢迎下次使用" << endl;
			system("pause");
			return 0;
			break;

		}
	}

	return 0;
}