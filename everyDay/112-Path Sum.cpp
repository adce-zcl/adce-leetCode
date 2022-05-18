// 路径总和
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
    bool hasPathSum(TreeNode* root, int targetSum) 
    {
        if (root == nullptr)
        {
            return false;
        }
        return pathSum(root, targetSum);
    }
    bool pathSum(TreeNode *root, int target_sum)
    {
        if (target_sum - root->val == 0 && root->left == nullptr && root->right == nullptr)
        {
            return true;
        }
        if (target_sum - root->val != 0 && root->left == nullptr && root->right == nullptr)
        {
            return false;
        }
        bool left_bool, right_bool;
        if (root->left != nullptr)
        {
            left_bool = pathSum(root->left, target_sum - root->val);
        }
        if (root->right != nullptr)
        {
            right_bool = pathSum(root->right, target_sum - root->val);
        }
        return left_bool || right_bool;
    }
};