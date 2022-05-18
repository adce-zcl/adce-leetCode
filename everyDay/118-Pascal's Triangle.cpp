// 杨辉三角
#include <vector>
using namespace std;
class Solution 
{
public:
    vector<vector<int>> generate(int numRows) 
    {
        vector<vector<int>> t(numRows);
        for (int i = 1; i <= numRows; ++i)
        {
            t.at(i).resize(i);
            t.at(i).at(0) = 1;
            t.at(i).at(i - 1) = 1;
            for (int j = 1; j < i; ++j)
            {
                t.at(i).at(j) = t.at(i - 1).at(j - 1) + t.at(i - 1).at(j);
            }
        }
        return t;
    }
};