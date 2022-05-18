// 完全二叉树的节点个数
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
    int countNodes(TreeNode* root) 
    {
        if (root == nullptr)
        {
            return 0;
        }
        TreeNode *left = root->left;
        TreeNode *right = root->right;
        int left_height = 0, right_height = 0;
        while (left != nullptr)
        {
            left = left->left;
            ++left_height;
        }
        while (right != nullptr)
        {
            right = right->right;
            ++right_height;
        }
        if (left_height == right_height)
        {
            return (2 << left_height) - 1;
        }
        // 递归计算左子树和右子树
        return countNodes(root->left) + countNodes(root->right) + 1;
    }
};