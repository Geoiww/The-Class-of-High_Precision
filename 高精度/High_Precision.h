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
	string print();//临时用的输出函数
private:
	int myCompare(string a, string b);			//大数比较设定a>b返回1 a<b返回-1 a=b返回0 
	string myAdd(string a, string b);			//高精度加法 
	string mySubtract(string a, string b);		//高精度减法(整体思想同加法) 
	string myMultiply(string a, string b);		//高精度乘法 
	vector<string> myDivide(string a, string b);//高精度除法
	string myFactorial(string a);				//高精度阶乘 
	string a;
	bool is_Neg;
};

