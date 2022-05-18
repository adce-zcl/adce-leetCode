#include <string>
#include <iostream>
using namespace std;
class Solution
{
public:
    int strongPasswordChecker(string password)
    {
        // 先判断字符的种类是不是满足三种
        int A = 0, B = 0, C = 0;
        int type_size = 0;
        for (auto &&i : password)
        {
            if (i >= 'a' && i <= 'z') {A = 1;}
            if (i >= 'A' && i <= 'Z') {B = 1;}
            if (i >= '1' && i <= '9') {C = 1;}
            if (A == 1 && B == 1 && C == 1) {break;}
        }
        type_size = A + B + C;
        int step = 0;   // 变换的次数
        // 判断字符的个数
        int size = password.size();
        // size < 6
        if (size < 6)
        {
            // 删除操作只是为了破坏连续字串，可以用替换代替
            // 很可能会用到增加操作
            // 如果有三种字符，那么就肯定不会有超过四个连续，所以用一个替换就可以
            // 如果没有三个字符，在替换成三个字符之后，也可以直接满足
            step = max(6 - size, 3 - type_size);
        }
        // 6 <= size <= 20
        else if (size >= 6 && size <= 20)
        {
            // 如果字符种类不够可以用替换
            // 如果需要破坏连续字串，也可以用替换
            // 而替换次数，每遇到3个连续字符就+1
            // 如果替换次数正好大于等于替换字符种类的次数，那么就可以更优秀
            int count = 0;  // 替换次数
            for (int i = 0; i < size; ++i)
            {
                int j = i;
                while (password.at(j) == password.at(i)) {++j;}
                count += (j - i) / 3;   // 逢三改一
                i = j;
            }
            step = max(count, 3 - type_size);
        }
        // size >= 20
        else if (size > 20)
        {
            // 只需要用到删除和替换操作
            int count = 0;
            /*...*/
            // 这个位置的模拟大法不写了
        }
        return step;
    }
};
