#include"High_Precision.h"
#include<iostream>
using namespace std;

High_Precision A(High_Precision n)
{
	High_Precision a;
	a = 1;
	for (High_Precision i = 1; i < n; ++i) {
		a *= i;
	}
	return a;
}

int main()
{
	High_Precision  n;
	High_Precision a;
	//cin >> a >> n;
	string b;
	cin >> a >> n;
	a = a - n;
	cout << a;
	//n = A(a);
	//cout << n;
	return 0;
}