// 最小基因变化
// 回溯
#include <string>
#include <vector>
#include <algorithm>
#include <unordered_set>
using namespace std;
class Solution 
{
private:
    int minCount = INT_MAX;
    int count = 0;
    unordered_set<string> se;
    void backTracking(string &start, string &end, vector<string> &bank)
    {
        if (start == end)
        {
            minCount = min(minCount, count);
            return;
        }
        for (auto &&str : bank)
        {
            int diffCount = 0;
            for (int i = 0; i < start.size(); ++i)
            {
                if (start.at(i) != str.at(i))
                {
                    ++diffCount;
                }
            }
            if (diffCount == 1 && se.count(str) == 0)
            {
                ++count;
                se.insert(str);
                backTracking(str, end, bank);
                --count;
                se.erase(str);
            }
        }
        return;
    }
public:
    int minMutation(string start, string end, vector<string>& bank) 
    {
        backTracking(start, end, bank);
        if (minCount == INT_MAX)
        {
            return -1;
        }
        return minCount;
    }
};