class Solution:
    def twoSum(self, numbers: List[int], target: int) -> List[int]:
        mpp = {}
        
        for i in range(len(numbers)):
            if target-numbers[i] in mpp:
                return [mpp[target-numbers[i]]+1, i+1]
            else:
                mpp[numbers[i]] = i
        
        return  []
                