def maxArea(self, height: List[int]) -> int:
    left, right = 0, len(height) - 1;
    length, width = 0, 0

    ans = 0

    while(left < right) :
        length = right - left
        width = min(height[left], height[right])
        ans = max(ans, length * width)
        if height[left] < height[right]:
            left += 1
        else:
            right -= 1
    
    return ans