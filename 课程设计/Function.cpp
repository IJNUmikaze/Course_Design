#pragma once
#include<iostream>
#include<string>
#include<fstream>
#include<cmath>
#include"Function.h"
using namespace std;
void Divide() {
	cout << "====================================================";
	cout << "=============================================================" << endl;
	return;
}
void Divide2() {
	cout << "                             -----------------------------------------------" << endl;
	return;
}
void Title() {
	Divide();
	cout << "                            ��ӭʹ�õ��Բ�������ϵͳ����������²˵�ѡ����" << endl;
	Divide2();
	return;
}
void Title2() {
	Divide();
	cout << "                                         ��ӭʹ�õ��Բ�������ϵͳ" << endl;
	Divide2();
	return;
}

void Add(Computer**& Head) {
	cout << "                                                 ��ӹ���" << endl;
	cout << "�Ƿ񷵻���һ��:";
	string Back;
	cin >> Back;
	if (Back == "y" || Back == "Y") {
		Menu(Head);
		return;
	}
	if (Head == nullptr) {
		int NewAmount;
		cout << "��������Ҫ��Ӳ�����Ϣ������:";
		ToInt(NewAmount);
		bool Check;
		Check = CheckInt(NewAmount, "��������Ҫ��Ӳ�����Ϣ������:");
		if (Check == false) {
			return;
		}
		Computer** Temp = new Computer * [NewAmount];
		for (int i = 0; i < NewAmount; i++) {
			Temp[i] = new Computer;
			cout << "                                          ��ӵ�" << i + 1;
			cout << "�����Բ�����Ϣ" << endl;
			cout << "��������Բ����Ĳ�����:";
			string Co;
			cin >> Co;
			Temp[i]->SetComponent(Co);
			cout << "��������Բ����ļ۸�:";
			double Pr;
			ToDouble(Pr);
			Temp[i]->SetPrice(Pr);
			cout << "��������Բ������ͺ�:";
			string Ty;
			cin >> Ty;
			Temp[i]->SetType(Ty);
			cout << "��������Բ����ķ����:";
			string Cl;
			cin >> Cl;
			Temp[i]->SetClass(Cl);
			cout << "��������Բ����Ĳ���:";
			string M;
			cin >> M;
			Temp[i]->SetManufacturer(M);
			cout << "��������Բ����ı���ʱ��" << endl;
			string Ti;
			ToTime(Ti);
			Temp[i]->SetTime(Ti);
			Temp[i]->SetUseful(1);
		}
		Head = Temp;
		Head[0]->SetFlag(1);
		Head[0]->SetAmount(NewAmount);
		cout << endl;
		Show(Head);
		cout << endl;
		Save(Head);
	}
	else {
		
		int NewAmount;
		cout << "��������Ҫ��Ӳ�����Ϣ������:";
		ToInt(NewAmount);
		bool Check;
		Check = CheckInt(NewAmount, "��������Ҫ��Ӳ�����Ϣ������:");
		if (Check == false) {
			return;
		}
		Computer** Temp = new Computer * [NewAmount + Head[0]->GetAmount()];
		for (int i = 0; i < Head[0]->GetAmount(); i++) {
			Temp[i] = Head[i];
		}
		NewAmount += Head[0]->GetAmount();
		for (int i = Head[0]->GetAmount(); i < NewAmount; i++) {
			Temp[i] = new Computer;
			cout << "                                          ��ӵ�" << i - Head[0]->GetAmount() + 1;
			cout << "�����Բ�����Ϣ" << endl;
			cout << "��������Բ����Ĳ�����:";
			string Co;
			cin >> Co;
			Temp[i]->SetComponent(Co);
			cout << "��������Բ����ļ۸�:";
			double Pr;
			ToDouble(Pr);
			Temp[i]->SetPrice(Pr);
			cout << "��������Բ������ͺ�:";
			string Ty;
			cin >> Ty;
			Temp[i]->SetType(Ty);
			cout << "��������Բ����ķ����:";
			string Cl;
			cin >> Cl;
			Temp[i]->SetClass(Cl);
			cout << "��������Բ����Ĳ���:";
			string M;
			cin >> M;
			Temp[i]->SetManufacturer(M);
			cout << "��������Բ����ı���ʱ��" << endl;
			string Ti;
			ToTime(Ti);
			Temp[i]->SetTime(Ti);
			Temp[i]->SetUseful(1);
		}
		delete Head;
		Head = Temp;
		Head[0]->SetFlag(1);
		Head[0]->SetAmount(NewAmount);
		cout << endl;
		Show(Head);
		cout << endl;
		Save(Head);
	}
	
}
void Change(Computer**& Head) {
	cout << "                                                 �޸Ĺ���" << endl;
	if (Back(Head)) {
		return;
	}
	if (Head == nullptr) {
		cout << "                                   ��û�����ݿ����޸�,������������!!!!!" << endl;
		Head = Menu(Head);
		return;
	}
	else {
		if (Head[0]->GetAmount() == 0) {
			cout << "��ǰ�����ѱ�ȫ�����,������������!!!!!" << endl;
			return;
		}
		Show(Head, 0);//ֱ�����
		cout << endl;
		cout << "��ǰ������ֵΪNo." << Head[0]->GetAmount() <<"\t\t��Ŵ�1��ʼ�����ֵΪ0��ʾ��ǰû�����ݿ����޸�" << endl;
		cout << "��������Ҫ�޸Ĳ����ı��,��No.�����ֵ:";
		int Num;
		ToInt(Num);
		bool Check;
		Check = CheckInt(Num, "��������Ҫ�޸Ĳ����ı��,��No.�����ֵ:", 0, Head[0]->GetAmount());
		if (Check == false) {
			return;
		}
		cout << endl;
		cout << "�����ǿɹ��޸ĵ���������" << endl;
		cout << "1.�޸Ĳ�����" << endl;
		cout << "2.�޸ļ۸�" << endl;
		cout << "3.�޸��ͺ�" << endl;
		cout << "4.�޸ķ����" << endl;
		cout << "5.�޸ĳ���" << endl;
		cout << "6.�޸ı���ʱ��" << endl;
		cout << endl;
		cout << "��������Ҫ�޸ļ���:";
		int Total;
		ToInt(Total);

		Check = CheckInt(Total, "��������Ҫ�޸ļ���:", 0, 6);
		if (Check == false) {
			return;
		}
		string str;
		for (int i = 0; i < Total; i++) {
			cout << "��������Ҫ�޸ĵ�����ǰ�ı��:";
			int No;
			ToInt(No);
			if (No == 1) {
				cout << "�������µĲ�����:";
				cin >> str;
				Head[Num - 1]->SetComponent(str);
			}
			else if (No == 2) {
				cout << "�������µļ۸�:";
				double Price;
				ToDouble(Price);
				Head[Num - 1]->SetPrice(Price);
			}
			else if (No == 3) {
				cout << "�������µ��ͺ�:";
				cin >> str;
				Head[Num - 1]->SetType(str);
			}
			else if (No == 4) {
				cout << "�������µķ����:";
				cin >> str;
				Head[Num - 1]->SetClass(str);
			}
			else if (No == 5) {
				cout << "�������µĳ���:";
				cin >> str;
				Head[Num - 1]->SetManufacturer(str);
			}
			else if (No == 6) {
				cout << "�������µı���ʱ��:";
				ToTime(str);
				Head[Num - 1]->SetTime(str);
			}
			else {
				cout << "��������ȷ�ı��!!!!!" << endl;
				i--;
			}
		}
		cout << endl;
		Save(Head);
		cout << endl;
		Show(Head);
		return;
	}
}
void Delete(Computer**& Head) {
	cout << "                                                 ɾ������" << endl;
	if (Back(Head)) {
		return;
	}
	if (Head == nullptr) {
		cout << "                                   ��û�����ݿ���ɾ��,������д����!!!!!" << endl;
		Head=Menu(Head);
		return;
	}
	else {
		if (Head[0]->GetAmount() == 0) {
			cout << "��ǰ�����ѱ�ȫ�����,������������!!!!!" << endl;
			return;
		}
		cout << endl;
		cout << "\t����" << Head[0]->GetAmount() << "������" << endl;
		Show(Head, 0);
		cout << endl;
		cout << "��������Ҫɾ����������:";
		int No;
		ToInt(No);
		bool Check;
		Check = CheckInt(No, "��������Ҫɾ����������:", 0, Head[0]->GetAmount());
		if (Check == false) {
			return;
		}
		cout << endl;
		int NewAmount = Head[0]->GetAmount() - No;
		for (int i = 0; i < No; i++) {
			cout << "��������Ҫɾ���ĵ��Բ����ı��,��No.�����ֵ:";
			int Num;
			ToInt(Num);
			bool Check;
			Check = CheckInt(Num, "��������Ҫɾ���ĵ��Բ����ı��,��No.�����ֵ:", 0, Head[0]->GetAmount());
			if (Check == false) {
				return;
			}
			Head[Num-1]->SetUseful(false);
		}
		Computer** Temp = new Computer * [Head[0]->GetAmount()-No];
		int Count = 0;
		for (int i = 0; i < Head[0]->GetAmount(); i++) {
			if (Head[i]->GetUseful() == true) {
				Temp[Count++] = Head[i];
			}
			else {
				delete Head[i];
			}
		}
		Head = Temp;
		Head[0]->SetFlag(1);//��̬��Ա���ܷ��ʣ����඼���У�Ӧ������λ���й�
		Head[0]->SetAmount(NewAmount);//���ֳ���Ϊ0�����龹Ȼ���ᱨ��
		cout << endl;
		Show(Head);
		if (Head[0]->GetAmount() == 0) {
			cout << "��ǰ�����ѱ�ȫ�����!!!!!" << endl;
		}
		cout << endl;
		Save(Head);
		return;
	}
}



