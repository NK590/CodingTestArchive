#include <string>
#include <vector>
#include <set>
#include <cmath>

using namespace std;

vector<int> answer;

bool isUnique(int bit) {
    // 확정된 후보키 만큼 순회
    for (int j = 0; j < answer.size(); j++) {
        // bit 비트가 확정된 후보키에 속해있는 것이 있다면 
        if ((answer[j] & bit) == answer[j]) return false;
    }

    return true;
}

int solution(vector<vector<string>> relation) {

    int rowSize = relation.size(); // relation 열의 크기
    int columnSize = relation.front().size(); // relation 행의 크기
    

    for (int i = 1; i < pow(2, columnSize); i++) { // 4자리라면 0001 ~ 1111까지 확인

        set<string> mySet; // 유일성 확인을 위함

        for (int j = 0; j < rowSize; j++) { // 행의 크기만큼 반복

            string temp;

            for (int k = 0; k < columnSize; k++) { // 열의 크기만큼 반복

                if ((i & (1 << k))) { // 해당 열의 비트가 1이라면 temp에 추가
                    temp += relation[j][k];
                }
            }

            mySet.insert(temp); // set으로 중복을 제거하면서 insert
        }

        if (mySet.size() == rowSize) { // 크기가 같다면 유일성을 가질질 수 있다.
            if (isUnique(i)) { // 유일성 확인 후에 최소성을 확인 
                answer.push_back(i); // 유일성과 최소성을 모두 확인했으면 추가
            }
        }

    }

    return answer.size();
}