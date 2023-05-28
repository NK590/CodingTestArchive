#include <string>
#include <vector>
#include <iostream>
#include <set>
using namespace std;
struct MyNode;
vector<MyNode> _AllNodeV;
int answer = 0;
struct MyNode
{
    int _Num, _Type;
    vector<MyNode*> _ChildnodeV;
    MyNode(int _num, int _type) {
        _Num = _num;
        _Type = _type;
    }
};

void CustomDFS(int _cnt, int _sheep, int _wolf, set<int> _nodeSet) {
    if (_AllNodeV[_cnt]._Type) _wolf++;
    else _sheep++; // 늑대는 1, 양은 0
    if (_wolf >= _sheep) return; // 늑대가 같거나 크다면 return
    if (_sheep > answer) answer = _sheep; // 최댓값 갱신
    _nodeSet.erase(_cnt); // 갈 수 있는 곳을 지워준다.
    for (auto& it : _AllNodeV[_cnt]._ChildnodeV) 
        _nodeSet.insert(it->_Num); // 다음 갈 곳을 추가
    for (auto& it : _nodeSet)
        CustomDFS(it, _sheep, _wolf, _nodeSet);
}

int solution(vector<int> info, vector<vector<int>> edges) {   
    for (int i = 0; i < info.size(); i++) {
        MyNode _node = MyNode(i, info[i]);
        _AllNodeV.push_back(_node);
    }

    for (int i = 0; i < edges.size(); i++)
        _AllNodeV[edges[i][0]]._ChildnodeV.push_back(&_AllNodeV[edges[i][1]]);  
    set<int> _TempSet;
    _TempSet.insert(0);
    CustomDFS(0, 0, 0, _TempSet);
    return answer;
}


