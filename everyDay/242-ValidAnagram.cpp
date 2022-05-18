// 有效的字母异味词
#include <string>
#include <unordered_map>
using namespace std;
class Solution 
{
public:
    bool isAnagram(string s, string t) 
    {
        unordered_map<char, int> s_map;
        for (size_t i = 0; i < s.size(); ++i)
        {
            if(s_map.count(s.at(i)) == 0)
            {
                s_map.emplace(pair<char, int>(s.at(i), 1));
            }
            else
            {
                ++s_map[s.at(i)];
            }
        }
        for (size_t i = 0; i < t.size(); ++i)
        {
            if(s_map.count(t.at(i)) == 0)
            {
                return false;
            }
            else
            {
                --s_map[t.at(i)];
                if(s_map[t.at(i)] == 0)
                {
                    s_map.erase(t.at(i));
                }
            }
        }
        if(s_map.size() == 0)
        {
            return true;
        }
        else
        {
            return false;
        }
    }
};