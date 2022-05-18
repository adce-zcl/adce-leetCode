// 二叉树的中序遍历
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
        traversal(current->left, value);
        value.push_back(current->val);
        traversal(current->right, value);
    }
public:
    // 递归法
    vector<int> inorderTraversal(TreeNode* root) 
    {
        vector<int> value;
        traversal(root, value);
        return value;
    }

    // 迭代法
    vector<int> inorderTraversal(TreeNode* root) 
    {
        vector<int> value;
        if (root == nullptr)
        {
            return value;
        }
        stack<TreeNode *> st;
        TreeNode *cur = root;
        while (cur != nullptr || !st.empty())
        {
            if (cur != nullptr)
            {
                // 一直到最后一个left
                st.push(cur);
                cur = cur->left; 
            }
            else    // cur == nullptr
            {
                // 取栈顶
                cur = st.top();
                st.pop();
                value.push_back(cur->val);
                cur = cur->right;
            }
        }
        return value;
    }
};