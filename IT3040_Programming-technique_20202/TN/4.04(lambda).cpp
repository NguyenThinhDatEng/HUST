#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

void print_vector(const vector<int>& a) {
    for (int v : a) cout << v << ' ';
    cout << endl;
}

void delete_even(vector<int>& a) {
    for (int i = 0; i < a.size(); i++)
        if (a.at(i) % 2 == 0)
        {
            a.erase(a.begin() + i);
            i--;
        }
}

void sort_decrease(vector<int>& a) {
    sort(a.begin(), a.end(), [](int front, int back)
        {
            return front > back;
        });
}

vector<int> merge_vectors(const vector<int>& a, const vector<int>& b) {
    vector<int> c;
    int indexA = 0, indexB = 0;
    int varA, varB;
    do
    {
        varA = a.at(indexA);
        varB = b.at(indexB);
        if (varA > varB)
        {
            c.push_back(varA);
            ++indexA;
        }
        else
        {
            c.push_back(varB);
            ++indexB;
        }
    } while (indexA != a.size() && indexB != b.size());
    if (indexA == a.size())
        for (int i = indexB; i < b.size(); i++)
            c.push_back(b.at(i));
    if (indexB == b.size())
        for (int i = indexA; i < a.size(); i++)
            c.push_back(a.at(i));
    return c;
}

int main() {
    cout << "\nNguyen Van Thinh 20194178\n" << endl;
    int m, n, u;
    std::vector<int> a, b;

    std::cin >> m >> n;
    for (int i = 0; i < m; i++) {
        std::cin >> u;
        a.push_back(u);
    }
    for (int i = 0; i < n; i++) {
        std::cin >> u;
        b.push_back(u);
    }

    delete_even(a);
    cout << "Odd elements of a: ";
    print_vector(a);

    delete_even(b);
    cout << "Odd elements of b: ";
    print_vector(b);

    sort_decrease(a);
    cout << "Decreasingly sorted a: ";
    print_vector(a);

    sort_decrease(b);
    cout << "Decreasingly sorted b: ";
    print_vector(b);

    vector<int> c = merge_vectors(a, b);
    cout << "Decreasingly sorted c: ";
    print_vector(c);

    return 0;
}