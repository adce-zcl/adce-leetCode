// KMP
// 在一个串中查找是否出现过另一个串，这是KMP的看家本领
#include <string>
#include <vector>
#include <iostream>
using namespace std;
class Solution 
{
public:

    int strStr(string haystack, string needle) 
    {
        if (needle.size() == 0)
        {
            return 0;
        }
        vector<int> prefix(needle.size());
        getPrefix(prefix, needle);

        for (int father_index = 0, child_index = 0; father_index < haystack.size(); ++father_index)
        {
            while (child_index > 0 && haystack.at(father_index) != needle.at(child_index))
            {
                child_index = prefix.at(child_index - 1);
            }
            if (haystack.at(father_index) == needle.at(child_index))
            {
                ++child_index;
            }
            // 剪枝
            if (haystack.size() - father_index < needle.size() - child_index)
            {
                break;
            }
            if (child_index == needle.size())
            {
                return father_index - needle.size() + 1;
            }
        }
        return -1;
    }
    // 构建前缀表数组
    void getPrefix(vector<int> &prefix, string &needle)
    {
        // 找到最长相等前后缀
        int j = 0;  // 前缀的末尾下标的位置；也代表包括i之前的字串的最长相等前后缀的长度
        int i = 1;  // 后缀的末尾下标的位置
        prefix.at(0) = 0;    // 0的位置是0
        // 分别判断以needle[i]为后缀末尾的字串
        for ( i; i < needle.size(); ++i)    
        {
            // 回退
            while (j > 0 && needle.at(j) != needle.at(i))
            {
                j = prefix.at(j - 1);
            }
            // 如果前后缀的末尾相等
            if (needle.at(j) == needle.at(i))
            {
                ++j;
            }
            prefix.at(i) = j;
        }
    }
};
int main()
{
    


    string haystack = "aabaaabaaac", needle = "aabaaac";
    Solution s;
    cout << s.strStr(haystack, needle);
    system("pause");
}