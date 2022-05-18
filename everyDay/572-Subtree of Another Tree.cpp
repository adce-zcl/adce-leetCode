// 另一棵树的子树
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
    bool isSubtree(TreeNode* root, TreeNode* subRoot) 
    {
        vector<bool> value;
        queue<TreeNode *> que;
        que.push(root);
        while (!que.empty())
        {
            int size = que.size();
            for (unsigned i = 0; i < size; ++i)
            {
                TreeNode *cur = que.front();
                que.pop();
                if (cur->left != nullptr)
                {
                    que.push(cur->left);
                }
                if (cur->right != nullptr)
                {
                    que.push(cur->right);
                }
                if (cur->val == subRoot->val)
                {
                    value.push_back(sameTree(cur, subRoot));
                }
            }
        }
        bool val = false;
        for (auto &&bo : value)
        {
            val = val || bo;
        }
        return val;
    }
    bool sameTree(TreeNode* p, TreeNode* q)
    {
        if (p == nullptr && q != nullptr)
        {
            return false;
        }
        else if (p != nullptr && q == nullptr)
        {
            return false;
        }
        else if (p == nullptr && q == nullptr)
        {
            return true;
        }
        else if (p->val == q->val)
        {
            return true;
        }
        bool left = sameTree(p->left, q->left);
        bool right = sameTree(p->right, q->right);
        return left && right;
    }
};