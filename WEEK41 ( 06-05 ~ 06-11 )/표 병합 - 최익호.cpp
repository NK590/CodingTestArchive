#include <string>
#include <vector>
#include <sstream>
#include <cstdlib>
#include <map>

using namespace std;

string _StrArr[51][51];
string* _PtrArr[51][51];
pair<int, int> _MergeArr[51][51];
map<pair<int, int>, vector<pair<int, int>>> _MergeMap;
vector<string> _Answer;

void CommandProcessing(string& _command)
{
    istringstream iss(_command);
    string buffer;
    vector<string> res;
    while (getline(iss, buffer, ' '))
        res.push_back(buffer);

    if (res[0] == "UPDATE") {
        if (res.size() > 3) {  // "UPDATE r c value"
            pair<int, int> _MPair = _MergeArr[atoi(res[1].c_str())][atoi(res[2].c_str())];
            *_PtrArr[_MPair.first][_MPair.second] = res[3];
        }
        else {    // "UPDATE value1 value2"
            for (int i = 1; i <= 50; i++)
                for (int j = 1; j <= 50; j++) {
                    if (_StrArr[i][j] == "" || _StrArr[i][j] != res[1])
                        continue;
                    _StrArr[i][j] = res[2];
                }
        }
    }
    else if (res[0] == "MERGE") { // "UNMERGE r c"
        if (res[1] == res[3] && res[2] == res[4])
            return;

        pair<int, int> _MPair = _MergeArr[atoi(res[1].c_str())][atoi(res[2].c_str())];
        pair<int, int> _TPair = _MergeArr[atoi(res[3].c_str())][atoi(res[4].c_str())];

        if (_MPair == _TPair) 
            return;

        auto _Main = _MergeMap.find(_MPair);
        auto _Target = _MergeMap.find(_TPair);
        if (_Main == _MergeMap.end()) {
            vector<pair<int, int>> _Temp;
            _MergeMap.insert({ _MPair, _Temp });
            _Main = _MergeMap.find(_MPair);
        }

        _Main->second.push_back(_TPair);

        if (*_PtrArr[_MPair.first][_MPair.second] == "" && *_PtrArr[_TPair.first][_TPair.second] != "") {
            *_PtrArr[_MPair.first][_MPair.second] = "";
            _PtrArr[_MPair.first][_MPair.second] = _PtrArr[_TPair.first][_TPair.second];
            for (auto& it : _Main->second)
                _PtrArr[it.first][it.second] = _PtrArr[_TPair.first][_TPair.second];
        }

        _PtrArr[_TPair.first][_TPair.second] = _PtrArr[_MPair.first][_MPair.second];
        _MergeArr[_TPair.first][_TPair.second] = _MPair;

        if (_Target != _MergeMap.end()) {
            for (auto& it : _Target->second) {
                _Main->second.push_back(it);
                _MergeArr[it.first][it.second] = _MPair;
                _PtrArr[it.first][it.second] = _PtrArr[_MPair.first][_MPair.second];
            }
            _MergeMap.erase(_Target);
        }
    }
    else if (res[0] == "UNMERGE") { // "UNMERGE r c"
        pair<int, int> _MPair = _MergeArr[atoi(res[1].c_str())][atoi(res[2].c_str())];
        string str = *_PtrArr[_MPair.first][_MPair.second];
        _MergeArr[_MPair.first][_MPair.second] = _MPair;
        _PtrArr[_MPair.first][_MPair.second] = &_StrArr[_MPair.first][_MPair.second];
        *_PtrArr[_MPair.first][_MPair.second] = "";

        auto _Main = _MergeMap.find(_MPair);
        if (_Main != _MergeMap.end()) {
            for (auto& it : _Main->second) {
                _MergeArr[it.first][it.second] = make_pair(it.first, it.second);
                _PtrArr[it.first][it.second] = &_StrArr[it.first][it.second];
                *_PtrArr[it.first][it.second] = "";
            }
            _MergeMap.erase(_Main);
        }
        _StrArr[atoi(res[1].c_str())][atoi(res[2].c_str())] = str;
    }
    else {// "PRINT r c"
        pair<int, int> _MPair = _MergeArr[atoi(res[1].c_str())][atoi(res[2].c_str())];
        string str = *_PtrArr[_MPair.first][_MPair.second];
        if (str == "") _Answer.push_back("EMPTY");
        else _Answer.push_back(str);
    }
}


vector<string> solution(vector<string> commands) {
    // 포인터 배열 초기화
    for (int i = 1; i <= 50; i++)
        for (int j = 1; j <= 50; j++) {
            _PtrArr[i][j] = &_StrArr[i][j];
            _MergeArr[i][j] = make_pair(i, j);
            _StrArr[i][j] = "";
        }

    // 명령어 처리
    for (auto& it : commands)
        CommandProcessing(it);
    
    return _Answer;
}