n = int(input())
words = []

# 단어 입력받음
for i in range(n):
  words.append(input())

# 중복 제거
uniqWords = list(set(words))

# 먼저 길이로 정렬 후 알파벳 순으로 정렬
uniqWords.sort(key=lambda x: (len(x), x))

for i in uniqWords:
  print(i)
