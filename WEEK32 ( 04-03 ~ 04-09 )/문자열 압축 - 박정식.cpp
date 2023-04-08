#include <string>

using namespace std;


int solution(string s)
{
    int answer = s.length();
    for (int len = 1; len <= s.length() / 2; len++)
    {
        string result = "";
        string key = s.substr(0, len);
        int Cnt = 1;
        int index;
        for (index = len; index <= s.length(); index = index + len)
        {
            if (key == s.substr(index, len)) Cnt++;
            else
            {
                if (Cnt == 1) 
                    result += key;
                else
                {
                    result += to_string(Cnt);
                    result += key;
                }

                key = s.substr(index, len);
                Cnt = 1;
            }
        }

        if (index > s.length())
        {
            if (Cnt == 1) 
                result += key;
            else
            {
                result += to_string(Cnt);
                result += key;
            }
        }

        if (answer > result.length())
            answer = result.length();
    }
    return answer;
}
