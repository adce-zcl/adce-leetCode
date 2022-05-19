// 每日温度
#include <vector>
#include <stack>
using namespace std;
class Solution 
{
public:
    vector<int> dailyTemperatures(vector<int>& temperatures) 
    {
        int size = temperatures.size();
        vector<int> result(size, 0);
        stack<int> st;
        st.push(0);
        for (int i = 1; i < size; ++i)
        {
            if (temperatures.at(i) < temperatures.at(st.top()))
            {
                st.push(i);
            }
            else if (temperatures.at(i) == temperatures.at(st.top()))
            {
                st.push(i);
            }
            else
            {
                while (!st.empty() && temperatures.at(i) > temperatures.at(st.top()))
                {
                    result.at(st.top()) = i - st.top();
                    st.pop();
                }
                st.push(i);
            }
        }
        return result;
    }
};