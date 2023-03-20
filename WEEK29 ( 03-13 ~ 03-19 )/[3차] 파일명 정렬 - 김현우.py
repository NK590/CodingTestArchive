import re

# 정규식을 이용한 풀이. 너무 깔끔하고 간략한 풀이라 인터넷에서 가져옴
def solution(files):
    target = [re.split(r"([0-9]+)", file) for file in files]                # 숫자 문자열덩어리 기준으로 split
    sorted_list = sorted(target, key = lambda x: (x[0].lower(), int(x[1]))) # head 사전순 -> number 숫자순으로 정렬
    return [''.join(file) for file in sorted_list]                          # 정렬 끝난 문자열 덩어리들을 다시 join하여 출력