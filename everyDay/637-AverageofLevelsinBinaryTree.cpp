// 二叉树的层平均值
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
#include <queue>
using namespace std;
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
    vector<double> averageOfLevels(TreeNode* root) 
    {
        vector<double> value;
        if (root == nullptr)
        {
            return value;
        }
        queue<TreeNode *> st;
        st.push(root);
        while (!st.empty())
        {
            int size = st.size();
            double sum = 0;
            TreeNode *cur;
            for (int i = 0; i < size; ++i)
            {
                cur = st.front();
                sum += cur->val;
                st.pop();
                if (cur->left != nullptr)
                {
                    st.push(cur->left);
                }
                if (cur->right != nullptr)
                {
                    st.push(cur->right);
                }
            }
            value.push_back(sum / size);
        }
        return value;
    }
};