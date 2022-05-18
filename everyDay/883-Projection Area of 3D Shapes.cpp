// 三维形体投影面积
#include <vector>
using namespace std;
class Solution 
{
public:
    int projectionArea(vector<vector<int>>& grid) 
    {
        int xyArea = 0, xzArea = 0, yzArea = 0;
        for (size_t i = 0; i < grid.size(); ++i)
        {
            int xz = 0, yz = 0;
            for (size_t j = 0; j < grid.at(i).size(); ++j)
            {
                if (grid[i][j] != 0)
                {
                    ++xyArea;
                }
                xz = max(xz, grid[i][j]);
                yz = max(yz, grid[j][i]);
            }
            xzArea += xz;
            yzArea += yz;
        }
        return xyArea + xzArea + yzArea;
    }
};