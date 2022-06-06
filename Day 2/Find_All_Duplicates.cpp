#include <vector>
#include <iostream>
using namespace std;

vector<int> findDuplicates(vector<int> &nums)
{

    int n = nums.size();
    vector<int> ans;

    for (int i = 0; i < n; i++)
    {
        int currentNum = nums[i];

        int index = abs(currentNum) - 1;

        nums[index] = -nums[index];

        if (nums[index] > 0)
            ans.push_back(index + 1);
    }

    return ans;
}