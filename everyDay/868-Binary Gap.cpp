// 二进制间距
#include <string>
#include <cstdlib>
#include <bitset>
#include <iostream>
using namespace std;
class Solution 
{
public:
    int binaryGap(int n) 
    {
        bitset<32> bit(n);
        string a = bit.to_string();
        int maxLength = 0;
        int pos = a.find_first_of('1', 0);
        while (true)
        {
            int next = a.find_first_of('1', pos + 1);
            if (next == string::npos)
            {
                break;
            }
            maxLength = max(maxLength, next - pos);
            pos = next;
        }
        return maxLength;
    }
};
