#include <vector>
#include <iostream>
using namespace std;

int maxArea(vector<int> &height)
{

    int n = height.size();
    int low = 0, high = n - 1;
    int ans = 0;

    while (low <= high)
    {
        int leftHeight = height[low];
        int rightHeight = height[high];

        int x = high - low;
        int y = min(leftHeight, rightHeight);

        ans = max(ans, (x * y));

        if (leftHeight < rightHeight)
            low++;

        else
            high--;
    }

    return ans;
}