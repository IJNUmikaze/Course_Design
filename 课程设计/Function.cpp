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
	if (Back(Head)) {
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
	return;
}
void Change(Computer**& Head) {
	cout << "                                                 �޸Ĺ���" << endl;
	if (Back(Head)) {
		Menu(Head);
		return;
	}
	if (Head == nullptr) {
		cout << endl;
		cout << "                                   ��û�����ݿ����޸�,������������!!!!!" << endl;
		cout << endl;
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
		cout << "��ǰ������ֵΪNo." << Head[0]->GetAmount() << "\t\t��Ŵ�1��ʼ�����ֵΪ0��ʾ��ǰû�����ݿ����޸�" << endl << endl;
		int NewAmount;
		cout << "��������Ҫ�޸ĵ�����:";
		ToInt(NewAmount);
		bool Check;
		Check = CheckInt(NewAmount, "��������Ҫ�޸ĵ�����:",0,Head[0]->GetAmount());
		if (Check == false) {
			return;
		}
		for (int k = 0; k < NewAmount; k++) {
			cout << endl;
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
					cout << "�������µı���ʱ��:" << endl;
					ToTime(str);
					Head[Num - 1]->SetTime(str);
				}
				else {
					cout << "��������ȷ�ı��!!!!!" << endl;
					i--;
				}
			}
		}
		Head[0]->SetFlag(1);
		cout << endl;
		Show(Head);
		cout << endl;
		Save(Head);
		return;
	}
}
void Delete(Computer**& Head) {
	cout << "                                                 ɾ������" << endl;
	if (Back(Head)) {
		Menu(Head);
		return;
	}
	if (Head == nullptr) {
		cout << endl;
		cout << "                                   ��û�����ݿ���ɾ��,������д����!!!!!" << endl;
		cout << endl;
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
	cout << "2.�޸ĵ��Բ�����Ϣ(ǰ����һ���˵�)" << endl;
	cout << "3.ɾ�����Բ�����Ϣ(ǰ����һ���˵�)" << endl;
	cout << "4.��ѯ���Բ�����Ϣ(ǰ����һ���˵�)" << endl;
	cout << "5.�Ե��Բ�����������(ǰ����һ���˵�)" << endl;
	cout << "6.���浱ǰ�ļ�" << endl;
	cout << "7.�����ǰ��������" << endl;
	cout << "88.������ϵͳ" << endl;
	cout << endl;
	cout << "�������Ӧ����ǰ������:";
	ToInt(n);
	bool Check;
	Check = CheckInt(n, "�������Ӧ����ǰ������:",0,88);
	if (Check == false) {
		return Head;
	}
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
		Menu3(Head);
		return Head;
	}
	else if (n == 6) {
		Divide2();
		cout << "                                                 ���湦��" << endl;
		if (Head[0]->GetFlag() == false) {
			cout << "û�б༭,���豣��!!!!!" << endl;
		}
		else {
			Save(Head);
		}
		return Head;
	}
	else if (n == 7) {
		Divide2();
		cout << "                                                 չʾ����" << endl;
		if (Head==nullptr||Head[0]->GetAmount() == 0) {
			cout << "Ŀǰ��û�����ݿ������,������������!!!!!" << endl;
			return Head;
		}
		else {
			Show(Head,0);
		}
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
				cout << "��⵽�ļ�δ����,�Ƿ�Ҫ����(YΪ��,����Ϊ��):";
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
		cout << endl;
		cout << "!!!!!û�����ѡ��!!!!!" << endl;
		Menu(Head);
		return Head;
	}
	return Head;
}


