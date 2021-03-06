#include <vector>
#include <iostream>
using namespace std;

int removeDuplicates(vector<int> &nums)
{
    int k = 1;
    int n = nums.size();
    int prevElement = nums[0];

    for (int i = 1; i < n; i++)
    {
        if (prevElement != nums[i])
        {
            nums[k] = nums[i];
            k++;
            prevElement = nums[i];
        }
    }

    return k;
}