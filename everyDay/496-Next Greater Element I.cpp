// 下一个更大元素 I
#include <vector>
#include <stack>
#include <unordered_map>
using namespace std;
class Solution 
{
public:
    vector<int> nextGreaterElement(vector<int>& nums1, vector<int>& nums2) 
    {
        int size1 = nums1.size();
        int size2 = nums2.size();
        vector<int> result(size1, -1);
        unordered_map<int, int> uma;
        for (int i = 0; i < size1; ++i)
        {
            uma[nums1.at(i)] = i;
        }
        stack<int> st;
        st.push(0);
        for (int i = 1; i < size2; ++i)
        {
            if (nums2.at(i) < nums2.at(st.top()))
            {
                st.push(i);
            }
            else if (nums2.at(i) == nums2.at(st.top()))
            {
                st.push(i);
            }
            else
            {
                while (!st.empty() && nums2.at(i) > nums2.at(st.top()))
                {
                    if (uma.count(nums2.at(st.top())) != 0)
                    {
                        result.at(uma[nums2.at(st.top())]) = nums2.at(i);
                    }
                    st.pop();
                }
                st.push(i);
            }
        }
        return result;
    }
};