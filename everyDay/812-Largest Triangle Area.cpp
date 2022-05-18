// 最大三角形面积
#include <vector>
#include <cmath>
using namespace std;
class Solution 
{
private:
    double getArea(vector<int> &A, vector<int> &B, vector<int> &C)
    {
        return abs((A.at(0) * B.at(1) + B.at(0) * C.at(1) + C.at(0) * A.at(1) - A.at(0) * C.at(1) - B.at(0) * A.at(1) - C.at(0) * B.at(1))) * 0.5;
    }
public:
    double largestTriangleArea(vector<vector<int>>& points) 
    {
        double maxArea = 0.0;
        for (int i = 0; i < points.size(); ++i)
        {
            for (int j = i + 1; j < points.size(); ++j)
            {
                for (int k = j + 1; k < points.size(); ++k)
                {
                    maxArea = max(maxArea, getArea(points.at(i), points.at(j), points.at(k)));
                }
            }
        }
        return maxArea;
    }
};