public boolean isBipartite(int[][] graph,int src,int[] color){
        LinkedList<Integer> que = new LinkedList<>();
        que.addLast(src);
        int count = 0;
        while(que.size() != 0){
            int size = que.size();
            while(size-->0){
                int vtx = que.removeFirst();
                if(color[vtx] != -1){
                    if(color[vtx] != count)
                        return false;
                    continue;
                }
                color[vtx] = count;
                for(int v: graph[vtx]){
                    if(color[v] == -1){
                        que.addLast(v);
                    }
                }
            }
            count = (count+1)%2;
        }
        return true;    
    }
    public boolean isBipartite(int[][] graph) {
        int n = graph.length;
        int color[] = new int[n];
        Arrays.fill(color,-1);
        for(int i=0;i<n;i++){
            if(color[i] == -1){
                if(!isBipartite(graph,i,color)) return false;
            }
        }
        return true;
    }