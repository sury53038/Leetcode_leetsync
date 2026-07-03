class Solution:
    def isAnagram(self, s: str, t: str) -> bool:
        if(len(s) != len(t)):
            return False
        
        map_s = {}
        map_t = {}

        for chars in s:
            map_s[chars] = map_s.get(chars, 0) + 1

        for chars in t:
            map_t[chars] = map_t.get(chars, 0) + 1
    
        for key,value in map_s.items():
            if key not in map_t:
                return False
            if(map_t[key] != value):
                return False
        return True

        