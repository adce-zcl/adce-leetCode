// 完成所有任务需要的最少轮数
#include <vector>
#include <algorithm>
using namespace std;
class Solution 
{
public:
    int minimumRounds(vector<int>& tasks) 
    {
        if (tasks.size() < 2)
        {
            return -1;
        }
        int i = tasks.size() % 3;
        int I = tasks.size() / 3;
        int j = tasks.size() % 2;
        int J = tasks.size() / 2;
        if ((i == 1 && I == 0) || (j == 1 && J == 0))
        {
            return -1;
        }
        sort(tasks.begin(), tasks.end());

        int count = 1;  // 计数
        int pre_num = tasks.at(0);  // 当前的数字
        vector<int> vec;

        for (size_t i = 1; i < tasks.size(); ++i)
        {
            if (tasks.at(i) == pre_num)
            {
                ++count;
            }
            else
            {
                vec.push_back(count);
                count = 1;
                pre_num = tasks.at(i);
            }
        }
        vec.push_back(count);
        int t = 0;
        for (auto &&count : vec)
        {
            if (count == 3 || count == 2)
            {
                continue;
            }
            else if (count < 2)
            {
                return -1;
            }
            else
            {
                int i = count % 3;
                int I = count / 3;
                int j = count % 2;
                int J = count / 2;
                if ((i == 1 && I == 0) || (j == 1 && J == 0))
                {
                    return -1;
                }
                else
                {
                    int temp = count / 2;
                    if (temp == 0)
                    {
                        ++t;
                    }
                    else
                    {
                        t += temp;
                    }
                    continue;
                }
            }
        }

        return vec.size() + t;
    }
};