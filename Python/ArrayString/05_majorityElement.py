def majorityElement(nums):

    nums.sort()
    count, ans = 1, 0
    
    for i in range(1, len(nums)):
        if(nums[i] == nums[i - 1]):
            count += 1;
        else:
            count = 1
        if(count > len(nums) // 2):
            return nums[i - 1]
    
    return nums[0]