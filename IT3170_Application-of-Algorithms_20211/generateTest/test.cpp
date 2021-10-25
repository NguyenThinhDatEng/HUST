#include <bits/stdc++.h>

using namespace std;
int n, tmp;
vector <int> arr;
vector <pair <int, int> > mark; // luu gia tri va index
vector <int> ans;

int main(){
    ios_base :: sync_with_stdio (0);
    cin.tie (0); cout.tie (0);
    // freopen("input.txt", "r", stdin);
    cin >> n;
    for (int i = 0; i < n; i++){
        cin >> tmp;
        arr.push_back(tmp);
    }
    /* 
        voi nhung so nho hon tat ca cac so trong mark thi in ra -1 va them vao mark
        nguoc lai thi khong can vi da co so nho hon so dang xet o phia sau, nen k can xet den so hien tai
    */
    mark.push_back({arr[n-1], n-1});
    ans.push_back(-1);
    int distance;
    int len = 1; // do dai cua mark
    int start, end, mid;
    for (int i = n-2; i >= 0 ; i--){
        distance = -1;
        //binary search
        start = 0, end = len;
        while (start < end){
            mid = (start + end) / 2;
            if (arr[i] > mark[mid].first){
                distance = mark[mid].second - i - 1;
                end = mid;
            } 
            else {
                start = mid + 1;
            }
        }

        if (distance == -1){
            mark.push_back({arr[i], i});
            len++;
        } 
        ans.push_back(distance);
    }

    // in ket qua
    for (int i = n -1; i >= 0; i--){
        cout << ans[i] << " ";
    }
    
    // fclose(stdin);
    return 0;
}