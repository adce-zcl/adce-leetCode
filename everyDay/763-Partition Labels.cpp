// 划分字母区间
#include <vector>
#include <string>
#include <unordered_map>
using namespace std;
class Solution 
{
public:
    vector<int> partitionLabels(string s) 
    {
        unordered_map<char, int> ma;
        for (int i = s.size() - 1; i >= 0; --i)
        {
            // 最后一次出现，记录最后一次出现的位置
            if (ma.count(s.at(i)) == 0)
            {
                ma[s.at(i)] = i;
            }
        }
        vector<int> result;
        int left = 0;
        int right = 0;
        for (int i = 0; i < s.size(); ++i)
        {
            right = max(right, ma[s.at(i)]);
            if (i == right)
            {
                result.push_back(right - left + 1);
                left = right + 1;
            }
        }
        return result;
    }
};