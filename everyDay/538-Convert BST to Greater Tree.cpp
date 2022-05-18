// 把二叉搜索树转换为累加树
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
    int pre = 0;
    // 递归法
    void traversal(TreeNode *root)
    {
        if (root == nullptr)
        {
            return;
        }
        traversal(root->right);
        root->val += pre;
        pre = root->val;
        traversal(root->left);
    }

    // 迭代法
    void traversal(TreeNode *root)
    {
        if (root == nullptr)
        {
            return;
        }
        stack<TreeNode *> st;
        TreeNode *cur = root;
        int pre = 0;
        while (cur != nullptr || !st.empty())
        {
            if (cur != nullptr)
            {
                st.push(cur);
                cur = cur->right;
            }
            else
            {
                cur = st.top();
                st.pop();
                cur->val += pre;
                pre = cur->val;
                cur = cur->left;
            }
        }
    }

public:
    TreeNode* convertBST(TreeNode* root) 
    {
        traversal(root);
        return root;
    }
};