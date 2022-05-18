// 统计是给定字符串前缀的字符串数目
#include <vector>
#include <string>
#include <unordered_set>
using namespace std;
class Solution 
{
public:
    int countPrefixes(vector<string>& words, string s) 
    {
        unordered_set<string> se;
        int result = 0;
        for (int i = 0; i < s.size(); ++i)
        {
            string str(s.begin(), s.begin() + i + 1);
            se.insert(str);
        }
        for (auto &&word : words)
        {
            if (se.count(word) != 0)
            {
                ++result;
            }
        }
        return result;
    }
};