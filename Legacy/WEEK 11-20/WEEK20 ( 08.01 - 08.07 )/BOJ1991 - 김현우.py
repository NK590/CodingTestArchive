import sys

n = int(sys.stdin.readline())
tree = {}

for _ in range(n):
    a, b, c = sys.stdin.readline().rstrip().split()
    tree[a] = [b, c]

# 전위 순회
def preorder(root):
    if root != '.':
        visited.append(root)
        preorder(tree[root][0])
        preorder(tree[root][1])

# 중위 순회
def inorder(root):
    if root != '.':
        inorder(tree[root][0])
        visited.append(root)
        inorder(tree[root][1])

# 후위 순회
def postorder(root):
    if root != '.':
        postorder(tree[root][0])
        postorder(tree[root][1])
        visited.append(root)

# 전위 순회 출력
visited = []
preorder('A')
print(*visited, sep = '')

# 중위 순회 출력
visited = []
inorder('A')
print(*visited, sep = '')

# 후위 순회 출력
visited = []
postorder('A')
print(*visited, sep = '')