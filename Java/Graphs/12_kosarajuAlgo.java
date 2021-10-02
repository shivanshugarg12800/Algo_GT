public void topo_DFS_01(ArrayList<Integer>[] graph, int src,boolean[] vis,ArrayList<Integer> ans){
        vis[src] = true;
        for(int e: graph[src]){
            if(!vis[e]){
                topo_DFS_01(graph,e,vis,ans);
            }
        }
        ans.add(src);
    }
    public void topo_DFS_02(ArrayList<Integer>[] graph, int src,boolean[] vis){
        vis[src] = true;
        for(int e: graph[src]){
            if(!vis[e]){
                topo_DFS_02(graph,e,vis);
            }
        }
    }
    //Function to find number of strongly connected components in the graph.
    public int kosaraju(int N, ArrayList<ArrayList<Integer>> edges)
    {
        @SuppressWarnings("unchecked")
        ArrayList<Integer>[] graph = new ArrayList[N];
        for(int i=0;i<N;i++) graph[i] = new ArrayList<>();
        
        for(int i=0;i<N;i++){
            for(int j=0;j<edges.get(i).size();j++){
                int v = edges.get(i).get(j);
                graph[i].add(v);
            }
        }
        
        boolean[] vis = new boolean[N];
        ArrayList<Integer> ans = new ArrayList<>();
        for(int i=0;i<N;i++){
            if(!vis[i]){
                topo_DFS_01(graph,i,vis,ans);
            }
        }
        
        @SuppressWarnings("unchecked")
        ArrayList<Integer>[] ngraph = new ArrayList[N];
        for(int i=0;i<N;i++) ngraph[i] = new ArrayList<>();
        
        for(int i=0;i<N;i++){
            for(int j=0;j<edges.get(i).size();j++){
                int v = edges.get(i).get(j);
                ngraph[v].add(i);
            }
        }
        
        vis = new boolean[N];
        int count = 0;
        for(int i=ans.size()-1;i>=0;i--){
            if(!vis[ans.get(i)]){
                count++;
                topo_DFS_02(ngraph,ans.get(i),vis);
            }
        }
        return count;
    }