class Solution:
    def removeDuplicates(self, nums: List[int]) -> int:
        if(len(nums) <= 1):
            return len(nums)
        i = 1
        j = 1
        for j in range(1, len(nums)):
            if(nums[j] != nums[j-1]):
                nums[i] = nums[j]
                i += 1
        return i
