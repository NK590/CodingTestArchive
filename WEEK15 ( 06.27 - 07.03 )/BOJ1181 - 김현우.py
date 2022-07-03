import sys

input = sys.stdin.readline

n = int(input())
wordList = list(set([input().rstrip() for _ in range(n)])) # 입력 후 중복단어 제거
# 1. ( 단어의 길이, 단어 ) 튜플을 원소로 가지는 리스트 생성
# 2. 그 리스트를 단어의 길이 -> 단어(사전순) 순서로 오름차순 정렬
sortedWordList = sorted(list(zip([len(x) for x in wordList], wordList)), key = lambda x : (x[0], x[1]))

# 정렬이 완료된 리스트 내의 단어들을 순서대로 출력
print(*[sortedWordList[x][1] for x in range(len(sortedWordList))], sep="\n")