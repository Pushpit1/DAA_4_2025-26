#include <iostream>
#include <vector>
using namespace std;

int climbStairs(int n)
{
    if (n <= 2)
        return n;

    vector<int> ways(n + 1);

    ways[1] = 1;
    ways[2] = 2;

    for (int i = 3; i <= n; i++)
    {
        ways[i] = ways[i - 1] + ways[i - 2];
    }

    return ways[n];
}

int main()
{
    int n;
    cout << "Enter number of stairs: ";
    cin >> n;

    int result = climbStairs(n);

    cout << "Number of distinct ways: " << result << endl;

    return 0;
}