// 字符串的总引力
#include <string>
#include <vector>
#include <unordered_set>
using namespace std;
class Solution 
{
public:
    vector<string> strs;
    string path;
    long long sum;
    void backTracking(string &s, int start_index)
    {
        if (start_index == s.size())
        {
            return;
        }
        for (size_t i = start_index; i < s.size(); ++i)
        {
            path.push_back(s.at(i));
            strs.push_back(path);
            backTracking(s, i + 1);
            path.pop_back();
        }
    }

    void getSum()
    {
        for (auto &&str : strs)
        {
            unordered_set<char> se;
            for (size_t i = 0; i < str.size(); ++i)
            {
                char ch = str.at(i);
                if (se.count(ch) == 0)
                {
                    se.insert(ch);
                    ++sum;
                }
                else
                {
                    continue;
                }
            }
        }
    }


    long long appealSum(string s) 
    {
        backTracking(s, 0);
        getSum();
        return sum;
    }
};

int main()
{
    Solution s;
    s.appealSum("abbca");
}