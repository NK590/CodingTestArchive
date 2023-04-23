import sys

def solution(s):
    answer = sys.maxsize

    # i칸 단위로 잘라서 비교
    for i in range(1, len(s) // 2 + 2):
        res = ''
        count = 1
        temp = s[:i]

        # i칸 단위로 자른 단위 문자열을 원래 문자열과 비교해가면서 줄여나가기
        for j in range(i, len(s) + i, i):
            if temp == s[j:j + i]:
                count += 1
            else:
                if count == 1:
                    res += temp
                else:
                    res += str(count) + temp
                temp = s[j:j + i]
                count = 1

        # 최소 길이 갱신
        answer = min(answer, len(res))

    return answer