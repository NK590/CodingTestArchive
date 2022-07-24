import sys
from itertools import combinations

input = sys.stdin.readline
max_count = 0

# 문자 -> 숫자 변환 딕셔너리
char_to_int = {'b': 20, 'd': 19, 'e': 18, 'f': 17, 'g': 16, 'h': 15, 'j': 14,
            'k': 13, 'l': 12, 'm': 11, 'o': 10, 'p': 9, 'q': 8, 'r': 7,
            's': 6, 'u': 5, 'v': 4, 'w': 3, 'x': 2, 'y': 1, 'z': 0}

# 문자열 -> 정수 변환 함수
def word_to_int(word):
    ans = 0
    for char in word:
        ans |= (1 << char_to_int[char])
    return ans

n, k = map(int, input().split())
word_list = []

# word_list 입력 -> 접두사 anta, 접미사 tica 제외하고 입력
for _ in range(n):
    word = input().rstrip()
    word_list.append(set(word[4:-4]).difference('a', 'n', 't', 'i', 'c'))

# 접두사 anta, 접미사 tica를 읽으려면 최소 5글자를 알아야 됨
# -> 5글자 미만을 가르치게 되면 이후 결과와 상관없이 읽을 수 있는 단어 수는 무조건 0
if k < 5:
    print(0)
    exit(0)
k -= 5 # 위 5글자 제외

# 탐색 시 단어의 2진수 변환값 계산용 리스트
power_of_2 = [2**i for i in range(21)]
word_list_num = [word_to_int(x) for x in word_list]

# combinations를 이용한 탐색
for comb in combinations(power_of_2, k):
    # 매 조합마다 단어 체크 후 모든 비트가 조합 내에 속하면 카운트 += 1
    comb_sum = sum(comb)
    temp_max_count = 0
    for word_int in word_list_num:
        if word_int & comb_sum == word_int:
            temp_max_count += 1
    max_count = max(max_count, temp_max_count)

print(max_count)
