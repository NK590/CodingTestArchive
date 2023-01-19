import sys

input = sys.stdin.readline

s, n = input().split()
s = int(s)

num_dict = { i : [[] for _ in range(2*s + 3)] for i in range(10) }
result = [[] for _ in range(2*s + 3)]

for i in range(10):
    if i in [1, 4]:
        num_dict[i][0].append(' '*(s+2))
    else:
        num_dict[i][0].append(' ' + '-'*s +' ')

    if i in [1, 2, 3, 7]:
        for j in range(1, s+1):
            num_dict[i][j].append(' '*(s+1) + '|')
    elif i in [5, 6]:
        for j in range(1, s+1):
            num_dict[i][j].append('|' + ' '*(s+1))
    else:
        for j in range(1, s+1):
            num_dict[i][j].append('|' + ' '*s + '|')

    if i in [1, 7, 0]:
        num_dict[i][s+1].append(' '*(s+2))
    else:
        num_dict[i][s+1].append(' ' + '-'*s +' ')

    if i in [1, 3, 4, 5, 7, 9]:
        for j in range(s+2, 2*s+2):
            num_dict[i][j].append(' '*(s+1) + '|')
    elif i in [2]:
        for j in range(s+2, 2*s+2):
            num_dict[i][j].append('|' + ' '*(s+1))
    else:
        for j in range(s+2, 2*s+2):
            num_dict[i][j].append('|' + ' '*s + '|')

    if i in [1, 4, 7]:
        num_dict[i][2*s+2].append(' '*(s+2))
    else:
        num_dict[i][2*s+2].append(' ' + '-'*s +' ')

for char in n:
    for i in range(2*s + 3):
        result[i].append(num_dict[int(char)][i])
        result[i].append([' '])

for i in range(2*s + 3):
    for j in range(len(result[i])):
        print(result[i][j][0], end='')
    print()