// 移除字母异位词后的结果数组
#include <vector>
#include <string>
#include <algorithm>
using namespace std;
class Solution 
{
public:
    vector<string> removeAnagrams(vector<string>& words) 
    {
        if (words.size() == 1)
        {
            return words;
        }
        string preword = words.at(0);
        sort(preword.begin(), preword.end());
        int index = 1;
        while (index < words.size())
        {
            string curword = words.at(index);
            sort(curword.begin(), curword.end());
            if (preword == curword)
            {
                words.erase(words.begin() + index);
                continue;
            }
            ++index;
            preword = curword;
        }
        return words;
    }
};