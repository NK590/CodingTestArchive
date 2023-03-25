#include <iostream>
#include <string>
#include <vector>
#include <sstream>

using namespace std;

struct Music
{
    string name;
    string info;
    int runningTime;
};

vector<string> split(string str, char delimiter)
{
    istringstream iss(str);
    string buffer;

    vector<string> result;

    while (getline(iss, buffer, delimiter))
    {
        result.push_back(buffer);
    }
    return result;
}

string changeSharptoLowerCase(string str)
{
    string result;

    int tempIdx = 0;
    for (int i = 0; i < str.size(); ++i)
    {
        if (str[i + 1] == '#')
        {
            result.push_back(str[i] + 32);
        }
        else if (str[i] =='#')
        {
            continue;
        }
        else
        {
            result.push_back(str[i]);
        }
    }
    return result;
}

string solution(string m, vector<string> musicinfos)
{
    string answer = "";
    
    vector<Music> musics;
    string radioMelody;

    string changeM = changeSharptoLowerCase(m);

    for (int i = 0; i < musicinfos.size(); ++i)
    {
        Music temp;
        int startT;
        int endT;
        startT = (stoi(split(split(musicinfos[i], ',')[0], ':')[0]) * 60 + stoi(split(split(musicinfos[i], ',')[0], ':')[1]));
        endT = (stoi(split(split(musicinfos[i], ',')[1], ':')[0]) * 60 + stoi(split(split(musicinfos[i], ',')[1], ':')[1]));
        temp.runningTime = endT - startT + 1;
        temp.name = split(musicinfos[i], ',')[2];
        temp.info = changeSharptoLowerCase(split(musicinfos[i], ',')[3]);

        musics.push_back(temp);
    }

    for (int i = 0; i < musics.size(); ++i)
    {
        for (int j = 0; j < musics[i].runningTime; ++j)
        {
            radioMelody += musics[i].info[j % musics[i].info.size()];
        }
        radioMelody += ' ';
    }

    vector<int> answerCand;

    if (radioMelody.find(changeM) == -1)
    {
        answer = "(None)";
    }
    else
    {
        int tempIdx = 0;
        while (radioMelody.find(changeM, tempIdx) != -1)
        {
            int checkRunningT = 0;
            for (int i = 0; i < musics.size(); ++i)
            {
                checkRunningT += musics[i].runningTime;
                if (radioMelody.find(changeM, tempIdx) <= checkRunningT)
                {
                    answerCand.push_back(i);
                    break;
                }
                checkRunningT += 1;
            }
            tempIdx = radioMelody.find(changeM, tempIdx) + 1;
        }

        int maxRunningT = 0;
        for (int i = 0; i < answerCand.size(); ++i)
        {
            if (musics[answerCand[i]].runningTime > maxRunningT)
            {
                maxRunningT = musics[answerCand[i]].runningTime;
                answer = musics[answerCand[i]].name;
            }
        }
    }
    return answer;
}

int main()
{
}