Computer** Menu(Computer**& Head) {
	Title();
	int n;
	cout << "1.��ӵ��Բ�����Ϣ(ǰ����һ���˵�)"<<endl;
	cout << "2.�޸�һ�����Բ�����Ϣ(ǰ����һ���˵�)" << endl;
	cout << "3.ɾ��һ�����Բ�����Ϣ(ǰ����һ���˵�)" << endl;
	cout << "4.��ѯ���Բ�����Ϣ(ǰ����һ���˵�)" << endl;
	cout << "5.�Ե��Բ�����������(ǰ����һ���˵�)" << endl;
	cout << "88.������ϵͳ" << endl;
	cout << endl;
	cout << "�������Ӧ���ܵ�����:";
	while (cin >> n) {
		if (n == 1) {
			Divide2();
			Add(Head);
			return Head;
		}
		else if (n == 2) {
			Divide2();
			Change(Head);
			return Head;
		}
		else if (n == 3) {
			Divide2();
			Delete(Head);
			return Head;
		}
		else if (n == 4) {
			Divide2();
			Menu2(Head);
			return Head;
		}
		else if (n == 5) {
			Divide2();
			Menu3();
			return Head;
		}
		else if (n == 88) {
			if (Head == nullptr) {
				cout << endl;
				cout << "                                         ��л����ʹ�ã��´��ټ�" << endl;
				Divide();
				return nullptr;
			}
			else {
				if (Head[0]->GetFlag() == true) {
					cout << "��⵽�ļ�δ����,�Ƿ�Ҫ����:";
					string SaveOr;
					cin >> SaveOr;
					if (SaveOr == "y" || SaveOr == "Y") {
						Save(Head, 0);
					}
				}
				for (int i = 0; i < Head[0]->GetAmount(); i++) {
					delete Head[i];
				}
				delete Head;
				Head = nullptr;
				cout << endl;
				cout << "                                       ��л����ʹ�ã��´��ټ�" << endl;
				Divide();
				return nullptr;
			}
		}
		else {
			cout << "��������ȷ����:";
		}
	}
	return Head;
}


