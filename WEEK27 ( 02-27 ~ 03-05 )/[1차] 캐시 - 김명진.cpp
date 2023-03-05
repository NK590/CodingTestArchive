#include <iostream>
#include <string>
#include <vector>

using namespace std;

vector<string> caches;

int main(int cacheSize, vector<string> cities)
{
    if (cacheSize == 0) return cities.size() * 5;

    int answer = 0;

    for (int i = 0; i < cities.size(); ++i)
    {
        for (int j = 0; j < cities[i].size(); ++j)
        {
            if ('A' <= cities[i][j] && cities[i][j] <= 'Z')
            {
                cities[i][j] += 32;
            }
        }
    }

    for (int i = 0; i < cities.size(); ++i)
    {
        int isHit = -1;
        for (int j = 0; j < caches.size(); ++j)
        {
            if (cities[i] == caches[j])
            {
                isHit = j;
            }
        }

        if (isHit != -1)
        {
            for (int k = isHit; k < caches.size()-1; ++k)
            {
                caches[k] = caches[k + 1];
            }
            caches[caches.size() - 1] = cities[i];
            answer += 1;
        }
        else
        {
            if (caches.size() < cacheSize)
            {
                caches.push_back(cities[i]);
            }
            else
            {
                for (int k = 0; k < cacheSize - 1; ++k)
                {
                    caches[k] = caches[k + 1];
                }
                caches[cacheSize - 1] = cities[i];
            }
            answer += 5;
        }
    }

    return answer;
}