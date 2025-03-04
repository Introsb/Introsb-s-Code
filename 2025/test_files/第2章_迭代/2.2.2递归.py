def recur(n:int)->int:
    if n==1:
        return 1
    res=recur(n-1)
    return res+n

if __name__=="__main__":
    n=int (input("请输入一个数："))
    print(recur(n))