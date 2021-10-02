int firstMissingPositive(vector<int> &nums)
{
    /* the idea behind the approach is to place the numbers >=0 and which are 
    less than n on their respective indexes and then again traverse the array, 
    the first index where the number is not equal to the index itself is the 
    missing positive number.
    */
    int n = nums.size();
    for (int i = 0; i < nums.size(); i++)
    {
        while (nums[i] <= n and nums[i] >= 1 and nums[i] != nums[nums[i] - 1])
            swap(nums[i], nums[nums[i] - 1]);
    }
    for (int i = 0; i < nums.size(); i++)
    {
        if (nums[i] != (i + 1))
        {
            return i + 1;
        }
    }
    return n + 1;
}