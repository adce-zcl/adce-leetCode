// 从二叉搜索树到更大和树
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
private:
    int pre = 0;
    void bst(TreeNode *root)
    {
        if (root == nullptr)
        {
            return;
        }
        bst(root->right);
        root->val += pre;
        pre = root->val;
        bst(root->left);
    }
public:
    TreeNode* bstToGst(TreeNode* root) 
    {
        bst(root);
        return root;
    }
};