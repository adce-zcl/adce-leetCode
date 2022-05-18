// 将有序数组转换为二叉搜索树
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
#include <vector>
using namespace std;
struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};
class Solution 
{
private:
    TreeNode* arrayToBST(vector<int>& nums, int left, int right)
    {
        // 确定root节点的位置,中间靠左
        if (left > right)
        {
            return nullptr;
        }
        int root_index = (right - left) / 2 + left;
        TreeNode *root = new TreeNode(nums.at(root_index));
        root->left = arrayToBST(nums, left, root_index - 1);
        root->right = arrayToBST(nums, root_index + 1, right);
        return root;
    }
public:
    TreeNode* sortedArrayToBST(vector<int>& nums) 
    {
        return arrayToBST(nums, 0, nums.size() - 1);
    }
};