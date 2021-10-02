public class Solution {
    /**
     * @param grid: a list of lists of integers
     * @return: return an integer, denote the number of distinct islands
     */
    int dir[][] = {{-1,0},{0,-1},{1,0},{0,1}};
    char dirS[] = {'U','L','D','R'};
    String shape = "";
    public void dfs(int[][] grid, int i, int j){
        grid[i][j] = 0;
        for(int d=0;d<4;d++){
            int r = i + dir[d][0];
            int c = j + dir[d][1];

            if(r>=0 && c>=0 && r<grid.length && c<grid[0].length && grid[r][c] == 1){
                shape += dirS[d];
                dfs(grid,r,c);
                shape += "B";
            }
        }
    }
    public int numberofDistinctIslands(int[][] grid) {
        int n = grid.length;
        int m = grid[0].length;
        HashSet<String> set = new HashSet<>();
        
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(grid[i][j] == 1){
                    dfs(grid,i,j);
                    System.out.println(shape);
                    set.add(shape);
                    shape = "";
                }
            }
        }
        return set.size();
    }
}