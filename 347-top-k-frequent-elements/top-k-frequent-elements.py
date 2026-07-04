class Solution:
    def topKFrequent(self, nums: List[int], k: int) -> List[int]:
        count = {}
        ans = []
        for ele in nums:
            count[ele] = count.get(ele, 0) + 1

        sorted_count = sorted(count.items(),key = lambda x : x[1], reverse = True)

        for i in range(k):
            ans.append(sorted_count[i][0])
        
        return ans



        # for i in range(k):
        #     temp = 0
        #     cnt = 0
        #     for key, value in count.items():
        #         if cnt < value:
        #             cnt = value
        #             temp = key
        #     ans.append(temp)
        #     count[temp] = 0 
        # return ans