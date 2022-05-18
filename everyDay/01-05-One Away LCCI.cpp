// 面试题 01.05. 一次编辑
#include <string>
#include <cmath>
#include <unordered_map>
using namespace std;
class Solution 
{
public:
    bool oneEditAway(string first, string second) 
    {
        int firstSize = first.size();
        int secondSize = second.size();
        int sizeSub = abs(firstSize - secondSize);
        if (sizeSub > 1)
        {
            return false;
        }
        else if (sizeSub == 0)
        {
            int count = 0;
            for (int i = 0; i < firstSize; ++i)
            {
                if (first.at(i) != second.at(i))
                {
                    ++count;
                    if (count > 1)
                    {
                        return false;
                    }
                }
            }
        }
        else
        {
            string longstr, shortstr;
            if (firstSize > secondSize)
            {
                longstr = first;
                shortstr = second;
            }
            else
            {
                longstr = second;
                shortstr = first;
            }
            int count = 1;
            int longIndex = 0, shortIndex = 0;
            while (longIndex < longstr.size() && shortIndex < shortstr.size())
            {
                if (longstr.at(longIndex) != shortstr.at(shortIndex))
                {
                    ++longIndex;
                    --count;
                    if (count < 0)
                    {
                        return false;
                    }
                }
                else
                {
                    ++longIndex;
                    ++shortIndex;
                }
            }
        }
        return true;
    }
};