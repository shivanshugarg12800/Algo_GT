class Solution {
    public class Edge{
        String v;
        double w;
        Edge(String v,double w){
            this.v = v;
            this.w = w;
        }
    }
    double res = 1.0;
    public boolean dfs(HashMap<String,ArrayList<Edge>> map, String i,String j,HashSet<String> vis){
        if(i.equals(j)){
            // System.out.println("Yes");
            return true;
        }
        vis.add(i);
        ArrayList<Edge> al = map.get(i);
        for(Edge e: al){
            // System.out.println(e.v + ", " + e.w);
            if(!vis.contains(e.v)){
                res *= e.w;
                if(dfs(map,e.v,j,vis)) return true;
                res /= e.w;
            }
        }
        return false;
    }
    public double[] calcEquation(List<List<String>> equations, double[] values, List<List<String>> queries) {
        HashMap<String,ArrayList<Edge>> map = new HashMap<>();
        int n = values.length;
        for(int i=0;i<n;i++){
            String u = equations.get(i).get(0);
            String v = equations.get(i).get(1);
            double w = values[i];
            
            if(!map.containsKey(u)){
                map.put(u, new ArrayList<>());
            }
            if(!map.containsKey(v)){
                map.put(v, new ArrayList<>());
            }
            map.get(u).add(new Edge(v,w));
            map.get(v).add(new Edge(u,(double)1/w));
        }
        double[] ans = new double[queries.size()];
        int idx = 0;
        for(List<String> q: queries){
            String src = q.get(0);
            String dest = q.get(1);
            
            if(!map.containsKey(src) || !map.containsKey(dest)){
                ans[idx++] = -1.00000;
                continue;
            } 
            HashSet<String> vis = new HashSet<>();
            
            ans[idx++] = (dfs(map,src,dest,vis)) ?  res : -1.0;
            res = 1.00000;
        }
        return ans;
    }
}