import sys
from heapq import heappush, heappop

input = sys.stdin.readline

n, k = map(int, input().split())

# 보석의 무게와 가격, 가방의 최대 무게를 입력받은 후 정렬
jewel_list = [list(map(int, input().split())) for _ in range(n)]
jewel_list.sort()

bag_list = [int(input()) for _ in range(k)]
bag_list.sort()

# 우선순위 큐 사용
# 최대 힙을 사용하기 위해 입출력 시 마이너스 처리
max_heap = []
sum_value = 0

# 담을 수 있는 무게가 작은 배낭부터 탐색
for max_weight in bag_list:
    # 정렬된 보석 리스트에서 하나씩 뽑아서 가방 무게 한도와 비교 -> 최대 힙에 가능한 보석을 전부 넣기
    while jewel_list and max_weight >= jewel_list[0][0]:
        heappush(max_heap, -jewel_list[0][1])
        heappop(jewel_list)

    # 최대 힙 내에 임시 저장된 보석값들 중에서 제일 큰 거 하나를 뽑아 합에 더함
    if max_heap:
        sum_value -= heappop(max_heap)
    # 보석을 전부 꺼내서 비교 완료했을 때 반복문 종료
    elif not jewel_list:
        break

print(sum_value)