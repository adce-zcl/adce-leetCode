// 统计网格图中没有被保卫的格子数
#include <vector>
#include <unordered_set>
using namespace std;
class Solution 
{
private:
    int rows;
    int cols;
    vector<vector<int>> space;

public:
    int countUnguarded(int m, int n, vector<vector<int>>& guards, vector<vector<int>>& walls) 
    {
        rows = m;
        cols = n;
        long sum = m * n;
        unordered_set<int> red_rows;
        unordered_set<int> red_cols;
        for (auto &&guard : guards)
        {
            if (red_rows.count(guard.at(0)) == 0)
            {
                red_rows.insert(guard.at(0));
            }
            if (red_cols.count(guard.at(1)) == 0)
            {
                red_cols.insert(guard.at(1));
            }
        }
        // 还剩rows - red_rows.size() * cols - red_cols.size()
        for (auto &&wall : walls)
        {
            
        }
        
        
    }
};