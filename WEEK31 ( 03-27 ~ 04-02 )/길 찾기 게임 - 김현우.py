import sys

sys.setrecursionlimit(100000)


class Tree:
    def __init__(self, data_list, org_data_list):
        self.data = max(data_list, key=lambda x: x[1])  # y측 기준으로 오름차순 정렬 후 제일 큰 값을 찾기 -> 이 data값을 기준으로 좌우로 분기됨
        self.idx = org_data_list.index(self.data) + 1  # 현재 노드 인덱싱용 번호 -> 순회 시 인덱스로 사용

        # data의 x값을 기준으로 왼쪽, 오른쪽 리스트로 나누기
        left = list(filter(lambda x: x[0] < self.data[0], data_list))
        right = list(filter(lambda x: x[0] > self.data[0], data_list))

        # 현 트리 노드 기준 왼쪽, 오른쪽 서브트리를 재귀구현
        self.left = Tree(left, org_data_list) if left else None
        self.right = Tree(right, org_data_list) if right else None


# preorder, postorder를 같은 함수로 처리해버림
def go(tree, pre, post):
    pre.append(tree.idx)

    if tree.left is not None: go(tree.left, pre, post)
    if tree.right is not None: go(tree.right, pre, post)

    post.append(tree.idx)


def solution(nodeinfo):
    pre = []
    post = []

    tree = Tree(nodeinfo, nodeinfo)
    go(tree, pre, post)

    return [pre, post]