// 字典序排数
#include <vector>
using namespace std;

class Solution 
{
private:
    vector<int> result;
    void backTracking(int n, int start_index)
    {
        if (start_index  > n)
        {
            return;
        }
        result.push_back(start_index);
        for (size_t i = 0; i <= 9; ++i)
        {
            backTracking(n, start_index * 10 + i);
        }
    }
public:
    vector<int> lexicalOrder(int n) 
    {
        for (size_t i = 1; i <= 9; ++i)
        {
            backTracking(n, i);
        }
        return result;
    }
};