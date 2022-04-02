import sys

input = sys.stdin.readline

# 문자열 정렬 풀이법
# for _ in range(int(input())):
#     n = int(input())
#     numList = [input().rstrip() for _ in range(n)]
#     numList.sort()
#
#     isValidNum = True
#     for i in range(n-1):
#         if numList[i] == numList[i+1][:len(numList[i])]:
#             isValidNum = False
#             break
#
#     if isValidNum: print('YES')
#     else: print('NO')

# Trie 자료구조를 이용한 풀이법
class Node:
    def __init__(self, key, data=None):
        self.key = key
        self.data = data
        self.children = {}

class Trie:
    def __init__(self):
        self.head = Node(None)

    def insert(self, string):
        curNode = self.head

        for char in string:
            if char not in curNode.children:
                curNode.children[char] = Node(char)
            curNode = curNode.children[char]

    def search(self, string):
        curNode = self.head

        for char in string:
            curNode = curNode.children[char]

        if curNode.children: return False
        else: return True

for _ in range(int(input())):
    n = int(input())
    trie = Trie()
    numList = []

    for _ in range(n):
        num = input().rstrip()
        numList.append(num)
        trie.insert(num)

    isValidNum = True
    for num in numList:
        if not trie.search(num):
            isValidNum = False
            break

    if isValidNum: print('YES')
    else: print('NO')
