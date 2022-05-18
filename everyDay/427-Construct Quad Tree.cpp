#include <vector>
using namespace std;
// Definition for a QuadTree node.
class Node {
public:
    bool val;
    bool isLeaf;
    Node* topLeft;
    Node* topRight;
    Node* bottomLeft;
    Node* bottomRight;
    
    Node() {
        val = false;
        isLeaf = false;
        topLeft = NULL;
        topRight = NULL;
        bottomLeft = NULL;
        bottomRight = NULL;
    }
    
    Node(bool _val, bool _isLeaf) {
        val = _val;
        isLeaf = _isLeaf;
        topLeft = NULL;
        topRight = NULL;
        bottomLeft = NULL;
        bottomRight = NULL;
    }
    
    Node(bool _val, bool _isLeaf, Node* _topLeft, Node* _topRight, Node* _bottomLeft, Node* _bottomRight) {
        val = _val;
        isLeaf = _isLeaf;
        topLeft = _topLeft;
        topRight = _topRight;
        bottomLeft = _bottomLeft;
        bottomRight = _bottomRight;
    }
};



class Solution 
{
private:
    bool isLeaffunc(vector<vector<int>>& grid, int row0, int row1, int col0, int col1)
    {
        int num = grid.at(row0).at(col0);
        for (int row = row0; row < row1; ++row)
        {
            for (int col = col0; col < col1; col++)
            {
                if (grid.at(row).at(col) != num)
                {
                    return false;
                }
            }
        }
        return true;
    }

    Node* dfs(vector<vector<int>>& grid, int row0, int row1, int col0, int col1)
    {
        if (isLeaffunc(grid, row0, row1, col0, col1) == true)   // 是叶子节点
        {
            return new Node(grid.at(row0).at(col0), true);
        }
        else
        {
            return new Node(true, false,
                            dfs(grid, row0, (row0 + row1) / 2, col0, (col0 + col1) / 2),
                            dfs(grid, row0, (row0 + row1) / 2, (col0 + col1) / 2, col1),
                            dfs(grid, (row0 + row1) / 2, row1, col0, (col0 + col1) / 2),
                            dfs(grid, (row0 + row1) / 2, row1, (col0 + col1) / 2, col1));
        }
    }

public:
    Node* construct(vector<vector<int>>& grid) 
    {
        Node *root = dfs(grid, 0, grid.size() - 1, 0, grid.size() - 1);
        return root;
    }
};