#include <string>
#include <vector>
#include <cstdlib>
#include <iostream>

using namespace std;

string solution(int n, int m, int x, int y, int r, int c, int k)
{
    string answer = "";

    // 거리보다 k가 작은지 체크
    int distance = abs(x - r) + abs(y - c);
    if (distance > k)
        return "impossible";

    // k 는 짝수인데 minimumDistance가 짝수로 끝나지 않는다면
    if (k % 2 == 0 && distance % 2 == 1)
        return "impossible";
    // k 는 홀수인데 minimumDistance가 홀수로 끝나지 않는다면
    else if (k % 2 == 1 && distance % 2 == 0)
        return "impossible";

    // 각 방향으로 이동해야 하는 횟수
    int down = max(0, r - x);
    int up = max(0, x - r);
    int left = max(0, y - c);
    int right = max(0, c - y);

    // 반복이동 해야 하는 횟수
    int other = (k - distance) / 2;

    int curX = x;
    int curY = y;
    for (int i = 0; i < k; i++)
    {

        // 사전 순서 d l r u
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