// 删列造序
#include <vector>
#include <string>
using namespace std;
class Solution 
{
public:
    int minDeletionSize(vector<string>& strs) 
    {
        int rows = strs.size();
        int cols = strs.at(0).size();
        int count = 0;
        for (int col = 0; col < cols; ++col)
        {
            int row;
            for (row = 1; row < rows; ++row)
            {
                if (strs.at(row).at(col) < strs.at(row-1).at(col))
                {
                    break;
                }
            }
            if (row < rows)
            {
                ++count;
            }
        }
        return count;
    }
};