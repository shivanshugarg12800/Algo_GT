public class Solution {
    /**
     * @param words1: 
     * @param words2: 
     * @param pairs: 
     * @return: Whether sentences are similary or not?
     */
    public boolean isSimilarDFS(HashMap<String,ArrayList<String>> graph,String src,String dest, HashSet<String> vis){
        if(src.equals(dest)) return true;
        vis.add(src);
        if(graph.get(src) == null) return false;
        ArrayList<String> al = graph.get(src);
        for(int i=0;i<al.size();i++){
            String s = al.get(i);
            if(!vis.contains(s)){
                if(isSimilarDFS(graph,s,dest,vis))  return true;
            }
        }
        return false;
    }
    public boolean areSentencesSimilarTwo(List<String> words1, List<String> words2, List<List<String>> pairs) {
        int n = words1.size();
        int m = words2.size();
        if(n != m) return false;
        HashMap<String,ArrayList<String>> graph = new HashMap<>();
        for(List<String> p: pairs){
            String u = p.get(0);
            String v = p.get(1);
            if(!graph.containsKey(u)) graph.put(u,new ArrayList<>());
            if(!graph.containsKey(v)) graph.put(v,new ArrayList<>());
            graph.get(u).add(v);
            graph.get(v).add(u);
        } 
        
        for(int i=0;i<n;i++){
            HashSet<String> vis = new HashSet<>();
            String src = words1.get(i);
            String dest = words2.get(i);
            if(!isSimilarDFS(graph,src,dest,vis)) return false;
        }
        return true;
    }
}