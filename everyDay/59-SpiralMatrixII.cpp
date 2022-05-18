// 螺旋矩阵
#include <vector>
using namespace std;
class Solution 
{
public:
    // 按层遍历
    vector<vector<int>> generateMatrix(int n) 
    {
        vector<vector<int>> value(n, vector<int>(n));
        // 规定层号
        int top = 0;
        int left = 0;
        int right = n - 1;
        int bottom = n - 1;
        int k = 0;  // 待填充的元素
        while (k < n*n)
        {
            // top
            for (int i = left; i <= right; ++i)
            {
                value[top][i] = ++k;
            }
            ++top;
            // right
            for (int i = top; i <= bottom; ++i)
            {
                value[i][right] = ++k;
            }
            --right;
            // bottom
            for (int i = right; i >= left; --i)
            {
                value[bottom][i] = ++k;
            }
            --bottom;
            // left
            for (int i = bottom; i >= top; --i)
            {
                value[i][left] = ++k;
            }
            ++left;
        }
        return value;
    }
};

int main()
{
    Solution s;
    s.generateMatrix(3);
}