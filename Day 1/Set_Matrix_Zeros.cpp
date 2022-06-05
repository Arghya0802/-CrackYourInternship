#include <iostream>
#include <vector>
using namespace std;

void setMatrixZeros(int row, int col, int m, int n, vector<vector<int>> &matrix)
{
    // First set all the Row Elements as 0

    for (int currentCol = 0; currentCol < n; currentCol++)
    {
        matrix[row][currentCol] = 0;
    }

    // Next set all the Column Elements as 0

    for (int currentRow = 0; currentRow < m; currentRow++)
    {
        matrix[currentRow][col] = 0;
    }

    return;
}

void setZeroes(vector<vector<int>> &matrix)
{

    int m = matrix.size();
    int n = matrix[0].size();

    vector<pair<int, int>> memo;

    for (int currentRow = 0; currentRow < m; currentRow++)
    {
        for (int currentCol = 0; currentCol < n; currentCol++)
        {
            if (matrix[currentRow][currentCol] == 0)
                memo.push_back({currentRow, currentCol});
        }
    }

    for (int i = 0; i < memo.size(); i++)
    {
        pair<int, int> currentPair = memo[i];

        int row = currentPair.first;
        int col = currentPair.second;

        setMatrixZeros(row, col, m, n, matrix);
    }

    return;
}