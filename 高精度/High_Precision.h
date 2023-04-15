#include<iostream>
#include<vector>
#include<string>
#include<utility>
#pragma once
using namespace std;

class High_Precision
{
public:
	High_Precision();
	High_Precision(string);
	High_Precision(int);
	High_Precision(vector<string>);
	High_Precision(vector<string>, bool);
	High_Precision(string, bool);
	High_Precision  operator +(High_Precision);
	High_Precision  operator -(High_Precision);
	High_Precision  operator *(High_Precision);
	High_Precision  operator /(High_Precision);
	High_Precision  operator +(int);
	High_Precision  operator -(int);
	High_Precision  operator *(int);
	High_Precision  operator /(int);
	/*friend int operator +(High_Precision );
	friend int operator -(High_Precision );
	friend int operator *(High_Precision );
	friend int operator /(int,High_Precision );*/
	High_Precision  operator =(High_Precision);
	High_Precision  operator =(int);
	High_Precision  operator =(string);
	friend ostream& operator<<(ostream& os, High_Precision&);
	friend istream& operator>>(istream& is, High_Precision&);
	High_Precision operator +=(High_Precision);
	High_Precision operator -=(High_Precision);
	High_Precision operator *=(High_Precision);
	High_Precision operator /=(High_Precision);
	High_Precision operator +=(int);
	High_Precision operator -=(int);
	High_Precision operator *=(int);
	High_Precision operator /=(int);
	High_Precision operator ++();
	High_Precision operator --();
	bool operator >(High_Precision);
	bool operator <(High_Precision) const;
	bool operator >(int);
	bool operator <(int);
	int Compare(string, string);
	string print();//��ʱ�õ��������
private:
	int myCompare(string a, string b);			//�����Ƚ��趨a>b����1 a<b����-1 a=b����0 
	string myAdd(string a, string b);			//�߾��ȼӷ� 
	string mySubtract(string a, string b);		//�߾��ȼ���(����˼��ͬ�ӷ�) 
	string myMultiply(string a, string b);		//�߾��ȳ˷� 
	vector<string> myDivide(string a, string b);//�߾��ȳ���
	string myFactorial(string a);				//�߾��Ƚ׳� 
	string a;
	bool is_Neg;
};

