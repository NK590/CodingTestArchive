#include <string>
#include <vector>
#include <iostream>
#include <cstdlib>
#include <sstream>
#include <algorithm>

using namespace std;

vector<int> myVector[4][3][3][3];

vector<int> solution(vector<string> info, vector<string> query) {
    vector<int> answer;
    for (auto& it : info) {
        istringstream ss(it);
        vector<string> words; // 자른 문자열을 저장할 벡터
        string _Temp; // 임시
        // 스트림을 한 줄씩 읽어, 공백 단위로 분리한 뒤, 결과를 벡터에 저장
        while (getline(ss, _Temp, ' ')) words.push_back(_Temp);
        int _Lang, _Career, _Group, _Food, _Score;
        if (words[0] == "cpp") _Lang = 1; // 언어
        else if(words[0] == "java") _Lang = 2;
        else _Lang = 3;
        if (words[1] == "backend") _Group = 1; // 직군
        else _Group = 2;
        if (words[2] == "senior") _Career = 1; // 경력
        else _Career = 2;
        if (words[3] == "chicken") _Food = 1; // 소울푸드
        else _Food = 2;
        _Score = atoi(words[4].c_str()); // 점수

        myVector[0][0][0][0].push_back(_Score);
        myVector[_Lang][0][0][0].push_back(_Score);
        myVector[_Lang][_Group][0][0].push_back(_Score);
        myVector[_Lang][_Group][_Career][0].push_back(_Score);
        myVector[_Lang][_Group][_Career][_Food].push_back(_Score);
        myVector[_Lang][_Group][0][_Food].push_back(_Score);
        myVector[_Lang][0][_Career][0].push_back(_Score);
        myVector[_Lang][0][_Career][_Food].push_back(_Score);
        myVector[_Lang][0][0][_Food].push_back(_Score);
        myVector[0][_Group][0][0].push_back(_Score);
        myVector[0][_Group][_Career][0].push_back(_Score);
        myVector[0][_Group][_Career][_Food].push_back(_Score);
        myVector[0][_Group][0][_Food].push_back(_Score);
        myVector[0][0][_Career][0].push_back(_Score);
        myVector[0][0][_Career][_Food].push_back(_Score);
        myVector[0][0][0][_Food].push_back(_Score);
    }

    // 빠른 쿼리 검색을 위해서 정렬
    for (int i = 0; i < 4; i++) {
        for (int j = 0; j < 3; j++){
            for (int k = 0; k < 3; k++){
                for (int l = 0; l < 3; l++) {
                    sort(myVector[i][j][k][l].begin(), myVector[i][j][k][l].end());
                }
            }
        }
    }

    for (auto& it : query) {
        istringstream ss(it);
        vector<string> words; // 자른 문자열을 저장할 벡터
        string _Temp; // 임시
        // 스트림을 한 줄씩 읽어, 공백 단위로 분리한 뒤, 결과를 벡터에 저장
        while (getline(ss, _Temp, ' ')) {
            if (_Temp == "and") continue;
            words.push_back(_Temp);
        }
        int _Lang = 0, _Career = 0, _Group = 0, _Food = 0, _Score = 0;
        if (words[0] == "cpp") _Lang = 1; // 언어
        else if (words[0] == "java") _Lang = 2;
        else if (words[0] == "python") _Lang = 3;
        if (words[1] == "backend") _Group = 1; // 직군
        else if (words[1] == "frontend") _Group = 2;
        if (words[2] == "senior") _Career = 1; // 경력
        else if (words[2] == "junior") _Career = 2;
        if (words[3] == "chicken") _Food = 1; // 소울푸드
        else if (words[3] == "pizza") _Food = 2;
        if (words[4] != "-") _Score = atoi(words[4].c_str()); // 점수
        // _Score 이상의 수가 나오는 it 반환
        auto iter = lower_bound(myVector[_Lang][_Group][_Career][_Food].begin(), myVector[_Lang][_Group][_Career][_Food].end(), _Score);
        if (iter == myVector[_Lang][_Group][_Career][_Food].end()) answer.push_back(0); // end() 반환은 값이 없다는 이야기
        else answer.push_back(myVector[_Lang][_Group][_Career][_Food].size() - (iter - myVector[_Lang][_Group][_Career][_Food].begin()));
    }
    return answer;
}
