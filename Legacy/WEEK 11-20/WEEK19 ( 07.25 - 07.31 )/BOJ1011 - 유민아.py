t = int(input())

for _ in range(t):
  x, y = map(int, input().split()) #시작점 도착점
  d = y-x #거리
  num = 1

  while True:
    if num**2 <= d < (num + 1)**2:
      break
    else:
      num += 1

  if num**2 == d:
    print((num*2)-1)
  elif num**2 < d <= num**2 + num:
    print(num*2)
  else :
    print((num*2) + 1)
