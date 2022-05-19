// 下一个更大元素 II
#include <vector>
#include <stack>
using namespace std;
class Solution 
{
public:
    vector<int> nextGreaterElements(vector<int>& nums) 
    {
        // 两倍扩容
        vector<int> doubleNums(nums.begin(), nums.end());
        doubleNums.insert(doubleNums.end(), nums.begin(), nums.end());
        int size = doubleNums.size();
        vector<int> result(size, -1);
        stack<int> st;
        st.push(0);
        for (int i = 1; i < size; ++i)
        {
            if (doubleNums.at(i) < doubleNums.at(st.top()))
            {
                st.push(i);
            }
            else if (doubleNums.at(i) == doubleNums.at(st.top()))
            {
                st.push(i);
            }
            else
            {
                while (!st.empty() && doubleNums.at(i) > doubleNums.at(st.top()))
                {
                    result.at(st.top()) = doubleNums.at(i);
                    st.pop();
                }
                st.push(i);
            }
        }
        result.resize(result.size() / 2);
        return result;
    }
};