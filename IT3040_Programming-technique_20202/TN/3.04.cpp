#include <iostream>

using namespace std;

int n;          //# the number of elements
int a[1000];    //# input Array
int mem[1000];  //# mảng ghi nhớ lời giải các bài toán con đã được giải

void init() {
    memset(mem, 0, sizeof(mem));
}

//# Quy hoạch động, 
//# Hàm lis(i) trả về độ dài dãy con tăng dài nhất kết thúc bởi a[i]
int lis(int i) {
    int j = 0;
    do
    {
        if (a[i] > a[j])
        {
            int tmp = mem[j] + 1;
            if (mem[i] < tmp)
                mem[i] = tmp;
        }
        j++;
    } while (j < i);
    if (mem[i] == 0) mem[i] = 1;
    return mem[i];
}

//# Truy vet loi giai
void trace(int i) {
    for (int j = 0; j < i; j++) {
        if (a[j] < a[i] && mem[i] == 1 + mem[j]) {
            trace(j);
            break;
        }
    }
    cout << a[i] << " ";
}

int main() {
    cout << "\nNguyen Van Thinh 20194178\n" << endl;
    init();

    cin >> n;
    for (int i = 0; i < n; i++)
        cin >> a[i];

    int res = 1, pos = 0;   // position
    mem[0] = 1;

    for (int i = 1; i < n; i++) {
        if (res < lis(i)) {
            res = lis(i);
            pos = i;
        }
    }

    cout << res << endl;
    trace(pos);

    return 0;
}