/**
 * Definition for a point.
 * class Point {
 *     int x;
 *     int y;
 *     Point() { x = 0; y = 0; }
 *     Point(int a, int b) { x = a; y = b; }
 * }
 */

public class Solution {
    /**
     * @param n: An integer
     * @param m: An integer
     * @param operators: an array of point
     * @return: an integer array
     */
    int par[];
    public int getPar(int u){
        if(u == par[u]) return u;
        return par[u] = getPar(par[u]);
    } 
    public List<Integer> numIslands2(int n, int m, Point[] operators) {
        if(operators == null) return new ArrayList<>();
        par = new int[n*m];
        for(int i=0;i<n*m;i++){
            par[i] = i;
        }

        int[][] dir = {{-1,0},{0,-1},{1,0},{0,1}};
        int[][] grid = new int[n][m];
        
        List<Integer> ans = new ArrayList<>();
        int count =0;
        
        for(Point p: operators){
            int i = p.x;
            int j = p.y;
            if(grid[i][j] == 1){  
                ans.add(count);
                continue;
            }
            grid[i][j] = 1;
            count++;
            int gp1 = getPar(i*m + j);
            for(int d=0;d<4;d++){
                int r = i+ dir[d][0];
                int c = j+ dir[d][1];
                if(r>=0 && c>=0 && r<n && c<m && grid[r][c] == 1){
                    
                    int gp2 = getPar(r*m + c);
                    if(gp1 != gp2){
                        count--;
                        par[gp2] = gp1;
                    }
                }
            }
            ans.add(count);
        }
        return ans;
    }
}