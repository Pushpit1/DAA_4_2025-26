// Time Complexity: O(m * n)
// m = length of string s
// n = length of string t
// We iterate through each character of s (outer loop)
// and for each character, we traverse t backwards (inner loop)

// Space Complexity: O(n)
// We use a 1D DP array of size (n + 1)
// No extra 2D table is used, so space is optimized


#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int numDistinct(string s, string t) {
        int m = s.size(), n = t.size();
        
        vector<unsigned long long> dp(n + 1, 0);
        dp[0] = 1;  

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