void Menu2(Computer**& Head) {
	cout << "                                               ��ѯ����" << endl;
	if (Back(Head)) {
		return;
	}
	if (Head == nullptr) {
		cout << "                                   ��û�����ݿ��Բ�ѯ,������д����!!!!!" << endl;
		Head = Menu(Head);
		return;
	}
	else {
		if (Head[0]->GetAmount() == 0) {
			cout << "��ǰ�����ѱ�ȫ�����,������������!!!!!" << endl;
			return;
		}
		cout << "1.�����Ͳ�ѯ" << endl;
		cout << "2.���۸��ѯ" << endl;
		cout << "3.����������ѯ" << endl;
		cout << "4.������Ų�ѯ" << endl;
		cout << "5.���ͺŲ�ѯ" << endl;
		cout << "6.������ʱ���ѯ" << endl;
		cout << "7.������һ��" << endl;
		cout << endl;
		cout << "��������Ҫʵ�ֹ���ǰ������:";
		int n;
		while (cin >> n) {
			if (n == 1) {

			}
			else if (n == 2) {

			}
			else if (n == 3) {

			}
			else if (n == 4) {

			}
			else if (n == 5) {

			}
			else if (n == 6) {

			}
			else if (n == 6) {

			}
			else if (n == 7) {
				return;
			}
			else {
				cout << "��������ȷ��ֵ:";
			}
		}
		return;
	}
}


void Menu3() {
	cout << "                                               ������" << endl;
	cout << "1.����������" << endl;
	cout << "2.���۸�����" << endl;
	cout << "3.������������" << endl;
	cout << "4.�����������" << endl;
	cout << "5.���ͺ�����" << endl;
	cout << "6.������ʱ������" << endl;
	cout << endl;
	cout << "��������Ҫʵ�ֹ���ǰ������:";
	int n;
	cin >> n;
}


