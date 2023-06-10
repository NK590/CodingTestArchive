#include <string>
#include <vector>
#include <cstdlib>
#include <iostream>

using namespace std;

string solution(int n, int m, int x, int y, int r, int c, int k)
{
    string answer = "";

    // �Ÿ����� k�� ������ üũ
    int distance = abs(x - r) + abs(y - c);
    if (distance > k)
        return "impossible";

    // k �� ¦���ε� minimumDistance�� ¦���� ������ �ʴ´ٸ�
    if (k % 2 == 0 && distance % 2 == 1)
        return "impossible";
    // k �� Ȧ���ε� minimumDistance�� Ȧ���� ������ �ʴ´ٸ�
    else if (k % 2 == 1 && distance % 2 == 0)
        return "impossible";

    // �� �������� �̵��ؾ� �ϴ� Ƚ��
    int down = max(0, r - x);
    int up = max(0, x - r);
    int left = max(0, y - c);
    int right = max(0, c - y);

    // �ݺ��̵� �ؾ� �ϴ� Ƚ��
    int other = (k - distance) / 2;

    int curX = x;
    int curY = y;
    for (int i = 0; i < k; i++)
    {

        // ���� ���� d l r u
        if ((down > 0 || other > 0) && curX < n)
        {
            answer += "d";

            if (down > 0)
                down--;
            else
            {
                other--;
                up++;
            }
            curX++;
        }
        else if ((left > 0 || other > 0) && curY > 1)
        {
            answer += "l";

            if (left > 0)
                left--;
            else
            {
                other--;
                right++;
            }
            curY--;
        }
        else if ((right > 0 || other > 0) && curY < m)
        {
            answer += "r";

            if (right > 0)
                right--;
            else
            {
                other--;
                left++;
            }
            curY++;
        }
        else if ((up > 0 || other > 0) && curX > 1)
        {
            answer += "u";

            if (up > 0)
                up--;
            else
            {
                other--;
                down++;
            }
            curX--;
        }
    }

    return answer;
}