void Menu2(Computer**& Head) {
	cout << "                                               ��ѯ����" << endl;
	if (Head == nullptr) {
		cout << endl;
		cout << "                                   ��û�����ݿ��Բ�ѯ,������д����!!!!!" << endl;
		cout << endl;
		Head = Menu(Head);
		return;
	}
	else {
		if (Head[0]->GetAmount() == 0) {
			cout << "��ǰ�����ѱ�ȫ�����,������������!!!!!" << endl;
			return;
		}
		cout << endl;
		cout << "����Ϊ�ɹ���ѯ����Ϣ" << endl;
		cout << "1.����������ѯ" << endl;
		cout << "2.���۸��ѯ" << endl;
		cout << "3.���ͺŲ�ѯ" << endl;
		cout << "4.������Ų�ѯ" << endl;
		cout << "5.�����̲�ѯ" << endl;
		cout << "6.������ʱ���ѯ" << endl;
		cout << "7.������һ��" << endl;
		cout << endl;
		cout << "��������Ҫʵ�ֹ���ǰ������:";
		int n;
		ToInt(n);
		bool Check;
		Check = CheckInt(n, "�������Ӧ��Ϣǰ������:");
		if (Check == false) {
			return;
		}
		if (n == 1) {
			Divide2();
			FindComponent(Head);
			return;
		}
		else if (n == 2) {
			Divide2();
			FindPrice(Head);
			return;
		}
		else if (n == 3) {
			Divide2();
			FindType(Head);
			return;
		}
		else if (n == 4) {
			Divide2();
			FindClass(Head);
			return;
		}
		else if (n == 5) {
			Divide2();
			FindManufacturer(Head);
			return;
		}
		else if (n == 6) {
			Divide2();
			FindTime(Head);
			return;
		}
		else if (n == 7) {
			Menu(Head);
			return;
		}
		else {
			cout << endl;
			cout << "!!!!!��������ȷ��ֵ!!!!!" << endl;
			Divide2();
			Menu2(Head);
			return;
		}
		return;
	}
}


void Menu3(Computer**& Head) {
	cout << "                                               ������" << endl;
	if (Head == nullptr) {
		cout << endl;
		cout << "                                   ��û�����ݿ�������,������д����!!!!!" << endl;
		cout << endl;
		Head = Menu(Head);
		return;
	}
	else {
		if (Head[0]->GetAmount() == 0) {
			cout << "��ǰ�����ѱ�ȫ�����,������������!!!!!" << endl;
			return;
		}
		cout << "1.������������" << endl;
		cout << "2.���۸�����" << endl;
		cout << "3.���ͺ�����" << endl;
		cout << "4.�����������" << endl;
		cout << "5.����������" << endl;
		cout << "6.������ʱ������" << endl;
		cout << "7.������һ��" << endl;
		cout << endl;
		cout << "��������Ҫʵ�ֹ���ǰ������:";
		int n;
		ToInt(n);
		bool Check;
		Check = CheckInt(n, "�������Ӧ��Ϣǰ������:");
		if (Check == false) {
			return;
		}
		if (n == 1) {
			Divide2();
			OrderComponent(Head);
			return;
		}
		else if (n == 2) {
			Divide2();
			OrderPrice(Head);
			return;
		}
		else if (n == 3) {
			Divide2();
			OrderType(Head);
			return;
		}
		else if (n == 4) {
			Divide2();
			OrderClass(Head);
			return;
		}
		else if (n == 5) {
			Divide2();
			OrderManufacturer(Head);
			return;
		}
		else if (n == 6) {
			Divide2();
			OrderTime(Head);
			return;
		}
		else if (n == 7) {
			Divide2();
			OrderTime(Head);
			return;
		}
		else {
			cout << endl;
			cout << "!!!!!��������ȷ��ֵ!!!!!" << endl;
			Divide2();
			Menu2(Head);
			return;
		}
	}
	return;
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
				int Length = str.length();
				for (int i = 0; i < 10 - Length; i++) {
					str = ' ' + str;
				}
				Co[i]->SetTime(str);
			}
		}
	}
}

