def for_loop_recur(n:int)->int:
    stack=[]
    res=0
    for i in range(n,0,-1):
        stack.append(i)
    while stack:
        res+=stack.pop()
    return res