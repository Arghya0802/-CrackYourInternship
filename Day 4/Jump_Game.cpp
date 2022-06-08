#include <iostream>
#include <vector>
#include <unordered_map>
using namespace std;

// DP solution will not work so we need to use Greedy Approach in order to avoid TLE
bool dfs(int currentIndex, int targetIndex, vector<int> &nums, vector<int> &dp)
{
    if (currentIndex == targetIndex)
        return true;

    if (currentIndex > targetIndex)
        return false;

    if (dp[currentIndex] != -1)
        return dp[currentIndex];

    int currentJump = nums[currentIndex];
    bool ans = false;

    for (int jump = 1; jump <= currentJump; jump++)
    {
        bool tempAns = dfs(currentIndex + jump, targetIndex, nums, dp);

        ans = ans || tempAns;
    }

    dp[currentIndex] = ans;

    return ans;
}

// In Greedy Solution, we will start from (n-2)th index and try to reach 0th Index by checking whether currentMaxJump + i >= target or not
bool canJump(vector<int> &nums)
{

    //     vector<int> dp (n , - 1);

    //     bool ans = dfs(0 , n - 1 , nums , dp) ;

    int n = nums.size();

    int target = n - 1;

    for (int i = n - 2; i >= 0; i--)
    {
        int currentMaxJump = nums[i];

        if (currentMaxJump + i >= target)
            target = i;
    }

    if (target == 0)
        return true;
    else
        return false;
}