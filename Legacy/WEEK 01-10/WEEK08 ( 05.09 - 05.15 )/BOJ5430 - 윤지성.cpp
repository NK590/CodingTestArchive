#include <sstream>
#include <iostream>
#include <vector>
#include <string>
using namespace std;
int t, n;
string p, arr, sb;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);
	cin >> t;

	while (t--) {
		int start = 0, end, index = 1; //시작, 끝 인덱스와, 뒤집기 저장 변수
		vector<string> result;
		bool flag = true; //처음 출력하는지 판별
		cin >> p >> n >> arr;
		stringstream ss(arr);
		while (getline(ss, sb, ',')) { //콤마를 기준으로 나누기
			if (sb[0] == '[' && sb[1] == ']') //빈문자열일 경우
				break;
			else if (sb[0] == '[' && sb.back() == ']') //숫자 하나만 들어있을 경우
				result.push_back(sb.substr(1, sb.length() - 2)); //숫자만 배열에 넣기
			else if (sb[0] == '[') //숫자 여러개이고, 첫 숫자일 경우
				result.push_back(sb.substr(1));
			else if (sb.back() == ']') //숫자 여러개이고, 마지막 숫자일 경우
				result.push_back(sb.substr(0, sb.length() - 1));
			else //숫자 여러개이고, 중간 숫자일 경우
				result.push_back(sb);
		}
		end = result.size(); 

		for (int i = 0; i < p.size(); i++) {
			if (p[i] == 'R') { //뒤집기면 변수에 저장
				index *= -1;
			}
			else if (p[i] == 'D') { //삭제일 경우
				if (start >= end) { //비어있는데 삭제할 경우
					cout << "error\n";
					index = 0;
					break;
				}
				if (index == 1) //정방향일 때
					start++; 
				else if (index == -1) //역방향일 때
					end--; 
			}
		}
		if (!index) //error 띄웠을 때
			continue;
		if (start >= end) //빈문자열인데 error 안띄웠을 때
			cout << "[";
			
		while (start < end) {
			if (index == -1) //역방향일 때 출력
				cout << (flag ? '[' : ',') << result[--end];
			else //정방향일 때 출력
				cout << (flag ? '[' : ',') << result[start++];
			flag = false;
		}
		cout << "]\n";
	}
		
		return 0;
}
