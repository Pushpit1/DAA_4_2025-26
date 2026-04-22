/*
Overall Time Complexity:
= O(n) + O(n * sum) + O(sum)
= O(n * sum)

Overall Space Complexity:
= O(sum)
*/

#include <bits/stdc++.h>
using namespace std;

int minDifference(vector<int>& arr) {
    int n = arr.size();

    // Time: O(n)
    int sum = 0;
    for(int i = 0; i < n; i++) {
        sum += arr[i];
    }

    // Space: O(sum)
    vector<bool> dp(sum + 1, false);
    dp[0] = true;

    // Time: O(n * sum)
    for(int i = 0; i < n; i++) {
        for(int j = sum; j >= arr[i]; j--) {
            dp[j] = dp[j] || dp[j - arr[i]];
        }
    }

    // Time: O(sum)
    int min_diff = INT_MAX;
    for(int j = 0; j <= sum/2; j++) {
        if(dp[j]) {
            min_diff = min(min_diff, sum - 2*j);
        }
    }

    return min_diff;
}

int main() {
    int n;
    cin >> n;

    vector<int> arr(n);
    for(int i = 0; i < n; i++) {
        cin >> arr[i];
    }

    cout << minDifference(arr);

    return 0;
}

