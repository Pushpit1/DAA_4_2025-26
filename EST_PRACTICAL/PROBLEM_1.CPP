#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int n;
    vector<vector<int>> dp;

    int solve(int mask, int pos, vector<vector<int>> &cost) {
        if (mask == (1 << n) - 1)
            return cost[pos][0];

        if (dp[mask][pos] != -1)
            return dp[mask][pos];

        int ans = INT_MAX;

        for (int city = 0; city < n; city++) {
            if ((mask & (1 << city)) == 0) {
                int newAns = cost[pos][city] + solve(mask | (1 << city), city, cost);
                ans = min(ans, newAns);
            }
        }

        return dp[mask][pos] = ans;
    }

    int tsp(vector<vector<int>> &cost) {
        n = cost.size();
        dp.assign(1 << n, vector<int>(n, -1));
        return solve(1, 0, cost);
    }
};