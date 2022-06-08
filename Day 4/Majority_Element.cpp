#include <iostream>
#include <vector>
using namespace std;

// Solved using Bayer Moore's Majority Voting Algorithm
int majorityElement(vector<int> &nums)
{

    int count = 0;
    int majorElement;

    int n = nums.size();

    for (int i = 0; i < n; i++)
    {
        if (count == 0)
            majorElement = nums[i];

        if (majorElement == nums[i])
            count++;

        else
            count--;
    }

    int checkCount = 0;

    for (int i = 0; i < n; i++)
    {
        if (nums[i] == majorElement)
            checkCount++;
    }

    int boundary = n / 2;

    if (checkCount >= boundary)
        return majorElement;

    return -1;
}