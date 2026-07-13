class Solution:
    def topKFrequent(self, nums: List[int], k: int) -> List[int]:
        ans = []
        mpp = {}

        for x in nums:
            mpp[x] = mpp.get(x, 0) + 1

        for i in range(k):
            maxi = 0
            temp = -1000000000
            for key,value in mpp.items():
                if(value > maxi):
                    maxi = value
                    temp = key
            ans.append(temp)
            mpp[temp] = -1
        return ans
        


        