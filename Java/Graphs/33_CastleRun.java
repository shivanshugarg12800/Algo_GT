class Solution
{
    public int isPossible(int[][] graph)
    {
        int n = graph.length;
        int count = 0;
        for(int i=0;i<n;i++){
            for(int j=0;j<n;j++){
                if(graph[i][j] == 1) count++; 
            }
            if((count & 1) != 0 ) return 0;
        }
        return 1;
        
    }
}