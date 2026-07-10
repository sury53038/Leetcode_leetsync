class Solution:
    def groupAnagrams(self, strs: List[str]) -> List[List[str]]:
        mpp = {}
        for st in strs:
            if tuple(sorted(st)) not in mpp:
                mpp[tuple(sorted(st))] = [st]
            elif tuple(sorted(st)) in mpp:
                mpp[tuple(sorted(st))].append(st)

        ans = []
        for key, values in mpp.items():
            ans.append(values)
        return ans
            
