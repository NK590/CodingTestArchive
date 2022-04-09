import sys, heapq

input = sys.stdin.readline

n, k = map(int, input().split())

jewel_list = [list(map(int, input().split())) for _ in range(n)]
jewel_list.sort()

bag_list = [int(input()) for _ in range(k)]
bag_list.sort()

max_heap = []
sum_value = 0

for max_weight in bag_list:
    while jewel_list and max_weight >= jewel_list[0][0]:
        heapq.heappush(max_heap, -jewel_list[0][1])
        heapq.heappop(jewel_list)
    
    if max_heap:
        sum_value -= heapq.heappop(max_heap)
    elif not jewel_list:
        break

print(sum_value)