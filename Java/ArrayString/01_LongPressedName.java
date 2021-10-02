public boolean isLongPressedName(String a, String b) {
        int n = a.length(), m = b.length();
        int i = 0, j = 0;
        
        while(i<n && j<m){
            if(a.charAt(i) == b.charAt(j)){
                if(j+1 < m && b.charAt(j) == b.charAt(j+1)){
                    if(i+1 < n && a.charAt(i) == a.charAt(i+1)) i++;
                    j++;
                }
                else{
                    i++;
                    j++;
                }
            }
            else{
                return false;
            }
        }
        if((i==n && j<m) || (j==m && i<n)) return false;
        return true;
    }