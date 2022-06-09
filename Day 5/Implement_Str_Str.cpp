#include <iostream>
#include <vector>
using namespace std;

int strStr(string &haystack, string &needle)
{

    if (needle.size() == 0)
        return 0;

    int m = haystack.size();
    int n = needle.size();

    for (int i = 0; i < m; i++)
    {
        int k = i + 1, count = 0;
        if (haystack[i] == needle[0])
        {
            count++;
            for (int j = 1; j < n; j++)
            {
                if (haystack[k] != needle[j])
                    break;

                k++;
                count++;
            }

            if (count == n)
                return i;
        }
    }

    return -1;
}