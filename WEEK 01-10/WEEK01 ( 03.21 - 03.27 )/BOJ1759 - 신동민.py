l,c = map(int,input().split())

arr=list(map(str,input().split()))
arr.sort()

def check(pw):
    vowels=['a','e','i','o','u']
    vowel_cnt=0
    consonant_cnt=0

    for p in list(pw):
        if p in vowels:
            vowel_cnt+=1
        else:
            consonant_cnt+=1

    if vowel_cnt >= 1 and consonant_cnt >= 2:
        return True
    else:
        return False

def dfs(index,pw):
    global l,c

    if len(pw) == l:
        if check(pw):
            print(pw)
        return

    if index>=c:
        return

    dfs(index+1,pw+arr[index])
    dfs(index+1,pw)

dfs(0,'')