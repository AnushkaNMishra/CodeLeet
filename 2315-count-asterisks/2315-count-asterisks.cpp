class Solution {
public:
    int countAsterisks(string s) {
        int n=s.size();
        int l=0;
        int count=0;
        for(int i=0;i<n;i++){
           if(s[i]=='|'){
               l++;
           }
            if(l==2){
                l=0;
            }
            if(l==0 && s[i]=='*'){
                count++;
            }
        }
        return count;
    }
};