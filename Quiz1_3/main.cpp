// http://web.ntnu.edu.tw/~algo/LongestCommonSubsequence.html
// DP

#include <iostream>
#include <string>
#include <algorithm>

using std::cout;
using std::cin;
using std::endl;
using std::string;
using std::max;

int dp[5001][5001];

int main() {
    cin.sync_with_stdio(0);
    cin.tie(0);

    string text1, text2;
    getline(cin, text1);
    getline(cin, text2);


    int n1 = text1.size(), n2 = text2.size();
    for(int i = 0; i <= n1; i++)
        dp[i][0] = 0;
    for(int j = 0; j <= n2; j++)
        dp[0][j] = 0;

    for(int i = 1; i <= n1; i++) {
        for(int j = 1; j <= n2; j++) {
            if(text1[i - 1] == text2[j - 1])
                dp[i][j] = dp[i - 1][j - 1] + 1;
            else
                dp[i][j] = max(dp[i - 1][j], dp[i][j - 1]);
        }
    }

    cout << dp[n1][n2];

    return 0;
}
