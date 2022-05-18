//  重塑矩阵
#include <vector>
using namespace std;
class Solution 
{
public:
    vector<vector<int>> matrixReshape(vector<vector<int>>& mat, int r, int c) 
    {
        int rows = mat.size();
        int cols = mat.at(0).size();
        if (rows == r && cols == c)
        {
            return mat;
        }
        if (rows * cols != r * c)
        {
            return mat;
        }
        vector<vector<int>> newMat(r, vector<int>(c));
        int row = 0;
        int col = 0;
        for (int i = 0; i < r; ++i)
        {
            for (int j = 0; j < c; ++j)
            {
                newMat.at(i).at(j) = mat.at(row).at(col);
                if (++col == cols)
                {
                    ++row;
                    col = 0;
                }
            }
        }
        return newMat;
    }
};