public boolean isVowel(char ch){
        return ch == 'a' || ch == 'e' || ch == 'i' || ch == 'o' || ch == 'u' || ch == 'A' || ch == 'E' || ch == 'I' || ch == 'O' || ch == 'U'; 
    }
    public void swap(char[] arr,int si,int ei){
        char temp = arr[si];
        arr[si]  = arr[ei];
        arr[ei] = temp;
    }
    public String reverseVowels(String s) {
        char[] arr = s.toCharArray();
        int n = s.length(), si = 0, ei = n-1;
        while(si < ei){
            while(si<ei && !isVowel(arr[si])) si++;
            while(si<ei && !isVowel(arr[ei])) ei--;
            swap(arr,si++,ei--);
        }
        StringBuilder sb = new StringBuilder();
        int idx= 0;
        while(idx<n){
            sb.append(arr[idx++]);
        }
        return sb.toString();
    }