void In(fstream& in,Computer**& Co) {
	string str;
	double flo;
	int n;
	in.ignore(100, ':');
	in >> n;
	Co = new Computer * [n];
	for (int i = 0; i < n; i++) {
		Co[i] = new Computer;
	}
	(**Co).SetAmount(n);
	for (int i = 0; i < n; i++) {
		in.ignore();
		in.ignore(100, '\n');
		Co[i]->SetUseful(1);
		for (int j = 0; j < 6; j++) {
			in.ignore(100, ':');
			if (j == 0) {
				in >> str;
				Co[i]->SetComponent(str);
			}
			else if (j == 1) {
				in >> flo;
				Co[i]->SetPrice(flo);
			}
			else if (j == 2) {
				in >> str;
				Co[i]->SetType(str);
			}
			else if (j == 3) {
				in >> str;
				Co[i]->SetClass(str);
			}
			else if (j == 4) {
				in >> str;
				Co[i]->SetManufacturer(str);
			}
			else if (j == 5) {
				in >> str;
				Co[i]->SetTime(str);
			}
		}
	}
}

void Show(Computer**& Head,bool Flag) {
	if (Flag) {
		string TF;
		cout << "�Ƿ���Ҫ��������б�:";
		cin >> TF;
		if (TF == "y" || TF == "Y") {
			for (int i = 0; i < Head[0]->GetAmount(); i++) {
				cout << "No." << i + 1 << endl;
				cout << "������:" << Head[i]->GetComponent() << '\t';
				cout << "�۸�Ϊ:" << Head[i]->GetPrice() << endl;
				cout << "�ͺ�Ϊ:" << Head[i]->GetType() << '\t';
				cout << "�����Ϊ:" << Head[i]->GetClass() << endl;
				cout << "����Ϊ:" << Head[i]->GetManufacturer() << '\t';
				cout << "����ʱ��Ϊ:" << Head[i]->GetTime() << endl;
			}
		}
	}
	else {
		for (int i = 0; i < Head[0]->GetAmount(); i++) {
			cout << "No." << i + 1 << endl;
			cout << "������:" << Head[i]->GetComponent() << '\t';
			cout << "�۸�Ϊ:" << Head[i]->GetPrice() << endl;
			cout << "�ͺ�Ϊ:" << Head[i]->GetType() << '\t';
			cout << "�����Ϊ:" << Head[i]->GetClass() << endl;
			cout << "����Ϊ:" << Head[i]->GetManufacturer() << '\t';
			cout << "����ʱ��Ϊ:" << Head[i]->GetTime() << endl;
		}
	}
	return;
}

void Save(Computer**& Head,bool Flag) {
	if (Flag) {
		cout << "�Ƿ�Ҫ����:";
		string TF;
		cin >> TF;
		if (TF == "y" || TF == "Y") {
			fstream outfile("Computer.txt", ios::out | ios::_Nocreate | ios::trunc);
			if (!outfile) {
				cerr << "Open Error" << endl;
				return;
			}
			outfile << "���Բ�������Ϊ:" << Head[0]->GetAmount() << endl;
			for (int i = 0; i < Head[0]->GetAmount(); i++) {
				outfile << endl;
				outfile << "     ��" << i + 1 << "�����Բ�����Ϣ" << endl;
				outfile << "������:" << Head[i]->GetComponent() << endl;
				outfile << "�۸�:" << Head[i]->GetPrice() << endl;
				outfile << "����:" << Head[i]->GetType() << endl;
				outfile << "�����:" << Head[i]->GetClass() << endl;
				outfile << "����:" << Head[i]->GetManufacturer() << endl;
				outfile << "����ʱ��:" << Head[i]->GetTime() << endl;
			}
			outfile.flush();
			outfile.close();
			Head[0]->SetFlag(0);
		}
		return;
	}
	else {
		fstream outfile("Computer.txt", ios::out | ios::_Nocreate | ios::trunc);
		if (!outfile) {
			cerr << "Open Error" << endl;
			return;
		}
		outfile << "���Բ�������Ϊ:" << Head[0]->GetAmount() << endl;
		for (int i = 0; i < Head[0]->GetAmount(); i++) {
			outfile << endl;
			outfile << "     ��" << i + 1 << "�����Բ�����Ϣ" << endl;
			outfile << "������:" << Head[i]->GetComponent() << endl;
			outfile << "�۸�:" << Head[i]->GetPrice() << endl;
			outfile << "����:" << Head[i]->GetType() << endl;
			outfile << "�����:" << Head[i]->GetClass() << endl;
			outfile << "����:" << Head[i]->GetManufacturer() << endl;
			outfile << "����ʱ��:" << Head[i]->GetTime() << endl;
		}
		outfile.flush();
		outfile.close();
		Head[0]->SetFlag(0);
		return;
	}
	
}

