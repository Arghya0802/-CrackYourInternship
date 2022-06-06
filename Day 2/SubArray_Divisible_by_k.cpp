#include <unordered_map>
#include <iostream>
#include <vector>
using namespace std;

int subarraysDivByK(vector<int> &nums, int k)
{

    unordered_map<int, int> memo;
    int prefixSum = 0;
    int ans = 0;

    memo[prefixSum] = 1;

    for (int i = 0; i < nums.size(); i++)
    {
        prefixSum = prefixSum + nums[i];

        prefixSum = ((prefixSum % k) + k) % k;

        if (memo.find(prefixSum) != memo.end())
        {
            ans = ans + memo[prefixSum];
            memo[prefixSum]++;
        }

        else
            memo[prefixSum] = 1;
    }

    return ans;
}