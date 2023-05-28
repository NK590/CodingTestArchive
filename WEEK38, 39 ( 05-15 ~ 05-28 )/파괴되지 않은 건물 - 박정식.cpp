#include <string>
#include <vector>
#include <iostream>

using namespace std;

int map[1001][1001];
int temp[1001][1001];

int solution(vector<vector<int>> board, vector<vector<int>> skill)
{
    int answer = 0;

    int height = board.size();
    int width = board[0].size();

    // �ʱ� ���� �Է�
    for (int row = 0; row < height; ++row)
    {
        for (int col = 0; col < width; ++col)
            map[row][col] = board[row][col];
    }

    int skillSize = skill.size();
    for (int index = 0; index < skillSize; index++)
    {
        if (skill[index][0] == 1) 
            skill[index][5] = skill[index][5] * (-1);

        temp[skill[index][1]][skill[index][2]] += skill[index][5]; //������ġ
        temp[skill[index][3] + 1][skill[index][2]] -= skill[index][5]; // ������ġ�κ��� ������
        temp[skill[index][1]][skill[index][4] + 1] -= skill[index][5]; // ������ġ�κ��� �Ʒ�
        temp[skill[index][3] + 1][skill[index][4] + 1] += skill[index][5]; // ������ġ�κ��� �밢��
    }

    //���� ������
    for (int row = 0; row < height; row++)
    {
        for (int col = 1; col < width; col++)
            temp[row][col] += temp[row][col - 1];
    }
    //���� ������
    for (int col = 0; col < width; col++)
    {
        for (int row = 1; row < height; row++)
            temp[row][col] += temp[row-1][col];
    }


    for (int row = 0; row < height; ++row)
    {
        for (int col = 0; col < width; ++col)
        {
            if (map[row][col] + temp[row][col] > 0)
                answer++;
        }
    }

    return answer;
}
