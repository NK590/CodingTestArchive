#include <vector>
#include <string>
using namespace std;
int solution(string s)
{
	if (s.length() == 1) return 1; // 길이 '1' 예외 처리
	int answer = INT32_MAX;
	for (int i = 1; i <= s.length() / 2; i++) {
		vector<string> _ResV;
		int _AnsT = 0;
		for (int j = 0; ; j += i) {
			if (j + i > s.length()) {
				_AnsT = s.length() - j;
				break;
			}
			string _Temp = s.substr(j, i);
			_ResV.push_back(_Temp);
		}
		string _DupStr = "";
		int _DupInt = 1;
		for (int i = 0; i < _ResV.size(); i++) {
			if (_ResV[i] == _DupStr) _DupInt++;	
			else {
				_AnsT += _DupStr.size();
				if (_DupInt > 1) _AnsT += to_string(_DupInt).length();
				_DupStr = _ResV[i];
				_DupInt = 1;
			}
		}
		_AnsT += _DupStr.size();
		if (_DupInt > 1) _AnsT += to_string(_DupInt).length();
		answer = min(answer, _AnsT);
	}

	return answer;
}