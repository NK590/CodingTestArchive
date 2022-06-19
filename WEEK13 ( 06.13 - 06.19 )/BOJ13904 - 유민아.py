# https://www.acmicpc.net/problem/1390
# days[] 가 idx 날에 문제 해결하면 1로 저장시킴
# 점수가 큰 순서대로 정렬한뒤에 포문돌려서 넣는건데
#  마감일 순서대로 -1씩 빼면서 해결 안된 날이 있으면 그 날 해결하고 이미 다른 과제를 하는 거면 그 전날을 살펴서 빈 날에 과제를 한다.
# 이렇게 하면 점수가 큰 순서대로 진행하고 (1차 포문) 
# 각 과제별로 마감일의 역순으로 빈 날에 과제를 해결할 수 있다.

n = int(input())
graph = []
for _ in range(n):
  graph.append(list(map(int, input().split())))

# 점수가 큰 순서대로 정렬
graph.sort(key=lambda x:x[1], reverse=True) 
# print(graph)

score = 0
days = [0]*1001
for i in graph:
  for j in range(i[0], 0, -1): #과제별로 남은일수 for문 ex. 3일 남았으면 3, 2, 1로 포문을 돌린다. 그래서 days[3]에 해당 위치가 0이면 과제를 해결하고(3일차에 과제를 푼다) 아니면 days[2], 즉 2일차에 과제를 푸는 식으로 줄여간다.
    # print('i,j:', i,j)
    if days[j] == 0: # 과제 해결 안했으면 해결
      days[j] = 1
      score += i[1]
      # print('jjjj:',j)
      break

print(score)


