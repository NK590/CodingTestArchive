#include <string>
#include <vector>
#include <unordered_map>

using namespace std;

unordered_map<string, int> myMap;

vector<int> solution(string msg) {
    
    vector<int> answer;

    for (int i = 1; i <= 26; i++) { // 사전을 초기화
        string temp = "";
        temp.push_back('A' + i - 1);
        myMap.insert(make_pair(temp, i));
    }

    for (int j = 0; j < msg.length(); j++) { // 시작 피봇
        for (int i = msg.length() - j; i >= 1; i--) { // 슬라이싱 피봇
            auto it = myMap.find(msg.substr(j, i));
            if (it != myMap.end()) {
                answer.push_back(it->second);
                if (j + i < msg.length()) 
                    myMap.insert(make_pair(msg.substr(j, i + 1), myMap.size() + 1));            
                j += it->first.length() - 1;
                break;
            }
        }
    }

    return answer;
}