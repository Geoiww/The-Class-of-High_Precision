#include "High_Precision.h"
#define _CRT_SECURE_NO_WARNINGS

High_Precision::High_Precision()
{
	a = "0";
	is_Neg = 0;
}

High_Precision::High_Precision(string n)
{
	if (n[0] == '-') {
		is_Neg = 1;
		n[0] = 0;
	}
	else {
		is_Neg = 0;
		a = n;
	}
}

High_Precision::High_Precision(int n)
{
	string s = to_string(n);
	if (s[0] == '-') {
		is_Neg = 1;
		s[0] = 0;
	}
	else {
		is_Neg = 0;
		a = s;
	}
}

High_Precision::High_Precision(vector<string> n)
{
	a = n[0];
}

High_Precision::High_Precision(vector<string> n, bool is_neg)
{
	a = n[0];
	is_Neg = is_neg;
}

High_Precision::High_Precision(string n, bool Neg)
{
	if (n[0] == '-') {
		is_Neg = Neg;
		n[0] = 0;
	}
	a = n;
}

int High_Precision::myCompare(string a, string b)
{
	if (a.size() != b.size())//����ַ������Ȳ�ͬ��ô���ȴ���Ǹ����Ǹ���Ĵ��� 
	{
		if (a.size() > b.size())
			return is_Neg ? -1 : 1;
		else
			return is_Neg ? 1 : -1;
	}
	else //����ַ���������ͬ����ͨ��ֱ�ӱȽ��ַ������ֵ������жϴ�С 
	{
		if (a > b)
			return is_Neg ? -1 : 1;
		else if (a == b)
			return 0;
		else
			return is_Neg ? 1 : -1;
	}
}

string High_Precision::myAdd(string a, string b)
{
	int n = max(a.size(), b.size()) + 1;
	vector<int>ans(n, 0);//����һ���㹻�洢��������飬�����λ�����Ϊ λ�������Ǹ�����λ����һ(���ǽ�λ)
	int i = a.size() - 1, j = b.size() - 1, k = n - 1;//�Ӹ�λ��ʼͨ��ģ����ʽ���д����ӷ� 
	while (i >= 0 && j >= 0)//��������δ����ʱ 
	{
		ans[k--] = (a[i--] - '0') + (b[j--] - '0');//���������ǵ�����洢ÿһλ��ӵĽ��ע�⽫�ַ���תΪ�������� 
	}
	//����Ƿ���ĳ�����ĸ�λδ���꽫��ֱ�Ӵ��������� 
	while (j >= 0)
	{
		ans[k--] = (b[j--] - '0');
	}
	while (i >= 0)
	{
		ans[k--] = (a[i--] - '0');
	}
	string c = "";//����һ���ַ���ȥ�洢�� 
	for (int i = n - 1; i > 0; i--)//��Ϊ֮ǰ����ʽ��ÿһλ��û���ǽ�λ�������Ǵ����ʼ����λ 
	{//��Ϊ�Ǽӷ�����н�λ���Ҳ�ͽ�һ 
		if (ans[i] >= 10)//�������10˵��Ӧ�ý�λ��ô�����ô�λ��10���ĸ�һλ��1 
		{
			ans[i] -= 10;
			ans[i - 1]++;
		}
		c.insert(0, 1, ans[i] + '0');//�����Ľ��ת��Ϊ�ַ��������ַ�����λ
	}

	if (ans[0] > 0)//��������λ�Ƿ����0����������û�н�λ��ô��һλ����0���ǾͲ��ش洢������������ַ��� 
	{
		c.insert(0, 1, ans[0] + '0');
	}
	return c;//���ش� 
}

string High_Precision::mySubtract(string a, string b)
{
	string c = "";               //����һ���ַ���ȥ�洢�� 
	if (myCompare(a, b) == 0)      //�ȱȽ�һ��������С����������ֱ�ӷ���0���� 
		return "0";
	if (myCompare(a, b) == -1)//���a<b��ô���ǽ���������ֵͬʱ�ڴ��ַ������ȷ���һ������ 
	{
		swap(a, b);
		c.push_back('-');
	}
	int n = a.size();
	//����һ���㹻�洢���������  ���������λ�����Ϊλ�������Ǹ�����λ�����Ǳ�֤��aΪ�Ĵ������Ծ���a��λ�� 
	vector<int>ans(n, 0);
	int i = a.size() - 1, j = b.size() - 1, k = n - 1;//�Ӹ�λ��ʼģ����ʽ���� 
	int t = 0;//��ʾ��λ�Ľ�λ���  0:�޽�λ   1:�н�λ 
	while (i >= 0)                         //ͬ�ӷ�һ��ģ����������֪��a�Ǵ�������a��������ʽ����� 
	{
		char nowb;//��������ǰλ������������ û����˵������0
		if (j >= 0) nowb = b[j];
		else nowb = '0';
		ans[k] = a[i] - nowb - t;//��Ӧλ���ͬʱ��ȥ��λ�Ľ�λ
		if (ans[k] < 0)//������С��0 �����λ��һλ
		{
			t = 1;
			ans[k] += 10;
		}
		else t = 0;  //�������λ�޽�λ
		k--, i--, j--;  //�����жϸ�һλ
	}
	bool flag = true;//������ӷ���ͬ��λ���ܳ��ֶ���㿪ͷ�����������Ҫ�ҵ���һ������ĵط��ٴ��� 
	for (int i = 0; i < n; i++)
	{
		if (flag && ans[i] == 0)//�����ǰ��Ϊ0��δ������ִ�д������� 
			continue;
		flag = false;        //һ�����������ı�־λ 
		c.push_back(ans[i] + '0');
	}
	return c;              //���ؽ�� 
}

