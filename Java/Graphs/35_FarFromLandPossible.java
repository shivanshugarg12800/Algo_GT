class Solution {
    public int maxDistance(int[][] grid) {
        int n = grid.length;
        int m = grid[0].length;
        int dir[][] = {{-1,0},{0,-1},{1,0},{0,1}};
        Queue<Integer> que = new LinkedList<>();
        int c1 = 0, c0 = 0;
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(grid[i][j] == 1){
                    que.add(i*m + j);
                    c1++;
                }
                else c0++;
            }
        }
        if(c1 == 0 || c0 == 0) return -1;
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
                    if(r>=0 && c>=0 && r<n && c<m && grid[r][c] == 0){
                        grid[r][c] = 1;
                        que.add(r*m + c);
                    }
                }
            }
            level++;
        }
        
        return level-1;
    }
}