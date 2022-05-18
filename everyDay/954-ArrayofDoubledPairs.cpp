// 二倍数对数组
#include <vector>
#include <unordered_map>
#include <algorithm>
using namespace std;
class Solution
{
public:
    bool canReorderDoubled(vector<int> &arr)
    {
        unordered_map<int, int> count;
        for (auto &&i : arr)
        {
            ++count[i];
        }
        // 因为0只能和0配对，所以0的个数必须是偶数
        if (count[0] % 2 != 0)
        {
            return false;
        }
        sort(arr.begin(), arr.end(), [&](int &a, int &b) { return abs(a) < abs(b); });
        for (auto &&i : arr)
        {
            if (count[2 * i] < count[i])
            {
                return false;
            }
            else
            {
                count[2 * i] -= count[i];
                count[i] = 0;
            }
        }
        return true;
    }
};