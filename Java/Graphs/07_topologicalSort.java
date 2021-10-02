@SuppressWarnings("unchecked")
static int[] topoSort(int N, ArrayList<ArrayList<Integer>> edges) 
    {
        ArrayList<Integer>[] graph = new ArrayList[N];
        for(int i=0;i<N;i++) graph[i] = new ArrayList<>();
        
        int[] ans = new int[N];
        int idx = 0;
        
        int indegree[] = new int[N];
        for(int i=0;i<N;i++){
            for(int j=0;j<edges.get(i).size();j++){
                int v = edges.get(i).get(j);
                indegree[v]++;
                graph[i].add(v);
            }
        }
        
        LinkedList<Integer> que = new LinkedList<>();
        for(int i=0;i<N;i++){
            if(indegree[i] == 0) que.addLast(i);
        }
        
        while(que.size() != 0){
            int vtx = que.removeFirst();
            ans[idx++] = vtx;
            for(int v: graph[vtx]){
                if(--indegree[v] == 0) que.addLast(v);
            }
        }
        if(idx== N) return ans;
        else return new int[0];
    }