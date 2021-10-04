 #include <iostream>
 #include <cmath>
 #include <iomanip>
 #include <utility>
 using namespace std;
 using Point = pair<double, double>;

double area(Point a, Point b, Point c) {
    Point AB = { b.first - a.first, b.second - a.second };
    Point AC = { c.first - a.first, c.second - a.second };
    return abs(AB.first * AC.second - AB.second * AC.first) / 2;
}

 int main() {
     cout << "\nNguyen Van Thinh 20194178\n" << endl;
     cout << setprecision(2) << fixed;
     cout << area({1, 2}, {2.5, 10}, {15, -5.25}) << endl;
     return 0;
 }