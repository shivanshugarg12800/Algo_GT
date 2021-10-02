import java.util.*;
class TestClass {
    public static void SCC_DFS(ArrayList<Integer>[] graph, int src,boolean[] vis,ArrayList<Integer> ans){
        vis[src] = true;
        for(Integer e: graph[src]){
            if(!vis[e]){
                SCC_DFS(graph,e,vis,ans);
            }
        }
        ans.add(src);
    }

    public static int[] SCC(ArrayList<Integer>[] graph,int N){
        int res[] = new int[N+1];
        ArrayList<Integer> ans = new ArrayList<>();
        boolean[] vis = new boolean[N+1];
        for(int i=1;i<=N;i++){
            if(!vis[i]){
                SCC_DFS(graph,i,vis,ans);
            }
        }
        // System.out.println(ans);
        @SuppressWarnings("unchecked")
        ArrayList<Integer>[] ngraph = new ArrayList[N+1];
        for(int i=0;i<=N;i++) ngraph[i] = new ArrayList<>();

        for(int i=1;i<=N;i++){
            for(int e: graph[i]){
                ngraph[e].add(i);
            }
        }
        vis = new boolean[N+1];
        for(int i = ans.size()-1;i>=0;i--){
            if(!vis[ans.get(i)]){
                ArrayList<Integer> singleComp = new ArrayList<>();
                SCC_DFS(ngraph,ans.get(i),vis,singleComp);
                // System.out.println(singleComp);
                if(singleComp.size() > 1){
                    for(int idx: singleComp){
                        res[idx] = 1;
                    }
                }
            }
        }
        return res;
    }
    public static void main(String args[] ) throws Exception {
        Scanner scn = new Scanner(System.in);
        int N = scn.nextInt();
        int M = scn.nextInt();
        int[][] edges = new int[M][2];
        for(int i=0;i<M;i++){
            edges[i][0] = scn.nextInt();
            edges[i][1] = scn.nextInt();
        }
        @SuppressWarnings("unchecked")
        ArrayList<Integer>[] graph = new ArrayList[N+1];
        for(int i=0;i<=N;i++) graph[i] = new ArrayList<>();

        for(int[] a: edges){
            graph[a[0]].add(a[1]);
        }
        int ans[] = SCC(graph,N);
        for(int i=1;i<=N;i++) System.out.print(ans[i] + " ");
    }
}