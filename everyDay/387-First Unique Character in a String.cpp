// 字符串中的第一个唯一字符
#include <string>
#include <map>
using namespace std;
class Solution 
{
public:
    int firstUniqChar(string s) 
    {
        map<char, int> ma;
        int index = 0;
        for (auto &&ch : s)
        {
            if (ma.count(ch) == 0)
            {
                ma[ch] = index;
            }
            else
            {
                ma[ch] = -1;
            }
            ++index;
        }
        index = INT_MAX;
        for (auto &&i : ma)
        {
            if (i.second != -1 && i.second < index)
            {
                index = i.second;
            }
        }
        if (index == INT_MAX)
        {
            index = -1;
        }
        return index;
    }
};
int main()
{
    string s = "loveleetcode";
    Solution ss;
    ss.firstUniqChar(s);
}