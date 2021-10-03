class Solution {
public:
    int toInt(string s){
        int res=0;
        for(int i=0; i<s.length(); i++){
            res*=10;
            res+=s[i]-'0';
        }
        
        return res;
    }
    string decodeString(string s) {
        int currIdx=0, n=s.length();
        string res="";
        while(currIdx<n){
            if((s[currIdx]>='a')&&(s[currIdx]<='z')){
                string left="";
                while(currIdx<n){
                    if((s[currIdx]>='a')&&(s[currIdx]<='z')){
                        left+=s[currIdx];
                        currIdx++;
                    }             
                    else{
                        break;
                    }
                }
                res+=left;    
            }
            else if((s[currIdx]>='0')&&(s[currIdx]<='9')){
                string num="";
                while(currIdx<n){
                    if((s[currIdx]>='0')&&(s[currIdx]<='9')){
                        num+=s[currIdx];
                        currIdx++;
                    }             
                    else{
                        break;
                    }
                }
                
                currIdx++;
                int bal=1;
                string mid="";
                while(currIdx<n){
                    if(s[currIdx]=='['){
                        bal++;
                    }
                    else if(s[currIdx]==']'){
                        bal--;
                        if(bal==0){
                            break;
                        }
                    }
                    
                    mid+=s[currIdx];
                    currIdx++;
                }
                currIdx++;
                
                int nofCopies=toInt(num);
                mid=decodeString(mid);
                for(int i=0; i<nofCopies; i++){
                    res+=mid;
                }
            }
        }
        
        return res;
    }
};
