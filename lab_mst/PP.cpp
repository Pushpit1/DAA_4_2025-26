#include <iostream>
#include <vector>
#include <string>
using namespace std;

class Solution {
public:
    vector<vector<string>> partition(string s) {
        int n = s.size();

        vector<vector<bool>> dp(n, vector<bool>(n, false));

        for (int i = n - 1; i >= 0; i--) {
            for (int j = i; j < n; j++) {
                if (s[i] == s[j]) {
                    if (j - i <= 2) dp[i][j] = true;
                    else dp[i][j] = dp[i + 1][j - 1];
                }
            }
        }

        vector<vector<string>> res;
        vector<string> curr;

        dfs(0, s, curr, res, dp);
        return res;
    }

    void dfs(int idx, string &s, vector<string> &curr,
             vector<vector<string>> &res,
             vector<vector<bool>> &dp) {

        if (idx == s.size()) {
            res.push_back(curr);
            return;
        }

        for (int j = idx; j < s.size(); j++) {
            if (dp[idx][j]) {
                curr.push_back(s.substr(idx, j - idx + 1));
                dfs(j + 1, s, curr, res, dp);
                curr.pop_back();
            }
        }
    }
};

int main() {
    Solution obj;
    string s = "aab";

    vector<vector<string>> result = obj.partition(s);

    for (auto &vec : result) {
        for (auto &str : vec) {
            cout << str << " ";
        }
        cout << endl;
    }

    return 0;
}