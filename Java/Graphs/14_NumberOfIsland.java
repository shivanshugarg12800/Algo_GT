class Solution {
    int par[];
    int size[];
    public int getPar(int u){
        if(u == par[u]) return u;
        return par[u] = getPar(par[u]);
    }
    public int numIslands(char[][] grid) {
        int n = grid.length;
        int m = grid[0].length;
        int dir[][] = {{0,1},{1,0}};
        int count = 0;
        par = new int[n*m];
        size = new int[n*m];
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(grid[i][j] == '1'){
                    par[i*m + j] = i*m + j;
                    size[i*m + j] = 1;
                    count++;
                }
                else{
                    par[i*m + j] = -1;
                    size[i*m + j] = 0;
                }
            }
        }
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(grid[i][j] == '1'){
                    int gp1 = getPar(i*m+j);
                    for(int d=0;d<2;d++){
                        int r = i + dir[d][0];
                        int c = j + dir[d][1];
                        if(r<n && c<m && grid[r][c] == '1'){
                            int gp2 = getPar(r*m + c);
                            if(gp1 != gp2){
                                count--;
                                par[gp2] = gp1;
                                size[gp1] += size[gp2];
                            }
                        }
                    }
                }
            }
        }
        return count;
    }
}