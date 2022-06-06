#include <vector>
#include <iostream>
#include <unordered_map>
using namespace std;

vector<int> twoSum(vector<int> &nums, int target)
{

    vector<int> ans(2, -1);

    unordered_map<int, int> memo;

    for (int i = 0; i < nums.size(); i++)
    {
        int currentNum = nums[i];
        int findTarget = target - nums[i];

        if (memo.find(findTarget) != memo.end())
        {
            ans[0] = i;
            ans[1] = memo[findTarget];
            break;
        }

        else
            memo[currentNum] = i;
    }

    return ans;
}