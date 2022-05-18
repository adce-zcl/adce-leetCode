// II. 左旋转字符串 LCOF
// 花式反转
#include <string>
#include <iostream>
#include <algorithm>
using namespace std;
class Solution 
{
public:
    string reverseLeftWords(string s, int n) 
    {
        reverse(s.begin(), s.end());
        reverse(s.begin(), s.begin() + s.size() - n);
        reverse(s.end() - n, s.end());
        return s;
    }
};