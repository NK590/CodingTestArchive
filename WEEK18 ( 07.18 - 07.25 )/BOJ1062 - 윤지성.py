import sys

n, k = map(int,input().split())
words = [set(sys.stdin.readline().rstrip()) for _ in range(n)]
# K가 5보다 작으면 단어배우기 불가
if k < 5:
    print(0)
    sys.exit()
# K가 26이면 다 배울수 있음
elif k == 26:
    print(n)
    sys.exit()

learn = [0] * 26
result = 0

# a, c, i, n, t는 무조건 배워야 함
for c in ('a', 'c', 'i', 'n', 't'):
    learn[ord(c) - ord('a')] = True


def dfs(idx, count):
    global result

    if count == k - 5:
        tmp = 0
        for word in words:
            isContain = True
            for w in word:
                # 한 번이라도 알파벳이 해당 단어에 없으면 배울 수 없다.
                if not learn[ord(w) - ord('a')]:
                    isContain = False
                    break
            if isContain:
                tmp += 1
        result = max(tmp, result)
        return

    for i in range(idx, 26):
        if not learn[i]:
            learn[i] = True
            dfs(i, count + 1)
            learn[i] = False
dfs(0, 0)
print(result)