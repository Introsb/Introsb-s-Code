from typing import List


class Solution:
    def trap(self, height: List[int]) -> int:
        n = len(height)
        pre_max = [0] * n
        suf_max = [0] * n
        for i in range(1, n):
            pre_max[i] = max(pre_max[i - 1],height[i])
        
        for i in range(n - 2, -1, -1):
            suf_max[i] = max(suf_max[i + 1], height[i])

        for h, pre, suf in zip(height, pre_max, suf_max):
            ans += min(suf, pre) - h
        return ans
        