// 按位与结果大于零的最长组合
#include <vector>
#include <climits>
using namespace std;
class Solution 
{
private:
    int getAnd(vector<int> &nums)
    {
        int value = INT_MAX;
        for (auto &&num : nums)
        {
            value &= num;
        }
        return value;
    }
public:
    int largestCombination(vector<int>& candidates) 
    {
        int value = 0;
        value = getAnd(candidates);
        if (value > 0)
        {
            return value;
        }
        for (int i = 0; i < candidates.size(); ++i)
        {
            candidates.at(i) = ~candidates.at(i);
            
        }
        

        return ;
    }
};

int main()
{
    Solution s;
    vector<int> vec{33,93,31,99,74,37,3,4,2,94,77,10,75,54,24,95,65,100,41,82,35,65,38,49,85,72,67,21,20,31};
    s.largestCombination(vec);
}