def linear_log_recur(n:int)->int:
    if n<=1:
        return 1
    count=linear_log_recur(n//2)+linear_log_recur(n//2)
    for _ in range(n):
        count+=1
    return count