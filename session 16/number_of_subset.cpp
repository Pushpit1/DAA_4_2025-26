#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

vector<int> getLongestSubset(vector<vector<int>>& dp,
                             vector<int>& arr,
                             int n,
                             int target)
{
    vector<int> result;

    if (dp[n][target] == -1)
        return result;

    int i = n;
    int j = target;

    while (i > 0 && j > 0)
    {
        
        if (dp[i][j] == dp[i - 1][j])
        {
            i--;
        }
        else
        {
            result.push_back(arr[i - 1]);
            j -= arr[i - 1];
            i--;
        }
    }

    return result;
}

int main()
{
    vector<int> arr = {3, 4, 1, 2, 5};
    int n = arr.size();
    int target = 8;

    vector<vector<int>> dp(n + 1, vector<int>(target + 1, -1));

   
    for (int i = 0; i <= n; i++)
        dp[i][0] = 0;

    
    for (int i = 1; i <= n; i++)
    {
        for (int j = 0; j <= target; j++)
        {
           
            dp[i][j] = dp[i - 1][j];

          
            if (j >= arr[i - 1] && dp[i - 1][j - arr[i - 1]] != -1)
            {
                dp[i][j] = max(dp[i][j],
                               dp[i - 1][j - arr[i - 1]] + 1);
            }
        }
    }

    if (dp[n][target] == -1)
    {
        cout << "No subset found\n";
        return 0;
    }

    cout << "Length of the longest subset: "
         << dp[n][target] << endl;

    vector<int> subset = getLongestSubset(dp, arr, n, target);

    for (int val : subset)
        cout << val << " ";

    cout << endl;

    return 0;
}