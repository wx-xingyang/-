#include<iostream>
using namespace std;
#define MAX 1000

//��ϵ�˽ṹ��
//��ϵ�˵���Ϣ�������������Ա����䣬��ϵ�绰����ͥסַ
struct Person
{
	string m_name;//������
	int m_Sex;//�Ա�1��2Ů��
	int m_Age;//����
	string m_Phone;//�绰��
	string m_Addr;//��ַ
};

//ͨѶ¼�ṹ��
struct Addressbooks
{
	struct Person PersonArray[MAX];
	int m_Size;//ͨѶ¼��Ա����


};
void showMenu()
{



	cout << "***********************************" << endl;
	cout << "********   1�������ϵ��   ********" << endl;
	cout << "********   2����ʾ��ϵ��   ********" << endl;
	cout << "********   3��ɾ����ϵ��   ********" << endl;
	cout << "********   4��������ϵ��   ********" << endl;
	cout << "********   5���޸���ϵ��   ********" << endl;
	cout << "********   6�������ϵ��   ********" << endl;
	cout << "********   0���˳�ͨѶ¼   ********" << endl;
	cout << "***********************************" << endl;
}
//�����ϵ����Ϣ
void addPerson(Addressbooks* abs)
{
	//�жϵ绰���Ƿ�����
	if (abs->m_Size == MAX) 
	{
		cout << "ͨ��¼�������޷����" << endl;
		return;
	}
	else
	{
		string name;//����
		cout << "������������" << endl;
		cin >> name;
		abs->PersonArray[abs->m_Size].m_name = name;

		cout << "�������Ա�;" << endl;
		cout << "1--��" <<endl;
		cout << "2--Ů" << endl;
		
		int sex = 0;
		while (true)
		{
			cin >> sex;
			if (sex == 1 || sex == 2)
			{
				abs->PersonArray[abs->m_Size].m_Sex = sex;
				break;
			}
			cout << "�����������������";


		}
		//����
		cout << "���������䣺" << endl;
		int age = 0;
		cin >> age;
		abs->PersonArray[abs->m_Size].m_Age = age;

		//��ϵ�绰
		cout << "��������ϵ�绰��" << endl;
		string phone = "";
		cin >> phone;
		abs->PersonArray[abs->m_Size].m_Phone = phone;

		//��ͥסַ
		cout << "�������ͥסַ" << endl;
		string address;
		cin >> address;
		abs->PersonArray[abs->m_Size].m_Addr = address;

		//����ͨ��¼����
		abs->m_Size++;
		cout << "��ӳɹ�" << endl;
		system("pause");
		system("cls");

	}


}
//��ʾ��ϵ��

