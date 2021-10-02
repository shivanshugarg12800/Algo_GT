class Solution
{
    public int  topo_DFS(ArrayList<Integer>[] graph, int src,boolean[] vis){
        int count = 1;
        vis[src] = true;
        for(int e: graph[src]){
            if(!vis[e]){
                count += topo_DFS(graph,e,vis);
            }
        }
        return count;
    }
    //Function to find a Mother Vertex in the Graph.
    public int findMotherVertex(int N, ArrayList<ArrayList<Integer>> edges)
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
        int count = 0;
        boolean[] vis = new boolean[N];
        for(int i=0;i<N;i++){
            if(!vis[i]){
                count = topo_DFS(graph,i,vis);
                if(count == N) return i;
            }
        }
        return -1;
    }
}