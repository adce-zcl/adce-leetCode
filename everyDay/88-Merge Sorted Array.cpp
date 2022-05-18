// 合并两个有序数组
#include <vector>
using namespace std;
class Solution 
{
public:
    void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) 
    {
        int start = nums1.size() - 1;
        int index1 = m - 1, index2 = n - 1;
        while (index1 >= 0 && index2 >= 0)
        {
            if (nums1.at(index1) > nums2.at(index2))
            {
                nums1.at(start) = nums1.at(index1);
                --start;
                --index1;
            }
            else
            {
                nums1.at(start) = nums2.at(index2);
                --start;
                --index2;
            }
        }
        while (index1 >= 0)
        {
            nums1.at(start--) = nums1.at(index1--);
        }
        while (index2 >= 0)
        {
            nums1.at(start--) = nums2.at(index2--);
        }
        return;
    }
};