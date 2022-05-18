// N 皇后
#include <vector>
#include <string>
using namespace std;
class Solution 
{
private:
    vector<vector<string>> result;
    bool isQueens(vector<string> &chessboard, int n, int row, int col)
    {
        for (int i = 0; i < row; ++i)
        {
            if (chessboard.at(i).at(col) == 'Q')
            {
                return false;
            }
        }
        for (int i = row - 1, j = col - 1; i >= 0 && j >= 0; --i, --j)
        {
            if (chessboard.at(i).at(j) == 'Q')
            {
                return false;
            }
        }
        for (int i = row - 1, j = col + 1; i >=0 && j < n; --i, ++j)
        {
            if (chessboard.at(i).at(j) == 'Q')
            {
                return false;
            }
        }
        return true;
    }

    void backTracking(vector<string> &chessboard, int n, int row)
    {
        if (row == n)
        {
            result.push_back(chessboard);
            return;
        }
        for (int i = 0; i < n; ++i)
        {
            if (isQueens(chessboard, n, row, i))
            {
                chessboard.at(row).at(i) = 'Q';
                backTracking(chessboard, n, row + 1);
                chessboard.at(row).at(i) = '.';
            }
        }
        return;
    }

public:
    vector<vector<string>> solveNQueens(int n) 
    {
        vector<string> chessboard(n, string(n, '.'));
        backTracking(chessboard, chessboard.size(), 0);
        return result;
    }
};