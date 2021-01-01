#include <cstdio>
#include <vector>
#include <algorithm>
using namespace std;

int n, m, a[500000];

int main() {
    scanf("%d %d", &n, &m);
    for(int i = 0; i < n; i++)
        scanf("%d", &a[i]);
    for(int i = 0; i < m; i++) {
        int l, r;
        scanf("%d %d", &l, &r);
        vector<int> table = vector<int>(n, 0);
        for(int j = l; j < r; j++)
            table[a[j]]++;
        printf("%ld\n", max_element(table.begin(), table.end()) - table.begin());
    }

    return 0;
}
