#include <bits/stdc++.h>
using namespace std;

int twoSum(vector<int> &a, int target) {
    int n = a.size();
	int result = 0;
	unordered_map<int, int> map;
	for(int i = 0; i < n; i++) {
		map[a[i]] = i;
	}
	for(int i = 0; i < n; i++) {
		int complement = target - a[i];
		auto iter = map.find(complement);
		if((iter != map.end()) && (i < iter->second)) {
			result++;
		}
	}
	return result;
}

int main() {
    cin.tie(0);
    cin.sync_with_stdio(0);

    int n, target;
    cin >> n >> target;
    vector<int> a(n);
    for (int &x : a) {
        cin >> x;
    }
    cout << twoSum(a, target) << '\n';
}
