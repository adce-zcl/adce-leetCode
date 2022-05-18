// 四数相加
#include <vector>
#include <unordered_map>
using namespace std;
class Solution 
{
public:
    int fourSumCount(vector<int>& nums1, vector<int>& nums2, vector<int>& nums3, vector<int>& nums4) 
    {
        // 把nums1和nums2的和保存下载
        unordered_map<int,int> nums1_and_nums2;
        for (int i = 0; i < nums1.size(); ++i)
        {
            for (int j = 0; j < nums2.size(); ++j)
            {
                ++nums1_and_nums2[nums1.at(i) + nums2.at(j)];
            }
        }
        // 把nums3和nums4的和保存下载
        int temp;
        int value = 0;
        int sum;
        for (int i = 0; i < nums3.size(); ++i)
        {
            for (int j = 0; j < nums4.size(); ++j)
            {
                sum = nums3.at(i) + nums4.at(j);
                if(nums1_and_nums2.find(-sum) != nums1_and_nums2.end())
                {
                    value += nums1_and_nums2[-sum];
                }
            }
        }
        return value;
    }
};