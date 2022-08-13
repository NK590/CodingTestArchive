n,k=map(int,input().split())
nums=input()

stack=[]

# stack을 활용하여, stack 맨 위의 값이 넣을 값보다 작다면 넣을 값 중 크거나 같은 값이 나올 때까지 pop.
# pop할 때마다 k - 1. 왜냐하면 해당 숫자를 제거하는 것이기 때문
for num in nums:
    while stack and k>0 and stack[-1] < num:
        stack.pop()
        k-=1
    stack.append(num)

print("".join(stack[:len(stack)-k])) # 제거 횟수를 다 사용하지 않았을때 남은 횟수만큼 리스트 뒷부분을 자름