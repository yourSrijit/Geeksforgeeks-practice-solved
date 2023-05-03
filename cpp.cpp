class Solution:
    def makePalindrome(self, n : int, arr : List[str]) -> bool:
        # code here
        l=list(arr)
        while len(l)>1:
            temp=l.pop()
            if temp[::-1] in l:
                l.remove(temp[::-1])
            else:
                return False
        if len(l)==0:
            return True
        if l[0]==l[0][::-1] :
            return True 
        else: 
            return False
