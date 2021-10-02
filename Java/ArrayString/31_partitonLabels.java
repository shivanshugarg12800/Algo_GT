 //M1
    public List<Integer> partitionLabels(String s) {
        int n = s.length();
        List<Integer> ans = new ArrayList<>();
        HashMap<Character,Integer> map = new HashMap<>();
        for(int i=0;i<n;i++){
            map.put(s.charAt(i), map.getOrDefault(s.charAt(i),0) + 1);
        }
        boolean[] vis = new boolean[26];
        int count = 0, si = 0;
        for(int ei=0;ei<n;ei++){
            char ch = s.charAt(ei);
            if(!vis[ch - 'a']){
                vis[ch - 'a'] = true;
                count++;
            }
            map.put(ch, map.get(ch)-1);
            if(map.get(ch) == 0) count--;
            if(count == 0){
                ans.add(ei - si + 1);
                si = ei+1;
            }
        }
        return ans;
    }
    //M2 using array better solution
    public List<Integer> partitionLabels(String s) {
        int n = s.length();
        List<Integer> ans = new ArrayList<>();
        int[] map = new int[26];
        for(int i=0;i<n;i++){
            map[s.charAt(i) - 'a']++;
        }
        boolean[] vis = new boolean[26];
        int count = 0, si = 0;
        for(int ei=0;ei<n;ei++){
            char ch = s.charAt(ei);
            if(!vis[ch - 'a']){
                vis[ch - 'a'] = true;
                count++;
            }
            map[ch- 'a']--;
            if(map[ch- 'a'] == 0) count--;
            if(count == 0){
                ans.add(ei - si + 1);
                si = ei+1;
            }
        }
        return ans;
    }