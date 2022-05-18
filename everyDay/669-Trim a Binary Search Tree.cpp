// 修剪二叉搜索树
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
    // 递归法
    TreeNode* trimBST(TreeNode* root, int low, int high)
    {
        if (root == nullptr ) return nullptr;
        if (root->val < low) {
            TreeNode* right = trimBST(root->right, low, high); // 寻找符合区间[low, high]的节点
            return right;
        }
        if (root->val > high) {
            TreeNode* left = trimBST(root->left, low, high); // 寻找符合区间[low, high]的节点
            return left;
        }
        root->left = trimBST(root->left, low, high); // root->left接入符合条件的左孩子
        root->right = trimBST(root->right, low, high); // root->right接入符合条件的右孩子
        return root;
    }
    // 迭代法
    TreeNode* trimBST(TreeNode* root, int low, int high) 
    {
        if (root == nullptr)
        {
            return nullptr;
        }
        while (root != nullptr && (root->val < low || root->val > high))
        {
            if (root->val < low)
            {
                root = root->right;
            }
            else
            {
                root = root->left;
            }
        }
        // root在low-high范围内
        // 先裁<low的部分
        TreeNode *cur = root;
        while (cur != nullptr)
        {
            while (cur->left != nullptr && cur->left->val < low)
            {
                cur->left = cur->left->right;
            }
            cur = cur->left;
        }
        cur = root;
        // 裁剪>high的部分
        while (cur != nullptr)
        {
            while (cur->right != nullptr && cur->right->val > high)
            {
                cur->right = cur->right->left;
            }
            cur = cur->right;
        }
        return root;
    }
};