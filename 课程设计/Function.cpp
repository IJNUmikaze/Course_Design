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
	cout << "                            欢迎使用电脑部件报价系统，请根据以下菜单选择功能" << endl;
	Divide2();
	return;
}
void Title2() {
	Divide();
	cout << "                                         欢迎使用电脑部件报价系统" << endl;
	Divide2();
	return;
}

void Add(Computer**& Head) {
	cout << "                                                 添加功能" << endl;
	cout << "是否返回上一步:";
	string Back;
	cin >> Back;
	if (Back == "y" || Back == "Y") {
		Menu(Head);
		return;
	}
	if (Head == nullptr) {
		int NewAmount;
		cout << "请输入想要添加部件信息的组数:";
		ToInt(NewAmount);
		bool Check;
		Check = CheckInt(NewAmount, "请输入想要添加部件信息的组数:");
		if (Check == false) {
			return;
		}
		Computer** Temp = new Computer * [NewAmount];
		for (int i = 0; i < NewAmount; i++) {
			Temp[i] = new Computer;
			cout << "                                          添加第" << i + 1;
			cout << "个电脑部件信息" << endl;
			cout << "请输入电脑部件的部件名:";
			string Co;
			cin >> Co;
			Temp[i]->SetComponent(Co);
			cout << "请输入电脑部件的价格:";
			double Pr;
			ToDouble(Pr);
			Temp[i]->SetPrice(Pr);
			cout << "请输入电脑部件的型号:";
			string Ty;
			cin >> Ty;
			Temp[i]->SetType(Ty);
			cout << "请输入电脑部件的分类号:";
			string Cl;
			cin >> Cl;
			Temp[i]->SetClass(Cl);
			cout << "请输入电脑部件的产商:";
			string M;
			cin >> M;
			Temp[i]->SetManufacturer(M);
			cout << "请输入电脑部件的报价时间" << endl;
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
		cout << "请输入想要添加部件信息的组数:";
		ToInt(NewAmount);
		bool Check;
		Check = CheckInt(NewAmount, "请输入想要添加部件信息的组数:");
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
			cout << "                                          添加第" << i - Head[0]->GetAmount() + 1;
			cout << "个电脑部件信息" << endl;
			cout << "请输入电脑部件的部件名:";
			string Co;
			cin >> Co;
			Temp[i]->SetComponent(Co);
			cout << "请输入电脑部件的价格:";
			double Pr;
			ToDouble(Pr);
			Temp[i]->SetPrice(Pr);
			cout << "请输入电脑部件的型号:";
			string Ty;
			cin >> Ty;
			Temp[i]->SetType(Ty);
			cout << "请输入电脑部件的分类号:";
			string Cl;
			cin >> Cl;
			Temp[i]->SetClass(Cl);
			cout << "请输入电脑部件的产商:";
			string M;
			cin >> M;
			Temp[i]->SetManufacturer(M);
			cout << "请输入电脑部件的报价时间" << endl;
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
	cout << "                                                 修改功能" << endl;
	if (Back(Head)) {
		return;
	}
	if (Head == nullptr) {
		cout << "                                   还没有数据可以修改,请先填入数据!!!!!" << endl;
		Head = Menu(Head);
		return;
	}
	else {
		if (Head[0]->GetAmount() == 0) {
			cout << "当前数据已被全部清空,请先输入数据!!!!!" << endl;
			return;
		}
		Show(Head, 0);//直接输出
		cout << endl;
		cout << "当前编号最大值为No." << Head[0]->GetAmount() <<"\t\t编号从1开始，最大值为0表示当前没有数据可以修改" << endl;
		cout << "请输入想要修改部件的编号,即No.后的数值:";
		int Num;
		ToInt(Num);
		bool Check;
		Check = CheckInt(Num, "请输入想要修改部件的编号,即No.后的数值:", 0, Head[0]->GetAmount());
		if (Check == false) {
			return;
		}
		cout << endl;
		cout << "以下是可供修改的数据类型" << endl;
		cout << "1.修改部件名" << endl;
		cout << "2.修改价格" << endl;
		cout << "3.修改型号" << endl;
		cout << "4.修改分类号" << endl;
		cout << "5.修改厂商" << endl;
		cout << "6.修改报价时间" << endl;
		cout << endl;
		cout << "请输入想要修改几处:";
		int Total;
		ToInt(Total);

		Check = CheckInt(Total, "请输入想要修改几处:", 0, 6);
		if (Check == false) {
			return;
		}
		string str;
		for (int i = 0; i < Total; i++) {
			cout << "请输入想要修改的类型前的编号:";
			int No;
			ToInt(No);
			if (No == 1) {
				cout << "请输入新的部件名:";
				cin >> str;
				Head[Num - 1]->SetComponent(str);
			}
			else if (No == 2) {
				cout << "请输入新的价格:";
				double Price;
				ToDouble(Price);
				Head[Num - 1]->SetPrice(Price);
			}
			else if (No == 3) {
				cout << "请输入新的型号:";
				cin >> str;
				Head[Num - 1]->SetType(str);
			}
			else if (No == 4) {
				cout << "请输入新的分类号:";
				cin >> str;
				Head[Num - 1]->SetClass(str);
			}
			else if (No == 5) {
				cout << "请输入新的厂商:";
				cin >> str;
				Head[Num - 1]->SetManufacturer(str);
			}
			else if (No == 6) {
				cout << "请输入新的报价时间:";
				ToTime(str);
				Head[Num - 1]->SetTime(str);
			}
			else {
				cout << "请输入正确的编号!!!!!" << endl;
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
	cout << "                                                 删除功能" << endl;
	if (Back(Head)) {
		return;
	}
	if (Head == nullptr) {
		cout << "                                   还没有数据可以删除,请先填写数据!!!!!" << endl;
		Head=Menu(Head);
		return;
	}
	else {
		if (Head[0]->GetAmount() == 0) {
			cout << "当前数据已被全部清空,请先输入数据!!!!!" << endl;
			return;
		}
		cout << endl;
		cout << "\t现有" << Head[0]->GetAmount() << "组数据" << endl;
		Show(Head, 0);
		cout << endl;
		cout << "请输入想要删除几组数据:";
		int No;
		ToInt(No);
		bool Check;
		Check = CheckInt(No, "请输入想要删除几组数据:", 0, Head[0]->GetAmount());
		if (Check == false) {
			return;
		}
		cout << endl;
		int NewAmount = Head[0]->GetAmount() - No;
		for (int i = 0; i < No; i++) {
			cout << "请输入想要删除的电脑部件的编号,即No.后的数值:";
			int Num;
			ToInt(Num);
			bool Check;
			Check = CheckInt(Num, "请输入想要删除的电脑部件的编号,即No.后的数值:", 0, Head[0]->GetAmount());
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
		Head[0]->SetFlag(1);//静态成员仍能访问，其余都不行，应该与存放位置有关
		Head[0]->SetAmount(NewAmount);//出现长度为0的数组竟然不会报错
		cout << endl;
		Show(Head);
		if (Head[0]->GetAmount() == 0) {
			cout << "当前数据已被全部清空!!!!!" << endl;
		}
		cout << endl;
		Save(Head);
		return;
	}
}



Computer** Menu(Computer**& Head) {
	Title();
	int n;
	cout << "1.添加电脑部件信息(前往下一级菜单)"<<endl;
	cout << "2.修改一个电脑部件信息(前往下一级菜单)" << endl;
	cout << "3.删除一个电脑部件信息(前往下一级菜单)" << endl;
	cout << "4.查询电脑部件信息(前往下一级菜单)" << endl;
	cout << "5.对电脑部件进行排序(前往下一级菜单)" << endl;
	cout << "88.结束本系统" << endl;
	cout << endl;
	cout << "请输入对应功能的数字:";
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
				cout << "                                         感谢您的使用，下次再见" << endl;
				Divide();
				return nullptr;
			}
			else {
				if (Head[0]->GetFlag() == true) {
					cout << "检测到文件未保存,是否要保存:";
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
				cout << "                                       感谢您的使用，下次再见" << endl;
				Divide();
				return nullptr;
			}
		}
		else {
			cout << "请输入正确数字:";
		}
	}
	return Head;
}


void Menu2(Computer**& Head) {
	cout << "                                               查询功能" << endl;
	if (Back(Head)) {
		return;
	}
	if (Head == nullptr) {
		cout << "                                   还没有数据可以查询,请先填写数据!!!!!" << endl;
		Head = Menu(Head);
		return;
	}
	else {
		if (Head[0]->GetAmount() == 0) {
			cout << "当前数据已被全部清空,请先输入数据!!!!!" << endl;
			return;
		}
		cout << "1.按类型查询" << endl;
		cout << "2.按价格查询" << endl;
		cout << "3.按部件名查询" << endl;
		cout << "4.按分类号查询" << endl;
		cout << "5.按型号查询" << endl;
		cout << "6.按报价时间查询" << endl;
		cout << "7.返回上一步" << endl;
		cout << endl;
		cout << "请输入想要实现功能前的数字:";
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
				cout << "请输入正确数值:";
			}
		}
		return;
	}
}


void Menu3() {
	cout << "                                               排序功能" << endl;
	cout << "1.按类型排序" << endl;
	cout << "2.按价格排序" << endl;
	cout << "3.按部件名排序" << endl;
	cout << "4.按分类号排序" << endl;
	cout << "5.按型号排序" << endl;
	cout << "6.按报价时间排序" << endl;
	cout << endl;
	cout << "请输入想要实现功能前的数字:";
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
		cout << "是否需要输出数据列表:";
		cin >> TF;
		if (TF == "y" || TF == "Y") {
			for (int i = 0; i < Head[0]->GetAmount(); i++) {
				cout << "No." << i + 1 << endl;
				cout << "部件名:" << Head[i]->GetComponent() << '\t';
				cout << "价格为:" << Head[i]->GetPrice() << endl;
				cout << "型号为:" << Head[i]->GetType() << '\t';
				cout << "分类号为:" << Head[i]->GetClass() << endl;
				cout << "厂商为:" << Head[i]->GetManufacturer() << '\t';
				cout << "报价时间为:" << Head[i]->GetTime() << endl;
			}
		}
	}
	else {
		for (int i = 0; i < Head[0]->GetAmount(); i++) {
			cout << "No." << i + 1 << endl;
			cout << "部件名:" << Head[i]->GetComponent() << '\t';
			cout << "价格为:" << Head[i]->GetPrice() << endl;
			cout << "型号为:" << Head[i]->GetType() << '\t';
			cout << "分类号为:" << Head[i]->GetClass() << endl;
			cout << "厂商为:" << Head[i]->GetManufacturer() << '\t';
			cout << "报价时间为:" << Head[i]->GetTime() << endl;
		}
	}
	return;
}

void Save(Computer**& Head,bool Flag) {
	if (Flag) {
		cout << "是否要保存:";
		string TF;
		cin >> TF;
		if (TF == "y" || TF == "Y") {
			fstream outfile("Computer.txt", ios::out | ios::_Nocreate | ios::trunc);
			if (!outfile) {
				cerr << "Open Error" << endl;
				return;
			}
			outfile << "电脑部件总数为:" << Head[0]->GetAmount() << endl;
			for (int i = 0; i < Head[0]->GetAmount(); i++) {
				outfile << endl;
				outfile << "     第" << i + 1 << "个电脑部件信息" << endl;
				outfile << "部件名:" << Head[i]->GetComponent() << endl;
				outfile << "价格:" << Head[i]->GetPrice() << endl;
				outfile << "类型:" << Head[i]->GetType() << endl;
				outfile << "分类号:" << Head[i]->GetClass() << endl;
				outfile << "厂商:" << Head[i]->GetManufacturer() << endl;
				outfile << "报价时间:" << Head[i]->GetTime() << endl;
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
		outfile << "电脑部件总数为:" << Head[0]->GetAmount() << endl;
		for (int i = 0; i < Head[0]->GetAmount(); i++) {
			outfile << endl;
			outfile << "     第" << i + 1 << "个电脑部件信息" << endl;
			outfile << "部件名:" << Head[i]->GetComponent() << endl;
			outfile << "价格:" << Head[i]->GetPrice() << endl;
			outfile << "类型:" << Head[i]->GetType() << endl;
			outfile << "分类号:" << Head[i]->GetClass() << endl;
			outfile << "厂商:" << Head[i]->GetManufacturer() << endl;
			outfile << "报价时间:" << Head[i]->GetTime() << endl;
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
			cout << "请不要调戏系统,并重新输入数据(正浮点数):";
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
			cout << "请不要调戏系统,并输入正确数值(正整数):";
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
	cout << "  请输入年份:";
	while (1) {
		ToInt(Int);
		if (Int > 2022) {
			cout << "  年份未到!!!!!" << endl;
			cout << "  请重新输入:";
		}
		else {
			break;
		}
	}
	for (int i = Int; i > 0; i = i / 10) {
		int m = i % 10;
		Year = char(m + 48) + Year;
	}
	cout << "  请输入月份:";
	while (1) {
		ToInt(Int);
		if (Int > 12|| Int == 0) {
			cout << "  没有这个月!!!!!" << endl;
			cout << "  请重新输入:";
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
	cout << "  请输入日:";
	while (1) {
		ToInt(Int);
		if (Int > 31|| Int == 0) {
			cout << "  没有这个日!!!!!" << endl;
			cout << "  请重新输入:";
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
			cout << "请不要调戏系统，再给你一次机会" << endl;
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
			cout << "请不要调戏系统，再给你一次机会(取值范围" << Min << "-" << Max << ",其中0不可取)" << endl;
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
	cout << "是否返回上一步:";
	string Back;
	cin >> Back;
	if (Back == "y" || Back == "Y") {
		Menu(Head);
		return true;
	}
	return false;
}