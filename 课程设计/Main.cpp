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
			cout << "!!!!!!ʹ�ô�������һ����ֵ,ǿ���˳�!!!!!" << endl;
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
		cout << "�Ƿ��������ʹ��(YΪ��,����Ϊ��):";
		string End;
		cin >> End;
		if (End == "y" || End == "Y") {
			if (Head[0]->GetFlag() == true) {
				cout << "��⵽�ļ�δ���棬�Ƿ�Ҫ����(YΪ��,����Ϊ��):";
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