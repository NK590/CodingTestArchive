//코드출처 https://barbera.tistory.com/61
//참고자료 https://driip.me/65d9b58c-bf02-44bf-8fba-54d394ed21e0

#include <iostream>
#include <string>
#include <vector>

using namespace std;

long change[1001][1001];

void imos(int a, int b, int c, int d, int val) 
{
    int x1 = a;
    int x2 = c + 1;
    int y1 = b;
    int y2 = d + 1;
    change[x1][y1] += val;
    change[x2][y2] += val;
    change[x1][y2] -= val;
    change[x2][y1] -= val;
}

int solution(vector<vector<int>> board, vector<vector<int>> skill) 
{
    int answer = 0;

    unsigned short row;
    unsigned short column;

    row = board.size();
    column = board[0].size();
    
    for (int i = 0; i < skill.size(); i++) 
    {
        int type = skill[i][0];
        int r1 = skill[i][1];
        int c1 = skill[i][2];
        int r2 = skill[i][3];
        int c2 = skill[i][4];
        int degree = skill[i][5];
        if (type == 1) degree *= -1;
        imos(r1, c1, r2, c2, degree);
    }

    for (int i = 0; i < row; i++) 
    {
        for (int j = 1; j < column; j++) 
        {
            change[i][j] += change[i][j - 1];
        }
    }

    for (int j = 0; j < row; j++) 
    {
        for (int i = 1; i < column; i++) 
        {
            change[i][j] += change[i - 1][j];
        }
    }

    for (int i = 0; i < row; i++) 
    {
        for (int j = 0; j < column; j++) 
        {
            change[i][j] += board[i][j];
            if (change[i][j] > 0) answer++;
        }
    }
    
    return answer;
}

int main()
{
    std::cout << "Hello World!\n";
}