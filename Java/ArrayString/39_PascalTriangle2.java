public List<Integer> getRow(int n) {
        List<Integer> ans = new ArrayList<>();
        long val = 1;
        for(int i=0;i<=n;i++){
            ans.add((int)val);
            val = (val * (n-i))/(i+1);
        }
        return ans;
    }