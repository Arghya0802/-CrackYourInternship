#include <vector>
#include <algorithm>
#include <iostream>
using namespace std;

vector<vector<int>> threeSum(vector<int> &nums)
{

    sort(nums.begin(), nums.end());
    vector<vector<int>> ans;
    int n = nums.size();

    for (int i = 0; i < n; i++)
    {
        int target = 0 - nums[i];
        int low = i + 1, high = n - 1;

        while (low < high)
        {
            int currentSum = nums[low] + nums[high];

            if (currentSum == target)
            {
                ans.push_back({nums[i], nums[low], nums[high]});

                int prevLow = nums[low], prevHigh = nums[high];

                while (prevLow == nums[low] && low < high)
                    low++;

                while (prevHigh == nums[high] && low < high)
                    high--;
            }

            else if (currentSum < target)
                low++;

            else
                high--;
        }

        while (i + 1 < n && nums[i] == nums[i + 1])
            i++;
    }

    return ans;
}