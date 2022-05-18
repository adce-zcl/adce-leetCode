//  自除数
#include <vector>
using namespace std;

class Solution 
{
public:
    vector<int> selfDividingNumbers(int left, int right) 
    {
        vector<int> value;
        int current;
        int last;
        for (int i = left; i <= right; ++i)
        {
            current = i;
            while (current != 0)
            {
                last = current % 10;
                if (last == 0 || i % last != 0)
                {
                    break;
                }
                current = current / 10;
            }
            if(current == 0)
            {
                value.push_back(i);
            }
        }
        return value;
    }
};