#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

vector<vector<int>> fourSum(vector<int> &nums, int target)
{

    int n = nums.size();
    sort(nums.begin(), nums.end());
    vector<vector<int>> ans;

    for (int i = 0; i < n; i++)
    {
        int target_2 = target - nums[i];

        for (int j = i + 1; j < n; j++)
        {
            int targetSum = target_2 - nums[j];
            int low = j + 1, high = n - 1;

            while (low < high)
            {
                int currentSum = nums[low] + nums[high];

                if (currentSum == targetSum)
                {
                    vector<int> temp(4, 0);

                    temp[0] = nums[i];
                    temp[1] = nums[j];
                    temp[2] = nums[low];
                    temp[3] = nums[high];

                    ans.push_back(temp);

                    int prevLow = nums[low], prevHigh = nums[high];

                    while (prevLow == nums[low] && low < high)
                        low++;

                    while (prevHigh == nums[high] && low < high)
                        high--;
                }

                else if (currentSum < targetSum)
                    low++;

                else
                    high--;
            }

            while (j + 1 < n && nums[j] == nums[j + 1])
                j++;
        }

        while (i + 1 < n && nums[i] == nums[i + 1])
            i++;
    }

    return ans;
}