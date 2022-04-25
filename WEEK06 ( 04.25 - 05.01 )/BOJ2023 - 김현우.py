import sys

input = sys.stdin.readline

def is_prime(num):
    if num == 1:
        return False
    if num == 2 or num == 3:
        return True
    for i in range(2, int(num**0.5)+1):
        if num % i == 0:
            return False
    return True

def backtrack():
    global num_str
    if len(num_str) == n:
        prime_num_list.append(int(num_str))
        return

    if len(num_str) == 0:
        for i in range(1, 10):
            if is_prime(int(num_str + str(i))):
                num_str = num_str + str(i)
                backtrack()
                num_str = num_str[:-1]
    else:
        for i in [1, 3, 7, 9]:
            if is_prime(int(num_str + str(i))):
                num_str = num_str + str(i)
                backtrack()
                num_str = num_str[:-1]

n = int(input())
prime_num_list = []
num_str = ""

backtrack()

prime_num_list.sort()
print(*prime_num_list, sep='\n')