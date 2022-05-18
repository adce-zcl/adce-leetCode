// 矩阵置零
#include <vector>
using namespace std;
class Solution 
{
public:
    void setZeroes(vector<vector<int>>& matrix) 
    {
        int rows = matrix.size();
        int cols = matrix.at(0).size();
        vector<pair<int, int>> zero;
        for (int i = 0; i < rows; ++i)
        {
            for (int j = 0; j < cols; ++j)
            {
                if (matrix.at(i).at(j) == 0)
                {
                    zero.push_back(pair<int, int>(i, j));
                }
            }
        }
        while (!zero.empty())
        {
            pair<int, int> cur = zero.front();
            zero.erase(zero.begin());
            int row = cur.first;
            int col = cur.second;
            for (int j = 0; j < cols; ++j)
            {
                matrix.at(row).at(j) = 0;
            }
            for (int i = 0; i < rows; ++i)
            {
                matrix.at(i).at(col) = 0;
            }
        }
        return;
    }
};