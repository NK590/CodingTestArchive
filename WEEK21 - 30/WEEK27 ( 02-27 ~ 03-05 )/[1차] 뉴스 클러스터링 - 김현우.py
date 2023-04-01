from collections import Counter

def solution(str1, str2):
    str1_trim = str1.lower()
    str2_trim = str2.lower()

    len_str1 = len(str1_trim)
    len_str2 = len(str2_trim)

    str1_list = []
    str2_list = []

    # 특수문자 없이 두문자씩 짤라서 append
    for i in range(len_str1 - 1):
        if str1_trim[i].isalpha() and str1_trim[i + 1].isalpha():
            str1_list.append(str1_trim[i:i + 2])
    for i in range(len_str2 - 1):
        if str2_trim[i].isalpha() and str2_trim[i + 1].isalpha():
            str2_list.append(str2_trim[i:i + 2])

    # Counter 모듈 사용으로 교집합, 합집합 구하기
    counter1 = Counter(str1_list)
    counter2 = Counter(str2_list)

    inter = list((counter1 & counter2).elements())
    union = list((counter1 | counter2).elements())

    return 65536 if len(inter) == 0 and len(union) == 0 else int((len(inter) / len(union)) * 65536)