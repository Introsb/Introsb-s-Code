def bubble_sort(nums:list[int])->int:
    count=0
    for i in range(len(nums)-1,0,-1):
        for j in range(i):
            if nums[j]>nums[j+1]:
                temp:int=nums[j]
                nums[j]=nums[j+1]
                nums[j+1]=temp
                count+=3
    return count