#include <vector>
#include <iostream>
#include <algorithm>
#include <utility>

using namespace std;

class jobseq
{
public:
    static bool sortp(pair<int, int> a, pair<int, int> b)
    {
        return a.first > b.first;
    }

    static int maxd(vector<pair<int, int>> v)
    {
        int mx = 0;
        for (int i = 0; i < v.size(); i++)
            if (v[i].second > mx)
                mx = v[i].second;
        return mx;
    }

    static int findp(vector<int>& arr, int x)
    {
        if (arr[x] == x)
            return x;
        return arr[x] = findp(arr, arr[x]);
    }

    static vector<int> jobseqfun(vector<int>& dl, vector<int>& pr)
    {
        int n = dl.size();
        vector<pair<int, int>> v;

        for (int i = 0; i < n; i++)
            v.push_back(make_pair(pr[i], dl[i]));

        sort(v.begin(), v.end(), sortp);

        int maxt = maxd(v);

        vector<int> arr(maxt + 1);
        for (int i = 0; i <= maxt; i++)
            arr[i] = i;

        int sum = 0, cnt = 0;

        for (int i = 0; i < n; i++)
        {
            int pos = findp(arr, v[i].second);
            if (pos > 0)
            {
                sum += v[i].first;
                cnt++;
                arr[pos] = findp(arr, pos - 1);
            }
        }

        return {cnt, sum};
    }
};

int main()
{
    int n;
    cout << "Enter number of jobs wanted : ";
    cin >> n;

    vector<int> pr, dl;
    cout << "Enter the profit and deadline:\n";
    for (int i = 0; i < n; i++)
    {
        int x, y;
        cin >> x >> y;
        pr.push_back(x);
        dl.push_back(y);
    }

    vector<int> ans = jobseq::jobseqfun(dl, pr);

    cout << "Jobs done are in order = " << ans[0] << endl;
    cout << "Total profit that we can get is  = " << ans[1] << endl;

    return 0;
}
