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
    string result = " ";

    vector<int> resultIdx;
    int tempIdx = 0;
    while ((tempIdx = str.find('#', tempIdx)) != std::string::npos)
    {
        tempIdx += 1;
        resultIdx.push_back(tempIdx);
    }

    for (int i = 0; i < str.size(); ++i)
    {
        for (int j = 0; j < resultIdx.size(); ++j)
        {
            if (i != resultIdx[j]-1)
            {
                result += str[i];
            }
        }
    }

    for (int i = 0; i < resultIdx.size(); ++i)
    {
        result[resultIdx[i]-1] += 32;
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
        temp.runningTime = endT - startT;
        temp.name = split(musicinfos[i], ',')[2];
        temp.info = changeSharptoLowerCase(split(musicinfos[i], ',')[3]);

        musics.push_back(temp);
    }

    for (int i = 0; i < musics.size(); ++i)
    {
        for (int j = 0; j <= musics[i].runningTime; ++j)
        {
            radioMelody += musics[i].info[j % musics[i].info.size()];
        }
        radioMelody += ' ';
    }

    vector<int> answerIdx;
    int tempIdx = 0;
    while ((tempIdx = radioMelody.find(changeM, tempIdx)) != std::string::npos)
    {
        tempIdx += changeM.length();
        answerIdx.push_back(tempIdx);
    }
    
    vector<int> answerCandidate;
    vector<int> finalRunningT;
    for (int i = 0; i < musics.size(); ++i)
    {
        int tempRunningT = 0;
        finalRunningT.push_back(tempRunningT += musics[i].runningTime);
    }
    for (int i = 0; i < answerIdx.size(); ++i)
    {
    }

    return answer;
}

int main()
{
}