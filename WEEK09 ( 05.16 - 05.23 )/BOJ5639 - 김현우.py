import sys

input = sys.stdin.readline
sys.setrecursionlimit(100000)

# 이진 탐색 트리의 전위 순회 결과를 입력받을 리스트
preorder = []

# 이진 탐색 트리의 전위 순회 결과를 후위 순회 결과로 바꿔주는 함수
# start : 시작 인덱스, end : 끝 인덱스
def postorder(start, end):
    if start > end: # 배열을 모두 탐색 시 함수 종료
        return
    root = end + 1 # 루트보다 큰 값이 존재하지 않을 경우를 대비

    # 해당 영역 사이의 루트 위치 찾기
    for index in range(start+1, end+1):
        if preorder[start] < preorder[index]:
            root = index
            break

    postorder(start+1, root-1) # root를 기준으로 왼쪽 서브트리, 오른쪽 서브트리 두 부분으로 나눠 탐색
    postorder(root, end)
    print(preorder[start]) # 후위 순회를 해야 하므로 start 인덱스 값을 출력

# 전위 순회 결과 입력
# 총 몇 줄의 입력을 받을 것인지 주어져 있지 않으므로 EOF에러를 캐치할 때까지 계속 입력받음
while True:
    try:
        preorder.append(int(input()))
    except:
        break

postorder(0, len(preorder)-1)