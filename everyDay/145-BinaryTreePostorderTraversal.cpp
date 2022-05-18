// 二叉树的后序遍历
#include <vector>
#include <stack>
#include <algorithm>
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
        traversal(current->right, value);
        value.push_back(current->val);
    }
public:
    // 递归法
    vector<int> postorderTraversal(TreeNode* root) 
    {
        vector<int> value;
        traversal(root, value);
        return value;
    }

    // 迭代法
    // 后续是左右中，前序是中左右，那么可以改成中右左，再反转变成左右中
    vector<int> postorderTraversal(TreeNode* root) 
    {
        vector<int> value;
        if (root == nullptr)
        {
            return value;
        }
        stack<TreeNode *> st;
        TreeNode *cur;
        st.push(root);
        while (!st.empty())
        {
            cur = st.top();
            st.pop();
            value.push_back(cur->val);
            if (cur->left != nullptr)
            {
                st.push(cur->left);
            }
            if (cur->right != nullptr)
            {
                st.push(cur->right);
            }
        }
        reverse(value.begin(), value.end());
        return value;
    }

};