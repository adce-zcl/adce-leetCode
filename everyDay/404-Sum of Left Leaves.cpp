// 左叶子之和
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
    int sumOfLeftLeaves(TreeNode* root) 
    {
        return sumLeft(root);
    }
    int sumLeft(TreeNode *root)
    {
        if (root == nullptr)
        {
            return 0;
        }
        int sum_left = sumLeft(root->left); // 计算左子树的左叶子节点的和
        int sum_right = sumLeft(root->right);// 计算右子树的左叶子节点的和
        // 计算当前节点的左叶子节点的和
        int cur = 0;
        if (root->left != nullptr && root->left->left == nullptr && root->left->right == nullptr)
        {
            cur = root->left->val;
        }
        // 返回三者的和
        return sum_left + sum_right + cur;
    }
};