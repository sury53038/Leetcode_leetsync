class Solution:
    def longestConsecutive(self, nums: List[int]) -> int:
        n = len(nums)
        if n <= 1:
            return n

        temp = sorted(nums)

        count = 1
        max_count = 0
        for i in range(1, n):
            if temp[i-1] == temp[i]:
                continue
            if temp[i-1] + 1 == temp[i]:
                count += 1
                max_count = max(count, max_count)
            else:
                count = 1
        return max(max_count, count)
