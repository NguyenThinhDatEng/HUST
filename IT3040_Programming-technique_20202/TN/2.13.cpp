#include<iostream>
#include<string>
#include<ostream>

using namespace std;

typedef struct bigNum {
	char sign;
	string num;
};

void intitialize_2_bigNum(bigNum& a, bigNum& b);

void standardized_string_length(string& a, string& b);

void sum(bigNum& a, bigNum& b, bigNum& c);

void sub(bigNum& a, bigNum& b, bigNum& c);

void multi(bigNum& a, bigNum& b, bigNum& c);

bigNum operator + (bigNum& a, bigNum& b);

bigNum operator - (bigNum& a, bigNum& b);

bigNum operator * (bigNum& a, int n);

bigNum operator * (bigNum& a, bigNum& b);

ostream& operator << (ostream& out, const bigNum& a);

int main()
{
	bigNum a, b;
	intitialize_2_bigNum(a, b);

	bigNum c = a * b;
	bigNum tmp = a * 3;
	c = c - tmp;
	tmp = b * 4;
	c = c + tmp;
	cout << c;
	return 0;
}

void intitialize_2_bigNum(bigNum& a, bigNum& b)
{
	string A, B;	// big integer numbers
	cin >> A >> B;

	// take sign and value of big integer number
	a.sign = A.at(0);
	a.num = A.substr(1);

	b.sign = B.at(0);
	b.num = B.substr(1);
}

void standardized_string_length(string& a, string& b)
{
	int difference = a.size() - b.size();	// Length difference between the 2 strings
	if (difference != 0)
	{
		int tmpDiff = abs(difference);	// convert to non_negative
		int i = 0;			// index of string zero
		string zero = "";	// string "00000...."

		do {
			zero += "0";
			i++;
		} while (i < tmpDiff);

		if (difference < 0)
			a = zero + a;
		else
			b = zero + b;
	}
}

void sum(bigNum& a, bigNum& b, bigNum& c)
{
	int i = a.num.size();	// practice calculation from the end of string
	int tmp;		// save result
	int surplus = 0;	// memory number
	do
	{
		i--;
		tmp = surplus + a.num.at(i) - '0' + b.num.at(i) - '0';
		c.num = to_string(tmp % 10) + c.num;
		if (tmp >= 10)
			surplus = 1;
		else
			surplus = 0;

	} while (i > 0);
	if (surplus == 1) c.num = "1" + c.num;
}

void sub(bigNum& a, bigNum& b, bigNum& c) {
	int i = a.num.size();	// practice calculation from the end of string
	int tmp;	// save result
	int memory = 0;	// memory number
	do {
		i--;
		char ca = a.num.at(i);
		char cb = b.num.at(i) + memory;
		if (ca >= cb)
		{
			c.num = to_string(ca - cb) + c.num;
			memory = 0;
		}
		else
		{
			c.num = to_string(ca + 10 - cb) + c.num;
			memory = 1;
		}
	} while (i > 0);
	if (c.num.at(0) == '0') c.num = c.num.substr(1);
}

void multi(bigNum& a, bigNum& b, bigNum& c)
{
	bigNum tmp;

	string zeroString = "0";
	int index = b.num.size() - 2;

	do
	{
		int n = b.num.at(index) - '0';
		if (n != 0)
		{ 
			tmp = a * n;
			tmp.sign = '1';
			tmp.num += zeroString;
			c = c + tmp;
		}
		zeroString += "0";
		index--;
	} while (index >= 0);
}

bigNum operator + (bigNum& a, bigNum& b) {
	standardized_string_length(a.num, b.num);

	bigNum c;
	c.num = "";

	if (a.sign != b.sign)
	{
		int cmp = a.num.compare(b.num);
		if (cmp > 0)
		{
			c.sign = a.sign;
			sub(a, b, c);
		}
		else
			if (cmp < 0)
			{
				c.sign = b.sign;
				sub(b, a, c);
			}
			else
				c.sign = '0';
		return c;
	}

	c.sign = a.sign;
	sum(a, b, c);
	return c;
}

bigNum operator - (bigNum& a, bigNum& b) {
	standardized_string_length(a.num, b.num);

	bigNum c;
	c.num = "";

	if (a.sign != b.sign)
	{
		c.sign = a.sign;
		sum(a, b, c);
		return c;
	}

	int cmp = a.num.compare(b.num);
	if (cmp > 0)
	{
		c.sign = a.sign;
		sub(a, b, c);
	}
	else
		if (cmp < 0)
		{
			c.sign = b.sign;
			sub(b, a, c);
		}
		else
			c.sign = '0';
	return c;
}

bigNum operator * (bigNum& a, bigNum& b)
{
	bigNum c;
	if (a.num.size() >= b.num.size())
	{
		c = a * (b.num.back() - '0');
		c.sign = '1';
		multi(a, b, c);
	}
	else
	{
		c = b * (a.num.back() - '0');
		c.sign = '1';
		multi(b, a, c);
	}
	if (a.sign != b.sign)
		c.sign = '0';
	return c;
}

bigNum operator * (bigNum& a, int n)
{
	bigNum c;
	c.sign = a.sign;
	c.num = "";
	int index = a.num.size();
	int memoryVarMulti = 0;
	int tmp;
	do {
		index--;
		tmp = n * (a.num.at(index) - '0') + memoryVarMulti;
		if (tmp >= 10)
			memoryVarMulti = tmp / 10;
		else
			memoryVarMulti = 0;
		c.num = to_string(tmp % 10) + c.num;
	} while (index > 0);
	if (memoryVarMulti != 0) c.num = to_string(memoryVarMulti) + c.num;
	return c;
}

ostream& operator << (ostream& out, const bigNum& a)
{
	out << "\n" << a.sign + a.num << endl;
	return out;
}