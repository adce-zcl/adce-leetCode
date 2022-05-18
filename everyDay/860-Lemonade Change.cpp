// 柠檬水找零
#include <vector>
#include <unordered_map>
using namespace std;
class Solution 
{
public:
    bool lemonadeChange(vector<int>& bills) 
    {
        unordered_map<int, int> totalBills;
        for (auto &&bill : bills)
        {
            if (bill == 10)
            {
                if (totalBills[5] <= 0)
                {
                    return false;
                }
                --totalBills[5];
                ++totalBills[10];
            }
            else if (bill == 20)
            {
                if (totalBills[10] > 0)
                {
                    --totalBills[10];
                    if (totalBills[5] <= 0)
                    {
                        return false;
                    }
                    --totalBills[5];
                }
                else
                {
                    if (totalBills[5] < 3)
                    {
                        return false;
                    }
                    totalBills[5] -= 3;
                }
            }
            else
            {
                ++totalBills[5];
            }
        }
        return true;
    }
};