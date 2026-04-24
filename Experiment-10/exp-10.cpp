#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int numDistinct(string s, string t) {
        int m = s.size(), n = t.size();
        
        vector<unsigned long long> dp(n + 1, 0);
        dp[0] = 1;  // Empty t
        
        for (int i = 0; i < m; i++) {
            for (int j = n; j >= 1; j--) {
                if (s[i] == t[j - 1]) {
                    dp[j] += dp[j - 1];
                }
            }
        }
        
        return (int)dp[n];
    }
};