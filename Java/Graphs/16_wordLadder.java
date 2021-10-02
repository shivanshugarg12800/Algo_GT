class Solution {

    //M1
    public int ladderLength(String src, String dest, List<String> wordList) {
        int n = wordList.size();
        boolean isDest = false;
        for(String s: wordList){
            if(s.equals(dest)){
                isDest = true;
                break;
            } 
        }
        if(!isDest) return 0;
        HashMap<String,ArrayList<String>> map = new HashMap<>();
        HashSet<String> vis = new HashSet<>();
        
        for(int i = -1;i<n;i++){
            String temp = "";
            if(i == -1) temp = src;
            else temp = wordList.get(i);
            for(int j=0;j<temp.length();j++){
                StringBuilder sb = new StringBuilder();
                sb.append(temp.substring(0,j) + "*" +  temp.substring(j+1));
                String temp1 = sb.toString();
                if(!map.containsKey(temp1)) map.put(temp1,new ArrayList<>());
                map.get(temp1).add(temp);
            }
        }
        
        
        Queue<String> que = new LinkedList<>();
        que.add(src);
        vis.add(src);
        int dis = 1;
        while(que.size() != 0){
            int size = que.size();
            while(size-->0){
                String str = que.remove();
                for(int i=0;i<str.length();i++){
                    StringBuilder sb = new StringBuilder();
                    sb.append(str.substring(0,i) + "*" +  str.substring(i+1));
                    String temp1 = sb.toString();
                    ArrayList<String> al = map.get(temp1);
                    for(String s: al){
                        if(!vis.contains(s)){
                            if(s.equals(dest)) return dis+1;
                            que.add(s);
                            vis.add(s);
                        }
                    }
                }
            }
            dis++;
        }
        return 0;
    }


    //M2: more Intutive
    public int ladderLength(String src, String dest, List<String> wordList) {
        HashSet<String> dict = new HashSet<>(wordList);
        Queue<String> que = new LinkedList<>();
        que.add(src);
        int count = 1;
        while(que.size() != 0){
            int size = que.size();
            while(size-->0){
                String str = que.remove();
                
                if(str.equals(dest)) return count;
                
                char[] arr = str.toCharArray();
                for(int i=0;i<arr.length;i++){
                    char ch = arr[i];
                    for(char j = 'a'; j<='z'; j++){
                        arr[i] = j;
                        String currString = new String(arr);
                        if(dict.contains(currString)){
                            dict.remove(currString);
                            que.add(currString);
                        }
                    }
                    arr[i] = ch;
                }
                
            }
            count++;
        }
        return 0;
    }
}