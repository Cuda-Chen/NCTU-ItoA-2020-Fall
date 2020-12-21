#include <cstdio>
#include <algorithm>
using namespace std;

long n, a[2 * 10^6], dp[2 * 10^6] = { 0 };

int main() {
    scanf("%d", &n);
    for(int i = 0; i < n; i++)
        scanf("%d", &a[i]);
    for(int i = 0; i < n; i++) {
        dp[i] = max((i > 1 ? dp[i - 2] : 0) + a[i],
                    (i > 0 ? dp[i - 1] : 0));
    }
    printf("%d\n", dp[n - 1]);
    return 0;
}
