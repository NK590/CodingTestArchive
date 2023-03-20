# n자리수 숫자 생성 재귀 구현
def convert(n, base):
    num = "0123456789ABCDEF"
    q, r = divmod(n, base)
    return num[r] if q == 0 else convert(q, base) + num[r]

def solution(n, t, m, p):
    answer = ''
    temp = ''

    # temp 스트링에 우선 모든 숫자 때려넣기
    for i in range(m * t):
        temp += str(convert(i, n))

    # 자기 순서에 맞는 숫자만 answer에 합쳐 출력
    while len(answer) < t:
        answer += temp[p - 1]
        p += m

    return answer