// 反转字符串
#include <vector>
using namespace std;
class Solution 
{
public:
    void reverseString(vector<char>& s) 
    {
        int left = 0;
        int right = s.size() - 1;
        while (left < right)
        {
            swap(s.at(left++), s.at(right--));
        }
    }
};