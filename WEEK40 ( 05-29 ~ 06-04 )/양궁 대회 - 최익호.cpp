#include <string>
#include <vector>

using namespace std;

int _N, _LionRes, _ApeachRes, _Maxdiff;

vector<int> _Answer = { -1 };

bool Check(vector<int>& _Answer, vector<int>& _ComparisonV)
{
    for (int i = 10; i >= 0; i--) {
        if (_Answer[i] < _ComparisonV[i]) return true;
        else if (_Answer[i] > _ComparisonV[i]) return false;
    }
    return false;
}

// 완전 탐색
void Search(vector<int>& _apeachV, vector<int>& _ryanV, int _cnt, int _pivot)
{
    if (_cnt == _N) {
        _ApeachRes = 0; _LionRes = 0;
        for (int i = 0; i < 10; i++) {
            if (_apeachV[i] < _ryanV[i]) _LionRes += (10 - i);
            else if (_apeachV[i] > 0) _ApeachRes += (10 - i);
        }

        int _DiffValue = _LionRes - _ApeachRes;
        if ((_DiffValue > 0 && _Maxdiff <= _DiffValue)) {
            if (_Maxdiff == _DiffValue && !Check(_Answer, _ryanV)) return;
            _Maxdiff = _DiffValue;
            _Answer = _ryanV;
        }
        return;
    }

    // 피봇을 이용하여 중복을 제거
    for (int i = _pivot; i <= 10; i++) {
        _ryanV[i]++;
        Search(_apeachV, _ryanV, _cnt + 1, i);
        _ryanV[i]--;
    }

}

vector<int> solution(int n, vector<int> info) {
    _N = n;
    vector<int> _BaseV = { 0,0,0,0,0,0,0,0,0,0,0 };
    Search(info, _BaseV, 0, 0);
    return _Answer;
}