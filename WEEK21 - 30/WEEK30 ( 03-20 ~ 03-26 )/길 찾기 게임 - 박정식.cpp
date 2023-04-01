#include <string>
#include <vector>
#include <algorithm>

using namespace std;

struct Node
{
    int x, y;
    int index;
    Node *left;
    Node *right;
};

// y순으로 정렬후 y가 같다면 x순으로 정렬
bool Compare(Node node1, Node node2)
{
    if (node1.y >= node2.y)
    {
        if (node1.y == node2.y)
        {
            if (node1.x < node2.x)
            {
                return true;
            }
            return false;
        }
        return true;
    }
    return false;
}

void CreateTree(Node *root, Node *child)
{
    if (root->x > child->x)
    {
        if (root->left == NULL)
        {
            root->left = child;
            return;
        }
        CreateTree(root->left, child);
    }
    else
    {
        if (root->right == NULL)
        {
            root->right = child;
            return;
        }
        CreateTree(root->right, child);
    }
}

void PreOrder(Node *root, vector<int>& v)
{
    if (root == NULL) 
        return;
    v.push_back(root->index);
    PreOrder(root->left, v);
    PreOrder(root->right, v);
}

void PostOrder(Node *root, vector<int>& v)
{
    if (root == NULL) 
        return;
    PostOrder(root->left, v);
    PostOrder(root->right, v);
    v.push_back(root->index);
}


vector<vector<int>> solution(vector<vector<int>> nodeinfo) 
{
    vector<vector<int>> answer;
    vector<Node> tree;

    for (int i = 0; i < nodeinfo.size(); i++)
    {
        int x = nodeinfo[i][0];
        int y = nodeinfo[i][1];
        int index = i + 1;
        tree.push_back({ x, y, index, NULL, NULL });
    }
    sort(tree.begin(), tree.end(), Compare);
    Node* root = &tree[0];
    for (int i = 1; i < tree.size(); i++)
    {
        CreateTree(root, &tree[i]);
    }

    vector<int> preV, postV;

    PreOrder(root, preV);
    PostOrder(root, postV);

    answer.push_back(preV);
    answer.push_back(postV);

    return answer;
}