// 验证外星语词典
#include <vector>
#include <string>
#include <unordered_map>
using namespace std;
class Solution 
{
private:
    unordered_map<char, int> ma;
    bool compe(string &before, string &laft)
    {
        int preIndex = 0, lastIndex = 0;
        while (preIndex < before.size() && lastIndex < laft.size())
        {
            if (ma[before.at(preIndex)] > ma[laft.at(lastIndex)])
            {
                return false;
            }
            else if (ma[before.at(preIndex)] < ma[laft.at(lastIndex)])
            {
                return true;
            }
            else
            {
                ++preIndex;
                ++lastIndex;
            }
        }
        if (before.size() > laft.size())
        {
            return false;
        }
        return true;
    }
public:
    bool isAlienSorted(vector<string>& words, string order) 
    {
        for (int i = 0; i < order.size(); ++i)
        {
            ma[order.at(i)] = i;
        }
        for (int i = 1; i < words.size(); ++i)
        {
            if (!compe(words.at(i-1), words.at(i)))
            {
                return false;
            }
        }
        return true;
    }
};