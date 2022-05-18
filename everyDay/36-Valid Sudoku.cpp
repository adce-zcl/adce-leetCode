// 有效的数独
#include <vector>
#include <unordered_set>
using namespace std;
// 有效的数独
class Solution 
{
public:
    bool isValidSudoku(vector<vector<char>>& board) 
    {
        unordered_set<char> se;
        // 验证每一行是否有效
        for (int i = 0; i < 9; ++i)
        {
            for (int j = 0; j < 9; ++j)
            {
                char temp = board.at(i).at(j);
                if (temp == '.')
                {
                    continue;
                }
                if (se.count(temp) == 0)
                {
                    se.insert(temp);
                }
                else
                {
                    return false;
                }
            }
            se.clear();
        }
        // 验证每一列是否有效
        for (int i = 0; i < 9; ++i)
        {
            for (int j = 0; j < 9; ++j)
            {
                char temp = board.at(j).at(i);
                if (temp == '.')
                {
                    continue;
                }
                if (se.count(temp) == 0)
                {
                    se.insert(temp);
                }
                else
                {
                    return false;
                }
            }
            se.clear();
        }
        // 验证每一个方格
        int num = 0;    // 在第几个方格
        int row = 0, col = 0;
        while (num < 9)
        {
            for (int i = row; i <= row + 2; ++i)
            {
                for (int j = col; j <= col + 2; ++j)
                {
                    char temp = board.at(i).at(j);
                    if (temp == '.')
                    {
                        continue;
                    }
                    if (se.count(temp) == 0)
                    {
                        se.insert(temp);
                    }
                    else
                    {
                        return false;
                    }
                }
            }
            se.clear();
            col += 3;
            if (col == 9)
            {
                row += 3;
                col = 0;
            }
            ++num;
        }
        return true;
    }
};
int main()
{
    vector<vector<char>> board{\
    {'5', '3', '.', '.', '7', '.', '.', '.', '.'}, \
    {'6', '.', '.', '1', '9', '5', '.', '.', '.'}, \
    {'.', '9', '8', '.', '.', '.', '.', '6', '.'}, \
    {'8', '.', '.', '.', '6', '.', '.', '.', '3'}, \
    {'4', '.', '.', '8', '.', '3', '.', '.', '1'}, \
    {'7', '.', '.', '.', '2', '.', '.', '.', '6'}, \
    {'.', '6', '.', '.', '.', '.', '2', '8', '.'}, \
    {'.', '.', '.', '4', '1', '9', '.', '.', '5'}, \
    {'.', '.', '.', '.', '8', '.', '.', '7', '9'}};
    Solution s;
    s.isValidSudoku(board);
}