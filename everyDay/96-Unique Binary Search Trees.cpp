// 不同的二叉搜索树
#include <vector>
#include <iostream>
using namespace std;
class Solution 
{
public:
    int numTrees(int n) 
    {
        vector<int> dp(n + 1);
        dp.at(0) = 1;
        dp.at(1) = 1;
        for (int i = 2; i <= n; ++i)
        {
            for (int j = 1; j <= i; ++j)
            {
                dp.at(i) += dp.at(j - 1) * dp.at(i - j);
            }
            cout << dp.at(i) << endl;
        }
        return dp.at(n);
    }
};
int main()
{
    Solution s;
    s.numTrees(3);
    system("pause");
}