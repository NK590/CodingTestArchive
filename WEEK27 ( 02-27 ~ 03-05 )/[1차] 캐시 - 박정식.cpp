#include <string>
#include <vector>
#include <deque>
#include <iostream>

using namespace std;

//vector<string> v = { "Jeju", "Pangyo", "Seoul", "NewYork", "LA", "Jeju", "Pangyo", "Seoul", "NewYork", "LA" };
vector<string> v = { "a", "b", "a"};
// 캐시 deque
deque<string> dq;
// 문자열 소문자 변환
string StringLowerConvert(string str)
{
    string result;

    for (int i = 0; i < str.size(); i++)
    {
        result += tolower(str[i]);
    }

    return result;
}

// 캐시에 있는지 체크
bool Check(string str)
{
    bool isHit = false;
    for (deque<string>::iterator it = dq.begin(); it != dq.end(); it++)
    {
        if (*it == str)
        {
            isHit = true;
            dq.erase(it);
            dq.push_back(str);
            return isHit;
        }
    }

    return isHit;
}

int solution(int cacheSize, vector<string> cities)
{
    int answer = 0;

    vector<string> cities_lower;
    for (string citie : cities)
    {
        string lower = StringLowerConvert(citie);
        cities_lower.push_back(lower);
    }

    int i = 0;
    for (string citie : cities_lower)
    {
        if (dq.size() == cacheSize)
            break;

        if (Check(citie) == true)
            answer += 1;
        else
        {
            dq.push_back(citie);
            answer += 5;
        }

        i++;
    }

    for (vector<string>::iterator it = cities_lower.begin() + i; it != cities_lower.end(); it++)
    {
        if (Check(*it) == true)
        {
            answer += 1;
            continue;
        }
        else
        {
            answer += 5;
            dq.push_back(*it);
            dq.pop_front();
        }
    }

    return answer;
}


int main()
{
    cout << solution(3, v) << endl;


    return 0;
}