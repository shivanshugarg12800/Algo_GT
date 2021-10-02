ppublic int maximumSwap(int num) {
        String s = "" + num;
        boolean flag = false;
        StringBuilder sb = new StringBuilder();
        int n = s.length();
        for(int i=0;i<n;i++){
            char maxChar = '0';
            int maxIdx = 0;
            for(int j=i+1;j<n;j++){
                if(maxChar <= s.charAt(j)){
                    maxChar = s.charAt(j);
                    maxIdx = j;
                }
            }
            if(s.charAt(i) < maxChar){
                flag = true;
                sb.append(s.substring(0,i) + s.charAt(maxIdx) + s.substring(i+1,maxIdx) + s.charAt(i) + s.substring(maxIdx+1)); 
                break;
            }
        }
        return flag ? Integer.parseInt(sb.toString()) : num;
    }
ublic int maximumSwap(int num) {
        String s = "" + num;
        boolean flag = false;
        StringBuilder sb = new StringBuilder();
        int n = s.length();
        for(int i=0;i<n;i++){
            char maxChar = '0';
            int maxIdx = 0;
            for(int j=i+1;j<n;j++){
                if(maxChar <= s.charAt(j)){
                    maxChar = s.charAt(j);
                    maxIdx = j;
                }
            }
            if(s.charAt(i) < maxChar){
                flag = true;
                sb.append(s.substring(0,i) + s.charAt(maxIdx) + s.substring(i+1,maxIdx) + s.charAt(i) + s.substring(maxIdx+1)); 
                break;
            }
        }
        return flag ? Integer.parseInt(sb.toString()) : num;
    }