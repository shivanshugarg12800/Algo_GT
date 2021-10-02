public int[] findOrder(int N, int[][] prerequisites) {
        ArrayList<Integer>[] graph = new ArrayList[N];
        for(int i=0;i<N;i++) graph[i] = new ArrayList<>();
        int[] indegree = new int[N];
        for(int[] a: prerequisites){
            indegree[a[1]]++;
            graph[a[0]].add(a[1]);
        }
        int[] ans = new int[N];
        int idx = N-1;
        LinkedList<Integer> que = new LinkedList<>();
        for(int i=0;i<N;i++){
            if(indegree[i] == 0) que.addLast(i);
        }
        while(que.size() != 0){
            int u = que.removeFirst();
            ans[idx--] = u;
            for(int v: graph[u]){
                if(--indegree[v] == 0) que.addLast(v);
            }
        }
        if(idx == -1) return ans;
        return new int[0];
        
    }