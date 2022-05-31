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
	cout << "是否继承上一次的文件:";
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
			cout << "强制退出!!!!!" << endl;
			break;
		}
		Head = Menu(Head);
		if (Head == nullptr) {
			break;
		}
		cout << endl;
		cout << "是否结束本次使用:";
		string End;
		cin >> End;
		if (End == "y" || End == "Y") {
			if (Head[0]->GetFlag() == true) {
				cout << "检测到文件未保存，是否要保存:";
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
			cout << "                                         感谢您的使用，下次再见" << endl;
			Divide();
			break;
		}
	}
	return 0;
}