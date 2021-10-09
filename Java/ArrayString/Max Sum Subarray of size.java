class Solution{
    static int maximumSumSubarray(int K, ArrayList<Integer> Arr,int N){
        // code here
     
       

      int maxSum = Integer.MIN_VALUE;
        int windowStart = 0;
        int windowSum = 0;

        for(int windowEnd = 0; windowEnd < N; windowEnd++) {
            windowSum += Arr.get(windowEnd); // Add the next element to the window
            
            if(windowEnd-windowStart+1 == K) { // When we hit the window size. Update maximum sum, and slide the window
                maxSum = Math.max(maxSum, windowSum);
                windowSum -= Arr.get(windowStart); // Subtract the element going out of the window
                windowStart++; // Slide the window
            }
        }

        return maxSum;
    }
}
