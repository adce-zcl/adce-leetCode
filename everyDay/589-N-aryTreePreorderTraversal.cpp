//  N 叉树的前序遍历
/*
// Definition for a Node.
class Node {
public:
    int val;
    vector<Node*> children;

    Node() {}

    Node(int _val) {
        val = _val;
    }

    Node(int _val, vector<Node*> _children) {
        val = _val;
        children = _children;
    }
};
*/
#include <vector>
#include <queue>
using namespace std;
class Node {
public:
    int val;
    vector<Node*> children;

    Node() {}

    Node(int _val) {
        val = _val;
    }

    Node(int _val, vector<Node*> _children) {
        val = _val;
        children = _children;
    }
};
class Solution 
{
private:
    void recursion(Node *root, vector<int> &value)
    {
        if (root == nullptr)
        {
            return;
        }
        value.push_back(root->val);
        // 递归遍历孩子？
        for (size_t i = 0; i < root->children.size(); ++i)
        {
            recursion(root->children.at(i), value);
        }
        
    }
public:
    vector<int> preorder(Node* root) 
    {
        vector<int> value;
        recursion(root, value);
        return value;
    }
};