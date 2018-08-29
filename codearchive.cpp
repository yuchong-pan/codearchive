#include <bits/stdc++.h>

using namespace std;

namespace graph {
    const int N = 1000000 + 5;
    const long long INFTY = 0x7f7f7f7f7f7f7f7fll;

    bool visited[N];
    long long dist[N];
    vector<pair<int, int>> edges[N];

    void addedge_directed(int u, int v, int w) {
        edges[u].push_back(make_pair(v, w));
    }

    void addedge_undirected(int u, int v, int w) {
        edges[u].push_back(make_pair(v, w));
        edges[v].push_back(make_pair(u, w));
    }

    /**
     * SPFA (Shortest Path Faster Algorithm)
     * assume: no negative cost cycles
     * time complexity: O(|V||E|); O(|E|) on average
     */
    void spfa(int s, int n) {
        for (int i = 1; i <= n; i++) {
            visited[i] = false;
            dist[i] = INFTY;
        }
        queue<int> q;
        visited[s] = true;
        dist[s] = 0;
        q.push(s);
        while (!q.empty()) {
            int x = q.front();
            q.pop();
            visited[x] = false;
            for (auto pr : edges[x]) {
                int y = pr.first, w = pr.second;
                if (dist[x] + w < dist[y]) {
                    dist[y] = dist[x] + w;
                    if (!visited[y]) {
                        visited[y] = true;
                        q.push(y);
                    }
                }
            }
        }
    }
}

int main() {
    return 0;
}