string High_Precision::myMultiply(string a, string b)
{
	if (a == "0" || b == "0")   //������һ��Ϊ0ʱֱ�ӷ���0 
		return "0";
	vector<int>ans;      //����һ���㹻�洢���������
	int n = a.size(), m = b.size();
	ans.resize(n + m, 0);   //�˷������λ�����Ϊ������λ��֮��
	for (int i = 0; i < n; i++) //����Ӹ�λ��ʼ�ʹӵ�λ��ʼ����ν���ǽ�������˵Ľ�������Ƿŵ���Ӧλ�����ȥ����λ���� 
	{                    //�����λ�˰�λ�Ľ�� �Լ�ʮλ��ʮλ�Ľ�� ���ŵ���λ�� 
		for (int j = 0; j < m; j++)
		{
			ans[i + j + 1] += (a[i] - '0') * (b[j] - '0');
		}
	}
	for (int i = n + m - 1; i > 0; i--)      //���Ǵӵ�λ��ʼ����λ 
	{
		if (ans[i] >= 10)            //�������10˵���н�λ���˷��Ľ�λ��һ��ֻ��1 
		{
			ans[i - 1] += (ans[i] / 10);//��λ�ӵ�λ�ĸ��ڸ�λ���� 
			ans[i] %= 10;           //��λ��ʮ���� 
		}
	}
	string c = "";   //�����ַ����洢�� 
	bool flag = true; //ͬ����һ���ҵ���һ������0��λ�ÿ�ʼ���� 
	for (int t = 0; t < n + m; t++)
	{
		if (flag && ans[t] == 0)
			continue;
		flag = false;
		c.push_back(ans[t] + '0');
	}
	return c;      //���ش� 
}

vector<string> High_Precision::myDivide(string a, string b)
{
	vector<string>ans(2, "0");//�ȴ��������ַ����ռ�ȥ�洢��һ������һ�������� 
	if (myCompare(a, b) == -1)   //����������ȳ���С��Ϊ0����Ϊa���ش𰸼��� 
	{
		ans[1] = a;
		return ans;
	}
	else if (myCompare(a, b) == 0)//�������������������Ϊ1����Ϊ0���ش𰸼���
	{
		ans[0] = "1";
		return ans;
	}
	else              //����������Ҫģ���������ʽ�����м��� 
	{
		string res = "";//�����洢�̵��ַ��� 
		int m1 = a.size(), m2 = b.size();
		string a1 = a.substr(0, m2 - 1);
		for (int i = m2 - 1; i < m1; i++)     //ģ����ʽ�Ӹ�λ��ʼ����ȡ����ȥ�����ܼ�������λ�̵ĵ�ǰλ���Ǽ� 
		{
			if (a1 == "0")			     //���a1Ϊ0Ϊ�˷�ֹa1����0��ͷ��������ǽ������ 
				a1 = "";
			a1.push_back(a[i]);      //���Ǵӱ�������ȡһ��������a1������ 
			int e = 0;
			while (myCompare(a1, b) >= 0)//��a1���ڵ��ڳ���ʱ��һֱ��ͬʱe�ۼ� 
			{
				e++;
				a1 = mySubtract(a1, b);
			}
			if (res.size() || e)        //���res��Ϊ�ջ���e��Ϊ0���Ǵ洢�� 
				res.push_back(e + '0');
		}
		ans[0] = res;   //���res������ 
		ans[1] = a1;    //a1�������� 
		return ans;   //���ش� 
	}
}

string High_Precision::myFactorial(string a)
{/*���ǻ��������ø߾��ȼ����ͳ˷�ʵ�ִ����Ľ׳�(�������г�10000���ҵĽ׳�)*/
	if (a == "1")
		return a;
	else
		return myMultiply(a, myFactorial(mySubtract(a, "1")));
}

High_Precision  High_Precision ::operator+(High_Precision f)
{
	if (!is_Neg || !f.is_Neg)
		return High_Precision(myAdd(a, f.a));
	else if (!is_Neg || f.is_Neg)
		return High_Precision(mySubtract(a, f.a));
	else if (is_Neg || f.is_Neg)
		return High_Precision(myAdd(a, f.a), 1);
	else if (is_Neg || !f.is_Neg)
		return High_Precision(mySubtract(f.a, a));
	return High_Precision("NULL");//���ش� 
}

