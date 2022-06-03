#include<iostream>
#include<string>
#include<fstream>
#include"Computer.h"
#include"Function.h"
#include"Function.cpp"
using namespace std;
int main() {
	int Count = 1;
	Computer** Head = nullptr;
	Default(Head);
	while (1) {
		Count++;
		if (Count == 50) {
			cout << "!!!!!!使用次数到达一定数值,强制退出!!!!!" << endl;
			if (Head != nullptr) {
				Save(Head);
			}
			break;
		}
		Head = Menu(Head);
		if (Head == nullptr) {
			break;
		}
		cout << endl;
		cout << "是否结束本次使用(Y为是,其余为否):";
		string End;
		cin >> End;
		if (End == "y" || End == "Y") {
			if (Head[0]->GetFlag() == true) {
				cout << "检测到文件未保存，是否要保存(Y为是,其余为否):";
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