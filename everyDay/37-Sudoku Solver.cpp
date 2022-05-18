// 解数独
#include <vector>
using namespace std;
class Solution 
{
private:
    bool isValid(int row, int col, int n, vector<vector<char>> &board, char c)
    {
        for (int i = 0; i <  n; ++i)
        {
            if (board.at(row).at(i) == c)
            {
                return false;
            }
        }
        for (int i = 0; i < n; ++i)
        {
            if (board.at(i).at(col) == c)
            {
                return false;
            }
        }
        int r = row / 3;    // 行数第r个方块
        int l = col / 3;    // 列数第l个方块
        // 范围是 r*3 - r*3+2
        for (int i = r*3; i <= r*3+2; ++i)
        {
            for (int j = l*3; j <= l*3+2; ++j)
            {
                if (board.at(i).at(j) == c)
                {
                    return false;
                }
            }
        }
        return true;
    }
    bool backTracking(vector<vector<char>> &board)
    {
        for (int row = 0; row < board.size(); ++row)
        {
            for (int col = 0; col < board.size(); ++col)
            {
                if (board.at(row).at(col) != '.')   // 这个位置已经有数字了，就不看
                {
                    continue;
                }
                for (char c = '1'; c <= '9'; ++c)   // 依次判断这个位置放某个数字行不行
                {
                    if (isValid(row, col, board.size(), board, c))  // 如果这个位置放这个数字可行
                    {
                        board.at(row).at(col) = c;
                        // 如果一直是放好的，就一直放下去
                        if (backTracking(board) == true)    // 放好了再重新看
                        {
                            return true;
                        }
                        board.at(row).at(col) = '.';
                    }
                }
                return false;   // 正常来讲不会到这个位置，如果到这个位置，说明九个数字都不行，那么这个题无解。
            }
        }
        return true;
    }
public:
    void solveSudoku(vector<vector<char>>& board) 
    {
        backTracking(board);
        return;
    }
};