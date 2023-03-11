class Solution {
public:
    bool halvesAreAlike(string s) {
        string s2="";
        int n2=s.size()/2;
        for(int i=0;i<=n2;i++){
            s2+=s[i];
        }
        
        int c1=0,c2=0;
       for(int i=n2;i<s.size();i++){
            if(s[i]=='A' || s[i]=='a' || s[i]=='E' || s[i]=='e' || s[i]=='I' || s[i]=='i' || s[i]=='O' || s[i]=='o' || s[i]=='U' || s[i]=='u'){
                c1++;
            }
        }
        for(int i=0;i<n2;i++){
           if(s2[i]=='A' || s2[i]=='a' || s2[i]=='E' || s2[i]=='e' || s2[i]=='I' || s2[i]=='i' || s2[i]=='O' || s2[i]=='o' || s2[i]=='U' || s2[i]=='u'){
                c2++;
            }
        }
        
        if(c1==c2){
            return true;
        }
        return false;
    }
};