High_Precision  High_Precision ::operator-(High_Precision  f)
{
	if (!is_Neg || !f.is_Neg)
		return High_Precision(mySubtract(a, f.a));
	else if (!is_Neg || f.is_Neg)
		return High_Precision(myAdd(a, f.a));
	else if (is_Neg || f.is_Neg)
		return High_Precision(mySubtract(f.a, a));
	else if (is_Neg || !f.is_Neg)
		return High_Precision(myAdd(a, f.a), 1);
	return High_Precision("NULL");//���ش� 
}

High_Precision  High_Precision ::operator*(High_Precision  f)
{
	if (is_Neg == f.is_Neg)
		return High_Precision(myMultiply(a, f.a), 0);
	else
		return High_Precision(myMultiply(a, f.a), 1);
	return High_Precision("NULL");
}

High_Precision  High_Precision ::operator/(High_Precision  f)
{
	if (is_Neg == f.is_Neg)
		return High_Precision(myDivide(a, f.a), 0);
	else
		return High_Precision(myDivide(a, f.a), 1);
	return High_Precision("NULL");
}

High_Precision  High_Precision ::operator+(int f)
{
	string n = to_string(f);
	return *this + High_Precision(n);
}

High_Precision  High_Precision ::operator-(int f)
{
	string n = to_string(f);
	return *this - High_Precision(n);
}

High_Precision  High_Precision ::operator*(int f)
{
	string n = to_string(f);
	return *this * High_Precision(n);
}

High_Precision  High_Precision ::operator/(int f)
{
	string n = to_string(f);
	return *this / High_Precision(n);
}

High_Precision  High_Precision ::operator=(High_Precision  f)
{
	a = f.a;
	is_Neg = f.is_Neg;
	return *this;
}

High_Precision  High_Precision ::operator=(int f)
{
	string s = to_string(f);
	*this = High_Precision(s);
	return *this;
}

High_Precision High_Precision::operator=(string f)
{
	*this = High_Precision(f);
	return *this;
}

High_Precision High_Precision::operator+=(High_Precision f)
{
	*this = *this + f;
	return *this;
}

High_Precision High_Precision::operator-=(High_Precision f)
{
	*this = *this - f;
	return *this;
}

High_Precision High_Precision::operator*=(High_Precision f)
{
	*this = *this * f;
	return *this;
}

High_Precision High_Precision::operator/=(High_Precision f)
{
	*this = *this / f;
	return *this;
}

High_Precision High_Precision::operator+=(int f)
{
	*this = *this + High_Precision(to_string(f));
	return *this;
}

High_Precision High_Precision::operator-=(int f)
{
	*this = *this - High_Precision(to_string(f));
	return *this;
}

High_Precision High_Precision::operator*=(int f)
{
	*this = *this * High_Precision(to_string(f));
	return *this;
}

High_Precision High_Precision::operator/=(int f)
{
	*this = *this / High_Precision(to_string(f));
	return *this;
}

High_Precision High_Precision::operator++()
{
	High_Precision& n(*this);
	n += 1;
	return *this;
}

High_Precision High_Precision::operator--()
{
	High_Precision& n(*this);
	n -= 1;
	return *this;
}

bool High_Precision::operator>(High_Precision f)
{
	bool n = is_Neg, m = f.is_Neg;
	string a = High_Precision::a, b = f.a;
	if (n == 1 && m == 0)
		return 0;
	else if (n == 0 && m == 1)
		return 1;
	else if (myCompare(a, b) == 1) {
		if (n == 1 && m == 1)
			return 0;
		else
			return 1;
	}
	else if (myCompare(a, b) == -1) {
		if (n == 1 && m == 1)
			return 1;
		else
			return 0;
	}
	else if (myCompare(a, b) == 0)
		return 0;
}

bool High_Precision::operator<(High_Precision f)
{
	bool n = is_Neg, m = f.is_Neg;
	string a = High_Precision::a, b = f.a;
	if (n == 1 && m == 0)
		return 1;
	else if (n == 0 && m == 1)
		return 0;
	else if (myCompare(a, b) == 1) {
		if (n == 1 && m == 1)
			return 1;
		else
			return 0;
	}
	else if (myCompare(a, b) == -1) {
		if (n == 1 && m == 1)
			return 0;
		else
			return 1;
	}
	else if (myCompare(a, b) == 0)
		return -1;
}

bool High_Precision::operator>(int f)
{
	High_Precision n = f;
	return *this > n;
}

bool High_Precision::operator<(int f)
{
	High_Precision n = f;
	return *this < n;
}

int High_Precision::Compare(string a, string b)
{
	return myCompare(a, b);
}

string High_Precision::print()
{
	return a;
}

ostream& operator<<(ostream& os, High_Precision& f)
{
	if (f.is_Neg)
		os << '-';
	os << f.a;
	return os;
}

istream& operator>>(istream& is, High_Precision& f)
{
	string s;
	is >> s;
	f = s;
	return is;
}
