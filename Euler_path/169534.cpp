#include<bits/stdc++.h>
using namespace std;

struct graf{
    int n, m;
    vector< set<int> > G;
    vector<int> deg, path;
    int vetex_start = 1;

    graf(int _n, int _m) : n(_n), m(_m) {
        G = vector< set<int> > (n+1);
        deg = vector<int> (n+1);
    } 

    void add_edge(int a, int b) {
        G[a].insert(b); G[b].insert(a);
        deg[a]++;   deg[b]++;
    }

    bool check_if_exists() {
        int uneven = 0, even = 0;
        for(int i = 1; i <= n; i++)
            if(deg[i]&1)
                uneven++, vetex_start = i;
            else
                even++;

        return uneven == 2 or uneven == 0;
    }

    void dfs(int start) {
        while(!G[start].empty()) {
            int x = *G[start].begin();
            G[start].erase(x);
            G[x].erase(start);

            dfs(x);
        }
        path.push_back(start);
    }

    void print_path() {
        if((int)path.size() != m+1) {
            cout << -1;
            return;
        }
        for(auto x : path) 
            cout << x << " ";
    }
};

int main() {
    ios_base::sync_with_stdio(false);   cin.tie(0); cout.tie(0);

    int n, m;   cin >> n >> m;
    graf graph(n, m);

    for(int i = 0; i < m; i++) {
        int a, b;   cin >> a >> b;
        graph.add_edge(a, b);
    }

    if(!graph.check_if_exists()) {
        cout << -1;
    } else {
        graph.dfs(graph.vetex_start);
        graph.print_path();
    }

    return 0;
}
