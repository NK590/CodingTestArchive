from heapq import heappush, heappop

def solution(food_times, k):
    # 일단 음식 다 먹을 경우 예외처리
    if sum(food_times) <= k:
        return -1

    # 우선순위 큐로 순서대로 다 먹은 음식을 관리
    pq = []
    for index, time in enumerate(food_times):
        heappush(pq, (time, index))

    cycle_count = len(food_times)
    prev = 0
    while pq:
        # 음식을 전부 먹으며 돌아갈 수 있는 사이클만큼 시간 빼주기
        cycle_sum = (pq[0][0] - prev) * cycle_count
        if cycle_sum <= k:
            k -= cycle_sum
            cycle_count -= 1
            prev, dummy = heappop(pq)
        # 사이클을 돌 수 없으면 (사이클 돌기 전에 k초가 다 지나가면)
        # 남은 수만큼 사이클 돌려서 인덱스 return
        else:
            index = k % cycle_count
            pq.sort(key=lambda x: x[1])
            return pq[index][1] + 1