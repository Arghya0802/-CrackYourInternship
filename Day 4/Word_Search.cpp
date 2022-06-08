#include <iostream>
#include <unordered_map>
#include <vector>
using namespace std;

bool dfs(int currentRow, int currentCol, int currentIndex, int m, int n, string &word, vector<vector<char>> &board)
{
    if (currentIndex == word.size())
        return true;

    if (currentRow < 0 || currentRow >= m || currentCol < 0 || currentCol >= n)
        return false;

    if (board[currentRow][currentCol] == '.')
        return false;

    if (board[currentRow][currentCol] != word[currentIndex])
        return false;

    char ch = board[currentRow][currentCol];
    board[currentRow][currentCol] = '.';

    bool upMove = dfs(currentRow - 1, currentCol, currentIndex + 1, m, n, word, board);
    bool downMove = dfs(currentRow + 1, currentCol, currentIndex + 1, m, n, word, board);
    bool leftMove = dfs(currentRow, currentCol - 1, currentIndex + 1, m, n, word, board);
    bool rightMove = dfs(currentRow, currentCol + 1, currentIndex + 1, m, n, word, board);

    board[currentRow][currentCol] = ch;

    if (upMove == true || downMove == true || leftMove == true || rightMove == true)
        return true;

    return false;
}

bool exist(vector<vector<char>> &board, string &word)
{

    int m = board.size();
    int n = board[0].size();

    for (int currentRow = 0; currentRow < m; currentRow++)
    {
        for (int currentCol = 0; currentCol < n; currentCol++)
        {
            if (board[currentRow][currentCol] == word[0])
            {
                bool ans = dfs(currentRow, currentCol, 0, m, n, word, board);

                if (ans == true)
                    return ans;
            }
        }
    }

    return false;
}