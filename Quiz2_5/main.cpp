// http://web.ntnu.edu.tw/~algo/Path3.html#1
// naive Floyd-Warshell

#include <cstdio>
#include <vector>
#include <climits>
using namespace std;

#define MAX 999

int n;
vector<vector<int>> g;
vector<vector<int>> d;

void allPairsShortestPaths() {
    for(int i = 0; i < n; i++) {
        for(int j = 0; j < n; j++) {
            d[i][j] = (g[i][j] != 0) ? g[i][j] : MAX;
            //d[i][j] = g[i][j];
        }
    }

    for(int i = 0; i < n; i++)
        d[i][i] = 0;

    for(int k = 0; k < n; k++) {
        for(int i = 0; i < n; i++) {
            for(int j = 0; j < n; j++) {
                if(d[i][k] + d[k][j] < d[i][j])
                    d[i][j] = d[i][k] + d[k][j]; //printf("%d %d %d %d\n", i, k, j, d[i][j]);
            }
        }
    }
}

int main() {
    scanf("%d", &n);
    g = vector<vector<int>>(n, vector<int>(n));
    d = vector<vector<int>>(n, vector<int>(n));
    for(int i = 0; i < n; i++) {
        for(int j = 0; j < n; j++) {
            scanf("%d", &g[i][j]);
        }
    }

    allPairsShortestPaths();

    for(int i = 0; i < n; i++) {
        for(int j = 0; j < n; j++) {
            printf("%d ", (d[i][j] != MAX) ? d[i][j] : -1);
        }
        printf("\n");
    }

    return 0;
}
