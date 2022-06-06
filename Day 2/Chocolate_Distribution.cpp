#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

long long findMinDiff(vector<long long> a, long long n, long long m)
{

    sort(a.begin(), a.end());
    long long int ans = a[m - 1] - a[0];

    int index = 0;

    for (int i = m; i < n; i++)
    {
        index++;

        long long int tempAns = a[i] - a[index];

        ans = min(ans, tempAns);
    }

    return ans;
}