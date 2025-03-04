import random
def random_numbers(n:int)->list[int]:
    nums=[i for i in range(1,n+1)]
    random.shuffle(nums)
    return nums

def find_one(nums:list[int])->int:
    for i in range(len(nums)):
        if nums[i]==1:
            return i
    return -1

if __name__=="__main__":
    n=int(input("请输入一个数:"))
    list1=random_numbers(n)
    print(find_one(list1))