#include <string>
#include <vector>
#include <map>
#include <sstream>

using namespace std;

//https://www.lifencoding.com/language/22#post?p=1
vector<string> split(string str, char Delimiter) 
{
    istringstream iss(str);             // istringstream에 str을 담는다.
    string buffer;                      // 구분자를 기준으로 절삭된 문자열이 담겨지는 버퍼

    vector<string> result;

    // istringstream은 istream을 상속받으므로 getline을 사용할 수 있다.
    while (getline(iss, buffer, Delimiter)) 
    {
        result.push_back(buffer);               // 절삭된 문자열을 vector에 저장
    }

    return result;
}

vector<string> solution(vector<string> record) 
{
    vector<string> answer;

    map<string, string> uidMap;
    vector<pair<string, string>> uidRecord;

    int recordSize = record.size();
    for (int i = 0; i < recordSize; i++)
    {
        vector<string> splitStr = split(record[i], ' ');
        string command = splitStr[0];
        string uid = splitStr[1]; 
        
        if (command == "Enter")
        {
            string nickname = splitStr[2];
            // 기존 유저
            if (uidMap.find(uid) != uidMap.end())
                uidMap[uid] = nickname;
            // 신규 유저
            else
                uidMap.insert({uid, nickname});

            uidRecord.push_back({uid, "님이 들어왔습니다."});
        }
        else if (command == "Leave")
        {
            uidRecord.push_back({ uid, "님이 나갔습니다." });
        }
        else if (command == "Change")
        {
            string nickname = splitStr[2];
            if (uidMap.find(uid) != uidMap.end())
                uidMap[uid] = nickname;
        }
    }

    int uidRecordSize = uidRecord.size();
    for (int i = 0; i < uidRecordSize; i++)
    {
        answer.push_back(uidMap[uidRecord[i].first] + uidRecord[i].second);
    }

    return answer;
}