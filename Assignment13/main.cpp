// 0/1 knapsack variant
// DP (bottom-up)
// get WA
// http://web.ntnu.edu.tw/~algo/KnapsackProblem.html#3

#include <iostream>
#include <climits>
#include <algorithm>
#include <vector>

using std::cin;
using std::cout;
using std::max;
using std::vector;

int N, W, V;
int cost[500];
int weight[500];
int volume[500];
int dp[501][501][501] = {0};

int main() {
    std::cin.sync_with_stdio(0);
    std::cin.tie(0);

    cin >> N >> W >> V;
    for(int i = 0; i < N; i++)
        cin >> weight[i] >> volume[i] >> cost[i];
    
    for(int i = 0; i < N; i++) {
        for(int j = 0; j <= W; j++) {
            for(int k = 0, k <= V, k++) {
                if(j - weight[i] < 0 || k - volume[i] < 0)
                    dp[i + 1][j][k] = dp[i][j][k];
                else
                    dp[i + 1][j][k] = max(dp[i][j][k], dp[i][j - weight[i]][k - volume[k]] + cost[i]);
            }
        }
    }

    cout << dp[N][W][V];
    return 0;
}
