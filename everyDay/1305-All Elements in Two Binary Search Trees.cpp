// 两棵二叉搜索树中的所有元素
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
    vector<int> nodes1;
    vector<int> nodes2;
    vector<int> result;
    void innoderTraversal(TreeNode *root, vector<int> &nodes)
    {
        if (root == nullptr)
        {
            return;
        }
        innoderTraversal(root->left, nodes);
        nodes.push_back(root->val);
        innoderTraversal(root->right, nodes);
    }    

public:
    vector<int> getAllElements(TreeNode* root1, TreeNode* root2) 
    {
        innoderTraversal(root1, nodes1);
        innoderTraversal(root2, nodes2);
        int start1 = 0, start2 = 0;
        while (start1 < nodes1.size() && start2 < nodes2.size())
        {
            int temp1 = nodes1.at(start1);
            int temp2 = nodes2.at(start2);
            if (temp1 <= temp2)
            {
                result.push_back(temp1);
                ++start1;
            }
            else
            {
                result.push_back(temp2);
                ++start2;
            }
        }
        while (start1 < nodes1.size())
        {
            result.push_back(nodes1.at(start1++));
        }
        while (start2 < nodes2.size())
        {
            result.push_back(nodes2.at(start2++));
        }
        return result;
    }
};