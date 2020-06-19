/*
 * Author: Sam Henry
 * Date: October 1, 2019
 * 
 * Dinic's algorithm for max flow min cost.
 * Complexity: O(V^2 * E)
 */

#include <iostream>
#include <vector>
#include <queue>
#include <climits>
using namespace std; 

#define MAXN 5001
#define INF 0x7FFFFFFF
typedef long long int ll;

struct Edge {
    int v;
    ll flow;
    ll cap;
    int rev;
};

int n, m;
vector<Edge> adj[MAXN];
int level[MAXN];
int start[MAXN];

inline void addEdge(int u, int v, ll cap) {
    adj[u].push_back({v, 0, cap, (int) adj[v].size()});
    adj[v].push_back({u, 0, 0, (int) adj[u].size() - 1});
}

bool computeLevels(int s, int t) {
    fill(level, level + n, -1);
    level[s] = 0;
    queue<int> bfs({s});
    while (!bfs.empty()) {
        int u = bfs.front(); bfs.pop();
        for (int i = 0; i < adj[u].size(); i++) {
            Edge &e = adj[u][i];
            if (level[e.v] < 0 and e.flow < e.cap) {
                level[e.v] = level[u] + 1;
                bfs.push(e.v);
            }
        }
    }
    return level[t] >= 0;
}

ll sendFlow(int u, int t, ll flow) {
    if (u == t) return flow;
    for (; start[u] < adj[u].size(); start[u]++) {
        Edge &e = adj[u][start[u]];
        if (level[e.v] == level[u] + 1 and e.flow < e.cap) {
            ll curFlow = min(flow, e.cap - e.flow);
            ll tempFlow = sendFlow(e.v, t, curFlow);
            if (tempFlow > 0) {
                e.flow += tempFlow;
                adj[e.v][e.rev].flow -= tempFlow;
                return tempFlow;
            }
        }
    }
    return 0;
}

ll dinic(int s, int t) {
    if (s == t) return 0;
    ll total = 0;
    while (computeLevels(s, t)) {
        fill(start, start + n, 0);
        while (ll flow = sendFlow(s, t, LLONG_MAX))
            total += flow;
    }
    return total;
}

int main() {
    ios::sync_with_stdio(false);

    cin >> n >> m;
    while (m--) {
        int u, v; ll c; cin >> u >> v >> c;
        addEdge(--u, --v, c);
    }

    cout << dinic(0, n-1) << endl;

    return 0; 
} 
