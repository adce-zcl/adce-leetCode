// 寻找比目标字母大的最小字母
#include <vector>
using namespace std;
class Solution 
{
public:
    char nextGreatestLetter(vector<char>& letters, char target) 
    {
        for (auto &&ch : letters)
        {
            if (ch > target)
            {
                return ch;
            }
        }
        return letters.at(0);
    }
};