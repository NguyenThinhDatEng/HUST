//
#include <iostream>
#include <iomanip>
using namespace std;

int n;
int X[100], Y[100]; //# Lưu tọa độ các bước di chuyển của quân mã
int mark[100][100]; //# Đánh dấu vị trí các ô mà quân mã đã di chuyển qua
int numberOfTiles;  //# Total number of step in a chess board
int step = 2;  // step n;

//# Mảng hx, hy mô tả 8 vị trí quân mã có thể di chuyển kể từ vị trí hiện tại
const int hx[] = { 1, 1, 2, 2, -1, -1, -2, -2 };
const int hy[] = { 2, -2, 1, -1, 2, -2, 1, -1 };

//# In ra dãy các di chuyển tìm được
void print_sol() {
    for (int j = 1; j <= numberOfTiles; ++j)
       cout << '(' << X[j] << ' ' << Y[j] << ')' << endl;
    exit(0);
}

bool shouldTakeNextStep(int xx, int yy)     // if not to the end, should check steps around
{
    for (int i = 0; i < 8; i++) {
        int x = xx + hx[i];
        int y = yy + hy[i];
        if (x < 1 || y < 1 || x > n || y > n)
            continue;
        if (mark[x][y] == 0)    // if exist a step which haven't visited
            return true;
    }
    return false;
}

inline bool isCandidate(int xx, int yy) {   // ung cu vien
    if (xx < 1 || yy < 1 || xx > n || yy > n || mark[xx][yy] != 0)
        return false;
    return true;
}

// # display every step of the knight
void showChessBoard()
{
    cout << "  ";
    for (int i = 1; i <= n; i++)
        cout << setw(4) << right << i;
    for (int i = 1; i <= n; i++)
    {
        cout << i << " ";
        for (int j = 1; j <= n; j++)
            if (mark[i][j])
                cout << setw(4) << right << mark[i][j];
            else
                cout << setw(4) << right << "";
        cout << endl;
    }
}

//# Thuật toán quay lui
void TRY(int k) {
    for (int i = 0; i < 8; i++) {
        int xx = X[k - 1] + hx[i];
        int yy = Y[k - 1] + hy[i];
        if (isCandidate(xx, yy))
        {
            mark[xx][yy] = step++;
            X[k] = xx;
            Y[k] = yy;
            if (k == numberOfTiles) {
                //showChessBoard();
                print_sol();
            }
            else
                TRY(k + 1);
            mark[xx][yy] = X[k] = Y[k] = 0;
            step--;
            if (shouldTakeNextStep(xx, yy) == false)
                break;
        }
    }
}

int main() {
    //cout << "\nNguyen Van Thinh 20194178\n" << endl;
    cin >> n;
    numberOfTiles = n * n;

    mark[1][1] = 1;
    X[1] = Y[1] = 1;
    TRY(2);

    return 0;
}