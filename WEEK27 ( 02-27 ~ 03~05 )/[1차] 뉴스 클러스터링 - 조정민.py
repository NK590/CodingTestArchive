def solution(str1, str2):   
    list1 = check(str1)
    list2 = check(str2)
    cnt = len(list1) + len(list2)
    cnt2 = 0
    
    for i in list1:
        for j in range(len(list2)):
            if i == list2[j]:
                cnt2 += 1
                del list2[j]
                break;
            
    print(cnt2)
    if cnt - cnt2 == 0:
        answer = 65536
    else :
        answer = cnt2 / (cnt - cnt2) * 65536

    return int(answer)

def check(str1):
    returnList = list()
    
    for i in range(len(str1) - 1):
        word1 = ord(str1[i].upper())
        word2 = ord(str1[i+1].upper())
        
        if word1 >= 65 and word1 <= 90 and word2 >= 65 and word2 <= 90:
            returnList.append(''+chr(word1)+chr(word2))
        
    
    return returnList
