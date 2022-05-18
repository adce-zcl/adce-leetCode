// 给定一个二叉树，根据先序遍历算法，构造字符串
#include <string>
#include <iostream>
#include <algorithm>
using std::cout, std::endl;
using std::string;
using std::to_string;
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
    string tree2str(TreeNode* root) {
        if(root->left == nullptr && root->right == nullptr)
        {
            return to_string(root->val);
        }
        fun(root);
        return value;
    }
private:
    string value = "";
    void fun(TreeNode *root) 
    {
        if(root == nullptr)
        {
            return;
        }
        value += to_string(root->val);
        if(root->left != nullptr && root->right != nullptr)
        {
            value += "(";
            fun(root->left);
            value += ")";
            value += "(";
            fun(root->right);
            value += ")";
        }
        if(root->left == nullptr && root->right != nullptr)
        {
            value += "()";
            value += "(";
            fun(root->right);
            value += ")";
        }
        if(root->left != nullptr && root->right == nullptr)
        {
            value += "(";
            fun(root->left);
            value += ")";
            fun(root->right);
        }
    }
};