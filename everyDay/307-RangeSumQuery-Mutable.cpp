// 307. 区域和检索 - 数组可修改
// 难在优化
// 二叉索引树
#include <vector>
using namespace std;
class NumArray 
{
private:
    vector<int> &nums;
    vector<int> tree;   // 树状数组
    
    // 求二进制最后一个1 的位置
    int lowBit(int index)
    {
        return index & (index ^ (index - 1));
    }
    // 给二叉索引树增加数值
    void add(int _index, int val)
    {
        // 目标想把index变成val，而二叉索引树只看比以前增加了多少
        int index = _index + 1;
        while (index < (int)tree.size())
        {
            tree.at(index) += val;
            index += lowBit(index);
        }
    }
    // 求前缀和
    int getSum(int _index)
    {
        int sum = 0;
        int index = _index + 1;
        while (index > 0)
        {
            sum += tree.at(index);
            index -= lowBit(index);
        }
        return sum;
    }

public:
    NumArray(vector<int>& nums) : nums(nums), tree(nums.size() + 1)
    {
        for (size_t i = 0; i < nums.size(); ++i)
        {
            add(i, nums.at(i));
        }
    }
    
    void update(int index, int val) 
    {
        add(index, val - nums.at(index));
        nums.at(index) = val;
    }
    
    int sumRange(int left, int right) 
    {
        return getSum(right) - getSum(left - 1);
    }
};

/**
 * Your NumArray object will be instantiated and called as such:
 * NumArray* obj = new NumArray(nums);
 * obj->update(index,val);
 * int param_2 = obj->sumRange(left,right);
 */
int main()
{
    vector<int> v{1, 3, 5};
    NumArray n(v);
    n.sumRange(0, 2);
    n.update(1, 2);
    n.sumRange(0, 2);
}