from sys import stdin
from itertools import combinations
from string import ascii_lowercase

n, k = map(int, input().split())
words = [] #입력 단어 리스트
minLength = 5
countResult = 0
restAlpha = set(ascii_lowercase).difference('a', 'c', 'i', 't', 'n')

for _ in range(n):
  #set로 해서 중복 알파벳 제거, must 다섯개는 제외
  words.append(set(stdin.readline().rstrip()).difference('a', 'c', 'i', 't', 'n'))
# print(n, k, words)

#  
if k < minLength :
  print(0)

else:
  for i in list(combinations(restAlpha, k-minLength)):
    count = 0
    for word in words:
      if not word.difference(i):
        count += 1

    countResult = max(countResult, count)
  print(countResult)
    


