class Solution {
    public String swap(String s,int i,int j){
        char[] arr = s.toCharArray();
        
        char temp = arr[i];
        arr[i] = arr[j];
        arr[j] = temp;
        
        return new String(arr);
    }
    public int slidingPuzzle(int[][] board) {
        int n = board.length;
        int m = board[0].length;
        int dir[][] = {{-1,0},{0,-1},{0,1},{1,0}};
        
        String dest = "123450";
        StringBuilder sb = new StringBuilder();
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                sb.append(board[i][j]);
            }
        }
        String src = sb.toString();
        HashSet<String> vis = new HashSet<>();
        Queue<String> que = new LinkedList<>();
        que.add(src);
        vis.add(src);
        int moves = 0;
        
        while(que.size() != 0){
            int size = que.size();
            while(size-->0){
                String str = que.remove();
                
                if(str.equals(dest)) return moves;
                
                int idx = str.indexOf("0");
                int i = idx/m;
                int j = idx%m;
                
                for(int d=0;d<dir.length;d++){
                    int r = i + dir[d][0];
                    int c = j + dir[d][1];
                    
                    if(r>=0 && c>=0 && r<n && c<m){
                        String next = swap(str,idx,r*m+c);
                        if(!vis.contains(next)){
                            vis.add(next);
                            que.add(next);
                        }
                    }
                }
            }
            moves++;
        }
        return -1;
    }
}