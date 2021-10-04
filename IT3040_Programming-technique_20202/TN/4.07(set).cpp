 #include <iostream>
 #include <set>

 using namespace std;

template<class T>
set<T> set_union(const set<T>& a, const set<T>& b) {
    set<T> c(a.begin(), a.end());
    for (T tmp : b)
        c.insert(tmp);
    return c;
}

template<class T>
set<T> set_intersection(const set<T>& a, const set<T>& b) {
    set<T> c;
    for (T tmp : a)
        if (b.find(tmp) != b.end())
            c.insert(tmp);
    return c;
}

 template<class T>
 void print_set(const set<T> &a) 
 {
     for (const T &x : a) {
         std::cout << x << ' ';
     }
     std::cout << std::endl;
 }

int main() {
    cout << "\nNguyen Van Thinh 20194178\n" << endl;
     std::set<int> a = {1, 2, 3, 5, 7};
     std::set<int> b = {2, 4, 5, 6, 9};
     std::set<int> c = set_union(a, b);
     std::set<int> d = set_intersection(a, b);

     cout << "Union: "; 
     print_set(c);
     std::cout << "Intersection: "; 
     print_set(d);

     return 0;
 }
