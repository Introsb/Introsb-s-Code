class Solution:
    def maxScore(self, s: str) -> int:
        max_score = 0
        for i in range(0,len(str)):
            num0 = str[:i].count('0')
            num1 = str[i:].count('1')
            max_score = max( max_score, num0 + num1)
        return max_score