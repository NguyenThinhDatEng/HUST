#include <iostream>
#include <queue>
#include <climits>

using namespace std;

struct cmp {
    bool operator() (pair<int, int> a, pair<int, int> b)
    {
        return a.second > b.second;
    }
};

vector<int> dijkstra(const vector< vector< pair<int, int> > >& adj) {
    priority_queue<pair<int, int>, vector<pair<int, int> >, cmp> pq;
    vector<int> dist(adj.size());
    int dist_size = dist.size();

    for (int i = 0; i < dist_size; i++) {
        dist[i] = INT_MAX;
    }
    dist[0] = 0; // khoang cach tu 0 -> 0 = 0

    // khoi tao gia tri cho hang doi uu tien
    for (int i = 0; i < dist_size; i++) {
        pq.push({ i, dist[i] });
    }
    // neu cung do uu tien sap xep thu tu trong queue

    while (!pq.empty()) 
    {
        pair<int, int> u_pair = pq.top();
        pq.pop();
        int u = u_pair.first; // lay ra dinh co thu tu uu tien nhat trong hang doi

        for (auto v_pair : adj[u]) {
            int v = v_pair.first;
            int weight = v_pair.second;

            if (dist[v] > dist[u] + weight) {
                dist[v] = dist[u] + weight;
                pq.push({ v, dist[v] });
            }
        }
    }

    return dist;
}
 int main() {
     cout << "\nNguyen Van Thinh 20194178\n" << endl; 
     int n = 9;
     vector< vector< pair<int, int> > > adj(n);
     auto add_edge = [&adj] (int u, int v, int w) {
         adj[u].push_back({v, w});
         adj[v].push_back({u, w});
     };

    add_edge(0, 1, 4);
    add_edge(0, 7, 8);
    add_edge(1, 7, 11);
    add_edge(1, 2, 8);
    add_edge(2, 3, 7);
    add_edge(2, 8, 2);
    add_edge(3, 4, 9);
    add_edge(3, 5, 14);
    add_edge(4, 5, 10);
    add_edge(5, 6, 2);
    add_edge(6, 7, 1);
    add_edge(6, 8, 6);
    add_edge(7, 8, 7);

     vector<int> distance = dijkstra(adj);
     for (int i = 0; i < distance.size(); ++i) {
         cout << "distance " << 0 << "->" << i << " = " << distance[i] << endl;
     }

     return 0;
 }
