#include<iostream>

int H(int n) {
	if (n < 5) return n;
	else
		return H(n - 4) + H(n - 3) - H(n - 2) + H(n - 1);
}
auto sum(int n) {
	long long t = 0;
	for (int i = 1; i <= n; i++)
		t += H(i);
	return t;
}
// Khử đệ quy
long long Tong(int n)
{
	int h1 = 1, h2 = 2, h3 = 3, h4 = 4;
	int h;
	long long t = 10;
	if (n == 1)  return 1;
	else if (n == 2) return 3;
	else if (n == 3) return 6;
	else if (n == 4) return 10;
	else
	{
		for (int i = 5; i <= n; i++) {
			h = h1 + h2 - h3 + h4;
			t += h;
			h1 = h2;
			h2 = h3;
			h3 = h4;
			h4 = h;
		}
	}
	return t;
}

// Dãy 2: 1, 2, 3, 4, 6, 9, 14, 21, 32, 48, ...
// tương tự với quy luật H(n - 4) - H(n - 3) + H(n - 2) + H(n - 1) = H(n)
