// 图片平滑器
#include <vector>
using namespace std;

class Solution
{
public:
    vector<vector<int>> imageSmoother(vector<vector<int>> &img)
    {
        int n = img.size();
        int m = img[0].size();
        vector<vector<int>> value(n,vector<int>(m));
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < m; j++)
            {
                int temp = 0;
                int num = 0;
                for (int x = i - 1; x <= i + 1; x++)
                {
                    for (int y = j - 1; y <= j + 1; y++)
                    {
                        if(x >= 0 && y >= 0 && x < n && y < m)
                        {
                            temp += img[x][y];
                            num++;
                        }
                    }
                }
                value[i][j] = temp / num;
            }
        }
        return value;
    }
};