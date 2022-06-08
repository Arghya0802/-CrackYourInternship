#include <iostream>
#include <vector>
using namespace std;

vector<int> spiralOrder(vector<vector<int>> &matrix)
{

    vector<int> ans;

    int left = 0, right = 0;

    int m = matrix.size();
    int n = matrix[0].size();

    int startRow = 0, endRow = m - 1;
    int startCol = 0, endCol = n - 1;

    int total = m * n;
    int count = 0;

    while (count < total)
    {
        for (int index = startCol; index <= endCol; index++)
        {
            if (count >= total)
                break;

            int currentCell = matrix[startRow][index];
            count++;

            ans.push_back(currentCell);
        }

        startRow++;

        for (int index = startRow; index <= endRow; index++)
        {
            if (count >= total)
                break;

            int currentCell = matrix[index][endCol];
            count++;

            ans.push_back(currentCell);
        }

        endCol--;

        for (int index = endCol; index >= startCol; index--)
        {
            if (count >= total)
                break;

            int currentCell = matrix[endRow][index];
            count++;

            ans.push_back(currentCell);
        }

        endRow--;

        for (int index = endRow; index >= startRow; index--)
        {
            if (count >= total)
                break;

            int currentCell = matrix[index][startCol];
            count++;

            ans.push_back(currentCell);
        }

        startCol++;
    }

    return ans;
}