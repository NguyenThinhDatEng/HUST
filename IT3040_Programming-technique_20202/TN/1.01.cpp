#include<iostream>

using namespace std;

int main()
{
    int x, y, z;
    int* ptr;
    cout << "Enter three integers: ";
    cin >> x >> y >> z;
    cout << "\nThe three integers are:\n";
    ptr = &x;
    cout << *ptr << "\n";

    ptr = &y;
    cout << *ptr << "\n";

    ptr = &z;
    cout << *ptr;
	return 0;
}