class Solution:
    def productExceptSelf(self, nums: List[int]) -> List[int]:
        left = []
        right = []
        ans = []

        left.append(1)
        right.append(1)

        n = len(nums)

        pdct = 1

        for i in range(1, n):
            pdct = pdct * nums[i-1]
            left.append(pdct)
        
        pdct = 1

        for j in range(n-2, -1, -1):
            pdct = pdct * nums[j+1]
            right.append(pdct)

        right.reverse()

        for i in range(n):
            ans.append(left[i] * right[i])
        
        return ans