#include <string>
#include <vector>
#include <sstream>
#include <cstdlib>
#include <string>

using namespace std;

int Total_PT_Int, Total_ADV_Time;
long long int TimeLine[360000], _Res;

vector<pair<int, int>> Logs_Times;

int StringTimeConverter(string time) {
    int second;

    int to_hour = ((time[0] - '0') * 10) + (time[1] - '0');
    int to_min = ((time[3] - '0') * 10) + (time[4] - '0');
    int to_sec = ((time[6] - '0') * 10) + (time[7] - '0');
    second = to_hour * 3600 + to_min * 60 + to_sec;

    return second;
}

string IntToTimeString(int timeInSeconds) {
    int hours = timeInSeconds / 3600;
    int minutes = (timeInSeconds % 3600) / 60;
    int seconds = (timeInSeconds % 3600) % 60;
    string str;
    if (hours < 10) str += "0" + to_string(hours) + ":";
    else str += to_string(hours) + ":";
    if (minutes < 10) str += "0" + to_string(minutes) + ":";
    else str += to_string(minutes) + ":";
    if (seconds < 10) str += "0" + to_string(seconds);
    else str += to_string(seconds);
    return str;
}

string solution(string play_time, string adv_time, vector<string> logs) {
    string answer = "";
    Total_PT_Int = StringTimeConverter(play_time);
    Total_ADV_Time = StringTimeConverter(adv_time);
    for (auto& it : logs)
    {
        vector<string> _ResV;
        istringstream ss(it);
        string _temp;
        while (getline(ss, _temp, '-'))
            _ResV.push_back(_temp);
        int _Start = StringTimeConverter(_ResV[0]);
        int _End = StringTimeConverter(_ResV[1]); 
        Logs_Times.push_back(make_pair(_Start, _End));
        TimeLine[_Start]++;
        TimeLine[_End]--;
    }

    for (int i = 1; i < Total_PT_Int; i++) 
        TimeLine[i] += TimeLine[i - 1];

    // 0 부터 시작
    int STime = 0;
    for (int i = 1; i < Total_ADV_Time; i++)
        _Res += TimeLine[i - 1];
    long long int Max = _Res;


    for (int i = Total_ADV_Time; i < Total_PT_Int; i++) {
        _Res += TimeLine[i];
        _Res -= TimeLine[i - Total_ADV_Time];
        if (_Res > Max) {
            Max = _Res;
           STime = i - Total_ADV_Time + 1;
        }
    }
    return IntToTimeString(STime);
}