void showPerson(Addressbooks* abs)
{
	if (abs->m_Size == 0)
	{
		cout << "��ǰ��¼Ϊ��" << endl;
	}
	else
	{
		for (int i = 0; i < abs->m_Size; i++)
		{
			cout << "������" << abs->PersonArray[i].m_name << "\t";
			cout << "�Ա�" << abs->PersonArray[i].m_Sex << "\t";
			cout << "���䣺" << abs->PersonArray[i].m_Age << "\t";
			cout << "�绰��" << abs->PersonArray[i].m_Phone << "\t";
			cout << "סַ��" << abs->PersonArray[i].m_Addr << endl;
			
		}
	}
	system("pause");
	system("cls");
}
//ɾ��
//���ж���ϵ���Ƿ����
int isExist(Addressbooks* abs, string name)
{
	for (int i = 0; i < abs->m_Size;i++)//�����õ��˷�ѭ������ʵ�Ҹо���������ѭ��Ҳ���ԣ��ؼ��ֲ�һ����Ҫ���������绰�Ƿ�Ҳ�ǿ��Եģ�
	{
		if(abs->PersonArray[i].m_name == name)
			{
				return i;
			}
	}
	return -1;
}
//ɾ��ָ����ϵ����Ϣ
void deletePerson(Addressbooks* abs)
{
	cout << "��������Ҫɾ������ϵ������" << endl;
	string name;
	cin >> name;
	int ret = isExist(abs, name);//�ȼ�������Ƿ����
	if (ret != -1)
	{
		for (int i = ret; i < abs->m_Size; i++)
		{
			abs->PersonArray[i] = abs->PersonArray[i + 1];//�������ƣ�

		}
		abs->m_Size--;//����-1��
		cout << "ɾ���ɹ�" << endl;

	}
	else
	{
		cout << "���޴���" << endl;

	}

	system("pause");
	system("cls");//����
}
//����ָ����ϵ��
void findPerson(Addressbooks* abs)
{
	cout << "��������Ҫ���ҵ���ϵ������" << endl;
	string name;
	cin >> name;
	int ret = isExist(abs, name);
	if (ret != -1)
	{
		cout << "������" << abs->PersonArray[ret].m_name << "\t";
		cout << "�Ա�" << abs->PersonArray[ret].m_Sex << "\t";
		cout << "���䣺" << abs->PersonArray[ret].m_Age << "\t";
		cout << "�绰��" << abs->PersonArray[ret].m_Phone << "\t";
		cout << "סַ��" << abs->PersonArray[ret].m_Addr << endl;
	}
	else
	{
		cout << "���޴���" << endl;

	}
	system("pause");
	system("cls");

}
//�޸���ϵ��
void modifyPerson(Addressbooks* abs)
{

	cout << "��������Ҫ�޸ĵ���ϵ������" << endl;
	string name;
	cin >> name;
	int ret = isExist(abs, name);
	if (ret != -1)
	{
		string name;//����
		cout << "������������" << endl;
		cin >> name;
		abs->PersonArray[abs->m_Size].m_name = name;

		cout << "�������Ա�;" << endl;
		cout << "1--��" << endl;
		cout << "2--Ů" << endl;

		int sex = 0;
		while (true)
		{
			cin >> sex;
			if (sex == 1 || sex == 2)
			{
				abs->PersonArray[abs->m_Size].m_Sex = sex;
				break;
			}
			cout << "�����������������";


		}
		//����
		cout << "���������䣺" << endl;
		int age = 0;
		cin >> age;
		abs->PersonArray[abs->m_Size].m_Age = age;

		//��ϵ�绰
		cout << "��������ϵ�绰��" << endl;
		string phone = "";
		cin >> phone;
		abs->PersonArray[abs->m_Size].m_Phone = phone;

		//��ͥסַ
		cout << "�������ͥסַ" << endl;
		string address;
		cin >> address;
		abs->PersonArray[abs->m_Size].m_Addr = address;

		cout << "�޸ĳɹ�" << endl;
	}
	else
	{
		cout << "���޴���" << endl;
	}

	system("pause");
	system("cls");


}
//�����ϵ��
void cleanPerson(Addressbooks* abs)
{
	abs->m_Size = 0;
	cout << "ͨѶ¼�Ѿ����" << endl;
	system("pause");
	system("cls");

}
int main()
{
	//����ͨѶ¼
	Addressbooks abs;
	abs.m_Size = 0;//��ʼ��
	int select = 0;
	while (true)
	{
		showMenu();
		cin >> select;
		switch (select)
		{
		case 1://�����ϵ��
			addPerson(&abs);
			break;
		case 2://��ʾ��ϵ��
			showPerson(&abs);
			break;
		case 3://ɾ����ϵ��
			deletePerson(&abs);
			break;
		case 4://������ϵ��
			findPerson(&abs);
			break;
		case 5://�޸���ϵ��
			modifyPerson(&abs);
			break;
		case 6://�����ϵ��
			cleanPerson(&abs);
			break;
		case 0://�˳�ͨѶ¼
		
			cout << "��ӭ�´�ʹ��" << endl;
			system("pause");
			return 0;
			break;

		}
	}

	return 0;
}