class Solution {
    //Note We gonna do optimal selection of string to come in queue  
    public String swap(String str,int i,int j){
        char[] arr = str.toCharArray();
        char temp = arr[i];
        arr[i] = arr[j];
        arr[j] = temp;
        
        return new String(arr);
    }
    public int kSimilarity(String src, String dest) {
        int n = src.length();
        HashSet<String> set = new HashSet<>();
        Queue<String> que = new LinkedList<>();
        que.add(src);
        
        int level = 0;
        while(que.size() != 0){
            int size = que.size();
            while(size-->0){
                String rst = que.remove();
                if(rst.equals(dest)) return level;
                
                int idx = 0;
                //we will not change substrings that starts from both src, dest and which are same 
                while(idx < n){
                    if(rst.charAt(idx) == dest.charAt(idx)) idx++;
                    else break;
                }
                
                for(int i=idx+1;i<n;i++){
                    if(rst.charAt(idx) == dest.charAt(i)){
                        String temp = swap(rst,idx,i);
                        if(!set.contains(temp)){
                            que.add(temp);
                            set.add(temp);
                        }
                    }
                }
                
            }
            level++;
        }
        return -1;
    }
}