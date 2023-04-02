#include <string>
#include <vector>
#include <map>
#include <sstream>

using namespace std;

//https://www.lifencoding.com/language/22#post?p=1
vector<string> split(string str, char Delimiter) 
{
    istringstream iss(str);             // istringstream�� str�� ��´�.
    string buffer;                      // �����ڸ� �������� ����� ���ڿ��� ������� ����

    vector<string> result;

    // istringstream�� istream�� ��ӹ����Ƿ� getline�� ����� �� �ִ�.
    while (getline(iss, buffer, Delimiter)) 
    {
        result.push_back(buffer);               // ����� ���ڿ��� vector�� ����
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
            // ���� ����
            if (uidMap.find(uid) != uidMap.end())
                uidMap[uid] = nickname;
            // �ű� ����
            else
                uidMap.insert({uid, nickname});

            uidRecord.push_back({uid, "���� ���Խ��ϴ�."});
        }
        else if (command == "Leave")
        {
            uidRecord.push_back({ uid, "���� �������ϴ�." });
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