// 柱状图中最大的矩形
// 单调栈
#include <vector>
#include <stack>
using namespace std;
class Solution 
{
public:
    int largestRectangleArea(vector<int>& heights) 
    {
        // 为了便于处理，在数组首尾增加高度为0的数据
        heights.insert(heights.begin(), 0);
        heights.push_back(0);
        int size = heights.size();
        // 栈存放下标
        stack<int> st;
        st.push(0);
        int result = 0;
        for (int i = 1; i < size; ++i)
        {
            if (heights.at(i) > heights.at(st.top()))
            {
                st.push(i);
            }
            else if (heights.at(i) == heights.at(st.top()))
            {
                st.push(i);
            }
            else
            {
                while (!st.empty() && heights.at(i) < heights.at(st.top()))
                {
                    int midIndex = st.top();
                    st.pop();
                    int leftIndex = st.top();
                    int rightIndex = i;
                    int width = rightIndex - leftIndex - 1;
                    int height = heights.at(midIndex);
                    result = max(result, height * width);
                }
                st.push(i);
            }
        }
        return result;
    }
};