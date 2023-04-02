#include <string>
#include <vector>
#include <algorithm>

using namespace std;

vector<int> PreorderAnswer;
vector<int> PostorderAnswer;

struct _Node
{
    int _Number;
    pair<int, int> _data;
    struct _Node* _LeftNode;
    struct _Node* _RightNode;
    
    _Node(int x, int y, int n)
    {
        _Number = n;
        _data = make_pair(x, y);
        _LeftNode = NULL;
        _RightNode = NULL;
    };
};


void PushNode(_Node& p_UpNode, _Node& p_Node)
{
    if (p_UpNode._data.first > p_Node._data.first) {   
        if (p_UpNode._LeftNode != NULL) PushNode(*p_UpNode._LeftNode, p_Node);    
        else p_UpNode._LeftNode = &p_Node;
    }
    else {
        if (p_UpNode._RightNode != NULL) PushNode(*p_UpNode._RightNode, p_Node);
        else p_UpNode._RightNode = &p_Node;
    }
}

bool Compare(_Node& p_A_Node, _Node& p_B_Node)
{
    return p_A_Node._data.second > p_B_Node._data.second;
}

void Preorder_Traverse(_Node* t) {
    if (t != NULL)
    {
        PreorderAnswer.push_back(t->_Number);
        Preorder_Traverse(t->_LeftNode);
        Preorder_Traverse(t->_RightNode);
    }
}

void Postorder_Traverse(_Node* t) {
    if (t != NULL)
    {
        Postorder_Traverse(t->_LeftNode);
        Postorder_Traverse(t->_RightNode);
        PostorderAnswer.push_back(t->_Number);
    }
}

vector<vector<int>> solution(vector<vector<int>> nodeinfo) {
    vector<_Node> _NodeVector; 
    int cnt = 1;
    for (int i = 0; i < nodeinfo.size(); i++) {
        _Node node = { nodeinfo[i][0], nodeinfo[i][1], cnt++ };
        _NodeVector.push_back(node);
    }
  
    sort(_NodeVector.begin(), _NodeVector.end(), Compare); // Y값으로 정렬
    for (int i = 1; i < _NodeVector.size(); i++) {
        PushNode(*_NodeVector.begin(), _NodeVector[i]);
    }
    Preorder_Traverse(&_NodeVector[0]);
    Postorder_Traverse(&_NodeVector[0]);
    vector<vector<int>> answer;
    answer.push_back(PreorderAnswer);
    answer.push_back(PostorderAnswer);
    return answer;
}