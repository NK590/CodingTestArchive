#define MAX 362440

#include <string>
#include <vector>
#include <iomanip> 

using namespace std;

vector<int> v(MAX);

int TimeToSecond(string timeStr)
{
    int hour = stoi(timeStr.substr(0, 2));
    int minute = stoi(timeStr.substr(3, 2));
    int second = stoi(timeStr.substr(6, 2));

    second += minute * 60;
    second += hour * 3600;

    return second;
}
string SecondToTime(unsigned long second)
{
    string hour = to_string(second / 3600);
    if (stoi(hour) <= 9)
        hour = "0" + hour;

    string minute = to_string((second % 3600) / 60);
    if (stoi(minute) <= 9)
        minute = "0" + minute;

    string sec = to_string(second % 60);
    if (stoi(sec) <= 9)
        sec = "0" + sec;


    string result = hour + ":" + minute + ":" + sec;
    return result;
}

string solution(string play_time, string adv_time, vector<string> logs) 
{
    int playTime = TimeToSecond(play_time);
    int advTime = TimeToSecond(adv_time);

    for (auto log : logs)
    {
        int startTime = TimeToSecond(log.substr(0,8));
        int endTime = TimeToSecond(log.substr(9,8));

        for (int idx = startTime; idx < endTime; ++idx)
            v[idx]++;
    }

    string answer = "";
    long highViewTime = 0;
    long highIndex = 0;
    for (long idx = 0; idx <= playTime - advTime; ++idx)
    {
        long viewTime = 0;

        for (long curTime = idx; curTime < advTime + idx; ++curTime)
            viewTime += v[curTime];

        if (viewTime > highViewTime)
        {
            highViewTime = viewTime;
            highIndex = idx;
        }
    }
    answer = SecondToTime(highIndex);
    return answer;
}
