// 二叉树的前序遍历
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
#include <stack>
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
private:
    void traversal(TreeNode* current, vector<int> &value)
    {
        if (current == nullptr)
        {
            return;
        }
        value.push_back(current->val);
        traversal(current->left, value);
        traversal(current->right, value);
    }
public:
    // 递归法
    vector<int> preorderTraversal(TreeNode* root) 
    {
        vector<int> value;
        traversal(root, value);
        return value;
    }
    
    // 迭代法
    vector<int> preorderTraversal(TreeNode* root) 
    {
        // 利用栈
        vector<int> value;
        if (root == nullptr)
        {
            return value;
        }
        stack<TreeNode *> st;
        st.push(root);
        while (!st.empty())
        {
            TreeNode *cur = st.top();
            st.pop();
            value.push_back(cur->val);
            if (cur->right != nullptr)
            {
                st.push(cur->right);
            }
            if (cur->left != nullptr)
            {
                st.push(cur->left);
            }
        }
        return value;
    }
};