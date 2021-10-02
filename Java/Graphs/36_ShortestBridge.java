class Solution {
    int dir[][] = {{-1,0},{0,-1},{1,0},{0,1}};
    public void dfs(int[][] grid,int i,int j){
        grid[i][j] = 2;
        for(int d=0;d<4;d++){
            int r = i + dir[d][0];
            int c = j + dir[d][1];
                    
            if(r>=0 && c>=0 && r<grid.length && c<grid[0].length && grid[r][c] == 1){
                dfs(grid,r,c);
            }
        }
    }
    
    
    public int shortestBridge(int[][] grid) {
        int n = grid.length;
        int m = grid[0].length;
        boolean isUpdate = false;
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(grid[i][j] == 1){
                    dfs(grid,i,j);
                    isUpdate = true;
                    break;
                }
            }
            if(isUpdate) break;
        } 
        Queue<Integer> que = new LinkedList<>();
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(grid[i][j] == 2) que.add(i*m + j);
            }
        }
        int level = 0;
        while(que.size() != 0){
            int size = que.size();
            while(size-->0){
                int idx = que.remove();
                int i = idx/m;
                int j = idx%m;
                
                for(int d=0;d<4;d++){
                    int r = i + dir[d][0];
                    int c = j + dir[d][1];
                    
                    if(r>=0 && c>=0 && r<n && c<m && grid[r][c] != 2){
                        if(grid[r][c] == 1)  return level;
                        grid[r][c] = 2;
                        que.add(r*m + c);
                    }
                }
            }
            level++;
        }
        return -1;
    }
}