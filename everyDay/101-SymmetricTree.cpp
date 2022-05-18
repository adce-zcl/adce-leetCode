// 对称二叉树
// 递归解法
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
public:
    bool isSymmetric(TreeNode* root) 
    {
        return compare(root->left, root->right);
    }

    bool compare(TreeNode* left, TreeNode *right)
    {
        // 退出条件
        if (left == nullptr && right == nullptr)
        {
            return true;
        }
        else if (left == nullptr && right != nullptr)
        {
            return false;
        }
        else if (left != nullptr && right == nullptr)
        {
            return false;
        }
        else if (left->val != right->val)
        {
            return false;
        }

        // 比较左边的左边和右边的右边是否对称（相等）
        bool b1 = compare(left->left, right->right);
        // 比较左边的右边和右边的左边是否对称（相等）
        bool b2 = compare(left->right, right->left);
        bool value = b1 && b2;
        return value;
    }
};