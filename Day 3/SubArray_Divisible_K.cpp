#include <iostream>
#include <vector>
#include <unordered_map>
using namespace std;

int subarraySum(vector<int> &nums, int k)
{

    unordered_map<int, int> memo;
    int n = nums.size();

    int prefixSum = 0;
    int ans = 0;

    memo[prefixSum] = 1;

    for (int i = 0; i < n; i++)
    {
        prefixSum = prefixSum + nums[i];

        if (memo.find(prefixSum - k) != memo.end())
        {
            ans = ans + memo[prefixSum - k];
        }

        if (memo.find(prefixSum) != memo.end())
            memo[prefixSum]++;

        else
            memo[prefixSum] = 1;
    }

    return ans;
}