import sys
from itertools import combinations

input = sys.stdin.readline
minChickenLength = sys.maxsize

n, m = map(int, input().split())
city = [list(map(int, input().split())) for _ in range(n)]

houses = []
chickenStores = []

# 집의 위치는 houses 리스트에, 치킨집 위치는 chickenStores 리스트에 저장
for i in range(n):
    for j in range(n):
        if city[i][j] == 1: houses.append([i, j])
        elif city[i][j] == 2: chickenStores.append([i, j])

# itertools 모듈의 combinations 함수 사용
# chickenStore 변수에는 chickenStores에서 m개를 뽑은 이터러블 객체가 저장되어 있음 (조합론의 C와 동일)
for chickenStore in combinations(chickenStores, m):
    tempSum = 0
    # 모든 집에 대해 치킨 거리 탐색
    for house in houses:
        # 한 집에서 여러 치킨집에 접근할 수 있음 -> 그 중에서 치킨 거리가 제일 짧은 치킨집을 찾아 그 치킨거리를 tempSum에 더함
        tempSum += min([abs(house[0] - storePos[0]) + abs(house[1] - storePos[1]) for storePos in chickenStore])
    # 도시의 최소 치킨 거리 갱신
    minChickenLength = min(minChickenLength, tempSum)

print(minChickenLength)