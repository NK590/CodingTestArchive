# Trie 클래스 선언
class Trie():
    def __init__(self):
        self.child = dict()
        self.count = 0

    def insert(self, string):
        curr = self
        for str in string:
            if str not in curr.child:
                curr.child[str] = Trie()
            curr = curr.child[str]
            curr.count += 1

    def search(self, string):
        curr = self
        for index, str in enumerate(string):
            if curr.child[str].count == 1:
                return index + 1
            curr = curr.child[str]
        return index + 1

# 사실상 Trie 자료구조 연습문제
def solution(words):
    answer = 0
    trie = Trie()

    for word in words:
        trie.insert(word)

    for word in words:
        answer += trie.search(word)

    return answer