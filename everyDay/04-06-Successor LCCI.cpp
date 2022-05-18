// 后继者
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
};
class Solution 
{
public:
    TreeNode* inorderSuccessor(TreeNode* root, TreeNode* p) 
    {
        TreeNode *ans = nullptr;
        TreeNode *cur = root;
        while (cur != nullptr)
        {
            if (p->val < cur->val)
            {
                ans = cur;
                cur = cur->left;
            }
            else
            {   
                cur = cur->right;
            }
        }
        return ans;
    }
};