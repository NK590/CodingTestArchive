import sys

input = sys.stdin.readline

# 주어진 문자열이 좋은 수열인지 판정하는 함수
def isGoodSeq(string):
    for i in range(len(string)):
        for j in range(1, (len(string) - i) // 2 + 1):
            if string[i:i + j] == string[i + j:i + 2 * j]:
                return False
    return True

def backtrack(n, string):
    # 길이 n까지 최초로 끝까지 탐색했을 시 그 좋은 수열을 출력하고 프로그램 종료
    if n == 0:
        print(string)
        exit(0)

    # 기존 좋은 수열 문자열에 1, 2, 3을 이어붙임
    for char in '123':
        # 기존 좋은 수열 + 새 숫자가 좋은 수열일 때 and 기존 좋은 수열의 마지막 자리가 새 숫자와 다른 수일 때
        # 그 숫자를 붙여서 재귀 탐색
        if isGoodSeq(string + char) and string[-1] != char:
            backtrack(n - 1, string + char)

n = int(input())

# 좋은 수열 최소값의 맨 처음 수는 무조건 1로 시작함
backtrack(n - 1, '1')