// DP
// house robber variant

#include <cstdio>
#include <algorithm>
using namespace std;

long n, a[2000000], dp[2000000] = { 0 };

int main() {
    scanf("%ld", &n);
    for(int i = 0; i < n; i++)
        scanf("%ld", &a[i]);
    for(int i = 0; i < n; i++) {
        dp[i] = max((i > 1 ? dp[i - 2] : 0) + a[i],
                    (i > 0 ? dp[i - 1] : 0));
    }
    printf("%ld\n", dp[n - 1]);
    return 0;
}
