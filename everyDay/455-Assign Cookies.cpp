// 分发饼干
#include <algorithm>
#include <vector>
using namespace std;
class Solution 
{
public:
    int findContentChildren(vector<int>& g, vector<int>& s) 
    {
        sort(g.begin(), g.end());
        sort(s.begin(), s.end());
        int max_num = 0;
        int index_g = 0, index_s = 0;
        while (index_g < g.size() && index_s < s.size())
        {
            if (s.at(index_s) >= g.at(index_g))
            {
                ++max_num;
                ++index_s;
                ++index_g;
            }
            else
            {
                ++index_s;
            }
        }
        return max_num;
    }
};