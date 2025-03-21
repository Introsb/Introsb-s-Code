def insert_sort(nums: list[int]):
    """插入排序"""
    # 外循环: 已排序区间为 [0, i-1]
    for i in range(1, len(nums)):
        base = nums[i]
        j = i - 1