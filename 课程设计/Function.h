#pragma once
void Divide();
void Divide2();
void Add(Computer**&);
void Change(Computer**&);
void Delete(Computer**&);
Computer** Menu(Computer**&);
void Menu2(Computer**&);
void Menu3();
void Title();
void Title2();
void In(fstream& ,Computer**&);
void Show(Computer**&,bool Flag=true);
void Save(Computer**&,bool Flag=true);
void ToDouble(double&);
void ToInt(int&);
void ToTime(string&);
bool CheckInt(int&,string,int min=-1,int max=-1);