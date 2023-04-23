#include <iostream>
#include <string>
#include <vector>

using namespace std;

vector<string> ParsingUV(string p)
{
    vector<string> parsingUV;
    string u = "";
    string v = "";
    int uIdx = 0;
    int vIdx = 0;
    for (int i = 0; i < p.size(); ++i)
    {
        if (i != 0 && uIdx == 0)
        {
            break;
        }
        if (p[i] == '(')
        {
            u.push_back(p[i]);
            ++uIdx;
            ++vIdx;
        }
        else
        {
            u.push_back(p[i]);
            --uIdx;
            ++vIdx;
        }
    }
    for (int i = vIdx; i < p.size(); ++i)
    {
        v.push_back(p[i]);
    }
    parsingUV.push_back(u);
    parsingUV.push_back(v);
    return parsingUV;
}

bool IsRightString(string s)
{
    int rIdx = 0;
    for (int i = 0; i < s.size(); ++i)
    {
        if (s[i] == '(')
        {
            ++rIdx;
        }
        else if (rIdx > 0)
        {
            --rIdx;
        }
        else
        {
            return false;
        }
    }
    return true;
}

string RecursionFunc(string p)
{
    if (p == "") return "";
    vector<string> s;
    string u = "";
    string v = "";
    s = ParsingUV(p);
    u = s[0];
    v = s[1];
    if (IsRightString(u))
    {
        return u + RecursionFunc(v);
    }
    else
    {
        string finalS = '(' + RecursionFunc(v) + ')';
        u.pop_back();
        u.erase(0, 1);
        string newU = "";
        for (int i = 0; i < u.size(); ++i)
        {
            if (u[i] == '(')
            {
                newU.push_back(')');
            }
            else
            {
                newU.push_back('(');
            }
        }
        return finalS + newU;
    }
}

string solution(string p)
{
    if (p == "") return "";
    string answer = "";

    answer = RecursionFunc(p);

    return answer;
}


int main()
{
    std::cout << "Hello World!\n";
}