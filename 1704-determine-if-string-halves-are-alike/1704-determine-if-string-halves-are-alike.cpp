class Solution {
public:
    bool halvesAreAlike(string s) {
        string s2="";
        int c1=0;
        int n=s.size();
        for(int i=0;i<n;i++){
            if(i<n/2){
                if(s[i]=='A' || s[i]=='a' || s[i]=='E' || s[i]=='e' || s[i]=='I' || s[i]=='i' || s[i]=='O' || s[i]=='o' || s[i]=='U' || s[i]=='u'){
                c1++;
                }
            }
            else{
                if(s[i]=='A' || s[i]=='a' || s[i]=='E' || s[i]=='e' || s[i]=='I' || s[i]=='i' || s[i]=='O' || s[i]=='o' || s[i]=='U' || s[i]=='u'){
                c1--;
                }
                
            }
             
        }
        
      
        if(c1==0){
            return true;
        }
        return false;
    }
};