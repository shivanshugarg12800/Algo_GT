def sortedSquares(self, nums: List[int]) -> List[int]:
    ans = []
    for element in nums:
        ans.append(element ** 2)
    
    ans.sort()
    print(ans)
    return ans