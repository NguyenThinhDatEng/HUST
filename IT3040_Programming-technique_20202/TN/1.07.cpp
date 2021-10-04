#include<iostream>

using namespace std;

int* a;
int n, tmp;

int main() {
    cout << "Enter the number of elements: ";
    cin >> n;

    //#Allocate memory
    a = new int[n];

    for (int i = 0; i < n; i++)
        cin >> *(a + i);

    cout << "The input array is: \n";
    for (int i = 0; i < n; i++)
        cout << *(a + i) << " ";
    cout << endl;

    //#Sort array
    for (int i = 0; i < n - 1; i++)
        for (int j = i + 1; j < n; j++)
            if (a[j] < a[i])
            {
                int temp = a[i];
                a[i] = a[j];
                a[j] = temp;
            }

    printf("The sorted array is: \n");
    for (int i = 0; i < n; i++)
        cout << *(a + i) << " ";
    cout << "\n";

    delete[] a;
    return 0;
}