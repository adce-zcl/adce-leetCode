// N 叉树的层序遍历

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
class Node 
{
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
public:
    vector<vector<int>> levelOrder(Node* root) 
    {
        vector<vector<int>> value;
        if (root == nullptr)
        {
            return value;
        }
        queue<Node *> que;
        que.push(root);
        while (!que.empty())
        {
            vector<int> current;
            current.clear();
            int size = que.size();
            for (int i = 0; i < size; ++i)
            {
                
                Node *cur = que.front();
                current.push_back(cur->val);
                que.pop();
                for (size_t i = 0; i < cur->children.size(); ++i)
                {
                    que.push(cur->children.at(i));
                }
                
            }
            value.push_back(current);
        }
        return value;
    }
};