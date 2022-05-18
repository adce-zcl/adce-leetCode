// 最大二叉树
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
#include <algorithm>
using namespace std;
struct TreeNode 
{
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};
class Solution 
{
public:
    TreeNode* constructMaximumBinaryTree(vector<int>& nums) 
    {
        if (nums.size() == 0)
        {
            return nullptr;
        }
        vector<int>::iterator root_it = max_element(nums.begin(), nums.end());
        TreeNode *root = new TreeNode(*root_it);
        if (nums.size() == 1)
        {
            return root;
        }
        vector<int> nums_left(nums.begin(), root_it);
        vector<int> nums_right(root_it + 1, nums.end());
        root->left = constructMaximumBinaryTree(nums_left);
        root->right = constructMaximumBinaryTree(nums_right);
        return root;
    }
};