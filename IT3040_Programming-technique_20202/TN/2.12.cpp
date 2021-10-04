#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;

typedef struct number
{
	int value;
	int key;
};

void initializeVector(vector <number>& v)
{
	int tmp, tmp1;
	number n;
	while (cin >> tmp && cin >> tmp1)
	{
		n.key = tmp;
		n.value = tmp1;
		v.push_back(n);
	}
}

int main()
{
	vector <number> num;
	initializeVector(num);
	sort(num.begin(), num.end(), [](number n0, number n1) {
		if (n0.value != n1.value)
			return n0.value > n1.value;
		else
			return n0.key > n1.key;
		});
	for (number n : num)
	{
		cout << n.key << " " << n.value;
		cout << endl;
	}
	return 0;
}