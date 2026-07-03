class Solution:
    def twoSum(self, nums: List[int], target: int) -> List[int]:
        map = {}
        for i in range(len(nums)):
            x = target - nums[i]
            if(x in map):
                return [map[x], i]
            map[nums[i]] = i