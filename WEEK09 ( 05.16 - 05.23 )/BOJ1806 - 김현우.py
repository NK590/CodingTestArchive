import sys

input = sys.stdin.readline

minLength = sys.maxsize
tempSum = 0 # 탐색 과정에서 사용할 임시 구간합
start = 0 # 시작 포인터
end = 0 # 끝 포인터

n, s = map(int, input().split())
numList = list(map(int, input().split()))

# 시작 포인터가 numList의 끝에 도달할 때까지 반복
while start < n:
    # 구간합이 s보다 크거나 같으면 문제 조건 만족 -> minLength 갱신 후 start 포인터를 증가
    if tempSum >= s:
        minLength = min(minLength, end-start)
        tempSum -= numList[start]
        start += 1
    # 구간합이 s보다 작으면서 end 포인터가 아직 끝에 도달하지 않음 -> end포인터 증가
    elif end < n:
        tempSum += numList[end]
        end += 1
    # 구간합이 s보다 작으면서 end 포인터가 끝에 도달 -> start포인터 증가
    else:
        tempSum -= numList[start]
        start += 1

# minLength가 초기값을 유지하고 있으면 한 번도 갱신되지 않음을 뜻함
# -> 해당 조건을 만족하는 부분합이 numList 리스트 내에 존재하지 않으므로 0 출력
if minLength != sys.maxsize:
    print(minLength)
else:
    print(0)