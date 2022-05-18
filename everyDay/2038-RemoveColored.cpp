// 如果相邻两个颜色均相同则删除当前颜色
#include <string>
#include <iostream>
using namespace std;
class Solution 
{
private:
    char flg = 'A'; //标志谁开始

public:
    bool winnerOfGame(string colors)
    {
        int count = 0;
        int AB[2] = {0, 0};
        char ch = 'C';
        for (auto &&i : colors)
        {
            if(i != ch)
            {
                ch = i;
                count = 1;
            }
            else if(++count >= 3)
            {
                AB['B' - i]++;
            }
        }
        return AB[1] > AB[0];
    }
    bool winnerOfGame1(string colors) 
    {
        while (true)
        {
            if(flg == 'A')
            {
                // 找到三个A,没有返回false
                auto index = colors.find("AAA");
                if(index == string::npos)
                {
                    return false;
                }
                colors.erase(colors.begin() + index);
                flg = 'B';
            }
            else
            {
                auto index = colors.find("BBB");
                if (index == string::npos)
                {
                    return true;
                }
                colors.erase(colors.begin() + index);
                flg = 'A';
            }
        }
    }
};

int main()
{
    Solution s;
    std::string str = "AAABABB";
    std::cout << s.winnerOfGame(str);
    system("pause");
    exit(0);
}