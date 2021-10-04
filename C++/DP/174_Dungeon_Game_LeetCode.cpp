class Solution {
public:
    int calculateMinimumHP(vector<vector<int>>& dun) {
        int n=dun.size(), m=dun[0].size();
        // This dp represents the minimum health.
        // You require to reach the end from that position.
        
        // We are comparing it with 1 because it is minimum value.
        // That knights of vale required to be in any cell.
        // If it goes down they will die.
        vector<vector<int>> dp(n, vector<int>(m, 0));
        dp[n-1][m-1]=max(1, 1-dun[n-1][m-1]);
        
        for(int i=n-2; i>=0; i--){
            dp[i][m-1]=max(1, dp[i+1][m-1]-dun[i][m-1]);
        }
        for(int j=m-2; j>=0; j--){
            dp[n-1][j]=max(1, dp[n-1][j+1]-dun[n-1][j]);
        }
        
        for(int i=n-2; i>=0; i--){
            for(int j=m-2; j>=0; j--){
                // This is the minimum health required in next steps.
                int miRq=min(dp[i][j+1], dp[i+1][j]);
                dp[i][j]=max(1, miRq-dun[i][j]);
            }
        }
        
        // for(int i=0; i<n; i++){
        //     for(int j=0; j<m; j++){
        //         cout<<dp[i][j]<<" ";
        //     }
        //     cout<<"\n";
        // }
        return dp[0][0];
    }
};
