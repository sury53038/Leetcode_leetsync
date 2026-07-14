class Solution:
    def isPalindrome(self, s: str) -> bool:
        temp = ""
        for x in s:
            if x >= 'A' and x <= 'Z':
                temp += x.lower()
            elif x <= 'z' and x >= 'a':
                temp += x
            elif x >= '0' and x <= '9':
                temp += x
        
        i = 0
        j = len(temp)-1
        print(temp)
        while(i <= j):
            if(temp[i] != temp[j]):
                return False
            i += 1
            j -= 1
        return True
        


        