#include <string>
#include <iostream>
#include <vector>
#include <unordered_set>
#include <algorithm>
using namespace std;
class Solution {
public:
    // 先将数组排序，排序规则先按长度，再按大小
    // 这样相同长度的会放在一起，且能保证比它短的一定已经见过，而且大小是逆序的，所以可以直接更新答案。
    string longestWord(vector<string>& words)
    {
        sort(words.begin(), words.end(), [=](string a, string b)
             { return b.size() != a.size() ? b.size() > a.size() : a > b; });
        unordered_set<string> s;
        s.insert("");
        string value;
        string temp;
        for (int i = 0; i < words.size(); i++)
        {
            temp = words.at(i);
            if(s.count(temp.substr(0,temp.size()-1)))
            {
                s.insert(temp);
                value = temp;
            }
        }
        return value;
    }
};
int main()
{
    Solution s;
    vector<string> words = {"rac","rs","ra","on","r","otif","o","onpdu","rsf","rs","ot","oti","racy","onpd" };
    system("pause");
    exit(0);
}