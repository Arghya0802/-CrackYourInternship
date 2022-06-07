#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int maxScore(vector<int> &cardPoints, int k)
{

    int n = cardPoints.size();
    int windowSum = 0;
    int totalSum = 0;
    int count = 0, j = 0;

    for (int i = 0; i < n; i++)
        totalSum = totalSum + cardPoints[i];

    while (count < (n - k))
    {
        windowSum = windowSum + cardPoints[j];
        j++;
        count++;
    }

    int ans = windowSum;
    int index = 0;
    int i = j;

    for (; i < n; i++)
    {
        windowSum = windowSum - cardPoints[index];
        index++;

        windowSum = windowSum + cardPoints[i];

        ans = min(ans, windowSum);
    }

    return (totalSum - ans);
}