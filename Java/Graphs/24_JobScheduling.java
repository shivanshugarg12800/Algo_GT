class Solution
{
    //Function to find the maximum profit and the number of jobs done.
    int[] JobScheduling(Job arr[], int n)
    {
        int[] ans = new int[2];
        Arrays.sort(arr,(a,b)->{
            return b.profit - a.profit;
        });
        int maxDeadline = 0;
        for(int i=0;i<n;i++){
            maxDeadline = Math.max(maxDeadline,arr[i].deadline);
        }
        boolean[] vis = new boolean[maxDeadline+1];
        int maxJobs = 0;
        int maxProfit = 0;
        for(Job a: arr){           
            for(int i=a.deadline;i>=1;i--){
                if(!vis[i]){
                    vis[i] = true;
                    maxJobs++;
                    maxProfit += a.profit;
                    break;
                }
            }
        }
        ans[0] = maxJobs;
        ans[1] = maxProfit;
        return ans;
    }
}