def solution(p):
    return fn(p)
    
def fn(text):
    if len(text) == 0:
        return ''
    
    u, v = divide(text)
    
    if check(u):
        return u + fn(v)
    else:
        returnText = '(' + fn(v) + ')'
        
        for i in u[1:len(u)-1]:
            if i == '(':
                returnText += ')'
            else:
                returnText += '('
        
        return returnText
    
def divide(text):
    front = 0
    back = 0
    
    for i in range(len(text)):
        if text[i] == '(':
            front += 1
        else:
            back += 1
        
        if front == back:
            break;
            
    return text[:front+back], text[front+back:]

def check(text):
    cnt = 0
    
    for i in text:
        if i == '(':
            cnt += 1
        else:
            if cnt == 0:
                return False
            else:
                cnt -= 1
    
    if cnt != 0:
        return False
    
    return True
