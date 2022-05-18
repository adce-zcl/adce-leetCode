// 统计值等于子树平均值的节点数
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
private:
    int result = 0;
    int num = 0;
    
    int travr(TreeNode *root)
    {
        if (root == nullptr)
        {
            return 0;
        }
        int n;
        if (root->left == nullptr && root->right == nullptr)
        {
            n = 1;
        }
        else if (root->left != nullptr && root->right != nullptr)
        {
            n = 3;
        }
        else
        {
            n = 2;
        }
        num += n;
        int left = travr(root->left);
        int right = travr(root->right);
        int sum = left + right;
        int avg = (sum + root->val) / num;
        if (avg == root->val)
        {
            ++result;
        }
        return sum;
    }
    int size = 0;
    vector<int> sums;
    int fun1(TreeNode *root)
    {
        if (root == nullptr)
        {
            return 0;
        }
        int left = fun1(root->left);
        int right = fun1(root->right);
        int sum = left + right + root->val;
        sums.push_back(sum);
        return 0;
    }
public:
    int averageOfSubtree(TreeNode* root) 
    {
        if (root->left == nullptr && root->right == nullptr)
        {
            return 1;
        }
        travr(root);
        return result;
    }
};