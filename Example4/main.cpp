#include <bits/stdc++.h>
using namespace std;

int findSingleton(vector<int> &a) {
    vector<int> map(a.size(), 0);
	for(auto elem : a)
		map[elem - 1]++;
	int i;
	for(i = 0; i < map.size(); i++) {
		if(map[i] == 1)
			break;
	}
	return i + 1;
}

int main() {
    cin.tie(0);
    cin.sync_with_stdio(0);

    int n;
    cin >> n;
    vector<int> a(2 * n - 1);
    for (int &x : a) {
        cin >> x;
    }
    cout << findSingleton(a) << '\n';
}
