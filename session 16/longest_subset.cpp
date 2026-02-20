#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

vector<int> buildSubset(vector<vector<int>>& table, vector<int>& arr, int size, int sum)
{
    vector<int> result;

    if (table[size][sum] < 0)
        return result;

    int i = size, j = sum;

    while (i > 0 && j > 0)
    {
       
        if (table[i][j] == table[i - 1][j])
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
    int sum = 8;

    vector<vector<int>> table(n + 1, vector<int>(sum + 1, -1));

    
    for (int i = 0; i <= n; i++)
        table[i][0] = 0;

   
    for (int i = 1; i <= n; i++)
    {
        for (int j = 0; j <= sum; j++)
        {
            table[i][j] = table[i - 1][j]; 

            if (j >= arr[i - 1] && table[i - 1][j - arr[i - 1]] != -1)
            {
                int take = table[i - 1][j - arr[i - 1]] + 1;
                table[i][j] = max(table[i][j], take);
            }
        }
    }

    if (table[n][sum] == -1)
    {
        cout << "No subset possible\n";
        return 0;
    }

    cout << "Maximum subset length: " << table[n][sum] << endl;

    vector<int> ans = buildSubset(table, arr, n, sum);

    for (int val : ans)
        cout << val << " ";

    cout << endl;

    return 0;
}