public int[][] updateMatrix(int[][] mat) {
        int n = mat.length;
        int m = mat[0].length;
        int[][] dir = {{-1,0},{0,-1},{1,0},{0,1}};
        int[][] vis = new int[n][m]; 
        Queue<Integer> que = new LinkedList<>();
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(mat[i][j] == 0){
                    que.add(i*m +j);    
                    vis[i][j] = 1;
                }   
            }
        }
        int dis = 1;
        while(que.size() != 0){
            int size = que.size();
            while(size-->0){
                int vtx = que.remove();
                int i = vtx/m;
                int j = vtx%m;

                for(int d=0;d<4;d++){
                    int r = i + dir[d][0];
                    int c = j + dir[d][1];
                    if(r>=0 && c>=0 && r<n && c<m && vis[r][c] == 0){
                        vis[r][c] = 1;
                        mat[r][c] = dis;
                        que.add(r*m + c);
                    }
                }
            }
            dis++;
        }
        return mat;
    }