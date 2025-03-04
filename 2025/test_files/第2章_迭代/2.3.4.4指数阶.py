def exponential(n:int)->int:
    count=0
    base=1
    for _ in range(n):
        for _ in range(base):
            count+=1
        base*=2
    return count