#include <string>
#include <vector>
#include <iostream>

using namespace std;

vector<string> v1 = { "go","gone","guild" };
vector<string> v2 = { "abc","def","ghi","jklm" };
vector<string> v3 = { "word","war","warrior","world" };


struct Trie
{
    Trie* node[26];
    bool finish;
    int child;

    Trie()
    {
        for (int i = 0; i < 26; i++)
            node[i] = NULL;

        finish = false;
        child = 0;
    }

    void Insert(const char* Str)
    {
        child++;
        if (*Str == NULL)
        {
            finish = true;
            return;
        }

        int cur = *Str - 'a';
        if (node[cur] == NULL) node[cur] = new Trie();
        node[cur]->Insert(Str + 1);
    }

    int Find(const char* str, int cnt)
    {
        if (*str == NULL || child == 1)
            return cnt;

        int cur = *str - 'a';
        return node[cur]->Find(str + 1, cnt +1);
    }

};

int solution(vector<string> words)
{
    int answer = 0;

    Trie *root = new Trie();
    int N = words.size();


    for (int i = 0; i < N; i++)
        root->Insert(words[i].c_str());

    for (int i = 0; i < N; i++)
        answer += (root->Find(words[i].c_str(), 0));



    return answer;
}


// Ÿ�� ���� O(N*N)
// 2�� ����
int solution1(vector<string> words) 
{
    int answer = 0;

    for (auto curWord : words)
    {       
        for (int idx = 0; idx < curWord.size(); idx++)
        {        
            bool check = false;
            for (auto compareWord : words)
            {
                if (curWord == compareWord)
                    continue;

                if (curWord.substr(0, idx + 1) == compareWord.substr(0, idx + 1))
                    check = true;
            }

            // ��� �ܾ �˻� �ϰ� ���� �ܾ ���ų�, �̹� �ܾ��� ������ �˻縦 �߰ų�
            if (!check || idx + 1 == curWord.size())
            {
                answer += idx+1;
                break;
            }
        }
    }
    return answer;
}

int main()
{
    cout << solution(v3) << endl; 

    return 0;
}

