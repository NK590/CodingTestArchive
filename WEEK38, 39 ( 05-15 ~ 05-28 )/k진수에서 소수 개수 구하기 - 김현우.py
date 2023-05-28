# 프로그래머스 Lv2. k진수에서 소수 개수 구하기

def base_k(n, k):
    temp = ""
    while n:
        temp += str(n % k)
        n = n // k
    return ''.join(reversed(temp))

def is_prime(n):
    if n == 1:
        return False
    if n == 2 or n == 3:
        return True
    for i in range(3, int(n ** 0.5) + 1):
        if n % i == 0:
            return False
    return True

def solution(n, k):
    answer = 0
    n_k = base_k(n, k)
    for num in n_k.split('0'):
        if num == '':
            continue
        if is_prime(int(num)):
            answer += 1
    return answer