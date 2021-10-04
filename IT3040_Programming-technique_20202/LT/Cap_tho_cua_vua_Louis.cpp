//
#include <iostream>
#include <vector>

using namespace std;
vector<int> pairsOfleverets;

int numberOfPairsOfRabbits(int month)
{
	if (month < 3) return 1;
	return numberOfPairsOfRabbits(month - 1) + numberOfPairsOfRabbits(month - 2);
}

int calculateMoney(int month, int money)
{
	if (month < 12) return 0;
	if (month == 12) return money + 10;
	money += pairsOfleverets.at(month - 11) * 10;
	return calculateMoney(month - 1, money);
}

int main()
{
	cout << "\nNguyen Van Thinh 20194178\n" << endl;
	int n;
	cout << "Enter month: ";
	cin >> n;
	cout << "The number of pairs of rabbits after " << n << " months : ";
	cout << numberOfPairsOfRabbits(n) << endl;

	cout << "Enter month: n = ";
	cin >> n;
	int m;
	cout << "Enter the number of pairs of rabbits: m = ";
	cin >> m;
	pairsOfleverets.push_back(0);	// don't have rabbits
	pairsOfleverets.push_back(1);	// month 1st
	pairsOfleverets.push_back(0);	// month 2nd	

	for (int i = 3; i <= 4; i++)
		pairsOfleverets.push_back(numberOfPairsOfRabbits(i) - numberOfPairsOfRabbits(i - 1));	// from month 3th to month 4th
	for (int i = 5; i <= n; i++)
		pairsOfleverets.push_back(pairsOfleverets.at(i - 2) + pairsOfleverets.at(i - 1));
	cout << "amount earned: ";
	cout << m * calculateMoney(n, 0) << "$";

	cout << "\n" << endl;
	return 0;
}