class Solution:
    def isAnagram(self, s: str, t: str) -> bool:
        if(len(s) != len(t)):
            return False
        map_s = {}
        map_t = {}

        for x in s:
            if(x in map_s):
                map_s[x] = map_s.get(x) + 1
            else:
                map_s[x] = 1
        
        for x in t:
            if(x in map_t):
                map_t[x] = map_t.get(x) + 1
            else:
                map_t[x] = 1

        for key, values in map_s.items():
            if key not in map_t:
                return False
            if values != map_t[key]:
                return False
        return True

    