void ToDouble(double& Price) {
	string Turn;
	bool Point = false;
	bool Flag = false;
	while (cin >> Turn) {
		Flag = false;
		int Length = Turn.length();
		for (int i = 0; i < Length; i++) {
			if (Turn[i] == '-') {
				Flag = true;
				break;
			}
			else if (Turn[i] == '.') {
				if (Point == false) {
					Point = true;
				}
				else if (Turn[0] == '.') {
					Flag = true;
					break;
				}
				else {
					Flag = true;
					break;
				}
			}
			else if (Turn[i] < 48 || Turn[i]>57) {
				Flag = true;
				break;
			}
		}
		if (Flag == false) {
			break;
		}
		else {
			cout << "�벻Ҫ��Ϸϵͳ,��������������(��������):";
		}
	}
	Price = 0;
	int Dian;
	Point = false;
	for (int i = 0; i < Turn.length(); i++) {
		if (Turn[i] == '.') {
			Dian = i + 1;
			Point = 1;
			break;
		}
	}
	for (int i = 0; i < Turn.length(); i++) {
		if (Turn[i] >= 48 && Turn[i] <= 57) {
			Price = Price * 10 + Turn[i] - 48;
		}
	}
	if (Point == false) {
	}
	else {
		Price = Price * pow(0.1, Turn.length() - Dian);
	}
	return;
}

void ToInt(int& Am) {
	string INT;
	bool Flag = false;
	while (cin >> INT) {
		Flag = false;
		int Length = INT.length();
		for (int i = 0; i < Length; i++) {
			if (INT[i] < 48 || INT[i]>57) {
				Flag = true;
				break;
			}
		}
		if (Flag == false) {
			break;
		}
		else {
			cout << "�벻Ҫ��Ϸϵͳ,��������ȷ��ֵ(������):";
		}
	}
	Am = 0;
	for (int i = 0; i < INT.length(); i++) {
		Am = Am * 10 + INT[i]-48;
	}
	return;
}

void ToTime(string& Ti) {
	int Int;
	string Year;
	string Month;
	string Day;
	cout << "  ���������:";
	while (1) {
		ToInt(Int);
		if (Int > 2022) {
			cout << "  ���δ��!!!!!" << endl;
			cout << "  ����������:";
		}
		else {
			break;
		}
	}
	for (int i = Int; i > 0; i = i / 10) {
		int m = i % 10;
		Year = char(m + 48) + Year;
	}
	cout << "  �������·�:";
	while (1) {
		ToInt(Int);
		if (Int > 12|| Int == 0) {
			cout << "  û�������!!!!!" << endl;
			cout << "  ����������:";
		}
		else {
			break;
		}
	}
	for (int i = Int; i > 0; i = i / 10) {
		int m = i % 10;
		Month = char(m + 48) + Month;
	}
	if (Int < 10) {
		Month = char(48) + Month;
	}
	cout << "  ��������:";
	while (1) {
		ToInt(Int);
		if (Int > 31|| Int == 0) {
			cout << "  û�������!!!!!" << endl;
			cout << "  ����������:";
		}
		else {
			break;
		}
	}
	for (int i = Int; i > 0; i = i / 10) {
		int m = i % 10;
		Day = char(m + 48) + Day;
	}
	if (Int < 10) {
		Day = char(48) + Day;
	}
	Ti = Year + "/" + Month + "/" + Day;
	return;
}

bool CheckInt(int& This,string str,int Min,int Max) {
	if (Min == -1 && Max == -1) {
		if (This == 0) {
			cout << "�벻Ҫ��Ϸϵͳ���ٸ���һ�λ���" << endl;
			cout << str;
			ToInt(This);
		}
		if (This == 0) {
			cout << "Get Away!!!!!" << endl;
			return false;
		}
		return true;
	}
	else {
		if (This <= 0||This>Max) {
			cout << "�벻Ҫ��Ϸϵͳ���ٸ���һ�λ���(ȡֵ��Χ" << Min << "-" << Max << ",����0����ȡ)" << endl;
			cout << str;
			ToInt(This);
		}
		if (This == 0||This>Max) {
			cout << "Get Away!!!!!" << endl;
			return false;
		}
		return true;
	}
}
bool Back(Computer**& Head) {
	cout << "�Ƿ񷵻���һ��:";
	string Back;
	cin >> Back;
	if (Back == "y" || Back == "Y") {
		Menu(Head);
		return true;
	}
	return false;
}