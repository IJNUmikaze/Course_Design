#include<iostream>
#include<string>
#include<fstream>
#include"Computer.h"
#include"Function.h"
#include"Function.cpp"
using namespace std;
int main() {
	int Count = 1;
	Title2();
	Computer** Head = nullptr;
	cout << "�Ƿ�̳���һ�ε��ļ�:";
	string str;
	cin >> str;
	if (str == "y" || str == "Y") {
		fstream input("Computer.txt", ios::in|ios::_Nocreate);
		if (!input) {
			cerr << "Open Error" << endl;
		}
		else {
			In(input,Head);
			input.close();
			Show(Head);
		}
	}
	while (1) {
		Count++;
		if (Count == 20) {
			cout << "ǿ���˳�!!!!!" << endl;
			break;
		}
		Head = Menu(Head);
		if (Head == nullptr) {
			break;
		}
		cout << endl;
		cout << "�Ƿ��������ʹ��:";
		string End;
		cin >> End;
		if (End == "y" || End == "Y") {
			if (Head[0]->GetFlag() == true) {
				cout << "��⵽�ļ�δ���棬�Ƿ�Ҫ����:";
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
			cout << "                                         ��л����ʹ�ã��´��ټ�" << endl;
			Divide();
			break;
		}
	}
	return 0;
}