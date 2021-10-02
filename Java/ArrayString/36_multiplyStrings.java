public String multiply(String num1, String num2) {
        if(num1.equals("0") || num2.equals("0")) return "0";
        
        int n = num1.length();
        int m = num2.length();
        
        int[] res = new int[n+m];
        
        for(int i=n-1;i>=0;i--){
            for(int j=m-1;j>=0;j--){
                int mul = (num1.charAt(i) - '0') * (num2.charAt(j) - '0');
                
                int p1 = i+j, p2 = i+j+1;
                
                int sum = mul + res[p2];
                
                res[p2] = sum%10;
                res[p1] += sum/10;
            }
        }
        
        StringBuilder sb = new StringBuilder();
        int i=0;
        while(i<res.length && res[i] == 0) i++;
        while(i<res.length){
            sb.append(res[i++]);
        }
        return sb.toString();
    }