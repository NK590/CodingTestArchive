from bisect import bisect_left

# 프로그래머스 LV2 - 순위 검색

def solution(info, query):
    language = {"cpp": 0, "java": 1, "python": 2, '-': 3}
    job = {"backend": 0, "frontend": 1, "-": 2}
    career = {"junior": 0, "senior": 1, "-": 2}
    food = {"chicken": 0, "pizza": 1, "-": 2}

    db = [[] for _ in range(1 << 13)]

    index_l_bar = 1 << 12
    index_j_bar = 1 << 8
    index_c_bar = 1 << 5
    index_f_bar = 1 << 2

    for data in info:
        l, j, c, f, score = data.split()
        score = int(score)

        index_l = 1 << (language[l] + 9)
        index_j = 1 << (job[j] + 6)
        index_c = 1 << (career[c] + 3)
        index_f = 1 << (food[f])

        for x in (index_l_bar, index_l):
            for y in (index_j_bar, index_j):
                for z in (index_c_bar, index_c):
                    for w in (index_f_bar, index_f):
                        db[x + y + z + w].append(score)

    for entry in db:
        entry.sort()

    ans = []

    for q in query:
        l, _, j, _, c, _, f, score = q.split()
        index = (1 << (language[l] + 9)) + (1 << (job[j] + 6)) + (1 << (career[c] + 3)) + (1 << food[f])
        ans.append(len(db[index]) - bisect_left(db[index], int(score)))

    return ans
