import sys
from collections import deque

input = sys.stdin.readline

for _ in range(int(input())):
    # reverseCount : R이 나온 회수 카운트
    # checkError : 에러 체크용 boolean 변수
    reverseCount = 0
    checkError = False

    cmd = input().rstrip()
    n = int(input())
    targetListStr = input().lstrip('[').rstrip(']\n').split(',') # 리스트 데이터 파싱

    # 양 끝단에서 pop을 하기 위해 deque로 변환 (파싱 후 데이터가 없을 시 빈 리스트로 설정)
    if targetListStr != ['']:
        targetList = deque(map(int, targetListStr))
    else:
        targetList = []

    # 명령어 처리
    for i in range(len(cmd)):
        # R 등장 시 회수 카운트
        if cmd[i] == 'R':
            reverseCount += 1
        elif cmd[i] == 'D':
            # D 등장 시 이미 리스트가 비어있으면 error
            if len(targetList) == 0:
                checkError = True
                break
            # R이 짝수번 등장했으면 앞에서 pop, 홀수번 등장했으면 뒤에서 pop
            elif reverseCount % 2 == 0:
                targetList.popleft()
            else:
                targetList.pop()

    # 마지막에 list형 전용 함수 사용을 위해 list로 돌려놓음
    targetList = list(targetList)

    # error 발생시 error 출력
    if checkError:
        print('error')
        continue
    # 총 R이 홀수번 등장했으면 리스트를 뒤집음
    elif reverseCount % 2 == 1:
        targetList.reverse()
    
    print('[', end='')
    print(*targetList, sep=',', end='')
    print(']')