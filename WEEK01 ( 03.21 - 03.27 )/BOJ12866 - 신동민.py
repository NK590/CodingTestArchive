import sys
sys.setrecursionlimit(1500*1500) # 재귀 깊이가 깊어질 수 있기에 임의 설정.
check=[[False]*1501 for _ in range(1501)] # 돌 3개 합이 최대 1500이기에 1501로 배열 설정

a,b,c = map(int,input().split())
s=a+b+c

# 3개의 돌 그룹을 비교 및 돌 교환
def dfs(x,y):

    # 만약 이전에 체크한 비교라면 리턴
    if check[x][y]:
        return
    check[x][y]=True

    # 3개의 돌 그룹
    a=[x,y,s-x-y]

    for i in range(3):
        for j in range(3):
            if a[i]<a[j]:
                # 임의의 그룹
                b = [x, y, s - x - y]

                b[i]+=a[i]
                b[j]-=a[i]

                dfs(b[0],b[1])

# 만약 돌 그룹 3개의 개수 합이 3으로 나눠 떨어지지 않으면 0 반환
if s%3!=0:
    print(0)
    sys.exit(0)
else:
    dfs(a,b)
    # 돌 그룹 2개가 전체 개수 합을 3으로 나눈 결과와 같다면 1 반환
    if check[s//3][s//3]:
        print(1)
    else:
        print(0)