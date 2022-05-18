// 两数之和IV - 输入BST
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
#include <unordered_set>
class Solution {
private:
    std::unordered_set<int> s;
public:
    bool findTarget(TreeNode* root, int k) 
    {
        fun(root);
        for (auto &&i : s)
        {
            if(s.count(k-i) && *s.find(k-i) != i)
            {
                return true;
            }
        }
        return false;
        }
    void fun(TreeNode* root)
    {
        if(root == nullptr)
        {
            return;
        }
        s.emplace(root->val);
        fun(root->left);
        fun(root->right);
    }

};