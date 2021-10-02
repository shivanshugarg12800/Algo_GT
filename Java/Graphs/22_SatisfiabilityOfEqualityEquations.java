class Solution {
    public boolean isFindString(ArrayList<Integer>[] graph,int u,int v,boolean[] vis){
        if(u == v) return true;
        vis[u] = true;
        for(int idx: graph[u]){
            if(!vis[idx]){
                if(isFindString(graph,idx,v,vis)) return true;
            }
        }
        return false;
    }
    public boolean equationsPossible(String[] equations) {
        ArrayList<Integer>[] graph = new ArrayList[26];
        for(int i=0;i<26;i++){
            graph[i] = new ArrayList<>();
        }
        
        for(String s: equations){
            if(s.charAt(1) == '='){
                int u = s.charAt(0) - 'a';
                int v = s.charAt(3) - 'a';
                graph[u].add(v);
                graph[v].add(u);
            }
        }
        for(String s: equations){
            if(s.charAt(1) == '!'){
                boolean[] vis = new boolean[26];
                int u = s.charAt(0) - 'a';
                int v = s.charAt(3) - 'a';
                if(isFindString(graph,u,v,vis)) return false;
            }
        }
        return true;  
    }
}