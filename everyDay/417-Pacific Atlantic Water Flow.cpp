// 太平洋大西洋水流问题
// 深搜是递归，广搜是遍历
#include <vector>
using namespace std;
class Solution 
{
private:
    int rows, cols;
    vector<vector<int>> ans;
    vector<vector<int>> pacific;
    vector<vector<int>> atlantic;
    void dfs(vector<vector<int>> &ocean, vector<vector<int>>& heights, int row, int col)
    {
        if (ocean.at(row).at(col) == 1)
        {
            return;
        }
        ocean.at(row).at(col) = 1;
        if (pacific.at(row).at(col) == 1 && atlantic.at(row).at(col) == 1)
        {
            ans.push_back({row, col});
        }

        if (row - 1 >= 0 && heights.at(row - 1).at(col) >= heights.at(row).at(col))
        {
            dfs(ocean, heights, row - 1, col);
        }
        if (col - 1 >= 0 && heights.at(row).at(col - 1) >= heights.at(row).at(col))
        {
            dfs(ocean, heights, row, col - 1);
        }
        if (col + 1 < cols && heights.at(row).at(col + 1) >= heights.at(row).at(col))
        {
            dfs(ocean, heights, row, col + 1);
        }
        if (row + 1 < rows && heights.at(row + 1).at(col) >= heights.at(row).at(col))
        {
            dfs(ocean, heights, row + 1, col);
        }
    }
public:
    vector<vector<int>> pacificAtlantic(vector<vector<int>>& heights) 
    {
        rows = heights.size();
        cols = heights.at(0).size();
        pacific = vector<vector<int>>(rows, vector<int>(cols, 0));
        atlantic = vector<vector<int>>(rows, vector<int>(cols, 0));
        // 从四周开始深搜
        for (int row = 0; row < rows; ++row)
        {
            dfs(pacific, heights, row, 0);
            dfs(atlantic, heights, row, cols - 1);
        }
        for (int col = 0; col < cols; ++col)
        {
            dfs(pacific, heights, 0, col);
            dfs(atlantic, heights, rows - 1, col);
        }
        return ans;
    }
};

int main()
{
    vector<vector<int>> heights{{2, 1}, {1, 2}};
    Solution s;
    s.pacificAtlantic(heights);
}