// merge sort
#include <cstdio>
#include <utility>
#include <algorithm>
using namespace std;

long long smaller[100010], bigger[100010];
pair<int, int> arr[100010], temp[100010]; // first: value, second: index

void mergeSort(int l, int r) {
    if(l == r) return;
    int mid = l + (r - l) / 2;
    mergeSort(l, mid);
    mergeSort(mid + 1, r);
    
    int lp = l, rp = mid + 1, idx = l;
    while(lp <= mid || rp <= r) {
        if(lp > mid) {
            temp[idx++] = arr[rp++];
        } else if(rp > r) {
            smaller[arr[lp].second] += rp - mid - 1;
            temp[idx++] = arr[lp++];
        } else if(arr[lp].first <= arr[rp].first) {
            smaller[arr[lp].second] += rp - mid - 1;
            temp[idx++] = arr[lp++];
        } else {
            bigger[arr[rp].second] += mid - lp + 1;
            temp[idx++] = arr[rp++];
        }
    }
    copy(temp + l, temp + r + 1, arr + l);
}

int main() {
    int n;
    scanf("%d", &n);
    for(int i = 0; i < n; i++) {
        int a;
        scanf("%d", &a);
        arr[i] = {a, i};
    }
    mergeSort(0, n - 1);
    long long result = 0;
    for(int i = 0; i < n; i++) result += bigger[i] * smaller[i];
    printf("%lld\n", result);
    return 0;
}
