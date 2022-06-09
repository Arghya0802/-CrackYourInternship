#include <vector>
#include <iostream>
using namespace std;

bool isValid(int currentRow, int currentCol, int m, int n)
{
    if (currentRow < 0 || currentRow >= m || currentCol < 0 || currentCol >= n)
        return false;

    else
        return true;
}

int countLiveNeighbour(int currentRow, int currentCol, int m, int n, vector<vector<int>> &board)
{
    int liveNeighbours = 0;

    if (isValid(currentRow - 1, currentCol, m, n) == true && board[currentRow - 1][currentCol] == 1)
        liveNeighbours++;

    if (isValid(currentRow + 1, currentCol, m, n) == true && board[currentRow + 1][currentCol] == 1)
        liveNeighbours++;

    if (isValid(currentRow, currentCol - 1, m, n) == true && board[currentRow][currentCol - 1] == 1)
        liveNeighbours++;

    if (isValid(currentRow, currentCol + 1, m, n) == true && board[currentRow][currentCol + 1] == 1)
        liveNeighbours++;

    if (isValid(currentRow - 1, currentCol - 1, m, n) == true && board[currentRow - 1][currentCol - 1] == 1)
        liveNeighbours++;

    if (isValid(currentRow - 1, currentCol + 1, m, n) == true && board[currentRow - 1][currentCol + 1] == 1)
        liveNeighbours++;

    if (isValid(currentRow + 1, currentCol - 1, m, n) == true && board[currentRow + 1][currentCol - 1] == 1)
        liveNeighbours++;

    if (isValid(currentRow + 1, currentCol + 1, m, n) == true && board[currentRow + 1][currentCol + 1] == 1)
        liveNeighbours++;

    return liveNeighbours;
}

void setMatrix(int currentRow, int currentCol, int currentCellVal, int countLiveNeigh, vector<vector<int>> &ans)
{
    if (currentCellVal == 0)
    {
        if (countLiveNeigh == 3)
            ans[currentRow][currentCol] = 1;
    }

    if (currentCellVal == 1)
    {
        if (countLiveNeigh < 2)
            ans[currentRow][currentCol] = 0;

        else if (countLiveNeigh == 2 || countLiveNeigh == 3)
            ans[currentRow][currentCol] = 1;

        else if (countLiveNeigh > 3)
            ans[currentRow][currentCol] = 0;
    }

    return;
}

void populateMatrix(vector<vector<int>> &ans, vector<vector<int>> &board, int m, int n)
{
    for (int currentRow = 0; currentRow < m; currentRow++)
    {
        for (int currentCol = 0; currentCol < n; currentCol++)
        {
            board[currentRow][currentCol] = ans[currentRow][currentCol];
        }
    }

    return;
}

// This Question can also be solved in O(1) but I have used O(M * N) extra space
void gameOfLife(vector<vector<int>> &board)
{

    int m = board.size();
    int n = board[0].size();

    vector<vector<int>> ans(m, vector<int>(n, 0));

    for (int currentRow = 0; currentRow < m; currentRow++)
    {
        for (int currentCol = 0; currentCol < n; currentCol++)
        {
            int countLives = countLiveNeighbour(currentRow, currentCol, m, n, board);
            int currentCell = board[currentRow][currentCol];

            setMatrix(currentRow, currentCol, currentCell, countLives, ans);
        }
    }

    populateMatrix(ans, board, m, n);

    return;
}