void Show(Computer**& Head,bool Flag) {
	if (Flag) {
		string TF;
		cout << "�Ƿ���Ҫ��������б�(YΪ��,����Ϊ��):";
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
		cout << "�Ƿ�Ҫ����(YΪ��,����Ϊ��):";
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
				outfile << "��" << i + 1 << "�����Բ�����Ϣ" << endl;
				outfile << "     ������:" << Head[i]->GetComponent() << endl;
				outfile << "     �۸�:" << Head[i]->GetPrice() << endl;
				outfile << "     ����:" << Head[i]->GetType() << endl;
				outfile << "     �����:" << Head[i]->GetClass() << endl;
				outfile << "     ����:" << Head[i]->GetManufacturer() << endl;
				outfile << "     ����ʱ��:" << Head[i]->GetTime() << endl;
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
			cout << "�벻Ҫ��Ϸϵͳ,��������ȷ��ֵ";
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
	if (Int < 10) {
		Year = ' ' + Year;
		Year = ' ' + Year;
		Year = ' ' + Year;
	}
	else if (Int < 100) {
		Year = ' ' + Year;
		Year = ' ' + Year;
	}
	else if (Int < 1000) {
		Year = ' ' + Year;
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
	else if (Min == 0 && Max == 1) {
		if (This < 0 || This>1) {
			cout << "�벻Ҫ��Ϸϵͳ���ٸ���һ�λ���(ȡֵ��Χ" << Min << "-" << Max << ")" << endl;
			cout << str;
			ToInt(This);
		}
		if (This < 0 || This>1) {
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
	cout << "�Ƿ񷵻���һ��(YΪ��,����Ϊ��):";
	string Back;
	cin >> Back;
	if (Back == "y" || Back == "Y") {
		return true;
	}
	return false;
}

void FindComponent(Computer**& Head) {
	cout << "                                             ����������ѯ" << endl;
	if (Back(Head)) {
		Divide2();
		Menu2(Head);
		return;
	}
	if (Head == nullptr) {
		cout << endl;
		cout << "                                   ��û�����ݿ��Բ�ѯ,������д����!!!!!" << endl;
		cout << endl;
		Head = Menu(Head);
		return;
	}
	else {
		int Count = 0;
		cout << "�������ѯ����Ĳ�����:";
		string Co;
		cin >> Co;
		int* P = new int[Head[0]->GetAmount()];
		for (int i = 0; i < Head[0]->GetAmount(); i++) {
			P[i] = -1;
		}
		for (int i = 0; i < Head[0]->GetAmount(); i++) {
			if (Head[i]->GetComponent() == Co) {
				P[Count++] = i;
			}
		}
		cout << endl;
		if (Count > 0) {
			cout << "һ����ѯ��" << Count << "����������Ҫ��" << endl;
		}
		else {
			cout << "δ�ܲ��ҵ����������" << endl;
		}
		cout << endl;
		FindShow(Head,P,Count);
		if (Count > 0) {
			FindChange(Head, P, Count);
		}
		return;
	}
	return;
}
void FindShow(Computer**& Head,int*& P,int Length) {
	if (Length == 0) {
		return;
	}
	else {
		cout << "�Ƿ�Ҫ������ҵ�������:";
		string TF;
		cin >> TF;
		cout << endl;
		if (TF == "y" || TF == "Y") {
			for (int i = 0; i < Length; i++) {
				cout << "No." << i + 1 << '\t';
				cout << "ԭ���No." << P[i] + 1 << endl;
				cout << "������:" << Head[P[i]]->GetComponent() << '\t';
				cout << "�۸�Ϊ:" << Head[P[i]]->GetPrice() << endl;
				cout << "�ͺ�Ϊ:" << Head[P[i]]->GetType() << '\t';
				cout << "�����Ϊ:" << Head[P[i]]->GetClass() << endl;
				cout << "����Ϊ:" << Head[P[i]]->GetManufacturer() << '\t';
				cout << "����ʱ��Ϊ:" << Head[P[i]]->GetTime() << endl;
			}
		}
		return;
	}
	return;
}
void FindPrice(Computer**& Head) {
	cout << "                                               ���۸��ѯ" << endl;
	if (Back(Head)) {
		Divide2();
		Menu2(Head);
		return;
	}
	if (Head == nullptr) {
		cout << endl;
		cout << "                                   ��û�����ݿ��Բ�ѯ,������д����!!!!!" << endl;
		cout << endl;
		Head = Menu(Head);
		return;
	}
	else {
		int Count = 0;
		cout << "�������ѯ����ļ۸�:";
		double Pr;
		ToDouble(Pr);
		int* P = new int[Head[0]->GetAmount()];
		for (int i = 0; i < Head[0]->GetAmount(); i++) {
			P[i] = -1;
		}
		for (int i = 0; i < Head[0]->GetAmount(); i++) {
			if (Head[i]->GetPrice() == Pr) {
				P[Count++] = i;
			}
		}
		cout << endl;
		if (Count > 0) {
			cout << "һ����ѯ��" << Count << "����������Ҫ��" << endl;
		}
		else {
			cout << "δ�ܲ��ҵ����������" << endl;
		}
		cout << endl;
		FindShow(Head, P, Count);
		if (Count > 0) {
			FindChange(Head, P, Count);
		}
		return;
	}
	return;
}
void FindType(Computer**& Head) {
	cout << "                                               ���ͺŲ�ѯ" << endl;
	if (Back(Head)) {
		Divide2();
		Menu2(Head);
		return;
	}
	if (Head == nullptr) {
		cout << endl;
		cout << "                                   ��û�����ݿ��Բ�ѯ,������д����!!!!!" << endl;
		cout << endl;
		Head = Menu(Head);
		return;
	}
	else {
		int Count = 0;
		cout << "�������ѯ������ͺ�:";
		string Ty;
		cin >> Ty;
		int* P = new int[Head[0]->GetAmount()];
		for (int i = 0; i < Head[0]->GetAmount(); i++) {
			P[i] = -1;
		}
		for (int i = 0; i < Head[0]->GetAmount(); i++) {
			if (Head[i]->GetType() == Ty) {
				P[Count++] = i;
			}
		}
		cout << endl;
		if (Count > 0) {
			cout << "һ����ѯ��" << Count << "����������Ҫ��" << endl;
		}
		else {
			cout << "δ�ܲ��ҵ����������" << endl;
		}
		cout << endl;
		FindShow(Head, P, Count);
		if (Count > 0) {
			FindChange(Head, P, Count);
		}
		return;
	}
	return;
}
void FindClass(Computer**& Head) {
	cout << "                                               ������Ų�ѯ" << endl;
	if (Back(Head)) {
		Divide2();
		Menu2(Head);
		return;
	}
	if (Head == nullptr) {
		cout << endl;
		cout << "                                   ��û�����ݿ��Բ�ѯ,������д����!!!!!" << endl;
		cout << endl;
		Head = Menu(Head);
		return;
	}
	else {
		int Count = 0;
		cout << "�������ѯ����ķ����:";
		string Cl;
		cin >> Cl;
		int* P = new int[Head[0]->GetAmount()];
		for (int i = 0; i < Head[0]->GetAmount(); i++) {
			P[i] = -1;
		}
		for (int i = 0; i < Head[0]->GetAmount(); i++) {
			if (Head[i]->GetClass() == Cl) {
				P[Count++] = i;
			}
		}
		cout << endl;
		if (Count > 0) {
			cout << "һ����ѯ��" << Count << "����������Ҫ��" << endl;
		}
		else {
			cout << "δ�ܲ��ҵ����������" << endl;
		}
		cout << endl;
		FindShow(Head, P, Count);
		if (Count > 0) {
			FindChange(Head, P, Count);
		}
		return;
	}
	return;
}
void FindManufacturer(Computer**& Head) {
	cout << "                                               �����̲�ѯ" << endl;
	if (Back(Head)) {
		Divide2();
		Menu2(Head);
		return;
	}
	if (Head == nullptr) {
		cout << endl;
		cout << "                                   ��û�����ݿ��Բ�ѯ,������д����!!!!!" << endl;
		cout << endl;
		Head = Menu(Head);
		return;
	}
	else {
		int Count = 0;
		cout << "�������ѯ����ĳ���:";
		string M;
		cin >> M;
		int* P = new int[Head[0]->GetAmount()];
		for (int i = 0; i < Head[0]->GetAmount(); i++) {
			P[i] = -1;
		}
		for (int i = 0; i < Head[0]->GetAmount(); i++) {
			if (Head[i]->GetManufacturer() == M) {
				P[Count++] = i;
			}
		}
		cout << endl;
		if (Count > 0) {
			cout << "һ����ѯ��" << Count << "����������Ҫ��" << endl;
		}
		else {
			cout << "δ�ܲ��ҵ����������" << endl;
		}
		cout << endl;
		FindShow(Head, P, Count);
		if (Count > 0) {
			FindChange(Head, P, Count);
		}
		return;
	}
	return;
}
void FindTime(Computer**& Head) {
	cout << "                                               ������ʱ���ѯ" << endl;
	if (Back(Head)) {
		Divide2();
		Menu2(Head);
		return;
	}
	if (Head == nullptr) {
		cout << endl;
		cout << "                                   ��û�����ݿ��Բ�ѯ,������д����!!!!!" << endl;
		cout << endl;
		Head = Menu(Head);
		return;
	}
	else {
		int Count = 0;
		cout << "�������ѯ����ı���ʱ��:";
		cout << endl;
		string Ti;
		ToTime(Ti);
		int* P = new int[Head[0]->GetAmount()];
		for (int i = 0; i < Head[0]->GetAmount(); i++) {
			P[i] = -1;
		}
		for (int i = 0; i < Head[0]->GetAmount(); i++) {
			if (Head[i]->GetTime() == Ti) {
				P[Count++] = i;
			}
		}
		cout << endl;
		if (Count > 0) {
			cout << "һ����ѯ��" << Count << "����������Ҫ��" << endl;
		}
		else {
			cout << "δ�ܲ��ҵ����������" << endl;
		}
		cout << endl;
		FindShow(Head, P, Count);
		if (Count > 0) {
			FindChange(Head, P, Count);
		}
		return;
	}
	return;
}
void FindChange(Computer**& Head,int*& P,int Length) {
	if (Length == 0) {
		return;
	}
	else {
		cout << endl;
		cout << "�Ƿ�Ҫ�޸Ĳ��ҵ�������(YΪ��,����Ϊ��):";
		string TF;
		cin >> TF;
		if (TF == "y" || TF == "Y") {
			cout << "��ǰ������ֵΪNo." << Head[0]->GetAmount() << "\t\t��Ŵ�1��ʼ�����ֵΪ0��ʾ��ǰû�����ݿ����޸�" << endl;
			cout << endl;
			int NewAmount;
			cout << "��������Ҫ�޸ĵ�����:";
			ToInt(NewAmount);
			bool Check;
			Check = CheckInt(NewAmount, "��������Ҫ�޸ĵ�����:");
			if (Check == false) {
				return;
			}
			cout << endl;
			for (int k = 0; k < NewAmount; k++) {
				cout << endl;
				cout << "��������Ҫ�޸Ĳ�����\"ԭʼ\"���:";
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
			}
			Head[0]->SetFlag(1);
			cout << endl;
			Show(Head);
			cout << endl;
			Save(Head);
			return;
		}
	}
	return;
}
void OrderComponent(Computer**& Head) {
	if (Head == nullptr) {
		cout << endl;
		cout << "!!!!!!û�����ݿ�������,������������!!!!!" << endl;
		cout << endl;
		Menu(Head);
		return;
	}
	if (Head[0]->GetAmount() == 0) {
		cout << endl;
		cout << "!!!!!��ǰ���ݾ���ɾ��,������д����!!!!!" << endl;
		cout << endl;
		Menu(Head);
		return;
	}
	else {
		cout << "                                             ������������" << endl;
		if (Back(Head)) {
			Divide2();
			Menu3(Head);
			return;
		}
		cout << endl;
		cout << "0Ϊ˳������,1Ϊ��������" << endl;
		cout << "��������Ҫ��˳��ǰ������:";
		int Flag;
		ToInt(Flag);
		bool Check;
		Check = CheckInt(Flag, "��������Ҫ��˳��ǰ������:",0,1);
		if (Check == false) {
			return;
		}
		Computer* Temp = nullptr;
		for (int i = 0; i < Head[0]->GetAmount(); i++) {
			for (int j = i; j < Head[0]->GetAmount() - i - 1; j++) {
				if (Flag) {
					if (Head[j]->GetComponent() < Head[j + 1]->GetComponent()) {
						Temp = Head[j];
						Head[j] = Head[j + 1];
						Head[j + 1] = Temp;
					}
				}
				else {
					if (Head[j]->GetComponent() > Head[j + 1]->GetComponent()) {
						Temp = Head[j];
						Head[j] = Head[j + 1];
						Head[j + 1] = Temp;
					}
				}
			}
		}
		Head[0]->SetFlag(1);
		cout << endl;
		Show(Head);
		cout << endl;
		Save(Head);
		return;
	}
	return;
}
void OrderPrice(Computer**& Head) {
	if (Head == nullptr) {
		cout << endl;
		cout << "!!!!!!û�����ݿ�������,������������!!!!!" << endl;
		cout << endl;
		Menu(Head);
		return;
	}
	if (Head[0]->GetAmount() == 0) {
		cout << endl;
		cout << "!!!!!��ǰ���ݾ���ɾ��,������д����!!!!!" << endl;
		cout << endl;
		Menu(Head);
		return;
	}
	else {
		cout << "                                              ���۸�����" << endl;
		if (Back(Head)) {
			Divide2();
			Menu3(Head);
			return;
		}
		cout << endl;
		cout << "0Ϊ˳������,1Ϊ��������" << endl;
		cout << "��������Ҫ��˳�������:";
		int Flag;
		ToInt(Flag);
		bool Check;
		Check = CheckInt(Flag, "��������Ҫ��˳��ǰ������:", 0, 1);
		if (Check == false) {
			return;
		}
		Computer* Temp = nullptr;
		for (int i = 0; i < Head[0]->GetAmount(); i++) {
			for (int j = i; j < Head[0]->GetAmount() - i - 1; j++) {
				if (Flag) {
					if (Head[j]->GetPrice() < Head[j + 1]->GetPrice()) {
						Temp = Head[j];
						Head[j] = Head[j + 1];
						Head[j + 1] = Temp;
					}
				}
				else {
					if (Head[j]->GetPrice() > Head[j + 1]->GetPrice()) {
						Temp = Head[j];
						Head[j] = Head[j + 1];
						Head[j + 1] = Temp;
					}
				}
			}
		}
		Head[0]->SetFlag(1);
		cout << endl;
		Show(Head);
		cout << endl;
		Save(Head);
		return;
	}
	return;
}
void OrderType(Computer**& Head) {
	if (Head == nullptr) {
		cout << endl;
		cout << "!!!!!!û�����ݿ�������,������������!!!!!" << endl;
		cout << endl;
		Menu(Head);
		return;
	}
	if (Head[0]->GetAmount() == 0) {
		cout << endl;
		cout << "!!!!!��ǰ���ݾ���ɾ��,������д����!!!!!" << endl;
		cout << endl;
		Menu(Head);
		return;
	}
	else {
		cout << "                                              ���ͺ�����" << endl;
		if (Back(Head)) {
			Divide2();
			Menu3(Head);
			return;
		}
		cout << endl;
		cout << "0Ϊ˳������,1Ϊ��������" << endl;
		cout << "��������Ҫ��˳�������:";
		int Flag;
		ToInt(Flag);
		bool Check;
		Check = CheckInt(Flag, "��������Ҫ��˳��ǰ������:", 0, 1);
		if (Check == false) {
			return;
		}
		Computer* Temp = nullptr;
		for (int i = 0; i < Head[0]->GetAmount(); i++) {
			for (int j = i; j < Head[0]->GetAmount() - i - 1; j++) {
				if (Flag) {
					if (Head[j]->GetType() < Head[j + 1]->GetType()) {
						Temp = Head[j];
						Head[j] = Head[j + 1];
						Head[j + 1] = Temp;
					}
				}
				else {
					if (Head[j]->GetType() > Head[j + 1]->GetType()) {
						Temp = Head[j];
						Head[j] = Head[j + 1];
						Head[j + 1] = Temp;
					}
				}
			}
		}
		Head[0]->SetFlag(1);
		cout << endl;
		Show(Head);
		cout << endl;
		Save(Head);
		return;
	}
	return;
}
void OrderClass(Computer**& Head) {
	if (Head == nullptr) {
		cout << endl;
		cout << "!!!!!!û�����ݿ�������,������������!!!!!" << endl;
		cout << endl;
		Menu(Head);
		return;
	}
	if (Head[0]->GetAmount() == 0) {
		cout << endl;
		cout << "!!!!!��ǰ���ݾ���ɾ��,������д����!!!!!" << endl;
		cout << endl;
		Menu(Head);
		return;
	}
	else {
		cout << "                                             �����������" << endl;
		if (Back(Head)) {
			Divide2();
			Menu3(Head);
			return;
		}
		cout << endl;
		cout << "0Ϊ˳������,1Ϊ��������" << endl;
		cout << "��������Ҫ��˳�������:";
		int Flag;
		ToInt(Flag);
		bool Check;
		Check = CheckInt(Flag, "��������Ҫ��˳��ǰ������:", 0, 1);
		if (Check == false) {
			return;
		}
		Computer* Temp = nullptr;
		for (int i = 0; i < Head[0]->GetAmount(); i++) {
			for (int j = i; j < Head[0]->GetAmount() - i - 1; j++) {
				if (Flag) {
					if (Head[j]->GetClass() < Head[j + 1]->GetClass()) {
						Temp = Head[j];
						Head[j] = Head[j + 1];
						Head[j + 1] = Temp;
					}
				}
				else {
					if (Head[j]->GetClass() > Head[j + 1]->GetClass()) {
						Temp = Head[j];
						Head[j] = Head[j + 1];
						Head[j + 1] = Temp;
					}
				}
			}
		}
		Head[0]->SetFlag(1);
		cout << endl;
		Show(Head);
		cout << endl;
		Save(Head);
		return;
	}
	return;
}
void OrderManufacturer(Computer**& Head) {
	if (Head == nullptr) {
		cout << endl;
		cout << "!!!!!!û�����ݿ�������,������������!!!!!" << endl;
		cout << endl;
		Menu(Head);
		return;
	}
	if (Head[0]->GetAmount() == 0) {
		cout << endl;
		cout << "!!!!!��ǰ���ݾ���ɾ��,������д����!!!!!" << endl;
		cout << endl;
		Menu(Head);
		return;
	}
	else {
		cout << "                                               ����������" << endl;
		if (Back(Head)) {
			Divide2();
			Menu3(Head);
			return;
		}
		cout << endl;
		cout << "0Ϊ˳������,1Ϊ��������" << endl;
		cout << "��������Ҫ��˳�������:";
		int Flag;
		ToInt(Flag);
		bool Check;
		Check = CheckInt(Flag, "��������Ҫ��˳��ǰ������:", 0, 1);
		if (Check == false) {
			return;
		}
		Computer* Temp = nullptr;
		for (int i = 0; i < Head[0]->GetAmount(); i++) {
			for (int j = i; j < Head[0]->GetAmount() - i - 1; j++) {
				if (Flag) {
					if (Head[j]->GetManufacturer() < Head[j + 1]->GetManufacturer()) {
						Temp = Head[j];
						Head[j] = Head[j + 1];
						Head[j + 1] = Temp;
					}
				}
				else {
					if (Head[j]->GetManufacturer() > Head[j + 1]->GetManufacturer()) {
						Temp = Head[j];
						Head[j] = Head[j + 1];
						Head[j + 1] = Temp;
					}
				}
			}
		}
		Head[0]->SetFlag(1);
		cout << endl;
		Show(Head);
		cout << endl;
		Save(Head);
		return;
	}
	return;
}
void OrderTime(Computer**& Head) {
	if (Head == nullptr) {
		cout << endl;
		cout << "!!!!!!û�����ݿ�������,������������!!!!!" << endl;
		cout << endl;
		Menu(Head);
		return;
	}
	if (Head[0]->GetAmount() == 0) {
		cout << endl;
		cout << "!!!!!��ǰ���ݾ���ɾ��,������д����!!!!!" << endl;
		cout << endl;
		Menu(Head);
		return;
	}
	else {
		cout << "                                             ������ʱ������" << endl;
		if (Back(Head)) {
			Divide2();
			Menu3(Head);
			return;
		}
		cout << endl;
		cout << "0Ϊ˳������,1Ϊ��������" << endl;
		cout << "��������Ҫ��˳�������:";
		int Flag;
		ToInt(Flag);
		bool Check;
		Check = CheckInt(Flag, "��������Ҫ��˳��ǰ������:", 0, 1);
		if (Check == false) {
			return;
		}
		Computer* Temp = nullptr;
		for (int i = 0; i < Head[0]->GetAmount(); i++) {
			for (int j = 0; j < Head[0]->GetAmount() - i - 1; j++) {
				if (Flag) {
					if (Head[j]->GetTime() < Head[j + 1]->GetTime()) {
						Temp = Head[j];
						Head[j] = Head[j + 1];
						Head[j + 1] = Temp;
					}
				}
				else {
					if (Head[j]->GetTime() > Head[j + 1]->GetTime()) {
						Temp = Head[j];
						Head[j] = Head[j + 1];
						Head[j + 1] = Temp;
					}
				}
			}
		}
		Head[0]->SetFlag(1);
		cout << endl;
		Show(Head);
		cout << endl;
		Save(Head);
		return;
	}
	return;
}
void Default(Computer**& Head) {
	Title2();
	cout << "�Ƿ�̳���һ�ε��ļ�(YΪ��,����Ϊ��):";
	string str;
	cin >> str;
	if (str == "y" || str == "Y") {
		fstream input("Computer.txt", ios::in | ios::_Nocreate);
		if (!input) {
			cerr << "Open Error" << endl;
		}
		else {
			In(input, Head);
			input.close();
			Show(Head);
		}
	}
	return;
}