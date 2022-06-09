#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

string longestCommonPrefix(vector<string> &strs)
{

    int n = strs.size();
    string ans = "";

    sort(strs.begin(), strs.end());

    string smallestWord = strs[0];
    int smallestCount = smallestWord.size();

    string largestWord = strs[n - 1];

    for (int i = 0; i < smallestCount; i++)
    {
        if (largestWord[i] == smallestWord[i])
            ans = ans + smallestWord[i];

        else
            break;
    }

    return ans;
}