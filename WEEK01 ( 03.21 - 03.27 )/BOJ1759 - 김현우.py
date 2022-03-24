import sys

input = sys.stdin.readline

visited = []
vowels = {'a', 'e', 'i', 'o', 'u'}

# 재귀를 이욯한 백트래킹 탐색
def backtrack(start):
    # l개의 문자를 전부 골랐을 때, 자음의 개수와 모음의 개수를 체크하여
    # 문제 조건에 맞을 시 출력 후 return
    if len(visited) == l:
        vowel_count = 0
        for char in visited:
            if char in vowels:
                vowel_count += 1
        consonant_count = l - vowel_count
        
        if consonant_count >= 2 and vowel_count >= 1:
            print(''.join(visited))
        return
    
    # start 지점을 기점으로 주어진 문자열 탐색
    # i번째 문자를 골랐을 시 그 다음은 재귀를 이용해 i+1번째부터 탐색
    for i in range(start, len(char_list)):
        if char_list[i] not in visited:
            visited.append(char_list[i])
            backtrack(i+1)
            visited.pop()

l, c = map(int, input().split())
char_list = list(input().rstrip().split())
# 알파벳 증가 순으로 출력하기 위해 정렬이 필요
char_list.sort()

backtrack(0)