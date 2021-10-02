public int maxArea(int[] height) {
        int n = height.length;
        int i = 0, j = n-1;
        int area = 0;
        while(i<j){
            int b = j-i;                
            area = (height[i] < height[j]) ?  Math.max(area, height[i++]*b) : Math.max(area, height[j--]*b);  
            // area = Math.max(area, (Math.min(height[i],height[j])) * (j-i));
            // if(height[i]>height[j])  j--;
            // else i++;
        }
        return area;
    }