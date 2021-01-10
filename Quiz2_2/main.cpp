#include <cstdio>
#include <vector>
#include <algorithm>
using namespace std;

int n, m, a[500000];

int main() {
    scanf("%d %d", &n, &m);
    for(int i = 0; i < n; i++)
        scanf("%d", &a[i]);

    vector<int> table = vector<int>(n, 0);
    for(int i = 0; i < m; i++) {
        int l, r;
        scanf("%d %d", &l, &r);
        for(int j = l; j < r; j++)
            table[a[j]]++;

        // https://github.com/algo-seacow/NCTU-ItoA-2020-Fall/tree/master/1134
        pair<int, int> result; // value & the number of the value occurs
        for(int j = l; j < r; j++) {
            if((table[a[j]] > result.second) || (a[j] < result.first && table[a[j]] == result.second))
                result = {a[j], table[a[j]]};
            table[a[j]] = 0;
        }
        printf("%d\n", result.first);
    }

    return 0;
}
