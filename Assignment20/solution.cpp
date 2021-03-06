// https://github.com/algo-seacow/NCTU-ItoA-2020-Fall/tree/master/1139
// maximum flow (augmenting path)
// Edmonds Karp
#include <cstdio>
#include <vector>
#include <queue>

using namespace std;

struct edge {
    int from, to, capacity;
};

class flow {
    public:
        // size: the number of normal vertex (without source and sink)
        // s: index of the source
        // t: index of the sink
        flow(int size, int s, int t) : adj_list(size + 2), size(size + 2), s(s), t(t), f(0) {}

        void addedge(int from, int to, int capacity) {
            adj_list[from].push_back({to, edges.size()});
            edges.push_back({from, to, capacity});

            adj_list[to].push_back({from, edges.size()});
            edges.push_back({to, from, 0});
        }

        int max_flow() {
            vector<int> dis, through;
            while(augmenting_path(dis, through)) {
                int bottleneck = 1;
                int temp = t;
                while(temp != s) {
                    edges[through[temp]].capacity -= bottleneck;
                    edges[through[temp] ^ 1].capacity += bottleneck;
                    temp = edges[through[temp]].from;
                }
                f += bottleneck;
            }
        
            return f;
        }
    private:
        vector<edge> edges;
        vector<vector<pair<int, int>>> adj_list; // vertex & edge number
        int size, s, t, f;

        bool augmenting_path(vector<int> &dis, vector<int> &through) {
            dis = vector<int>(size, size);
            through = vector<int>(size, -1);

            dis[s] = 0;
            queue<int> que;
            que.push(s);
            while(!que.empty()) {
                int u = que.front();
                que.pop();
                for(auto &[v, e] : adj_list[u]) {
                    if(dis[v] > dis[u] + 1 && edges[e].capacity > 0) {
                        dis[v] = dis[u] + 1;
                        through[v] = e;
                        if(v == t) return true;
                        que.push(v);
                    }
                }
            }
            return false;
        }
};

int main() {
    int n, m, k;
    scanf("%d %d %d", &n, &m, &k);
    int s = n + m, t = n + m + 1;
    flow f(n + m, s, t);
    for(int i = 0; i < n; i++) f.addedge(s, i, 1);
    for(int i = 0; i < m; i++) f.addedge(i + n, t, 1);

    for(int i = 0; i < k; i++) {
        int u, v;
        scanf("%d %d", &u, &v);
        f.addedge(u, n + v, 1);
        printf("%d\n", f.max_flow());
    }

    return 0;
}
