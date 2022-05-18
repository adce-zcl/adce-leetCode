// N 叉树的后序遍历
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
        for (size_t i = 0; i < root->children.size(); ++i)
        {
            recursion(root->children.at(i), value);
        }
        value.push_back(root->val);
    }
public:
    vector<int> postorder(Node* root) 
    {
        vector<int> value;
        if (root == nullptr)
        {
            return value;
        }
        recursion(root, value);
        return value;
    }
};