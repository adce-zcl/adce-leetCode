// 赎金信
// 可以用map，但是底层维护红黑树是比较费事的，如果都是小写字母，为什么不直接用整数数组呢？
#include <string>

using namespace std;
class Solution 
{
public:
    bool canConstruct(string ransomNote, string magazine) 
    {
        int magazine_array[26] = {0};
        for (int i = 0; i < magazine.size(); ++i)
        {
            ++magazine_array[magazine.at(i) - 'a'];
        }
        for (int i = 0; i < ransomNote.size(); ++i)
        {
            --magazine_array[ransomNote.at(i) - 'a'];
            if(magazine_array[ransomNote.at(i) - 'a'] < 0)
            {
                return false;
            }
        }
        return true;
    }
};