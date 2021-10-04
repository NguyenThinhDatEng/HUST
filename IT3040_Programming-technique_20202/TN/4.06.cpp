#include<iostream>
#include<vector>
#include<list>
#include<queue>

using namespace std;

void bfs(vector< list<int> > adj) {
    queue<int> Q;
    vector<bool> visited(adj.size(), false);
    Q.push(1); // Bắt đầu từ đỉnh số 1

    while (!Q.empty())
    {
        int u = Q.front();
        if (!visited[u])
        {
            visited[u] = true;
            cout << u << endl;
        }
        if (!adj[u].empty())
        {
            int v = adj[u].front();
            adj[u].pop_front();
            if (!visited[v])
                Q.push(v);
        }
        else
            Q.pop();
    }
}

void main()
{
    cout << "\nNguyen Van Thinh 20194178\n" << endl;
    int n = 7;
    vector< list<int> > adj;
    adj.resize(n + 1);
    adj[1].push_back(2);
    adj[2].push_back(4);
    adj[1].push_back(3);
    adj[3].push_back(4);
    adj[3].push_back(5);
    adj[5].push_back(2);
    adj[2].push_back(7);
    adj[6].push_back(7);
    bfs(adj);
}