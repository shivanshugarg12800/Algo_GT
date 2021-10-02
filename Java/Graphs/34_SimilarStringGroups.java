class Solution {
    public boolean isSimlar(String s, String t){
        int count = 0;
        for(int i=0;i<s.length();i++){
            if(s.charAt(i) != t.charAt(i)) count++;;

            if(count > 2) return false;
        }
        return true;
    }
    int par[];
    public int findPar(int u){
        if(u ==par[u]) return u;
        return par[u] = findPar(par[u]);
    }
    public int numSimilarGroups(String[] strs) {
        int n = strs.length;
        par = new int[n];
        for(int i=0;i<n;i++){
            par[i] = i;
        }
        int count = n;
        for(int i=0;i<n;i++){
            for(int j=i+1;j<n;j++){
                if(isSimlar(strs[i],strs[j])){
                    int gp1 = findPar(i);
                    int gp2 = findPar(j);
                    if(gp1 != gp2){
                        count--;
                        par[gp2] = gp1;
                    }
                    
                }
            }
        }
        return count;
    }
}