class Solution{
    static int eulerPath(int N, int graph[][]){
        int degree[] = new int[N];
        for(int i=0;i<N;i++){
            for(int j=0;j<N;j++){
                if(graph[i][j] == 1){
                    degree[j]++;
                }
            }
        }
        int count = 0;
        for(int ele: degree){
            if(ele%2 != 0) count++;
        }
        return (count == 0 || count  == 2) ? 1 : 0;
    }
}