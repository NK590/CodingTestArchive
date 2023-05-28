#include <iostream>
#include <string>
#include <vector>
#include <map>
#include <sstream>
#include <cmath>

using namespace std;

map<int, int> finalParkingTime;
map<int, int> inCheck;

vector<string> split(string str, char delimiter)
{
    istringstream iss(str);
    string temp;

    vector<string> result;

    while (getline(iss, temp, delimiter))
    {
        result.push_back(temp);
    }
    return result;
}

int changeToMin(string str)
{
    vector<string> temp = split(str, ':');
    return (stoi(temp[0]) * 60 + stoi(temp[1]));
}

vector<int> solution(vector<int> fees, vector<string> records) {
    vector<int> answer;

    for (int i = 0; i < records.size(); ++i)
    {
        vector<string> temps;
        temps = split(records[i], ' ');

        if (temps[2] == "OUT")
        {
            map<int, int>::iterator inInfo = inCheck.find(stoi(temps[1]));
            map<int, int>::iterator dupInfo = finalParkingTime.find(stoi(temps[1]));
            if (dupInfo != finalParkingTime.end())
            {
                dupInfo->second += (changeToMin(temps[0]) - inInfo->second);
            }
            else
            {
                finalParkingTime.insert(make_pair(stoi(temps[1]), changeToMin(temps[0]) - inInfo->second));
            }
            inCheck.erase(inInfo);
        }
        else
        {
            inCheck.insert(make_pair(stoi(temps[1]), changeToMin(temps[0])));
        }
    }

    for (auto iter = inCheck.begin(); iter != inCheck.end(); ++iter)
    {
        map<int, int>::iterator dupInfo = finalParkingTime.find(iter->first);
        if (dupInfo != finalParkingTime.end())
        {
            dupInfo->second += (1439 - iter->second);
        }
        else
        {
            finalParkingTime.insert(make_pair(iter->first, 1439 - iter->second));
        }
    }

    for (auto iter = finalParkingTime.begin(); iter != finalParkingTime.end(); ++iter)
    {
        if (iter->second <= fees[0])
        {
            answer.push_back(fees[1]);
        }
        else
        {
            answer.push_back(fees[1] + (ceil(float(iter->second - fees[0]) / fees[2])) * fees[3]);
        }
    }

    return answer;
}

int main()
{
    std::cout << "Hello World!\n";
}