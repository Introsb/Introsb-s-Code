def nest_for_loop(n:int) ->int:
    res=""
    for i in range(1,n+1):
        for j in range(1,n+1):
            res+=f"({i},{j}),"
        return res

if __name__=="__main__":
    n=int(input("请输入一个数："))
    print(nest_for_loop(n))